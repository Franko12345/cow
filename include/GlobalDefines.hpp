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
#include <memory>
#include <array>
#include <numeric>
#include <random>
#include <type_traits>
#include <cstdint>
#include <iomanip>
#include <sys/types.h>

using namespace std;

const uint8_t WORLD_SIZE = 20;

typedef struct {
    int x, y;
} Vec2;

bool operator==(const Vec2 &a, const Vec2 &b);
bool operator!=(const Vec2 &a, const Vec2 &b);

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
