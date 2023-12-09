#ifndef UI_H
#define UI_H

class UI {
public:
    UI();
    void update(float deltaTime);
    void render();
    void setRound(int round);
    void setHealth(float health);
    bool getStartScreen();
    void setStartScreen(bool start);
    void setGameOver(bool isGameOver);
    void setZombiesKilled(int zombiesKilled);

private:
    int round;
    float health;
    float countdownTimer;
    bool startScreen;
    bool gameOver;

    int zombiesKilled;
    int score;

    void renderHealthBar();
    void renderRound();
    void renderScore();
    void renderZombiesKilled();
    void renderCountdown();
    void renderStartScreen();
    void renderGameOverScreen();
};

#endif
