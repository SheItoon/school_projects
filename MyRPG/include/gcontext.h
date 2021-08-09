/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** gcontext.h
*/
#ifndef GCONTEXT_H_INCLUDED
#define GCONTEXT_H_INCLUDED

#include <SFML/Graphics.h>
#include "csfml_meta.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include "my.h"
#include "resource_holder.h"
#include "cevent.h"
#include "istl/hash_table.h"
#include "istl/common_types.h"
#include "istl/utility.h"
#include "creature.h"
#include "scene.h"
#include "animation.h"

extern const meta_bundle_t MB_ACTION; //!< ActionFunctor (action_t) type's infos
extern const meta_bundle_t MB_TILE;   //!< Tile (tile_t) type's infos

typedef struct GameContext (gcontext_t);

/*!
    \brief Event handler function prototype
    \details Any internal of SFML based event
    is processed by a so called **handler**.
    Such a handler should follow this exact signature
    to be integrated in the whole system. The
    argument list is completely generic, so it's
    up to you to pass the data in your handler
    from the handler calling function. Usually
    this function is proper to a game mode and
    is implemented with the **switch** statement.
*/
typedef int (*callback_t)(void *evt, gcontext_t *ctx);
typedef void (*session_t)(void);

/*!
    \brief Event-handler associated data bundle
    \details An event data associated to a handler function,
    to be executed whenever an event occurs. However, the
    stored pointer is not automatically called in the
    application mais loop. Think of it as a bridge between
    the application loop and your handler. You can pass to
    the function whatever you want, in addition of the
    stored event data from the application loop, but you
    have to set it up manually.
    \author Iaroslav Sorokin
*/
typedef struct ActionFunctor {
    bool_t custom;  //!< Indicated whether this is an SFML event handler
    callback_t function;    //!< Stored generic event handler function
    union {
        mdevent_t ctrigger; //!< Internal event associated data
        sfEvent strigger;   //!< SFML event associated data
    };
} action_t;

/*!
    \brief ActionFunctor allocating function.
*/
action_t *action_create(callback_t);

void *action_copy(void const *); //!< Copy constructor
void action_destroy(void *); //!< Destructor

/*! \brief Application's context singleton
    \details Main context singleton containing all the necessary
    application data, such as databases' references,
    main clock, window ref, etc. It can be accessed in any
    application's mode, function or a handler, but **please**
    refer to ```get_app_context``` before using it.
    \author Iaroslav Sorokin
*/
typedef struct GameContext {
    sfRenderWindow *window;
    /*!
        Frame cap determines minimum time threshold
        between two consecutive calls to **update**
        function. It is also the time value passed
        into the function, while the accumulated time
        buffer is still superiour to the frame cap.
        See: **Fixed Time Steps** technique
    */
    sfTime frame_cap;

    /*!
        ## Main purpose
        Application event queue allows the game to
        accumulate so called *actions* and execute
        all of them at the same time. This one is
        actually used to only accumulate event handlers
        of the internal events, such as *creature hovering*,
        *creature dying*, *tile clicking*, etc...
        ## Used in
        Internal SFML event handlers and in the action
        queue merging function.
    */
    list_t *app_equeue;

    /*!
        Frame buffer allows the application to save the
        unhandled time value after internal update calls.
    */
    sfTime frame_buffer;

    /*!
        The entire application time management lies upon
        this very clock. No other clocks are used, time
        may be accumulated in other structures by passing
        them the time delta value each game tick. So
        this is the only time handle of the application.
    */
    sfClock *frame_clock;

    /*!
        Hashmap data structure that contains textures
        associated to their given names. Its type is
        simply a typedef for **map_t** type, and shouldn't
        ever be accessed directly. Use **rget_texture**
        to access a texture resource via it's name, and
        **rload_texture** to load and store it from an
        external file.
    */
    rholder_t *texture_data;

    /*!
        Same as for **texture_data**
    */
    rholder_t *animation_data;

    rholder_t *font_data;

    /*!
        Same as for **texture_data**
    */
    // rholder_t *tile_data;

    /*!
        Hashmap data structure containing SFML event types
        to their aplication handlers. See **action_t**
        structure. Serves to associate a raised SFML event
        to it's application response, if any registered.
    */
    map_t *sfml_hdata;

    /*!
        Same as for **sfml_hdata**, but for internal
        application event handlers.
    */
    map_t *cstm_hdata;

    map_t *tprop_data;

    level_t *current_lvl;

    scene_t *appscene;
    scene_t *guiscene;
    scene_t *bgscene;
    session_t session_p;
    sfRenderStates appstates;
    sfView *gui_view;
    sfView *game_view;
    int phealth;
    int pmoney;
} gcontext_t;

/*!
    \callgraph
    \callergraph
    */
void app_init_window(sfVideoMode mode);

/*!
    \brief Global application's context singleton getter
    \details This function provides a pointer to the whole
    application's context singleton. This structure is the
    only one for the whole system, and is stored in the
    static memory space. You must **never** free this pointer,
    and limit as much as possible your interaction with it,
    if you're not trying to deal with the application loop
    itself or related functions. This function is not to be
    abused. For the events, all the necessary data is passed
    via either ```sfEvent``` or ```CustomEvent``` types and
    their respective handler functions. This function doesn't
    mean you shouldn't have to worry about passing arguments
    into your function, the opposite in fact. Prefer to organize
    your code through function interactions.
*/
gcontext_t *get_app_context(void);

sfRenderStates get_screen_states(void);

/*!
    \brief Application's memory freeing function
    \details This function is called to either free all
    the global memory took by the application, or to reset
    it. However, it doesn't refill all the data containers
    with resources.
    \todo Free the current lvl pointer
*/
void free_app_context(bool_t);

sfTime get_frame_buffer(void); //!< Application's frame buffer getter
sfTime get_frame_cap(void); //!< Application's frame cap getter

/*!
    \brief SFML's event handler register function
    \details This function allows to associate an ```sfEvent```
    to it's respective application handler. However, this only
    allows the application to be triggered when an event occurs,
    and to pass the event data in the processing pipeline, so
    you could manipulate arguments you would like to pass to your
    handler and to call it.
    \startuml {myimg.svg} width=200px
    actor "Client code" as Client
    participant "Application core" as Core
    participant "ActionFunctor" as Action
    participant "Event callback" as Callback
    participant "Mode core" as MCore
    participant SFML
    Client -> Callback: Create new handler
    Client -> Action: Create an empty action
    Client -> Action: Define custom as false
    Client -> Action: Set event callback
    Client -> Core: Register created action
    Client -> MCore: Create call case
    SFML -> MCore: Event catched
    MCore -> MCore: Checking event type
    MCore -> Callback: Calling stored function
    Callback -> Callback: Processing given event data
    \enduml
    \bug    Fix multiple handlers problem (only 1 event per handler
            is handled at this point)
*/
int app_register(sfEventType, callback_t);

int app_set_session(session_t);

session_t app_get_session(void);

/*!
    \brief Internal event handler register function
    \details Same principle as for SFML event case, but for a
    custom event type.
*/
int app_registerc(mdevent_type_t, callback_t);

/*!
    \brief Retrieve the ActionHandler associated to the sfEvent's type
    \details This function allows you to get the pre-filled ActionHandler
    structure with no event instance associated to it. Before calling this
    function, the requested type has to be registered through
    ```app_register``` function.
*/
action_t *app_get_handler(sfEventType);
list_t *app_get_handlers(sfEventType);

/*!
    \brief Retrieve the ActionHandler associated to the CustomEvent type
    \details Same principle as for ```app_get_handler```, but with
    a CustomEvent
*/
action_t *app_get_chandler(mdevent_type_t type);
list_t *app_get_chandlers(mdevent_type_t type);

/*!
    \brief Internal event's manual trigger
    \details Basically, internal events are proper to the application or
    a mode. This means that you have to decide when to trigger a certain
    ```CustomEvent```. This function is global, and interacts with
    the same application context. It allows you to trigger any internal
    event whenever you feel like it.
*/
int app_trigger_event(mdevent_t);

action_t *app_poll_event(void);

void app_handle_events(void);

/*!
    \brief Pre-defined application's window closing handler
    \callergraph
*/
int apph_close_window(void *evt, gcontext_t *ctx);

int apph_key_pressed(void *evt, gcontext_t *ctx);

/*!
    \brief Pre-defined application's window resizing handler
*/
int apph_resize_window(void *, gcontext_t *);

/*!
    \brief Pre-defined application's wheel handler
*/
int apph_mouse_scroll(void *, gcontext_t *);

/*!
    \brief Pre-defined application's mouse moving handler
*/
int apph_mouse_move(int ctr, ...);

#endif
