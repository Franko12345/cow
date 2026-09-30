#include "../include/GlobalDefines.hpp"
#include "../include/Entity.hpp"

Vec2 direction(pair<int, int> a, pair<int,int> b){
    return {b.first - a.first, b.second-a.second};
}

int sign(int a){
    if (a > 0) return 1;
    else if (a < 0) return -1;
    return 0;
}

class Tile{
    public:
        Floor base;
        int temperature, light;
        vector<Entity> entities;
        // Crop crop;
        // map<Feromones, int> feromones;
        // Machine machine;

        void tick(){
            // crop.tick();
            // machine.tick();
            for(auto E: entities)
                E.tick();

        }
};

int main(){
    vector<>


}
