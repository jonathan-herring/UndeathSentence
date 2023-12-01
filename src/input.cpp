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
    
    if (upPressed) dy -= speed * deltaTime;
    if (downPressed) dy += speed * deltaTime;
    if (leftPressed) dx -= speed * deltaTime;
    if (rightPressed) dx += speed * deltaTime;

    if ((upPressed || downPressed) && (leftPressed || rightPressed)) {
        float diagonalSpeed = speed / sqrt(2.0f); // Normalize speed for diagonal movement
        dx *= diagonalSpeed;
        dy *= diagonalSpeed;
    }

    player.move(dx, dy);
}