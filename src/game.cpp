#include "game.h"

#include <algorithm>

Game::Game() : controls(InputHandler(&player, &bullets)) 
{
    roundDuration = 15;
}

void Game::init() // Spawn player, zombies, set stats, **initialize UI elements** (later on), load textures?
{
    zombiesKilled = 0;
    secondsSurvived = 0;
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

    ui.render();
}

void Game::update(float deltaTime) // Handle input, move objects, collisions, update round, spawn zombies, update UI
{
    controls.update(deltaTime);

    timeSinceLastRoundChange += deltaTime;
    if (timeSinceLastRoundChange >= roundDuration) // Next round begins
    {
        currentRound++;
        spawnZombies(3);
        timeSinceLastRoundChange = 0;
    }

    for (auto& zombie : zombies)
    {
        zombie.move(player.x, player.y);
    }

    resolveZombieCollisions();
    resolveBulletCollisions();
    removeOffScreenBullets();
    removeDeadZombies();

    ui.setHealth(player.health);
    ui.setRound(currentRound);
    if (player.health <= 0) // Game over condition (guaranteed to happen eventually)
        ui.setGameOver(true);
    ui.update(deltaTime);
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

void Game::resolveBulletCollisions() // Checks if each bullet is colliding with each zombie; if so, erase bullet, damage zombie
{
    for (auto& bullet : bullets)
    {
        for (auto& zombie : zombies)
        {
            if (bullet.isCollidingWithZombie(zombie))
            {
                bullet.setCollisionStatusTrue();
                zombie.health -= bullet.damage;
            }
        }
    }
    // Remove collided bullets
    if (bullets.size() > 0)
    {
        bullets.erase(
            std::remove_if(bullets.begin(), bullets.end(), [](const Bullet& bullet) {
                return bullet.isCollided();
            }),
            bullets.end()
        );
    }
}


void Game::resolveZombieCollisions()
{
    for (size_t i = 0; i < zombies.size(); ++i) {
        for (size_t j = i + 1; j < zombies.size(); ++j) {
            if (checkCollision(zombies[i], zombies[j])) {
                adjustPositions(zombies[i], zombies[j]);
            }
        }
    }
}

bool Game::checkCollision(const Zombie& a, const Zombie& b)
{
    // Calculate the sides of the rectangles
    float aLeft = a.x - a.width / 2;
    float aRight = a.x + a.width / 2;
    float aTop = a.y + a.height / 2;
    float aBottom = a.y - a.height / 2;

    float bLeft = b.x - b.width / 2;
    float bRight = b.x + b.width / 2;
    float bTop = b.y + b.height / 2;
    float bBottom = b.y - b.height / 2;

    // Check if the rectangles are overlapping on the x and y axes
    bool xOverlap = (aRight > bLeft) && (aLeft < bRight);
    bool yOverlap = (aTop > bBottom) && (aBottom < bTop);

    // Collision occurs if there is an overlap on both axes
    return xOverlap && yOverlap;
}

void Game::adjustPositions(Zombie& a, Zombie& b) {
    float overlapFactor = 0.03; // Smaller factor for smoother movement

    float dx = (a.x + a.width / 2) - (b.x + b.width / 2);
    float dy = (a.y + a.height / 2) - (b.y + b.height / 2);

    if (dx != 0) {
        float adjustX = dx * overlapFactor;
        a.x += adjustX;
        b.x -= adjustX;
    }
    if (dy != 0) {
        float adjustY = dy * overlapFactor;
        a.y += adjustY;
        b.y -= adjustY;
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