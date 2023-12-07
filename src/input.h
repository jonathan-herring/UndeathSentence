#ifndef INPUT_H
#define INPUT_H

#include "player.h"
#include "bullet.h"

#include <vector>

class InputHandler {
public:
    InputHandler(Player* player, std::vector<Bullet>* bullets);
    void update(float deltaTime); // Update the position based on the elapsed time
    void keyPressed(unsigned char key, int x, int y);
    void keyUp(unsigned char key, int x, int y);
    void mousePressed(int button, int state, int x, int y);

private:
    Player* player;
    std::vector<Bullet>* bullets;
    float timeSinceLastFire; // Seconds
    float bulletCoolDown; // Seconds
    bool upPressed, downPressed, leftPressed, rightPressed;
};

#endif