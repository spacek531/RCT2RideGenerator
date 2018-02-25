#include "colordialog.h"
#include "palette.h"
#include "image.h"
#include <stdlib.h>
#include <string.h>


static void color_dialog_tool_clicked(GtkWidget* widget, gpointer user_data)
{
    color_select_tool_t* tool = (color_select_tool_t*)user_data;
    if (tool->value != NULL)
        gtk_dialog_response(tool->dialog->dialog,tool->value);
}

color_dialog_tool_t* color_dialog_tool_new(uint8_t color)
{
    color_select_tool_t* tool = malloc(sizeof(color_select_tool_t));
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
    for (i = 0; i < 32; i++) {
        color_select_tool_free(dialog->tools[i]);
    }
    gtk_widget_destroy(dialog->container);
    free(dialog->tools);
    free(dialog);
}

color_dialog_new(char* colorName)
{
    color_dialog_t* dialog = malloc(sizeof(color_dialog_t));
    dialog->dialog = gtk_dialog_new_with_buttons(colorName, NULL, 0, "Cancel",GTK_RESPONSE_CANCEL, NULL);
    GtkWidget* content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog->dialog));
    dialog->tools = malloc(32 * sizeof(color_select_tool_t*));
    dialog->container = gtk_table_new(4,8,TRUE);
    for (i=0; i < 32, i++) {
        dialog->tools[i] = color_dialog_tool_new(i,colorAddress);
        dialog->tools[i]->dialog = dialog;
        gtk_table_attach_defaults(GTK_TABLE(dialog->container),dialog->tools[i],i%8,(i%8)+1,i/4,i/4+1);
    }
    gtk_box_pack_start(GTK_BOX(content_area), dialog->container, FALSE, FALSE, 2);
    
    g_signal_connect_swapped (dialog,
        "response",
        G_CALLBACK (gtk_widget_destroy),
        dialog);
}