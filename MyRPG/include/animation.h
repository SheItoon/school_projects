/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** animation.h
*/
#ifndef ANIMATION_H_INCLUDED
#define ANIMATION_H_INCLUDED

#include <SFML/Graphics.h>
#include "istl/list.h"
#include "cubic_bezier.h"
#include "istl/common_types.h"
#include "csfml_types.h"

/*! FrameAnimation type infos */
extern const meta_bundle_t MB_ANIMATION;

/*!
    \brief FrameAnimation's filling mode
    \see https://www.w3schools.com/cssref/css3_pr_animation-fill-mode.asp
*/
typedef enum FA_FILL_TYPE {
    FORWARDS,   //!< Always keep on returning last element after completion
    BACKWARDS,  //!< NANI?
    BOTH,       //!< Omae wa, mo shindeiru
    NONE        //!< Nothing of listed (get trolled)
} fafill_t;

/*!
    \brief Hybrid animation type for shapes/sprites
    \details This type of animation doesn't affect any
    logical property of an entity. This is simply a scheme
    that allows you to give the **time passed** in a certain state
    and get the **associated sfIntRect** calculated with that state,
    [bezier curve][bezier] profile, animation's duration and filling
    parameter. You only have to push your frames that you want to
    associate, set a duration and a curve profile, and you're
    good to go. Since it is a scheme, no need in updating it on
    every tick or whatever. Usually you initialize it in the init
    stage of your project and then you retrieve it as a scheme.
    [bezier]: (https://javascript.info/bezier-curve)
    \startuml
    actor Client
    participant FrameAnimation as anim
    == Initialization ==
    Client -> anim: Creating an instance
    activate anim
    note right: With a duration and a profile curve
    Client -> anim: Filling with frames
    note left: Frames in order of playing. Think of it as of keyframes.
    Client -> anim: Setting other properties
    anim ->]: Storing somewhere
    deactivate anim
    note right: You might want to keep it in a resource holder
    == Usage in application ==
    [-> anim: Retrieve somewhere else
    activate anim
    Client -> anim: Passing time
    anim -> anim: Calculating associated frame
    anim -> Client: Texture's sub-rectangle
    deactivate anim
    \enduml
    \see [Inspiration](https://www.w3schools.com/css/css3_animations.asp)
    \see [ResourceHolder](@ref resource_holder.h)
    \see sfTexture
*/
typedef struct FrameAnimation {
    sfTime duration;
    point_set_t cprofile;
    list_t *frames;
    bool_t looped;
    bool_t direction;
    fafill_t fill;
} animf_t;

/*!
    Main FrameAnimation's constructor
*/
animf_t *animf_create(sfTime duration, point_set_t curve_profile);
void animf_free(animf_t **anim);
void *animf_copy(void const *data);
void animf_destroy(void *data);

void animf_push_frame(animf_t *anim, sfIntRect frame);
sfIntRect *animf_get_frame(animf_t *anim, sfTime in_state);

#endif
