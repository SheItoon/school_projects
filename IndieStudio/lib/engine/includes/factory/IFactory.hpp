/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** IFactory.hpp
*/

#ifndef __SHIPWRECK_IFACTORY_HPP__
#define __SHIPWRECK_IFACTORY_HPP__

namespace sw
{

    class IFactory
    {

        public:
            virtual ~IFactory() = default;

            virtual void load() = 0;
            virtual void update() = 0;
            virtual void unload() = 0;
            virtual void endUpdate() = 0;

    }; // class IFactory

} // namespace sw

#endif // __SHIPWRECK_IFACTORY_HPP__