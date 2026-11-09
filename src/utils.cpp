#include "../include/GlobalDefines.hpp"
#include "../include/utils.hpp"

Vec2 direction(Vec2 a, Vec2 b){
    return {b.x - a.x, b.y-a.y};
}

float vec_distance(Vec2 a, Vec2 b){
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

Vec2 sum_vec(Vec2 a, Vec2 b){
    return {a.x+b.x, a.y+b.y};
}

int sign(int a){
    if (a > 0) return 1;
    else if (a < 0) return -1;
    return 0;
}

bool operator==(const Vec2 &a, const Vec2 &b) {
  return a.x == b.x && a.y == b.y;
}
bool operator!=(const Vec2 &a, const Vec2 &b) {
  return a.x != b.x || a.y != b.y;
}
