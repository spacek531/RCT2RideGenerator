#ifndef MAINWINDOW_H_INCLUDED
#define MAINWINDOW_H_INCLUDED
#include<stdint.h>
#include "project.h"
#include "interface.h"
/*
typedef struct
{
int ImageDisplayCurrentImage;
GtkHBox* ImageDisplayHbox;
GtkButton* ImageDisplayPrevButton;
GtkButton* ImageDisplayNextButton;
GtkLabel* ImageDisplayPositionLabel;
GtkImage* ImageDisplayImage;
GdkPixbuf* ImageDisplayPixbuf;
GtkVBox* ImageDisplayVBox;
GtkEventBox* ImageDisplayEventBox;
}image_viewer_t;

typedef struct
{
int LanguageNum;
GtkComboBox* LanguageComboBox;
GtkLabel* RideNameLabel;
GtkEntry* RideNameEntry;
GtkLabel* RideDescriptionLabel;
GtkEntry* RideDescriptionEntry;
GtkLabel* RideCapacityLabel;
GtkEntry* RideCapacityEntry;
GtkTable* StringEditingTable;
}string_editor_t;
*/

typedef struct
{
uint8_t* track_type;
GtkWidget* container;
GtkWidget* label;
GtkWidget* select;
}track_type_editor_t;


typedef struct
{
uint32_t* flags;
uint32_t flag;
GtkWidget* label;
GtkWidget* checkbox;
}flag_checkbox_t;

typedef struct
{
uint32_t* flags;
flag_checkbox_t** flag_checkboxes;
int num_checkboxes;

GtkWidget* container;
GtkWidget* table;
}flag_editor_t;

typedef struct
{
uint8_t* car_type;
GtkWidget* container;
GtkWidget* label;
GtkWidget* car_select;
}car_type_editor_t;

typedef struct
{
car_settings_t* car_settings;
project_t* project;

flag_editor_t* flag_editor;
value_editor_t* spacing_editor;
value_editor_t* friction_editor;
value_editor_t* z_value_editor;

GtkWidget* animation_button;
GtkWidget* container;
}car_editor_t;

typedef struct
{
project_t* project;

track_type_editor_t* track_type_editor;
flag_editor_t* flag_editor;
value_editor_t* min_cars_editor;
value_editor_t* max_cars_editor;
car_type_editor_t* default_car_editor;
car_type_editor_t* front_car_editor;
car_type_editor_t* second_car_editor;
car_type_editor_t* third_car_editor;
car_type_editor_t* rear_car_editor;
car_editor_t* car_editors[NUM_CARS];
GtkWidget* container;
}header_editor_t;

typedef struct
{
project_t* project;

header_editor_t* header_editor;

GtkWidget* window;
GtkWidget* main_menu;
GtkWidget* main_vbox;
GtkWidget* model_menu;
GtkWidget* animation_menu;
//;
//GtkWidget* LeftVBox;
//GtkWidget* LowerHBox;
}main_window_t;

main_window_t* main_window_new();
void main_window_free(main_window_t* main_window);

#endif // MAINWINDOW_H_INCLUDED
