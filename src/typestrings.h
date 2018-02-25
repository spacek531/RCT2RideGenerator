#ifndef RIDETYPES_H_INCLUDED
#define RIDETYPES_H_INCLUDED

#include "dat.h"
#include <stdint.h>

#define NUM_RIDE_TYPES 91
#define NUM_ANIMATION_TYPES 10
#define NUM_RIDE_FLAGS 22
#define NUM_VEHICLE_FLAGS 27
#define NUM_VISUAL_EFFECTS 17
#define NUM_SPRITE_GROUPS 15
#define NUM_RUNNING_SOUNDS 8
#define NUM_SECONDARY_SOUNDS 6
#define NUM_CAR_POSITIONS 5
#define NUM_RIDE_CATEGORIES 7

typedef struct {
    uint8_t id;
    const char* name;
} ride_type_t;


ride_type_t* ride_type_by_index(int index);
ride_type_t* ride_type_by_id(int index);
ride_type_t* ride_type_by_name(const char* name);

ride_type_t* animation_type_by_index(int index);
ride_type_t* ride_flag_by_index(int index);
ride_type_t* vehicle_flag_by_index(int index);
ride_type_t* visual_effect_by_index(int index);
ride_type_t* sprite_group_by_index(int index);
ride_type_t* running_sound_by_index(int index);
ride_type_t* secondary_sound_by_index(int index);
ride_type_t* car_position_by_index(int index);
ride_type_t* ride_category_by_index(int index);

ride_type_t* ride_category_by_index(int index);
ride_type_t* ride_category_by_id(int index);
ride_type_t* ride_category_by_name(const char* name);
#endif // RIDETYPES_H_INCLUDED
