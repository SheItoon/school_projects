/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** sceneFunction.inl
*/

template <class ConcretScene>
inline ConcretScene& sw::Engine::createScene(const std::string& name)
{
    auto it = m_sceneMap.find(name);

    if (it == m_sceneMap.end()) {
        it = m_sceneMap.emplace(name, std::make_unique<ConcretScene>(name)).first;
        if (m_activeScene.empty())
            m_activeScene = name;
    }
    return (static_cast<ConcretScene&>(*it->second.get()));
}

template <class ConcretScene>
inline ConcretScene& sw::Engine::getScene(const std::string& name)
{
    auto it = m_sceneMap.find(name);

    if (it == m_sceneMap.end())
        throw sw::Error("ERROR: sw::Engine::getScene - Can't find Scene <" + name + ">", "");
    return (static_cast<ConcretScene&>(*it->second.get()));
}

inline sw::AScene& sw::Engine::getScene(const std::string& name)
{
    auto it = m_sceneMap.find(name);

    if (it == m_sceneMap.end())
        throw sw::Error("ERROR: sw::Engine::getScene - Can't find Scene <" + name + ">", "");
    return (*it->second.get());
}

template<class ConcretScene>
ConcretScene& sw::Engine::activeScene()
{
    auto it = m_sceneMap.find(m_activeScene);

    if (it == m_sceneMap.end())
        throw sw::Error("ERROR: sw::Engine::activeScene - Can't find active Scene <" + m_activeScene + ">", "");
    return (static_cast<ConcretScene&>(*it->second.get()));
}

inline sw::AScene& sw::Engine::activeScene()
{
    auto it = m_sceneMap.find(m_activeScene);

    if (it == m_sceneMap.end())
        throw sw::Error("ERROR: sw::Engine::activeScene - Can't find active Scene <" + m_activeScene + ">", "");
    return (*it->second.get());
}

inline void sw::Engine::deleteScene(const std::string& name)
{
    m_deleteScene.push_back(name);
}

inline void sw::Engine::deleteRequestedScene()
{
    for (auto name : m_deleteScene)
        m_sceneMap[name]->unload();
    m_deleteScene.clear();
}

inline void sw::Engine::setActiveScene(const std::string& name)
{
    auto it = m_sceneMap.find(name);

    if (it == m_sceneMap.end())
        throw sw::Error("ERROR: sw::Engine::setActiveScene - Can't find active Scene <" + name + ">", "");
    deleteScene(m_activeScene);
    m_activeScene = name;
    activeScene().load();
}