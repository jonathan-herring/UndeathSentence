#include "zombie.h"
#include "player.h"
#include <cstdlib>
#include <GL/glut.h>

Zombie::Zombie(Player& player) 
    : player(player)
{
    this->x = (float)(-99 + (rand() % 100));
    this->y = (float)(-49 + (rand() % 50));
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
    if (px > this->x) {
        this->x += 0.0075f;
    } else if(px > this->x) {
        this->x -= 0.0075f;
    }
    if (py > this->y) {
        this->y += 0.0075f;
    } else if(py > this->y) {
        this->y -= 0.0075f;
    }
}
