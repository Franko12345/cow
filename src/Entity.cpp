#include "../include/Entity.hpp"
#include "../include/World.hpp"
#include "../include/utils.hpp"

Entity::Entity(string name_, int age_, Vec2 health_, Vec2 hunger_,
         Vec2 thirst_, Vec2 energy_, Color color_, World* world_,
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
    world = world_;
    pos = pos_;
}
Entity::Entity(string name_, World* world_, Vec2 pos_){
    name = name_;
    age = 0;
    health = {10,10};
    hunger = {0,10};
    thirst = {0, 10};
    energy = {5, 10};
    color = Color({.R = 100, .G = 100, .B = 100});
    state = EntityState::sleeping;
    isAlive = true;
    world = world_;
    pos = pos_;
}

bool Entity::move(Vec2 offset){
    Vec2 new_pos = sum_vec(pos, offset);
    moveTo(new_pos);
    return true;
}
bool Entity::moveTo(Vec2 pos){
    // world.tiles
    //Search for best pratices
    //
    return true;
}
Vec2 Entity::search_for_tile(Floor tile){

    //Search for best pratices
    return {-1,-1};
}

vector<Vec2> Entity::search_for_tiles(vector<Floor> targets){
    vector<Vec2> locations(targets.size());
    for(int i = 0; i < targets.size(); i++){
        locations[i] = search_for_tile(targets[i]);
    }
    return locations;
}

Vec2 Entity::closest_tile(vector<Floor> targets){
    vector<Vec2> found_tiles = search_for_tiles(targets);
    return *max_element(found_tiles.begin(), found_tiles.end(), [this](const Vec2 a, const Vec2 b){return vec_distance(pos, a) < vec_distance(pos, b);});
}


void Entity::tick(){
    switch(state){
        case EntityState::wandering:
            {
                Vec2 mov = {(rand()%3)-1, (rand()%3)-1};
                move(mov);
                break;
            }
        case EntityState::searching_food:
            {
                Vec2 found = closest_tile(diet);
                if(found != (Vec2){-1,-1}) {
                    Vec2 dir = direction(pos, found);
                    // move()/
                }
                break;
            }
        case EntityState::searching_water:
            // bool found = closest_tile({Floor::water});
            // if(found) state = EntityState::eating;
            ;
            break;
        case EntityState::eating:
            ;
            break;
        case EntityState::sleeping:
            ;
            break;
        case EntityState::breeding:
            ;
            break;
        case EntityState::running_away:
            ;
            break;
        case EntityState::hunting:
            ;
            break;
        case EntityState::fighting:
            ;
            break;
        default:
            break;
    }
}
