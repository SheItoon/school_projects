/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** Script.hpp
*/

#ifndef SHIPWRECK_ENGINE_SCRIPT
#define SHIPWRECK_ENGINE_SCRIPT

#include "Component.hpp"

namespace sw
{

    class Script :
        public Component
    {

        public:
            ////////////////////////////////////////////////////////////////////////////
            /// \brief Default constructor
            ///
            /// \param entityRef
            ////////////////////////////////////////////////////////////////////////////
            Script(Entity& entityRef);
            Script(Script const& sc);
            Script(Script&& sc);
            Script() = delete;
            virtual ~Script() = default;
            Script& operator=(Script const&) = delete;
            Script& operator=(Script&&) = delete;

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Override this function to update your entity and their
            ///        component
            ///
            /// \param engine
            ////////////////////////////////////////////////////////////////////////////
            virtual void update() {}

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Override this function set up your entity when the project start
            ///
            /// \param engine
            ////////////////////////////////////////////////////////////////////////////
            virtual void start() {}

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Override this function to update your entity and their
            ///        component when he enter on collision
            ///
            /// \param engine
            ////////////////////////////////////////////////////////////////////////////
            virtual void onCollision(sw::Entity& cldEntity) {}

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Overwrite this function to update your entity and their
            ///        component when he enter on trigger
            ///
            /// \param engine
            ////////////////////////////////////////////////////////////////////////////
            virtual void onTrigger() {}

            ////////////////////////////////////////////////////////////////////////////
            /// Override this function to update your entity and their
            ///        component when user use right click on them
            ///
            /// @param engine
            ////////////////////////////////////////////////////////////////////////////
            virtual void onRightClick() {}

            ////////////////////////////////////////////////////////////////////////////
            /// Override this function to update your entity and their
            ///        component when user use left click on them
            ///
            /// @param engine
            ////////////////////////////////////////////////////////////////////////////
            virtual void onLeftClick() {}

            ////////////////////////////////////////////////////////////////////////////
            /// Override this function to update your entity and their
            ///        component when user move the mouse on them
            ///
            /// @param engine
            ////////////////////////////////////////////////////////////////////////////
            virtual void onHover() {}

    }; // class Script

    #include "Script.inl"

} // namespace sw

#endif //SHIPWRECK_ENGINE_SCRIPT