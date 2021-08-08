/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** Scene.inl
*/

inline sw::AScene::AScene(const std::string& sceneName) :
m_name(sceneName),
m_load(false)
{
    m_factoryLayer.needSort = true;
}

inline sw::AScene::~AScene()
{
    m_factoryMap.clear();
    m_factoryLayer.clear();
    m_deleteEntity.clear();
    std::cout << "Scene Destroyed" << std::endl;
}

inline void sw::AScene::load()
{
    if (m_load)
        return;
    m_load = true;
    m_resources.loadResources();
    onLoad();
    m_factoryLayer.sort();
    for (auto& [_, factoryName] : m_factoryLayer)
        m_factoryMap[factoryName]->load();
}

inline void sw::AScene::update()
{
    if (m_factoryLayer.needSort)
        m_factoryLayer.sort();
    onUpdate();
    for (auto& [index, factoryName] : m_factoryLayer)
        m_factoryMap[factoryName]->update();
    for (auto& [index, factoryName] : m_factoryLayer)
        m_factoryMap[factoryName]->endUpdate();
    deleteRequestedEntity();
}

inline void sw::AScene::unload()
{
    onUnload();
    m_resources.unloadResources();
    for (auto& [name, fact] : m_factoryMap) {
        fact->unload();
        std::cout << "Factory " << name << " unloaded" << std::endl;
    }
    m_factoryMap.clear();
    m_factoryLayer.clear();
    m_entityMap.clear();
    m_deleteEntity.clear();
    m_load = false;
}


inline sw::ITexture& sw::AScene::getTexture(std::string textureName)
{
    return (*m_resources.textures[textureName]);
}

inline sw::ISound& sw::AScene::getSound(std::string soundName)
{
    return (*m_resources.sounds[soundName]);
}

inline sw::IFont& sw::AScene::getFont(std::string fontName)
{
    auto& font = *m_resources.fonts[fontName];

    return (font);
}

inline sw::IModel& sw::AScene::getModel(std::string modelName)
{
    return (*m_resources.models[modelName]);
}

inline sw::IMusic& sw::AScene::getMusic(std::string musicName)
{
    return (*m_resources.music[musicName]);
}