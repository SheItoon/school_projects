/*
** EPITECH PROJECT, 2021
** TextFact.hpp
** File description:
** TextFact.hpp
*/

#ifndef TEXTFACT
#define TEXTFACT

#include "SW/Factory.hpp"

namespace ray
{
    class Text;

    class TextFact : public sw::AFactory<Text>
    {
    public:
        using sw::AFactory<Text>::AFactory;

        void onLoad() override {};
        void onUpdate() override;
        void onUnload() override {};
    }; // class TextFact

} // namespace ray

#endif //TEXTFACT
