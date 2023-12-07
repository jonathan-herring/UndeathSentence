#include "bullet.h"

#include <GL/glut.h>

Bullet::Bullet(float startX, float startY, float targetX, float targetY)
{
    this->x = startX;
    this->y = startY;
    this->speed = 1.5f;
    this->damage = 25;
    this->collided = false;

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
}

void Bullet::draw()
{
    glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.0f); // Yellow
        glVertex2f(x - width / 2, y - height / 2);
        glVertex2f(x + width / 2, y - height / 2);
        glVertex2f(x + width / 2, y + height / 2);
        glVertex2f(x - width / 2, y + height / 2);
        glColor3f(1.0f, 1.0f, 1.0f);
    glEnd();
}

void Bullet::setCollisionStatusTrue()
{
    this->collided = true;
}

bool Bullet::isOffScreen() const
{
    if (x < 0 || x > 1 || y < 0 || y > 0.8)
        return true;
    return false;
}

bool Bullet::isCollided() const
{
    return this->collided;
}

bool Bullet::isCollidingWithZombie(Zombie& zombie) // Check for collision with zombie using AABB collision detection
{
    // Bullet edges
    float bLeft = x - width / 2;
    float bRight = x + width / 2;
    float bTop = y + height / 2;
    float bBottom = y - height / 2;

    // Zombie edges
    float zLeft = zombie.x - zombie.width / 2;
    float zRight = zombie.x + zombie.width / 2;
    float zTop = zombie.y + zombie.height / 2;
    float zBottom = zombie.y - zombie.height / 2;

    // Collision checks
    if (bLeft > zRight || bRight < zLeft || bTop < zBottom || bBottom > zTop) {
        return false; // No collision
    }
    return true; // Collision
}
