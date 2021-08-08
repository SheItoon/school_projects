/*
** EPITECH PROJECT, 2021
** Model.cpp
** File description:
** Model.cpp
*/

#include <iostream>

#include "resources/Model.hpp"
#include "resources/Resources.hpp"

ray::RModel::RModel(Model model) : m_model(model)
{}

ray::RModel::~RModel() noexcept
{
    UnloadModel(m_model);
}

Model& ray::RModel::operator*()
{
    return (m_model);
}

void sw::Resources::loadModel()
{
    Model new_model;

    for (auto &[name, path] : m_neededModels) {
        new_model = LoadModel(path.c_str());
        models.emplace(name, std::make_shared<ray::RModel>(new_model));
    }
    if (models.empty())
        std::cout << "Warning no models can be loaded!" << std::endl;
}