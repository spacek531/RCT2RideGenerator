#include "colorschemes.h"
#include "palette.h"
#include "image.h"
#include <stdlib.h>
#include <string.h>


static void color_dialog_tool_clicked(GtkWidget* widget, gpointer user_data)
{
    color_dialog_tool_t* tool = (color_dialog_tool_t*)user_data;
    if (tool->value != NULL)
        gtk_dialog_response(tool->dialog->dialog,tool->value);
}

color_dialog_tool_t* color_dialog_tool_new(uint8_t color)
{
    color_dialog_tool_t* tool = malloc(sizeof(color_dialog_tool_t));
    tool->value = color;
    tool->pixbuf = gdk_pixbuf_new(GDK_COLORSPACE_RGB, FALSE, 8, 20, 20);
    pixbuf_set_color(tool->pixbuf, palette_remap_section_index(color, 6));
    tool->image = gtk_image_new_from_pixbuf(tool->pixbuf);
    tool->tool_item = gtk_tool_button_new(tool->image, "");
    g_signal_connect(tool->tool_item, "clicked",
        G_CALLBACK(color_dialog_tool_clicked), tool);
    return tool;
}

void color_dialog_tool_free(color_dialog_tool_t* tool)
{
    gtk_widget_destroy(tool->image);
    g_object_unref(G_OBJECT(tool->pixbuf));
    gtk_widget_destroy(GTK_WIDGET(tool->tool_item));
    free(tool);
}

void color_dialog_free(color_dialog_t* dialog)
{
    int i;
    for (i = 0; i < NUM_CHOOSABLE_COLORS; i++) {
        color_dialog_tool_free(dialog->tools[i]);
    }
    free(dialog->tools);
    gtk_widget_destroy(dialog->container);
    gtk_widget_destroy(dialog->dialog);
    free(dialog);
}

void color_dialog_free_connection(GtkWidget* widget, gpointer user_data)
{
    color_dialog_t* dialog = (color_dialog_t*)user_data;
    color_dialog_free(dialog);
}

color_dialog_t* color_dialog_new(char* colorName)
{
    int gridHeight = NUM_CHOOSABLE_COLORS/COLORGRID_WIDTH + (NUM_CHOOSABLE_COLORS % COLORGRID_WIDTH != 0)
    color_dialog_t* dialog = malloc(sizeof(color_dialog_t));
    dialog->toolbars = malloc(sizeof(GtkWidget*));
    dialog->dialog = gtk_dialog_new_with_buttons(colorName, NULL, 0, "Cancel",GTK_RESPONSE_CANCEL, NULL);
    GtkWidget* content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog->dialog));
    //GtkWidget* grid = gtk_table_new(gridHeight,COLORGRID_WIDTH,TRUE);
    for (i = 0; i < gridHeight; i++)
    {
        dialog->toolbars[i] = gtkToolbarNew();
    }
    dialog->tools = malloc(NUM_CHOOSABLE_COLORS * sizeof(color_dialog_tool_t*));
    for (i=0; i < NUM_CHOOSABLE_COLORS, i++)
    {
        dialog->tools[i] = color_dialog_tool_new(i,colorAddress);
        dialog->tools[i]->dialog = dialog;
        gtk_table_attach_defaults(GTK_TABLE(dialog->container),dialog->tools[i],i%COLORGRID_WIDTH,(i%COLORGRID_WIDTH)+1,i/gridHeight,i/gridHeight+1);
    }
    for (i = 0; i < gridHeight; i++)
    {
        gtk_box_pack_start(GTK_BOX(content_area),dialog->toolbars[i], FALSE, FALSE, 2);
    }
    g_signal_connect(dialog->dialog, "response",
        G_CALLBACK(color_dialog_free_connection), dialog);
    return dialog;
}