/*
** EPITECH PROJECT, 2021
** Text.hpp
** File description:
** Text.hpp
*/

#ifndef TEXT
#define TEXT

#include "SW/Components.hpp"
#include "resources/Font.hpp"
#include "utils/Color.hpp"

namespace ray
{
    class Text : public sw::Component
    {
    private:
        std::string m_text;
        float m_size;
        ray::RFont& m_font;
        float m_spacing;
        RColor m_color;
        unsigned int m_nbrDisplayedChar;

    public:
        Text(sw::Entity& entity);
        ~Text() = default;
        Text& setString(std::string message);
        Text& setSize(float size);
        Text& setFont(std::string fontName);
        Text& setSpacing(float spacing);
        Text& setColor(Color color);
        Text& setColor(int r, int g, int b, int a);
        Text& setNbrDisplayedChar(unsigned int nbr);

        [[nodiscard]] std::string getString() const;
        [[nodiscard]] float getSize() const;
        [[nodiscard]] ray::RFont getFont() const;
        [[nodiscard]] float getSpacing() const;
        [[nodiscard]] RColor getColor() const;
        [[nodiscard]] unsigned int getNbrDisplayedChar() const;
    }; // class Text
} // namespace ray

#endif //TEXT
