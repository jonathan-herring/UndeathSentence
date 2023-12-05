#include "input.h"

#include <GL/glut.h>
#include <math.h>

InputHandler::InputHandler(Player& player, std::vector<Bullet>& bullets) : player(player), bullets(bullets) {}

void InputHandler::keyPressed(unsigned char key, int x, int y) {
    switch (key) {
        case 'w': upPressed = true; break;
        case 's': downPressed = true; break;
        case 'a': leftPressed = true; break;
        case 'd': rightPressed = true; break;
        // Add other keys if needed
    }
}

void InputHandler::keyUp(unsigned char key, int x, int y) {
    switch (key) {
        case 'w': upPressed = false; break;
        case 's': downPressed = false; break;
        case 'a': leftPressed = false; break;
        case 'd': rightPressed = false; break;
        // Add other keys if needed
    }
}

void InputHandler::update(float deltaTime) { // Only handles movement of players and bullets based on input
    float dx = 0, dy = 0;
    float speed = player.speed;

    float positionChange = speed * deltaTime;

    if ((upPressed))
        dy += speed;
    if ((downPressed))
        dy -= speed;
    if ((leftPressed))
        dx -= speed;
    if ((rightPressed))
        dx += speed;

    if ((upPressed || downPressed) && (leftPressed || rightPressed)) {
        float diagNormConstant = 1 / std::sqrt(2.0f);
        dx *= diagNormConstant;
        dy *= diagNormConstant;
    }
    dx *= deltaTime;
    dy *= deltaTime;

    if (dy < 0 && (player.y - positionChange - player.height / 2 < 0))
        dy = 0;
    else if (dy > 0 && (player.y + positionChange + player.height / 2 > 0.8))
        dy = 0;
    if (dx < 0 && (player.x - positionChange - player.width / 2 < 0))
        dx = 0;
    else if (dx > 0 && (player.x + positionChange + player.width / 2 > 1)) {
        dx = 0;
    }

    player.move(dx, dy);

    for (size_t i = 0; i < this->bullets.size(); i++)
    {
        this->bullets.at(i).move(deltaTime);
    }
}

void InputHandler::mousePressed(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        float gameX = (x * (1.0f / 800.0f));
        float gameY = (1 - (y * (1.0f / 800.0f)));
        bullets.push_back(Bullet(player.x, player.y, gameX, gameY));
    }
}