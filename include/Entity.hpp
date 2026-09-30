#pragma once
#include "GlobalDefines.hpp"

class Entity{
    private:
        vector<vector<Tile>>* grid;
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
                 Vec2 thirst_, Vec2 energy_, Color color_, vector<vector<Tile>>* grid_,
                 Vec2 pos_);
        Entity(string name_, vector<vector<Tile>>* grid_, Vec2 pos_);


        void tick();
};
