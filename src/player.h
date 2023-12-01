#ifndef PLAYER_H
#define PLAYER_H

class Player
{
    public:

    float x, y; // Player position
    float width, height; // Player size

    Player();

    void draw();
    void move(float dx, float dy);
};

#endif
