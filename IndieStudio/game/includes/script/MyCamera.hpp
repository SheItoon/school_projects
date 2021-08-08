/*
** EPITECH PROJECT, 2021
** Camera.hpp
** File description:
** Camera.hpp
*/

#ifndef MYCAMERA
#define MYCAMERA

#include "SW/Components.hpp"

class MyCamera : public sw::Script
{
public:
    using sw::Script::Script;
    ~MyCamera() override = default;
    void start() override;
}; // class Camera



#endif //MYCAMERA
