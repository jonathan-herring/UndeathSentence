#ifndef ZOMBIE_H
#define ZOMBIE_H

class Player;

class Zombie
{
    private:

        Player* player;

    public:

        float health; // Default 100 | + 10 every round
        float damage; // Default 5.0 | + 5.0 every round
        float speed;  // Default .5 | + 0.1 every round
        
        float x, y; // Zombie position
        float width, height; // Zombie size

        Zombie(Player* player, float health, float damage, float speed);

        void draw();
        void move(float dx, float dy);
};

#endif