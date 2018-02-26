#ifndef COLORSCHEMES_INCLUDED
#define COLORSCHEMES_INCLUDED

#include "dat.h"
#include "modeldialog.h"
#include "interface.h"
#include <gtk/gtk.h>

#define NUM_COLOR_SCHEMES 16
#define NUM_CHOOSABLE_COLORS 32
#define COLORGRID_WIDTH 8

typedef struct {
    uint8_t value;
    GdkPixbuf* pixbuf;
    GtkWidget* image;
    GtkToolItem* tool_item;
    color_dialog_t* dialog;
} color_dialog_tool_t;

typedef struct {
    GtkWidget* dialog;
    uint8_t* colorAddress;
    GtkToolbar** toolbars;
    color_dialog_tool_t** tools;
} color_dialog_t;

typedef struct {
    uint8_t* color;
    GdkPixbuf* pixbuf;
    GtkWidget* image;
    GtkToolItem* tool_item;
    color_dialog_t* dialog;
} color_scheme_button_t;

typedef struct {
    color_scheme_t* color_scheme;
    uint8_t index;
    GtkWidget* hbox;
    GtkToolItem* deleteButton;
    GtkWidget* hseparator;
    color_scheme_button_t** tools;
} color_scheme_widget_t;

color_dialog_t* color_dialog_new(char* colorName, uint8_t* colorAddress);
void color_dialog_free(color_dialog_t* dialog);

#endif //COLORSCHEMES_INCLUDED