/*
** EPITECH PROJECT, 2021
** Matrix.cpp
** File description:
** Matrix.cpp
*/

#include "component/Transform.hpp"

void ray::Transform::updateMatrix() const
{
    //sw::Matrixf transformPosition({{1, 0, m_position.x},
    //                               {0, 1, m_position.y},
    //                               {0, 0, 1}});
    //auto rotation = 0/*(double)(*this).getRadianRotation()*/;
    //sw::Matrixf transformRotation({{(float)cos(rotation), (float)-sin(rotation), 0},
    //                               {(float)sin(rotation), (float)cos(rotation),  0},
    //                               {0,                    0,                     1}});
    //sw::Matrixf transformScale({{m_scale.x, 0,          0},
    //                            {0,         m_scale.y,  0},
    //                            {0,         0,          1}});
    //m_matrix.setIdentity();
    //m_matrix = m_matrix * transformPosition;
    //m_matrix = m_matrix * transformRotation;
    //m_matrix = m_matrix * transformScale;
}

const sw::Matrixf& ray::Transform::getMatrix() const
{
    if (m_need_update) {
        updateMatrix();
        //updateSfTransform();
        m_need_update = false;
    }
    return (m_matrix);
}

const sw::Matrixf& ray::Transform::getGlobalMatrix() const
{
    if (m_global_need_update) {
        m_globalMatrix = getMatrix();
        if (m_entity.m_parent.has_value())
            m_globalMatrix = m_globalMatrix * m_entity.m_parent.value().get().getComponent<ray::Transform>("TransformFact").getGlobalMatrix();
        updateGlobalSfTransform();
        m_global_need_update = false;
    }
    return (m_globalMatrix);
}