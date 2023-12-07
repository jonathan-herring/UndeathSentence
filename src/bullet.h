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

    void setCollisionStatusTrue();
    
    bool isCollidingWithZombie(Zombie& zombie);
    bool isOffScreen() const;
    bool isCollided() const;

    float damage; // Default damage is 25

private:
    float x, y; // Position
    float dirX, dirY; // Direction
    float speed; // Speed
    float width, height;
    bool collided;
};

#endif