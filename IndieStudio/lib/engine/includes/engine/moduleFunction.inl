/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** moduleFunction.inl
*/

template <class ConcretModule>
inline ConcretModule& sw::Engine::createModule(const std::string& name)
{
    auto it = m_moduleMap.find(name);

    if (it == m_moduleMap.end()) {
        it = m_moduleMap.emplace(name, std::make_unique<ConcretModule>()).first;
        if (m_activeModule.empty())
            m_activeModule = name;
    }
    return (static_cast<ConcretModule&>(*it->second.get()));
}

template <class ConcretModule>
inline ConcretModule& sw::Engine::getModule(const std::string& name)
{
    auto it = m_moduleMap.find(name);

    if (it == m_moduleMap.end())
        throw sw::Error("ERROR: sw::Engine::getModule - Can't find Module", "");
    return (static_cast<ConcretModule&>(*it->second.get()));
}

inline sw::IModule& sw::Engine::getModule(const std::string& name)
{
    auto it = m_moduleMap.find(name);

    if (it == m_moduleMap.end())
        throw sw::Error("ERROR: sw::Engine::getModule - Can't find Module", "");
    return (*it->second.get());
}

template<class ConcretModule>
ConcretModule& sw::Engine::activeModule()
{
    auto it = m_moduleMap.find(m_activeModule);

    if (it == m_moduleMap.end())
        throw sw::Error("ERROR: sw::Engine::activeModule - Can't find Module", "");
    return (static_cast<ConcretModule&>(*it->second.get()));
}

inline sw::IModule& sw::Engine::activeModule()
{
    auto it = m_moduleMap.find(m_activeModule);

    if (it == m_moduleMap.end())
        throw sw::Error("ERROR: sw::Engine::activeModule - Can't find Module", "");
    return (*it->second.get());
}

inline void sw::Engine::deleteModule(const std::string& name)
{
    m_moduleMap[name]->terminate();
    m_moduleMap.erase(name);
}