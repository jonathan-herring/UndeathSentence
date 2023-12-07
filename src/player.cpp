#include "player.h"

#include <GL/glut.h>

Player::Player()
{
    this->x = 0.5f;
    this->y = 0.5f;
    this->width = 0.05f;
    this->height = 0.05f;
    this->speed = 0.5f; // Default speed
    this->health = 100.0f; // Default health

    this->playerTexture = loadPNGTexture("src/assets/UndeathPlayerWithGun.png");
}

void Player::draw()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, playerTexture);
    glBegin(GL_QUADS);
        /*glTexCoord2f(0.0f, 0.0f);*/ glVertex2f(x - width / 2, y - height / 2);
        /*glTexCoord2f(1.0f, 0.0f);*/ glVertex2f(x + width / 2, y - height / 2);
        /*glTexCoord2f(1.0f, 1.0f);*/ glVertex2f(x + width / 2, y + height / 2);
        /*glTexCoord2f(0.0f, 1.0f);*/ glVertex2f(x - width / 2, y + height / 2);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void Player::move(float dx, float dy) 
{
    this->x += dx;
    this->y += dy;
}
