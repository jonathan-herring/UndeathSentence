// UI.h change meeeee

#ifndef UI_H
#define UI_H

class UI {
public:
    UI();
    void update(float deltaTime);
    void render();
    void setRound(int round);
    void setHealth(float health);
    void setGameOver(bool isGameOver);

private:
    int round;
    float health;
    float countdownTimer;
    bool gameOver;

    void renderHealthBar();
    void renderRound();
    void renderCountdown();
    void renderGameOverScreen();
};

#endif
