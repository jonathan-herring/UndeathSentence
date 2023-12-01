#ifndef ZOMBIE_H
#define ZOMBIE_H

class Zombie
{
    public:

    float x, y; // Zombie position
    float width, height; // Zombie size

    Zombie();

    void draw();
    void move(float dx, float dy);
};

#endif
