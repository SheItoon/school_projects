/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** ScriptFact.hpp
*/

#ifndef __SHIPWRECK_SCRIPTFACT_HPP__
#define __SHIPWRECK_SCRIPTFACT_HPP__

#include "factory/AFactory.hpp"

namespace sw
{

    class Script;

    class ScriptFact :
        public AFactory<Script>
    {

        public:
            using AFactory<Script>::AFactory;

            void onLoad() override;
            void onUpdate() override;
            void onUnload() override;

    }; // class ScriptFact

} // namespace sw

#endif // __SHIPWRECK_SCRIPTFACT_HPP__