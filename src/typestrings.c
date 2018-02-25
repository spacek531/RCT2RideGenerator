#include "ridetypes.h"
#include <string.h>

// ride type

ride_type_t ride_types[NUM_RIDE_TYPES] = {
    { 0x0, "Spiral Coaster" },
    { 0x1, "Stand-up Coaster" },
    { 0x2, "Suspended Swinging Coaster" },
    { 0x3, "Inverted Coaster" },
    { 0x4, "Junior Coaster" },
    { 0x5, "Miniature railway" },
    { 0x6, "Monorail" },
    { 0x7, "Mini Suspended Coaster" },
    { 0x8, "Boat Hire" },
    { 0x9, "Wooden Wild Mouse" },
    { 0xa, "Steeplechase" },
    { 0xb, "Car Ride" },
    { 0xc, "[V] Launched Freefall" },
    { 0xd, "Bobsleigh" },
    { 0xe, "[V] Observation Tower" },
    { 0xf, "Schwarzkopf Coaster" },
    { 0x10, "Dinghy Slide" },
    { 0x11, "Mine Train Coaster" },
    { 0x12, "Chairlift" },
    { 0x13, "Corkscrew Coaster" },
    { 0x14, "[F] Maze" },
    { 0x15, "Spiral Slide" },
    { 0x16, "Go Karts" },
    { 0x17, "Log Flume" },
    { 0x18, "River Rapids" },
    { 0x19, "Dodgems" },
    { 0x1a, "[F] Swinging Ship" },
    { 0x1b, "[F] Swinging Inverter Ship" },
    { 0x1c, "[S] Food Stall" },
    { 0x1d, "0x1D" },
    { 0x1e, "[S] Drink Stall" },
    { 0x1f, "0x1F" },
    { 0x20, "[S] Shop" },
    { 0x21, "[F] Carousel" },
    { 0x22, "0x22" },
    { 0x23, "[S] Info Kiosk" },
    { 0x24, "[S] Toilets" },
    { 0x25, "[F] Ferris Wheel" },
    { 0x26, "[F] Motion Simulator" },
    { 0x27, "[F] 3D Cinema" },
    { 0x28, "[F] Top Spin" },
    { 0x29, "[F] Space Rings" },
    { 0x2a, "Reverse Freefall Coaster" },
    { 0x2b, "[V] Elevator" },
    { 0x2c, "Vertical Drop Coaster" },
    { 0x2d, "[S] Cash Machine" },
    { 0x2e, "[F] Scrambled Eggs" },
    { 0x2f, "[F] Haunted House" },
    { 0x30, "[S] First Aid" },
    { 0x31, "[F] Circus" },
    { 0x32, "Ghost Train" },
    { 0x33, "B&M Coaster" },
    { 0x34, "Wooden Coaster" },
    { 0x35, "Side-Friction Coaster" },
    { 0x36, "Steel Wild Mouse" },
    { 0x37, "Multi-Dimension Coaster" },
    { 0x37, "[?] Multi-Dimension Coaster (Alt)" },
    { 0x39, "Flying Coaster" },
    { 0x3a, "[?] Flying Coaster (Alt)" },
    { 0x3b, "Virginia Reel" },
    { 0x3c, "Splash Boats" },
    { 0x3d, "Mini Helicopters" },
    { 0x3e, "Lay-down Coaster" },
    { 0x3f, "Suspended Monorail" },
    { 0x40, "[?] Lay-down Coaster (Alt)" },
    { 0x41, "Wooden Reverser Coaster" },
    { 0x42, "Togo Twister" },
    { 0x43, "Mini Golf" },
    { 0x44, "Giga Coaster" },
    { 0x45, "[V] Roto Drop" },
    { 0x46, "[F] Flying Saucers" },
    { 0x47, "[F] Crooked House" },
    { 0x48, "Monorail Cycles" },
    { 0x49, "Compact Inverted Coaster" },
    { 0x4a, "Water Coaster" },
    { 0x4b, "Air Powered Vertical Coaster" },
    { 0x4c, "Inverted Hairpin Coaster" },
    { 0x4d, "[F] Magic Carpet" },
    { 0x4e, "Submarine Ride" },
    { 0x4f, "River Rafts" },
    { 0x50, "0x50" },
    { 0x51, "[F] Enterprise" },
    { 0x52, "0x52" },
    { 0x53, "0x53" },
    { 0x54, "0x54" },
    { 0x55, "0x55" },
    { 0x56, "Inverted Impulse Coaster" },
    { 0x57, "Mini Coaster" },
    { 0x58, "Powered Coaster" },
    { 0x59, "0x59" },
    { 0x5a, "LIM Launched Roller Coaster" }
    { 0xff, "NULL" }
};

ride_type_t* ride_type_by_index(int index)
{
    return ride_types + index;
}

ride_type_t* ride_type_by_id(int index)
{
    int i;
    for (i = 0; i < NUM_RIDE_TYPES; i++)
        if (index == ride_types[i].id)
            return ride_types + i;
    return NULL;
}

ride_type_t* ride_type_by_name(const char* name)
{
    int i;
    for (i = 0; i < NUM_RIDE_TYPES; i++)
        if (strcmp(ride_types[i].name, name) == 0)
            return ride_types + i;
    return NULL;
}

//animation types

ride_type_t animation_types[NUM_ANIMATION_TYPES] = {
    { VEHICLE_ANIMATION_NONE, "No animation"},
    { VEHICLE_ANIMATION_MINITURE_RAILWAY_LOCOMOTIVE, "Steam train"},
    { VEHICLE_ANIMATION_SWAN, "Swan boats"},
    { VEHICLE_ANIMATION_CANOES, "Canoes"},
    { VEHICLE_ANIMATION_ROW_BOATS, "Rowboats"},
    { VEHICLE_ANIMATION_WATER_TRICYCLES, "Water tricycles"},
    { VEHICLE_ANIMATION_OBSERVATION_TOWER, "Observation tower"},
    { VEHICLE_ANIMATION_HELICARS, "Helicopters ride"},
    { VEHICLE_ANIMATION_MONORAIL_CYCLES, "Monorail cyles"},
    { VEHICLE_ANIMATION_MULTI_DIM_COASTER, "Multidimension coaster"}
};

ride_type_t* animation_type_by_index(int index)
{
    return animation_types + index;
}

//ride flags

ride_type_t ride_flags[NUM_RIDE_FLAGS] = {
    { RIDE_VEHICLE_TAB_SCALE_HALF, "Vehicle tab preview half scale"},
    { RIDE_NO_INVERSIONS, "No inversions"},
    { RIDE_NO_BANKED_TRACK, "No banked track"},
    { RIDE_CHUFFING_ON_DEPART, "Steam train chuffing on departure"},
    { RIDE_SWING_MODE_1, "Swing mode 1"},
    { RIDE_ROTATION_MODE_1, "Scrambled eggs rotation mode"},
    { RIDE_ROTATION_MODE_2, "Enterprise rotation mode"},
    { RIDE_FLAG_ALLOW_BOATS_TO_WANDER, "Allow boats to wander"},
    { RIDE_PLAY_SPLASH_SOUND, "Play splash sound on level track"},
    { RIDE_SLOW_IN_WATER, "Play splash sound on water sections"},
    { RIDE_COVERED, "Covered ride"},
    { RIDE_LIMIT_AIRTIME_BONUS, "Limit airtime bonus"},
    { RIDE_SEPARATE_RIDE_DEPRECATED, "Separate ride (OpenRCT2 deprecated)"},
    { RIDE_SEPARATE_RIDE, "Allow track designs"},
    { RIDE_CANNOT_BREAK_DOWN, "Disable breakdowns"},
    { RIDE_DISABLE_LAST_OPERATING_MODE, "Disable last operating mode"},
    { RIDE_DISALLOW_ADJACENT_WALLS, "Disallow adjacent walls"},
    { RIDE_DISABLE_FIRST_TWO_OPERATING_MODES, "Disable first two operating modes"},
    { RIDE_DISABLE_VEHICLE_IMPACTS, "Disable crashing on vehicle impacts"},
    { RIDE_DISABLE_COLOR_TAB, "Disable color tab (swing mode 1 must be set)"},
    { RIDE_ALTERNATIVE_SWING_MODE_2, "Alternative swing mode 2"},
};

ride_type_t* ride_flag_by_index(int index)
{
    return ride_flags + index;
}

//vehicle flags

ride_type_t vehicle_flags[NUM_VEHICLE_FLAGS] = {
    { CAR_COAST_AND_FLY_OFF, "Coast and fly off"},
    { CAR_NO_UPSTOPS_TIGHT_TOLERANCE, "No upstops (-0.40 G limit)"},
    { CAR_NO_UPSTOPS, "No upstops (-0.45 G limit)"},
    { CAR_IS_MINIGOLFER, "Minigolfer"},
    { CAR_FLAG_4, "Flag 4)"},
    { CAR_FLAG_5, "Flag 5"},
    { CAR_CAN_INVERT, "Can invert for long periods"},
    { CAR_DODGEM_LIGHTS, "Dodgem lights"},
    { CAR_OPENS_DOORS, "Opens oncoming doors"},
    { CAR_FLAG_10, "Flag 10"},
    { CAR_FLAG_11, "Flag 11"},
    { CAR_OVERRIDE_VERTICAL_FRAMES, "Override vertical frames"},
    { CAR_FLAG_11, "Flag 13"},
    { CAR_FLAG_15, "Flag 15"},
    { CAR_ENABLE_REMAP2, "Remap Color 2"},
    { CAR_IS_SWINGING, "Swinging"},
    { CAR_IS_SPINNING, "Spinning"},
    { CAR_IS_POWERED, "Powered"},
    { CAR_RIDERS_SCREAM, "Riders scream"},
    { CAR_BOAT_COLLISIONS, "Boat Collisions"},
    { CAR_IS_ANIMATED, "Car is animated"},
    { CAR_RIDERS_MOVE, "Riders change positions during animation"},
    { CAR_FLAG_26, "Flag 26"},
    { CAR_IS_CHAIRLIFT, "Chairlift"},
    { CAR_WATER_PROPELLED, "Pushed by water"},
    { CAR_GO_KART, "Go kart"},
    { CAR_DODGEM_PLACEMENT, "Dodgem placement"}
};

ride_type_t* vehicle_flag_by_index(int index)
{
    return vehicle_flags + index;
}

// visual effect types

ride_type_t visual_effects[NUM_VISUAL_EFFECTS] = {
    { VEHICLE_VISUAL_DEFAULT, "Default" },
    { VEHICLE_VISUAL_FLAT_RIDE_OR_CAR_RIDE, "Flat Ride or Car Ride" },
    { VEHICLE_VISUAL_LAUNCHED_FREEFALL, "Launched Freefall" },
    { VEHICLE_VISUAL_OBSERVATION_TOWER, "Observation Tower" },
    { VEHICLE_VISUAL_RIVER_RAPIDS, "River Rapids" },
    { VEHICLE_VISUAL_MINI_GOLF_PLAYER, "Minigolf Player" },
    { VEHICLE_VISUAL_MINI_GOLF_BALL, "Minigolf Ball" },
    { VEHICLE_VISUAL_REVERSER, "Reverser"},
    { VEHICLE_VISUAL_SPLASH_BOATS_OR_WATER_COASTER, "Splash Boats or Water Coaster" },
    { VEHICLE_VISUAL_ROTO_DROP, "Roto Drop"},
    { VEHICLE_VISUAL_SPLASH1_EFFECT, "Splash 1"},
    { VEHICLE_VISUAL_SPLASH2_EFFECT, "Splash 2"},
    { VEHICLE_VISUAL_SPLASH3_EFFECT, "Splash 3"},
    { VEHICLE_VISUAL_SPLASH4_EFFECT, "Splash 4"},
    { VEHICLE_VISUAL_SPLASH5_EFFECT, "Splash 5"},
    { VEHICLE_VISUAL_VIRGINIA_REEL, "Virginia Reel"},
    { VEHICLE_VISUAL_SUBMARINE, "Submarine"}
};

ride_type_t* visual_effect_by_index(int index)
{
    return visual_effects + index;
}

// sprite group flags

ride_type_t sprite_groups[NUM_SPRITE_GROUPS] = {
    { SPRITE_FLAT_SLOPE, "Flat Turns" },
    { SPRITE_BANKING, "Banked Turns" },
    { SPRITE_SLOPE_BANK_TRANSITION, "Slope-Flat Bank Transitions" },
    { SPRITE_GENTLE_SLOPE, "Gentle slopes" },
    { SPRITE_STEEP_SLOPE, "Steep slopes" },
    { SPRITE_VERTICAL_SLOPE, "Vertical Slopes and Loops" },
    { SPRITE_DIAGONAL_SLOPE, "Diagonal Slopes" },
    { SPRITE_INLINE_TWIST, "Inline Twists"},
    { SPRITE_SLOPED_BANK_TRANSITION, "Banked Flat-To-Gentle Transitions" },
    { SPRITE_DIAGONAL_BANK_TRANSITION, "Diagonal Banked Flat-To-Gentle Transitions"},
    { SPRITE_SLOPED_BANKED_TURN, "Sloped Banked Turns"},
    { SPRITE_BANKED_SLOPE_TRANSITION, "Banked Flat-To-Gentle"},
    { SPRITE_CORKSCREW, "Corkscrews"},
    { SPRITE_RESTRAINT_ANIMATION, "Animated Restraints"},
    { SPRITE_SPIRAL LIFT, "Spiral Lift"}
};

ride_type_t* sprite_group_by_index(int index)
{
    return sprite_groups + index;
}

// running sound

ride_type_t running_sounds[NUM_RUNNING_SOUNDS] = {
    { RUNNING_SOUND_NONE, "No running sound" },
    { RUNNING_SOUND_WOODEN_OLD, "Wooden (Old)" },
    { RUNNING_SOUND_WOODEN_MODERN, "Wooden (Modern)" },
    { RUNNING_SOUND_STEEL, "Steel (Classic)" },
    { RUNNING_SOUND_STEEL_SMOOTH, "Steel (Smooth)" },
    { RUNNING_SOUND_WATERSLIDE, "Waterslide" },
    { RUNNING_SOUND_TRAIN, "Train Track" },
    { RUNNING_SOUND_ENGINE, "Gasoline Motor" }
};

ride_type_t* running_sound_by_index(int index)
{
    return running_sounds + index;
}

// secondary sound

ride_type_t secondary_sounds[NUM_RUNNING_SOUNDS] = {
    { SECONDARY_SOUND_NONE, "No secondary sound" },
    { SECONDARY_SOUND_SCREAMS_1, "Screams (fastfalling)" },
    { SECONDARY_SOUND_SCREAMS_2, "Screams (woodie)" },
    { SECONDARY_SOUNDS_SCREAMS_3, "Screams (classic)" },
    { SECONDARY_SOUND_WHISTLE, "Steam Train Whistle" },
    { SECONDARY_SOUND_BELL, "Tram Bell" }
};

ride_type_t* secondary_sound_by_index(int index)
{
    return secondary_sounds + index;
}

// car positions

ride_type_t car_positions[NUM_CAR_POSITIONS] = {
    { CAR_INDEX_DEFAULT, "Default car" },
    { CAR_INDEX_FRONT, "Front car" },
    { CAR_INDEX_SECOND, "Second car" },
    { CAR_INDEX_THIRD, "Third car" },
    { CAR_INDEX_LAST, "Fourth car" }
};

ride_type_t* car_position_by_index(int index)
{
    return car_positions + index;
}

// ride category

ride_type_t ride_categories[NUM_RIDE_CATEGORIES] = {
    { CATEGORY_TRANSPORT_RIDE, "Transport ride" },
    { CATEGORY_GENTLE_RIDE, "Gentle ride" },
    { CATEGORY_ROLLERCOASTER, "Rollercoaster" },
    { CATEGORY_THRILL_RIDE, "Thrill ride" },
    { CATEGORY_WATER_RIDE, "Water ride" },
    { 0x5, "Shop" },
    { 0xFF, "Blank" },
};

ride_type_t* ride_category_by_index(int index)
{
    return ride_categories + index;
}

ride_type_t* ride_category_by_id(int index)
{
    int i;
    for (i = 0; i < NUM_RIDE_TYPES; i++)
        if (index == ride_category[i].id)
            return ride_category + i;
    return NULL;
}

ride_type_t* ride_category_by_name(const char* name)
{
    int i;
    for (i = 0; i < NUM_RIDE_CATEGORIES; i++)
        if (strcmp(ride_categories[i].name, name) == 0)
            return ride_categories + i;
    return NULL;
}