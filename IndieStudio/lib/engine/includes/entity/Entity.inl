/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** Entity.inl
*/

inline sw::Entity::Entity(const std::string& entityName, AScene& sceneRef)
    : m_name(entityName),
      m_scene(sceneRef),
      m_isActive(true)
{}

template <typename ConcretComponent>
inline ConcretComponent& sw::Entity::getComponent(const std::string& factoryName)
{
    return (m_scene.getFactory<sw::AFactory<ConcretComponent>>(factoryName)[m_name]);
}

template<typename ConcretComponent, typename... Args>
inline ConcretComponent& sw::Entity::createComponent(const std::string& factoryName, Args... values)
{
    sw::AFactory<ConcretComponent>& fact = m_scene.getFactory<sw::AFactory<ConcretComponent>>(factoryName);

    return (fact.createComponent(m_name, values...));
}

template<typename ConcretComponent, typename T, typename... Args>
T& sw::Entity::insertComponent(const std::string& factoryName, Args... values)
{
    sw::AFactory<ConcretComponent>& fact = m_scene.getFactory<sw::AFactory<ConcretComponent>>(factoryName);

    return (fact.template insertComponent<T>(m_name, values...));
}

inline void sw::Entity::setActive(bool value)
{
    m_isActive = value;
}

inline bool sw::Entity::isActive() const
{
    return (m_isActive);
}

inline void sw::Entity::addChild(const std::string& entityName)
{
    auto& entity = m_scene.getEntity(entityName);

    entity.m_parent = *this;
    m_childrenMap.insert({entity.m_name, entity});
}