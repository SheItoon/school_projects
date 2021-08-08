/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** IModule.hpp
*/

#ifndef __SHIPWRECK_ISYSTEM_HPP__
#define __SHIPWRECK_ISYSTEM_HPP__

namespace sw
{

    class IModule
    {

        protected:
            virtual void onInitialize() = 0;
            virtual void onUpdate() = 0;
            virtual void onTerminate() = 0;

        public:
            virtual ~IModule() = default;

            virtual void initialize() = 0;
            virtual bool isOk() = 0;
            virtual void update() = 0;
            virtual void terminate() = 0;

    }; // class IModule

} // namespace sw

#endif // __SHIPWRECK_ISYSTEM_HPP__