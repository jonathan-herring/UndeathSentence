#include "bullet.h"

#include <GL/glut.h>

Bullet::Bullet(float startX, float startY, float targetX, float targetY)
{
    this->x = startX;
    this->y = startY;
    this->speed = 1.5f;

    // Calculate direction vector
    float dx = targetX - startX;
    float dy = targetY - startY;
    float length = std::sqrt(dx * dx + dy * dy);
    this->dirX = dx / length;
    this->dirY = dy / length;

    this->width = 0.01f;
    this->height = 0.01f;
}

void Bullet::move(float deltaTime)
{
    // Update position based on speed and direction
    x += dirX * speed * deltaTime;
    y += dirY * speed * deltaTime;

    // Add collision detection logic here
}

void Bullet::draw()
{
    glBegin(GL_QUADS);
        glVertex2f(x - width / 2, y - height / 2);
        glVertex2f(x + width / 2, y - height / 2);
        glVertex2f(x + width / 2, y + height / 2);
        glVertex2f(x - width / 2, y + height / 2);
    glEnd();
}
