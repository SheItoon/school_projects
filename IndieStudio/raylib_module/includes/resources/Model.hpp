/*
** EPITECH PROJECT, 2021
** Resource.hpp
** File description:
** Resource.hpp
*/

#ifndef MODEL
#define MODEL

#include "raylib.h"
#include "SW/Resources.hpp"

namespace ray
{
    class RModel :
            public sw::IModel
    {
    private:
        Model m_model;

    public:
        RModel() = default;
        explicit RModel(Model model);
        ~RModel() noexcept override;

        Model& operator*();
    }; // class RModel

} // namespace ray

#endif //MODEL
