#ifndef ANIM_FRAMES_INCLUDED
#define ANIM_FRAMES_INCLUDED

#define NUM_ANIMATION_TYPES

typedef struct {
    uint8_t id;
    uint8_t car_frames;
    uint8_t peep_frames;
    const char* name;
} animation_frames_t;

#endif //ANIM_FRAMES_INCLUDED