/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** AFactory.inl
*/

template<typename ConcretComponent>
inline sw::AFactory<ConcretComponent>::AFactory(const std::string& factoryName, AScene& sceneRef)
    : m_scene(sceneRef),
      m_isActive(true),
      m_componentMap(),
      m_componentLayer(),
      m_name(factoryName),
      m_layer(0),
      m_removeList(),
      m_needDelete(false)
{
    m_componentLayer.needSort = true;
}

template <typename ConcretComponent>
template <typename... Args>
inline ConcretComponent& sw::AFactory<ConcretComponent>::createComponent(const std::string& entityName, Args... values)
{
    if (!m_scene.hasEntity(entityName))
        throw sw::Error("ERROR: sw::AFactory::createComponent - Can't find the entity", "");

    auto it = m_componentMap.find(entityName);

    if (it == m_componentMap.end()) {
        it = m_componentMap.try_emplace(entityName, std::make_unique<ConcretComponent>(m_scene.getEntity(entityName), values...)).first;
        m_componentLayer.emplace_front(std::make_pair(0, entityName));
        m_layer = 0;
    }
    return (*it->second);
}

template <typename ConcretComponent>
template <typename T, typename... Args>
inline T& sw::AFactory<ConcretComponent>::insertComponent(const std::string& entityName, Args... values)
{
    if (!std::is_convertible<T, ConcretComponent>())
        throw sw::Error("ERROR: sw::AFactory::createComponent - This type is not convertible to Factory Component type", "");
    if (!m_scene.hasEntity(entityName))
        throw sw::Error("ERROR: sw::AFactory::createComponent - Can't find the entity", "");

    auto it = m_componentMap.find(entityName);

    if (it == m_componentMap.end()) {
        it = m_componentMap.try_emplace(entityName, std::make_unique<T>(m_scene.getEntity(entityName), values...)).first;
        m_componentLayer.emplace_front(std::make_pair(0, entityName));
        m_layer = 0;
    }
    return (static_cast<T&>(*it->second));
}

template<typename ConcretComponent>
inline void sw::AFactory<ConcretComponent>::deleteComponent(const std::string& entityName)
{
    m_removeList.push_back(entityName);
    m_needDelete = true;
}

template<typename ConcretComponent>
inline void sw::AFactory<ConcretComponent>::load()
{
    onLoad();
    if (m_componentLayer.needSort)
        m_componentLayer.sort();
}

template<typename ConcretComponent>
inline void sw::AFactory<ConcretComponent>::update()
{
    if (m_componentLayer.needSort)
        m_componentLayer.sort();
    onUpdate();
}

template<typename ConcretComponent>
inline void sw::AFactory<ConcretComponent>::unload()
{
    onUnload();
    m_componentMap.clear();
    m_componentLayer.clear();
}

template <typename ConcretComponent>
inline void sw::AFactory<ConcretComponent>::endUpdate()
{
    deleteRequestedComponent();
}

template<typename ConcretComponent>
inline void sw::AFactory<ConcretComponent>::setLayer(const std::string& entityName, int newLayer)
{
    for (auto& [layer, name] : m_componentLayer)
        if (name == entityName) {
            layer = newLayer;
            m_layer = newLayer;
        }
    m_componentLayer.needSort = true;
}

template <typename ConcretComponent>
inline std::ostream& operator<<(std::ostream& os, sw::AFactory<ConcretComponent>& sys)
{
    std::cout << "Display AFactory" << std::endl;
    for (auto& [entityName, obj] : sys.m_componentMap)
        std::cout << "  " << entityName << " : " << obj << std::endl;
    std::cout << "<------------>" << std::endl << std::endl;
    return (os);
}

template<typename ConcretComponent>
template<typename T, typename... Args>
inline ConcretComponent& sw::AFactory<ConcretComponent>::addScript(const std::string &entityName, Args... values)
{
    if (!m_scene.hasEntity(entityName))
        throw sw::Error("Entity not found", "");

    auto it = m_componentMap.find(entityName);

    if (it == m_componentMap.end()) {
        it = m_componentMap.try_emplace(entityName, std::make_unique<T>(m_scene.getEntity(entityName), values...)).first;
        m_componentLayer.emplace_front(std::make_pair(0, entityName));
    }
    if (m_scene.m_load)
        (*it->second).start();
    return (*it->second);
}

template<typename ConcretComponent>
inline ConcretComponent& sw::AFactory<ConcretComponent>::operator[](const std::string& entityName)
{
    auto it = m_componentMap.find(entityName);

    if (it == m_componentMap.end())
        throw sw::Error(m_name + ": Component for " + entityName + " not found", "");
    return (*it->second);
}

template <typename ConcretComponent>
inline typename std::unordered_map<std::string, std::unique_ptr<ConcretComponent>>::iterator sw::AFactory<ConcretComponent>::begin()
{
    return (m_componentMap.begin());
}

template <typename ConcretComponent>
inline typename std::unordered_map<std::string, std::unique_ptr<ConcretComponent>>::iterator sw::AFactory<ConcretComponent>::end()
{
    return (m_componentMap.end());
}

template <typename ConcretComponent>
inline void sw::AFactory<ConcretComponent>::setActive(bool value)
{
    m_isActive = value;
}

template <typename ConcretComponent>
inline bool sw::AFactory<ConcretComponent>::isActive() const
{
    return (m_isActive);
}

template <typename ConcretComponent>
inline void sw::AFactory<ConcretComponent>::deleteRequestedComponent()
{
    for (auto name : m_removeList) {
        m_componentLayer.remove(std::pair<int, std::string>(0, name));
        m_componentMap.erase(name);
    }
    m_removeList.clear();
}