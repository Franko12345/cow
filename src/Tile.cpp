#include "../include/GlobalDefines.hpp"
#include "../include/Tile.hpp"

Tile::Tile(){

}

void Tile::tick(){
    // crop.tick();
    // machine.tick();
    for(int i = 0; i < entities.size(); i++)
        entities[i]->tick();

}
