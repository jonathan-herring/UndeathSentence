#include "zombie.h"
#include "player.h"
#include <cstdlib>
#include <GL/glut.h>
#include <ctime>

Zombie::Zombie(Player& player, float x_spawn, float, y_spawn) 
    : player(player)
{
    srand(static_cast<unsigned>(time(nullptr)));  // Seed the random number generator

    // this->x = static_cast<float>(rand() % (int)(1.0 * 800) / 800);
    // this->y = static_cast<float>(rand() % (int)(1.0 * 600) / 600);
    // this->x = (float)(rand() / RAND_MAX);
    // this->y = (float)(rand() / RAND_MAX);
    this->x = x_spawn;
    this->y = y_spawn;
    this->width = 0.05f;
    this->height = 0.05f;
}

void Zombie::draw()
{
    glBegin(GL_QUADS);
        glVertex2f(x - width / 2, y - height / 2);
        glVertex2f(x + width / 2, y - height / 2);
        glVertex2f(x + width / 2, y + height / 2);
        glVertex2f(x - width / 2, y + height / 2);
    glEnd();
}

void Zombie::move(float px, float py) 
{
    if (px > this->x + player.width) {
        this->x += 0.0075f;
    } else if (px  < this->x + player.width) {
        this->x -= 0.0075f;
    }
    if (py > this->y + player.height) {
        this->y += 0.0075f;
    } else if (py < this->y + player.height) {
        this->y -= 0.0075f;
    }
}
