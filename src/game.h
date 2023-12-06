#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "zombie.h"
#include "input.h"
#include "bullet.h"

#include <GL/glut.h>

class Game {
public:
    Game();
    void init();
    void update(float deltaTime);
    void render();

    // Handle input
    void handleKeyPress(unsigned char key, int x, int y);
    void handleKeyUp(unsigned char key, int x, int y);
    void handleMousePress(int button, int state, int x, int y);

private:
    Player player;
    std::vector<Zombie> zombies;
    std::vector<Bullet> bullets;
    InputHandler controls;

    void spawnZombies(int count); // Spawn x zombies with health, damage, and speed set according to round number
    void removeDeadZombies(); // For removing zombies that are 0 health
    void updateBullets(float deltaTime); // For updating bullet positions
    void removeOffScreenBullets(); // For removing bullets that are off-screen
    void resolveBulletCollision(); // Checks if each bullet is colliding with each zombie; if so, erase bullet, damage zombie

    int currentRound;
    float timeSinceLastRoundChange;
    float roundDuration; // 15 seconds

    int score;
};

#endif