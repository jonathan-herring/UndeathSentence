#include "player.h"

class MovementHandler {
public:
    MovementHandler();
    void update(float deltaTime); // Update the position based on the elapsed time
    void keyPressed(unsigned char key, int x, int y);
    void keyUp(unsigned char key, int x, int y);

private:
    bool upPressed, downPressed, leftPressed, rightPressed;
    float speed;
};