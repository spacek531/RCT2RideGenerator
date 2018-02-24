#ifndef TRACKS_H_INCLUDED
#define TRACKS_H_INCLUDED
#include 'math_defines.h'

// sprite rotation angles

#define TILE_SLOPE (1 / sqrt(6))

#define FLAT 0

#define GENTLE (atan(TILE_SLOPE))
#define STEEP (atan(4 * TILE_SLOPE))
#define VERTICAL M_PI_2
#define FG_TRANSITION ((FLAT + GENTLE) / 2)
#define GS_TRANSITION ((GENTLE + STEEP) / 2)
#define SV_TRANSITION ((STEEP + VERTICAL) / 2)

#define GENTLE_DIAGONAL (atan(TILE_SLOPE * M_SQRT1_2))
#define STEEP_DIAGONAL (atan(4 * TILE_SLOPE * M_SQRT1_2))
#define FG_TRANSITION_DIAGONAL ((FLAT + GENTLE_DIAGONAL) / 2)

#define BANK M_PI_4
#define BANK_TRANSITION (M_PI_4 / 2)

#define CORKSCREW_RIGHT_YAW(angle) \
    (atan2(0.5 * (1 - cos(angle)), 1 - 0.5 * (1 - cos(angle))))
#define CORKSCREW_RIGHT_PITCH(angle) (-asin(-sin(angle) / sqrt(2.0)))
#define CORKSCREW_RIGHT_ROLL(angle) (-atan2(sin(angle) / sqrt(2.0), cos(angle)))

#define CORKSCREW_LEFT_YAW(angle) (-CORKSCREW_RIGHT_YAW(angle))
#define CORKSCREW_LEFT_PITCH(angle) (-CORKSCREW_RIGHT_PITCH(-angle))
#define CORKSCREW_LEFT_ROLL(angle) (-CORKSCREW_RIGHT_ROLL(angle))
#define CORKSCREW_ANGLE_1 2.0 * M_PI_12
#define CORKSCREW_ANGLE_2 4.0 * M_PI_12
#define CORKSCREW_ANGLE_3 M_PI_2
#define CORKSCREW_ANGLE_4 8.0 * M_PI_12
#define CORKSCREW_ANGLE_5 10.0 * M_PI_12

// track IDs

#define TRACK_STATION                                   0x000000000000004l
#define TRACK_STRAIGHT                                  0x000000000000002l
#define TRACK_CHAIN_LIFT                                0x000000000000008l
#define TRACK_STEEP_CHAIN_LIFT                          0x000000000000010l
#define TRACK_TIRE_DRIVE_LIFT                           0x000000000000020l // Junior only
#define TRACK_BANKING                                   0x000000000000040l
#define TRACK_VERTICAL_LOOP                             0x000000000000080l
#define TRACK_GENTLE_SLOPE                              0x000000000000100l
#define TRACK_STEEP_SLOPE                               0x000000000000200l
#define TRACK_FLAT_TO_STEEP_SLOPE_SMALL                 0x000000000000400l
#define TRACK_SLOPED_TURNS                              0x000000000000800l //(Enables available turns)
#define TRACK_STEEP_SLOPED_TURNS                        0x000000000001000l
#define TRACK_S_BEND                                    0x000000000002000l
#define TRACK_TINY_TURNS                                0x000000000004000l
#define TRACK_SMALL_TURN                                0x000000000008000l //(Flat enabled)
#define TRACK_LARGE_TURN                                0x000000000010000l
#define TRACK_INLINE_TWIST                              0x000000000020000l
#define TRACK_HALF_LOOP                                 0x000000000040000l
#define TRACK_HALF_CORKSCREW                            0x000000000080000l
#define TRACK_VERTICAL_TOWER                            0x000000000100000l // Launched Freefall + Roto-Drop?)
#define TRACK_HELIX                                     0x000000000200000l //(For upright track only)
#define TRACK_QUARTER_HELIX                             0x000000000400000l //(For inverted track only)
#define TRACK_UNBANKED_QUARTER_HELIX                    0x000000000800000l // Suspended Swinging only
#define TRACK_BRAKES                                    0x000000001000000l
#define TRACK_ON_RIDE_PHOTO_SECTION                     0x000000004000000l
#define TRACK_WATER_SPLASH                              0x000000008000000l // Wooden only
#define TRACK_VERTICAL_SLOPE                            0x000000010000000l
#define TRACK_BARREL_ROLL                               0x000000020000000l
#define TRACK_LAUNCHED_LIFT                             0x000000040000000l
#define TRACK_LARGE_HALF_LOOP                           0x000000080000000l
#define TRACK_BANKED_FLAT_TO_UNBANKED_GENTLE_SLOPE_TURN 0x000000100000000l
#define TRACK_HEARTLINE_ROLL                            0x000000400000000l // Togo heartline only
#define TRACK_REVERSER_TURNTABLE                        0x000000200000000l // Log Flume only
#define TRACK_REVERSER                                  0x000000800000000l // Wooden reverser only
#define TRACK_FLAT_TO_VERTICAL_SLOPE                    0x000001000000000l // Enables vertical track
#define TRACK_VERTICAL_TO_FLAT                          0x000002000000000l // Enables top section
#define TRACK_BLOCK_BRAKES                              0x000004000000000l
#define TRACK_GENTLE_SLOPE_BANKING                      0x000008000000000l //(Enables available turns)
#define TRACK_FLAT_TO_STEEP_SLOPE                       0x000010000000000l
#define TRACK_VERTICAL_SLOPED_TURNS                     0x000020000000000l
#define TRACK_CABLE_LIFT                                0x0000800000000001 // Giga only
#define TRACK_SPIRAL_LIFT                               0x000100000000000l // Spiral Coaster only
#define TRACK_QUARTER_LOOP                              0x000200000000000l
#define TRACK_SPINNING_TUNNEL                           0x000400000000000l //(Ghost Train and Car Rides)
#define TRACK_SPINNING_TOGGLE                           0x000800000000000l // Spinning Wild Mouse only)
#define TRACK_INLINE_TWIST_UNINVERT                     0x001000000000000l
#define TRACK_INLINE_TWIST_INVERT                       0x002000000000000l
#define TRACK_QUARTER_LOOP_INVERT                       0x004000000000000l
#define TRACK_QUARTER_LOOP_UNINVERT                     0x008000000000000l
#define TRACK_RAPIDS                                    0x010000000000000l // Rapids / Log Bumps, River Rapids / Monster Trucks only
#define TRACK_HALF_LOOP_UNINVERT                        0x020000000000000l
#define TRACK_HALF_LOOP_INVERT                          0x040000000000000l

#endif// TRACKS_H_INCLUDED