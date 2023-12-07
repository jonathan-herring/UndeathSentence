#include "ui.h"

#include <GL/glut.h>
#include <cstdio>


UI::UI() : round(1), health(100), countdownTimer(15.0f), gameOver(false) {}

void UI::update(float deltaTime) {
    // Update countdown timer
    if (countdownTimer > 0) {
        countdownTimer -= deltaTime;
    } else {
        countdownTimer = 15;
    }
}

void UI::render() {
    // Render different UI components
    if (!gameOver) {
        renderHealthBar();
        renderRound();
        renderCountdown();
    } else {
        renderGameOverScreen();
    }
}

void UI::setRound(int round) {
    this->round = round;
}

void UI::setHealth(float health) {
    this->health = health;
}

void UI::setGameOver(bool isGameOver) {
    gameOver = isGameOver;
}

void UI::renderHealthBar() // 20 total health blocks, each representing 5 HP
{
    int healthBlocks = static_cast<int>(health) / 5;

    float topY = 0.86;
    float bottomY = 0.82;

    for (int i = 0; i < healthBlocks; i++)
    {
        float leftX = 0.05 + ((float)i * 0.045);
        float rightX = leftX + 0.044;

        glColor3f(1.0f, 0.0f, 0.0f); // Set color to red
        glBegin(GL_QUADS);
            glVertex2f(leftX, bottomY); // Bottom left
            glVertex2f(rightX, bottomY); // Bottom right
            glVertex2f(rightX, topY); // Top right
            glVertex2f(leftX, topY); // Top left
        glEnd();
        glColor3f(0.0f, 0.0f, 0.0f); // Set color to black
    }

}

void UI::renderRound() // Code to render the current round
{
    char roundText[20];
    std::sprintf(roundText, "Round: %d", this->round);

    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(0.05, 0.90);

    for (char* c = roundText; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }
}

void UI::renderCountdown() // Code to render the countdown timer
{
    int secondsLeft = static_cast<int>(countdownTimer);
    char roundText[20];
    std::sprintf(roundText, "More in %d seconds", secondsLeft);

    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(0.70, 0.90);

    for (char* c = roundText; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }
}

void UI::renderGameOverScreen() // Code to render the game over screen
{
    
}
