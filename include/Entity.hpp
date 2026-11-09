#pragma once
#include "GlobalDefines.hpp"
#include "World.hpp"

class World;

class Entity{
    private:
        World* world;
        vector<Floor> diet; //Mudar para crop depois
    public:
        string name;
        Vec2 health, hunger, thirst, energy;
        int age;
        Color color;
        EntityState state;
        bool isAlive;
        Vec2 pos;


        Entity(string name_, int age_, Vec2 health_, Vec2 hunger_,
                 Vec2 thirst_, Vec2 energy_, Color color_, World* grid_,
                 Vec2 pos_);
        Entity(string name_, World* grid_, Vec2 pos_);


        void tick();
        bool move(Vec2 offset);
        bool moveTo(Vec2 pos);
        Vec2 search_for_tile(Floor tile);
        vector<Vec2> search_for_tiles(vector<Floor> targets);
        Vec2 closest_tile(vector<Floor> targets);

};
