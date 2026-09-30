#include "../include/GlobalDefines.hpp"
#include "../include/utils.h"

Vec2 direction(Vec2 a, Vec2 b){
    return {b.first - a.first, b.second-a.second};
}

float vec_distance(Vec2 a, Vec2 b){
    return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));
}

int sign(int a){
    if (a > 0) return 1;
    else if (a < 0) return -1;
    return 0;
}
