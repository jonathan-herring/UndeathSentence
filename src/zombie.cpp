#include "zombie.h"
#include "player.h"
#include <cstdlib>
#include <GL/glut.h>

Zombie::Zombie(Player& player, float health, float damage, float speed) 
    : player(player), health(health), damage(damage), speed(speed)
{
    this->x = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    this->y = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    this->width = 0.05f;
    this->height = 0.05f;
    this->health = 100;
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
        this->x += 0.0045f * speed;
    } else if (px  < this->x + player.width) {
        this->x -= 0.0045f * speed;
    }
    if (py > this->y + player.height) {
        this->y += 0.0045f * speed;
    } else if (py < this->y + player.height) {
        this->y -= 0.0045f * speed;
    }
}