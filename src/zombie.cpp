#include "zombie.h"
#include "player.h"

#include <cstdlib>
#include <math.h>
#include <GL/glut.h>

Zombie::Zombie(Player* player, float health, float damage, float speed) 
    : player(player), health(health), damage(damage), speed(speed)
{
    this->x = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    this->y = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 0.8f;
    this->width = 0.05f;
    this->height = 0.05f;

    this->hitCooldown = 3.0f;
    this->timeSinceLastHit = 0.0f;
}

void Zombie::draw()
{
    glBegin(GL_QUADS);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(x - width / 2, y - height / 2);
        glVertex2f(x + width / 2, y - height / 2);
        glVertex2f(x + width / 2, y + height / 2);
        glVertex2f(x - width / 2, y + height / 2);
        glColor3f(1.0f, 1.0f, 1.0f);
    glEnd();
}

void Zombie::move(float px, float py) 
{
    if (px > this->x + player->width / 2) {
        this->x += 0.0045f * speed;
    } else if (px  < this->x + player->width / 2) {
        this->x -= 0.0045f * speed;
    }
    if (py > this->y + player->height / 2) {
        this->y += 0.0045f * speed;
    } else if (py < this->y + player->height / 2) {
        this->y -= 0.0045f * speed;
    }
}

void Zombie::damagePlayer()
{
    player->health -= damage;
}

bool Zombie::isInRange()
{
    // Distance between zombie and player
    float dx = this->x - player->x;
    float dy = this->y - player->y;
    float distance = std::sqrt(dx * dx + dy * dy);

    // Determine zombie can reach player
    float hitRange = (this->width + this->height) * 0.5f;
    return distance <= hitRange;
}