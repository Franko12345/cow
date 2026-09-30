#include "../include/Entity.hpp"
#include "../include/utils.h"

Entity::Entity(string name_, int age_, Vec2 health_, Vec2 hunger_,
         Vec2 thirst_, Vec2 energy_, Color color_, vector<vector<Tile>>* grid_,
         Vec2 pos_)
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
Entity::Entity(string name_, vector<vector<Tile>>* grid_, Vec2 pos_){
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

bool Entity::move(Vec2 offset){
    //Search for best pratices
}

Vec2 Entity::search_for_tile(Floor tile){

    //Search for best pratices
}

vector<Vec2> Entity::search_for_tiles(vector<Floor> targets){
    vector<Vec2> locations(targets.size());
    for(int i = 0; i < targets.size(); i++){
        locations[i] = search_for_tile(targets[i]);
    }
}

Vec2 Entity::closest_tile(vector<Floor> targets){
    vector<Vec2> found_tiles = search_for_tiles(targets);
    return *max_element(found_tiles.begin(), found_tiles.end(), [](const Vec2 a, const Vec2 b){return distance(pos, a) < distance(pos, b)});
}


Vec2 Entity::move(Vec2 offset){
    //Search for best pratices
}
void Entity::tick(){
    switch(state){
        case EntityState::wandering:
            move();
            break;
        case EntityState::searching_food:
            Vec2 found = search_for_tiles(diet);
            if(found != make_pair(-1, -1)) {
                Vec2 dir = direction(pos, found);
                move()
            }

            break;
        case EntityState::searching_water:
            bool found = search_for_tile(Floor::water);
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
