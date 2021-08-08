/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** Script.inl
*/

inline sw::Script::Script(Script&& sc)
    : sw::Component(sc.m_entity)
{}

inline sw::Script::Script(Script const& sc)
    : sw::Component(sc.m_entity)
{}

inline sw::Script::Script(Entity& entityRef)
    : sw::Component(entityRef)
{}
