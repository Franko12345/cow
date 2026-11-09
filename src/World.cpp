#include "../include/GlobalDefines.hpp"
#include "../include/World.hpp"
#include "PerlinNoise.hpp"

World::World(){
    tiles.resize(WORLD_SIZE);;
    generate(12345);
}

void World::generate(uint seed){
    const siv::PerlinNoise perlin{ (siv::PerlinNoise::seed_type)seed };
    cout << fixed << setprecision(2);
    for(float x = 0; x < WORLD_SIZE; x++){
        for(float y = 0; y < WORLD_SIZE; y++){
            const double noise = perlin.octave2D_01(x*0.1, y*0.1, 2);
            cout << noise << " ";
        }
        cout << endl;
    }
}
