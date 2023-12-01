#include "input.h"

#include <math.h>

void MovementHandler::keyPressed(unsigned char key, int x, int y) {
    switch (key) {
        case 'w': upPressed = true; break;
        case 's': downPressed = true; break;
        case 'a': leftPressed = true; break;
        case 'd': rightPressed = true; break;
        // Add other keys if needed
    }
}

void MovementHandler::keyUp(unsigned char key, int x, int y) {
    switch (key) {
        case 'w': upPressed = false; break;
        case 's': downPressed = false; break;
        case 'a': leftPressed = false; break;
        case 'd': rightPressed = false; break;
        // Add other keys if needed
    }
}

void MovementHandler::update(float deltaTime) {
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
        float diagNormConstant = 1 / sqrt(2.0f);
        dx *= diagNormConstant;
        dy *= diagNormConstant;
    }
    dx *= deltaTime;
    dy *= deltaTime;

    if (dy < 0 && (player.y - positionChange - player.height / 2 < 0))
        dy = 0;
    else if (dy > 0 && (player.y + positionChange + player.height / 2 > 1))
        dy = 0;
    if (dx < 0 && (player.x - positionChange - player.width / 2 < 0))
        dx = 0;
    else if (dx > 0 && (player.x + positionChange + player.width / 2 > 1)) {
        dx = 0;
    }

    player.move(dx, dy);
}