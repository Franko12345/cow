#pragma once

#include "GlobalDefines.hpp"
#include "Entity.hpp"

class Entity;
class Tile{
    public:
        Floor base;
        int temperature, light;
        vector<unique_ptr<Entity>> entities;
        // Crop crop;
        // map<Feromones, int> feromones;
        // Machine machine;
        Tile();
        void tick();

};
