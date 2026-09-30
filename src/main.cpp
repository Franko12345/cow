#include <iostream>
#include <algorithm>
#include <iterator>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <utility>
#include <vector>

using namespace std;

enum Floor {
    soil,
    grass,
    water
};

enum Feromones {
    cow,
    bunny,
    ant
};

enum EntityState {
    wandering,
    searching_food,
    searching_water,
    eating,
    sleeping,
    breeding,
    running_away,
    hunting,
    fighting
};

typedef struct {
    int R,G,B;
} Color;
class Tile;

pair<int, int> direction(pair<int, int> a, pair<int,int> b){
    return {b.first - a.first, b.second-a.second};
}

int sign(int a){
    if (a > 0) return 1;
    else if (a < 0) return -1;
    return 0;
}

class Entity{
    private:
        vector<vector<Tile>>* grid;
        vector<Floor> diet; //Mudar para crop depois
    public:
        string name;
        pair<int, int> health, hunger, thirst, energy;
        int age;
        Color color;
        EntityState state;
        bool isAlive;
        pair<int, int> pos;


        Entity(string name_, int age_, pair<int,int> health_, pair<int,int> hunger_,
                 pair<int,int> thirst_, pair<int,int> energy_, Color color_, vector<vector<Tile>>* grid_,
                 pair<int,int> pos_)
        {
            name = name_;
            age = age_;
            health = health_;
            hunger = hunger_;
            thirst = thirst_;
            energy = energy_;
            color = color_;
            state = EntityState::sleeping;
            isAlive = true;
            grid = grid_;
            pos = pos_;
        }

        Entity(string name_, vector<vector<Tile>>* grid_, pair<int,int> pos_){
            name = name_;
            age = 0;
            health = {10,10};
            hunger = {0,10};
            thirst = {0, 10};
            energy = {5, 10};
            color = Color({.R = 100, .G = 100, .B = 100});
            state = EntityState::sleeping;
            isAlive = true;
            grid = grid_;
            pos = pos_;
        }

        void tick(){
            switch(state){
                case EntityState::wandering:
                    move();
                    break;
                case EntityState::searching_food:
                    pair<int, int> found = search_for_tiles(diet);
                    if(found != make_pair(-1, -1)) {
                        pair<int,int> dir = direction(pos, found);
                        move()
                    }

                    break;
                case EntityState::searching_water:
                    bool found = search_for_tile();
                    if(found) state = EntityState::eating;

                    break;
                case EntityState::eating:

                    break;
                case EntityState::sleeping:

                    break;
                case EntityState::breeding:

                    break;
                case EntityState::running_away:

                    break;
                case EntityState::hunting:

                    break;
                case EntityState::fighting:

                    break;
                default:
                    break
            }
        }


};

class Tile{
    public:
        Floor base;
        int temperature, light;
        vector<Entity> entities;
        Crop crop;
        map<Feromones, int> feromones;
        Machine machine;

        void tick(){
            crop.tick();
            machine.tick();
            for(auto E: entities)
                E.tick();

        }
};

int main(){
    vector<>


}
