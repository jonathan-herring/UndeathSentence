#include "zombie.h"

#include <GL/glut.h>

Zombie::Zombie() 
{
    this->x = 0.5f;
    this->y = 0.5f;
    this->width = 0.05f;
    this->height = 0.05f;
}

void n::draw()
{
    glBegin(GL_QUADS);
        glVertex2f(x - width / 2, y - height / 2);
        glVertex2f(x + width / 2, y - height / 2);
        glVertex2f(x + width / 2, y + height / 2);
        glVertex2f(x - width / 2, y + height / 2);
    glEnd();
}

void Zombie::move(float dx, float dy) 
{
    this->x += dx;
    this->y += dy;
}
