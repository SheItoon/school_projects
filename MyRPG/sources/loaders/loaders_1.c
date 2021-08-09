/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** loaders_1.c
*/
#include "resource_loaders.h"

#define WALK_CURVE (CP_EASE_OUT)
#define WANIMS (sfSeconds(0.8f))

const sfIntRect SUBJECT_FRAMES[12] = {
    {233 * 0, 0, 233, 466},
    {233 * 1, 0, 233, 466},
    {233 * 2, 0, 233, 466},
    {233 * 3, 0, 233, 466},
    {233 * 4, 0, 233, 466},
    {233 * 5, 0, 233, 466},
    {233 * 6, 0, 233, 466},
    {233 * 5, 0, 233, 466},
    {233 * 4, 0, 233, 466},
    {233 * 3, 0, 233, 466},
    {233 * 2, 0, 233, 466},
    {233 * 1, 0, 233, 466},
};

static int rlac_alexa_walkr(void)
{
    animf_t *anim = animf_create(WANIMS, WALK_CURVE);
    int res = 0;

    animf_push_frame(anim, (sfIntRect){233 * 0, 466 * 2, 233, 466});
    animf_push_frame(anim, (sfIntRect){233 * 1, 466 * 2, 233, 466});
    animf_push_frame(anim, (sfIntRect){233 * 2, 466 * 2, 233, 466});
    animf_push_frame(anim, (sfIntRect){233 * 3, 466 * 2, 233, 466});
    res = rload_animation(anim, "creature_walk_r");
    animf_free(&anim);
    return (res);
}

static int rlac_alexa_walkl(void)
{
    animf_t *anim = animf_create(WANIMS, WALK_CURVE);
    int res = 0;

    animf_push_frame(anim, (sfIntRect){233 * 0, 466 * 1, 233, 466});
    animf_push_frame(anim, (sfIntRect){233 * 1, 466 * 1, 233, 466});
    animf_push_frame(anim, (sfIntRect){233 * 2, 466 * 1, 233, 466});
    animf_push_frame(anim, (sfIntRect){233 * 3, 466 * 1, 233, 466});
    res = rload_animation(anim, "creature_walk_l");
    animf_free(&anim);
    return (res);
}

static int rlac_alexa_walku(void)
{
    animf_t *anim = animf_create(WANIMS, WALK_CURVE);
    int res = 0;

    animf_push_frame(anim, (sfIntRect){233 * 0, 466 * 3, 233, 466});
    animf_push_frame(anim, (sfIntRect){233 * 1, 466 * 3, 233, 466});
    animf_push_frame(anim, (sfIntRect){233 * 2, 466 * 3, 233, 466});
    animf_push_frame(anim, (sfIntRect){233 * 3, 466 * 3, 233, 466});
    res = rload_animation(anim, "creature_walk_u");
    animf_free(&anim);
    return (res);
}

static int rlac_alexa_walkd(void)
{
    animf_t *anim = animf_create(WANIMS, WALK_CURVE);
    int res = 0;

    animf_push_frame(anim, (sfIntRect){233 * 0, 466 * 0, 233, 466});
    animf_push_frame(anim, (sfIntRect){233 * 1, 466 * 0, 233, 466});
    animf_push_frame(anim, (sfIntRect){233 * 2, 466 * 0, 233, 466});
    animf_push_frame(anim, (sfIntRect){233 * 3, 466 * 0, 233, 466});
    res = rload_animation(anim, "creature_walk_d");
    animf_free(&anim);
    return (res);
}

int rlac_alexa(void)
{
    int res = 0;
    animf_t *pepe = animf_create(sfSeconds(1.5f), CP_EASE_IN);

    res += rlac_alexa_walkr();
    res += rlac_alexa_walkl();
    res += rlac_alexa_walku();
    res += rlac_alexa_walkd();
    for (int i = 0; i < 12; i++)
        animf_push_frame(pepe, SUBJECT_FRAMES[i]);
    rload_animation(pepe, "subject_animation");
    animf_free(&pepe);
    return (res);
}
