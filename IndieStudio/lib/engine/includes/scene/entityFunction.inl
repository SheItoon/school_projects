/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** entityFunction.inl
*/

inline bool sw::AScene::hasEntity(const std::string& entityName)
{
    if (m_entityMap.find(entityName) == m_entityMap.end())
        return (false);
    return (true);
}

inline void sw::AScene::deleteEntity(const std::string& entityName)
{
    m_deleteEntity.push_back(entityName);
}

inline void sw::AScene::deleteRequestedEntity()
{
    for (auto name : m_deleteEntity)
        m_entityMap.erase(name);
    m_deleteEntity.clear();
}