/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** factoryFunction.inl
*/

template<typename ConcretFactory>
inline ConcretFactory& sw::AScene::createFactory(const std::string& factoryName)
{
    auto it = m_factoryMap.find(factoryName);

    if (it == m_factoryMap.end()) {
        it = m_factoryMap.emplace(factoryName, std::make_unique<ConcretFactory>(factoryName, *this)).first;
        m_factoryLayer.emplace_front(std::make_pair(0, factoryName));
    }
    return (static_cast<ConcretFactory&>(*it->second.get()));
}

template<typename ConcretFactory>
inline ConcretFactory& sw::AScene::getFactory(const std::string& factoryName)
{
    auto it = m_factoryMap.find(factoryName);

    if (it == m_factoryMap.end())
        throw sw::Error("ERROR: sw::Scene::getFactory - Can't find Factory <" + factoryName + ">", "");
    return (static_cast<ConcretFactory&>(*it->second.get()));
}

inline bool sw::AScene::hasFactory(const std::string& factoryName)
{
    if (m_factoryMap.find(factoryName) == m_factoryMap.end())
        return (false);
    return (true);
}

inline void sw::AScene::deleteFactory(const std::string& factoryName)
{
    for (auto [_, name] : m_factoryLayer)
        if (name == factoryName) {

        }
    m_factoryMap.erase(factoryName);
}

inline void sw::AScene::setLayer(const std::string& factoryName, int newLayer)
{
    for (auto& [layer, name] : m_factoryLayer)
        if (name == factoryName)
            layer = newLayer;
    m_factoryLayer.needSort = true;
}