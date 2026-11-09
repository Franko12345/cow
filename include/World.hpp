#pragma once
#include "GlobalDefines.hpp"
#include "Tile.hpp"

class Tile;
class World{
    public:
        vector<vector<Tile>> tiles;
        World();
        void generate(uint seed);
};
