#include "game.h"

#include <algorithm>

Game::Game() : controls(InputHandler(&player, &bullets)) 
{
    roundDuration = 15;
}

void Game::init() // Spawn player, zombies, set stats, **initialize UI elements** (later on), load textures?
{
    score = 0;
    currentRound = 1;
    timeSinceLastRoundChange = 0;

    spawnZombies(3);
}

void Game::render() // Draw background and game objects, possibly game over screen later on
{
    // Background
    glBegin(GL_QUADS);
        glColor3ub(19,23,25);
        glVertex2f(0, 0);
        glVertex2f(1, 0);
        glVertex2f(1, 0.8);
        glVertex2f(0, 0.8);
        glColor3ub(255,255,255);
    glEnd();

    // Objects - uncomment later
    player.draw();
    for (auto& zombie : zombies)
    {
        zombie.draw();
    }
    for (auto& bullet : bullets)
    {
        bullet.draw();
    }
}
#include <iostream>
void Game::update(float deltaTime) // Handle input, move objects, collisions, update mechanics, update round, spawn zombies, update UI
{
    controls.update(deltaTime);

    timeSinceLastRoundChange += deltaTime;
    if (timeSinceLastRoundChange >= roundDuration) // Next round begins
    {
        std::cout << "Welcome to round " << currentRound;
        currentRound++;
        spawnZombies(3);
        timeSinceLastRoundChange = 0;
    }

    for (auto& zombie : zombies)
    {
        zombie.move(player.x, player.y);
    }
    removeOffScreenBullets();
}



void Game::spawnZombies(int count) // Spawn x zombies with health, damage, and speed set according to round number
{
    float multiplier = currentRound - 1.0;
    float newZombieHealth = 100 + multiplier * 10.0; // + 10 every round
    float newZombieDamage = 5 + multiplier * 5.0; // + 5 every round
    float newZombieSpeed = 0.5 + multiplier * 0.1; // + 0.1 every round

    for (int i = 0; i < count; i ++)
    {
        zombies.push_back(Zombie(&player, newZombieHealth, newZombieDamage, newZombieSpeed));
    }
}

void Game::removeDeadZombies()
{
    zombies.erase(
        std::remove_if(zombies.begin(), zombies.end(), [](const Zombie& zombie) {
            return (zombie.health <= 0);
        }),
        zombies.end()
    );
}

void Game::updateBullets(float deltaTime)
{
    for (auto& bullet : bullets)
    {
        bullet.move(deltaTime);
    }
}

void Game::removeOffScreenBullets() 
{
    if (bullets.size() > 0)
    {
        bullets.erase(
            std::remove_if(bullets.begin(), bullets.end(), [](const Bullet& bullet) {
                return bullet.isOffScreen(); // Assuming Bullet has an isOffScreen method
            }),
            bullets.end()
        );
    }
}


void Game::handleKeyPress(unsigned char key, int x, int y)
{
    controls.keyPressed(key, x, y);
}

void Game::handleKeyUp(unsigned char key, int x, int y)
{
    controls.keyUp(key, x, y);
}

void Game::handleMousePress(int button, int state, int x, int y)
{
    controls.mousePressed(button, state, x, y);
}