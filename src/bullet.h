#ifndef BULLET_H
#define BULLET_H

#include "zombie.h"

#include <cmath>
#include <vector>

class Bullet {
public:
    Bullet(float startX, float startY, float targetX, float targetY);
    ~Bullet() {}

    void move(float deltaTime);
    void draw();
    
    bool isCollidingWithZombie(Zombie&);
    bool isOffScreen() const;

private:
    float x, y; // Position
    float dirX, dirY; // Direction
    float speed; // Speed
    float damage; // Default damage is 25
    float width, height;
};

#endif