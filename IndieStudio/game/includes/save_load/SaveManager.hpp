/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-guillaume.soisson
** File description:
** Save
*/

#pragma once

#include <optional>
#include <functional>

#include "SW/Scene.hpp"

template <typename T>
using ref = std::optional<std::reference_wrapper<T>>;

class SaveManager {
    public:
        SaveManager(sw::AScene& scene);
        SaveManager() = default;
        ~SaveManager() = default;
        void saveGame();
        void setScene(sw::AScene& scene) { m_entitiesMap.emplace(scene.getEntities()); }

    protected:
    private:
        ref<std::unordered_map<std::string, std::unique_ptr<sw::IEntity>>> m_entitiesMap;
        std::vector<std::string> m_mapVector;
        jsnp::Data m_saveData;
        std::unordered_map<std::string, std::unique_ptr<sw::IEntity>>& entitiesMap() const { 
            if (!m_entitiesMap.has_value())
                throw sw::Error("ERROR: SaveManager::saveGame - Tried to save, but no scene was specified or its entitiesMap is empty. Try using saveManager::setScene", "");
            return m_entitiesMap.value().get(); 
        } 
        int getMapSize() const;
        void saveMap();
        void savePlayers();
};
