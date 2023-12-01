#ifndef ZOMBIE_H
#define ZOMBIE_H

class Player;

class Zombie
{
    private:

    Player& player;

    public:

    float x, y; // Zombie position
    float width, height; // Zombie size

    Zombie(Player &player);

    void draw();
    void move(float dx, float dy);
};

#endif
