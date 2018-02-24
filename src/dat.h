#ifndef BACKEND_H_INCLUDED
#define BACKEND_H_INCLUDED
#include "image.h"
#include "math_defines.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_STRING_TABLES 3
#define NUM_LANGUAGES 11
#define NUM_CARS 4



typedef enum {
    STRING_TABLE_NAME = 0,
    STRING_TABLE_DESCRIPTION = 1,
    STRING_TABLE_CAPACITY = 2
} string_table_index_t;

typedef enum { LANGUAGE_ENGLISH_UK = 0,
    LANGUAGE_ENGLISH_US = 1 } language_t;

enum {
    RIDE_VEHICLE_TAB_SCALE_HALF =           0x00000001u,
    RIDE_NO_INVERSIONS =                    0x00000002u,
    RIDE_NO_BANKED_TRACK =                  0x00000004u,
    RIDE_CHUFFING_ON_DEPART =               0x00000008u,
    RIDE_SWING_MODE_1 =                     0x00000010u,
    RIDE_ROTATION_MODE_1 =                  0x00000020u, //twist
    RIDE_ROTATION_MODE_2 =                  0x00000040u, //enterprise
    RIDE_FLAG_ALLOW_BOATS_TO_WANDER =       0x00000080u,
    RIDE_PLAY_SPLASH_SOUND =                0x00000100u,// regular water rides
    RIDE_SLOW_IN_WATER =                    0x00000200u,// coaster boats
    RIDE_COVERED =                          0x00000400u,
    RIDE_LIMIT_AIRTIME_BONUS =              0x00000800u,
    RIDE_SEPARATE_RIDE_DEPRECATED =         0x00001000u,
    RIDE_SEPERATE =                         0x00001000u,
    RIDE_SEPARATE_RIDE =                    0x00002000u,//this enables track designs
    RIDE_CANNOT_BREAK_DOWN =                0x00004000u,
    RIDE_DISABLE_LAST_OPERATING_MODE =      0x00008000u,
    RIDE_DISALLOW_ADJACENT_WALLS =          0x00010000u,// prevents walls from being built next to the ride
    RIDE_DISABLE_FIRST_TWO_OPERATING_MODES = 0x00020000u,
    RIDE_DISABLE_VEHICLE_IMPACTS =          0x00040000u,// prevents vehicles from crashing when they hit each other
    RIDE_DISABLE_COLOR_TAB =                0x00080000u,// must be set with swing mode 1;
    RIDE_ALTERNATIVE_SWING_MODE_2 =         0x00100000u
} ride_flags_t;

enum {
    VEHICLE_ANIMATION_NONE =                        0x00u,
    VEHICLE_ANIMATION_MINITURE_RAILWAY_LOCOMOTIVE = 0x01u,
    VEHICLE_ANIMATION_SWAN =                        0x02u,
    VEHICLE_ANIMATION_CANOES =                      0x03u,
    VEHICLE_ANIMATION_ROW_BOATS =                   0x04u,
    VEHICLE_ANIMATION_WATER_TRICYCLES =             0x05u,
    VEHICLE_ANIMATION_OBSERVATION_TOWER =           0x06u,
    VEHICLE_ANIMATION_HELICARS =                    0x07u,
    VEHICLE_ANIMATION_MONORAIL_CYCLES =             0x08u,
    VEHICLE_ANIMATION_MULTI_DIM_COASTER =           0x09u
} car_animation_t;

enum { // if you update this, make sure you update typestrings!
    CAR_COAST_AND_FLY_OFF =           0x1u,//ghost trains
    CAR_NO_UPSTOPS_TIGHT_TOLERANCE =  0x2u,// max. -0.40 G
    CAR_NO_UPSTOPS =                  0x4u,//bobsled-style max -0.45 G
    CAR_IS_MINIGOLFER =               0x8u,
    CAR_FLAG_4 =                     0x10u,
    CAR_FLAG_5 =                     0x20u,
    CAR_CAN_INVERT =                 0x40u,//I assume this is set on the flying and lay-down so they can spawn properly on inverted station track
    CAR_DODGEM_LIGHTS =              0x80u,
    CAR_OPENS_DOORS =               0x100u,//only relevant for making things backwards-compatible with RCT2 and doors
    CAR_ENABLE_REMAP3 =             0x200u,
    CAR_FLAG_10 =                   0x400u,
    CAR_FLAG_11 =                   0x800u,
    CAR_OVERRIDE_VERTICAL_FRAMES = 0x1000u,
    CAR_FLAG_13 =                  0x2000u,
    CAR_FLAG_MORE_SPIN_FRAMES =    0x4000u,
    CAR_FLAG_15 =                  0x8000u,
    CAR_ENABLE_REMAP2 =           0x10000u,
    CAR_IS_SWINGING =             0x20000u,
    CAR_IS_SPINNING =             0x40000u,
    CAR_IS_POWERED =              0x80000u,
    CAR_RIDERS_SCREAM =          0x100000u,//riders can scream?
    CAR_FLAG_21 =                0x200000u,//related to swinging sprites - I believe this is only used for 3-frames
    CAR_BOAT_COLLISIONS =        0x400000u,
    CAR_IS_ANIMATED =            0x800000u,
    CAR_RIDERS_ANIMATED =       0x1000000u,
    CAR_FLAG_25 =               0x2000000u,// related to swinging sprites?
    CAR_FLAG_26 =               0x4000000u,
    CAR_FLAG_27 =               0x8000000u,// related to swinging sprites
    CAR_IS_CHAIRLIFT =         0x10000000u,
    CAR_WATER_PROPELLED =      0x20000000u,// allows cars to accelerate down slopes and continue travelling when the ride breaks down (but not uphill)
    CAR_GO_KART =              0x40000000u,
    CAR_DODGEM_PLACEMENT =     0x80000000u
} car_flags_t; // if you update this, make sure you update typestrings!

enum {
    VEHICLE_VISUAL_DEFAULT,
    VEHICLE_VISUAL_FLAT_RIDE_OR_CAR_RIDE,
    VEHICLE_VISUAL_LAUNCHED_FREEFALL,
    VEHICLE_VISUAL_OBSERVATION_TOWER,
    VEHICLE_VISUAL_RIVER_RAPIDS,
    VEHICLE_VISUAL_MINI_GOLF_PLAYER,
    VEHICLE_VISUAL_MINI_GOLF_BALL,
    VEHICLE_VISUAL_REVERSER,
    VEHICLE_VISUAL_SPLASH_BOATS_OR_WATER_COASTER,
    VEHICLE_VISUAL_ROTO_DROP,
    VEHICLE_VISUAL_SPLASH1_EFFECT,
    VEHICLE_VISUAL_SPLASH2_EFFECT,
    VEHICLE_VISUAL_SPLASH3_EFFECT,
    VEHICLE_VISUAL_SPLASH4_EFFECT,
    VEHICLE_VISUAL_SPLASH5_EFFECT,
    VEHICLE_VISUAL_VIRGINIA_REEL,
    VEHICLE_VISUAL_SUBMARINE
} visual_effects;

enum {
    SPRITE_FLAT_SLOPE = 0x0001,
    SPRITE_GENTLE_SLOPE = 0x0002,
    SPRITE_STEEP_SLOPE = 0x0004,
    SPRITE_VERTICAL_SLOPE = 0x0008,
    SPRITE_DIAGONAL_SLOPE = 0x0010,
    SPRITE_BANKING = 0x0020,
    SPRITE_INLINE_TWIST = 0x0040,
    SPRITE_SLOPE_BANK_TRANSITION = 0x0080,
    SPRITE_DIAGONAL_BANK_TRANSITION = 0x0100,
    SPRITE_SLOPED_BANK_TRANSITION = 0x0200,
    SPRITE_SLOPED_BANKED_TURN = 0x0400,
    SPRITE_BANKED_SLOPE_TRANSITION = 0x0800,
    SPRITE_CORKSCREW = 0x1000,
    SPRITE_RESTRAINT_ANIMATION = 0x2000,
    SPRITE_SPIRAL_LIFT = 0x4000
} sprite_flags_t;

enum {
    RUNNING_SOUND_WOODEN_OLD = 1,
    RUNNING_SOUND_WOODEN_MODERN = 54,
    RUNNING_SOUND_STEEL = 2,
    RUNNING_SOUND_STEEL_SMOOTH = 57,
    RUNNING_SOUND_WATERSLIDE = 32,
    RUNNING_SOUND_TRAIN = 31,
    RUNNING_SOUND_ENGINE = 21,
    RUNNING_SOUND_NONE = 255
} running_sound_t;

enum {
    SECONDARY_SOUND_SCREAMS_1 = 0,
    SECONDARY_SOUND_SCREAMS_2 = 1,
    SECONDARY_SOUND_SCREAMS_3 = 2,
    SECONDARY_SOUND_WHISTLE = 3,
    SECONDARY_SOUND_BELL = 4,
    SECONDARY_SOUND_NONE = 255,
} secondary_sound_t;

enum {
    CAR_INDEX_DEFAULT = 0,
    CAR_INDEX_FRONT = 1,
    CAR_INDEX_SECOND = 2,
    CAR_INDEX_THIRD = 4,
    CAR_INDEX_REAR = 3
} car_index_t;

enum {
    CATEGORY_TRANSPORT_RIDE = 0,
    CATEGORY_GENTLE_RIDE = 1,
    CATEGORY_ROLLERCOASTER = 2,
    CATEGORY_THRILL_RIDE = 3,
    CATEGORY_WATER_RIDE = 4
} category_t;



typedef struct {
    uint8_t* data;
    uint32_t size;
    uint32_t allocated;
} buffer_t;

typedef uint64_t track_section_t;

typedef struct {
    uint32_t start_address;
    uint16_t width;
    uint16_t height;
    int16_t x_offset;
    int16_t y_offset;
    uint16_t flags;
} graphic_record_t;

typedef struct {
    image_t** images;
    uint32_t num_images;
    uint32_t allocated;
} image_list_t;

typedef struct {
    language_t language;
    char* str;
} string_table_entry_t;

typedef struct {
    string_table_entry_t* strings;
    uint8_t num_strings;
} string_table_t;

typedef struct {
    uint32_t flags;
    uint32_t spacing;
    uint16_t unknown[9];
    uint16_t sprites;
    uint16_t friction;
    uint8_t running_sound;
    uint8_t secondary_sound;
    uint8_t extra_swing_frames;
    uint8_t highest_rotation_index;
    uint8_t rider_pairs;
    uint8_t riders;
    uint8_t rider_sprites;
    uint8_t spin_inertia;
    uint8_t spin_friction;
    uint8_t powered_acceleration;
    uint8_t powered_velocity;
    uint8_t z_value;
    uint8_t car_effect;
    uint8_t effect_visual;
} car_t;

typedef struct {
    uint64_t track_sections;
    uint32_t flags;
    uint8_t car_icon_index;
    uint8_t zero_cars;
    uint8_t preview_index;
    uint8_t track_style;
    uint8_t excitement;
    uint8_t intensity;
    uint8_t nausea;
    uint8_t max_height;
    uint8_t categories[2];
    uint8_t car_types[5];
    uint8_t minimum_cars;
    uint8_t maximum_cars;
    car_t cars[NUM_CARS];
} ride_header_t;

typedef struct {
    uint8_t colors[3];
} color_scheme_t;

typedef struct {
    uint8_t* positions;
    uint16_t num;
} peep_position_data_t;

typedef struct {
    color_scheme_t* default_colors;
    uint8_t num_default_colors;
    peep_position_data_t peep_positions[4];
} ride_structures_t;

typedef struct {
    ride_header_t* ride_header;
    string_table_t* string_tables[3];
    ride_structures_t* optional;
    image_list_t* images;
    uint32_t num_images;
} object_t;

string_table_t* string_table_new();
char* string_table_get_string_by_language(string_table_t* table,
    language_t language);
void string_table_set_string_by_language(string_table_t* table,
    language_t language,
    char* str);

image_list_t* image_list_new();
image_list_t* image_list_load(uint8_t* bytes, uint32_t* pos_ptr);
void image_list_write(image_list_t* list, buffer_t* buffer);
void image_list_set_image(image_list_t* list, int index, image_t* image);
void image_list_set_num_images(image_list_t* list, uint32_t num_images);
void image_list_free(image_list_t* list);

ride_header_t* ride_header_new();

ride_structures_t* ride_structures_new();
void ride_structures_set_num_peep_positions(ride_structures_t* structures,
    int car,
    int num);
void ride_structures_set_num_default_colors(ride_structures_t* structures,
    int num);

object_t* object_new_ride();
object_t* object_load_dat(const char* filename);
void object_save_dat(object_t* object, const char* filename, uint32_t checksum);
char* object_get_string(object_t* object,
    string_table_index_t table_num,
    language_t language);
void object_set_string(object_t* object,
    string_table_index_t table_num,
    language_t language,
    char* new_string);
/*void RenderSprites(object_t* file,Animation* animations[5]);*/
void object_free(object_t* object);
void track_encode(buffer_t* data, char* filename);
buffer_t* load_file(char* filename);
buffer_t* track_decode(char* file);
#endif /*BACKEND_H_INCLUDED*/
