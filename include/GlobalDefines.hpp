#pragma once

#include <iostream>
#include <algorithm>
#include <iterator>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <utility>
#include <vector>
#include <cmath>

using namespace std;

using Vec2 = pair<int,int>;

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
