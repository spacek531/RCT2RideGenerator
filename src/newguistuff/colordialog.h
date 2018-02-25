#ifndef COLORDIALOG_INCLUDED
#define COLORDIALOG_INCLUDED

#include "modeldialog.h"
#include "interface.h"
#include <gtk/gtk.h>
#define NUM_CHOOSABLE_COLORS 32

typedef struct {
    uint8_t value;
    GdkPixbuf* pixbuf;
    GtkWidget* image;
    GtkToolItem* tool_item;
    color_dialog_t* dialog;
} color_dialog_tool_t;

typedef struct {
    GtkWidget* dialog;
    GtkWidget* container;
    uint8_t* colorAddress;
    color_selector_tool_t** tools;
} color_dialog_t;


color_dialog_t* color_dialog_new(char* colorName, uint8_t* colorAddress);
void color_dialog_free(color_dialog_t* dialog);

#endif //COLORDIALOG_INCLUDED