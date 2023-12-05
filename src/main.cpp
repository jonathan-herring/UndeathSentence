#include "player.h"
#include "zombie.h"
#include "input.h"
#include "bullet.h"

#include <GL/glut.h>

Player player;
std::vector<Bullet> bullets;
InputHandler controls(player, bullets);
Zombie zombie1(player, 100, 5, 1);
Zombie zombie2(player, 100, 5, 1);
Zombie zombie3(player, 100, 5, 1);

void display();
void reshape(int, int);
void update(int);
void handleKeypress(unsigned char, int, int);
void handleKeyUp(unsigned char, int, int);
void handleMousePress(int, int, int, int);

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0); // Background color
}





int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Undeath Sentence");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(handleKeypress);
    glutKeyboardUpFunc(handleKeyUp);
    glutMouseFunc(handleMousePress);
    glutTimerFunc(16, update, 0);
    


    glutMainLoop();

    return 0;
}



void drawBackground();

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Game logic updates
    controls.update(0.01667);

    zombie1.move(player.x, player.y);
    zombie2.move(player.x, player.y);
    zombie3.move(player.x, player.y);

    for (auto bullet : bullets) {
        bullet.move(0.01667);
    }

    // Render game to screen
    drawBackground();

    player.draw();
    
    zombie1.draw();
    zombie2.draw();
    zombie3.draw();

    for (auto bullet : bullets) {
        bullet.draw();
    }

    glutSwapBuffers();
}

void drawBackground()
{
    glBegin(GL_QUADS);
        glColor3ub(19,23,25);
        glVertex2f(0, 0);
        glVertex2f(1, 0);
        glVertex2f(1, 0.8);
        glVertex2f(0, 0.8);
        glColor3ub(255,255,255);
    glEnd();
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 1, 0, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}


void update(int value)
{
    glutPostRedisplay();
    glutTimerFunc(33, update, 0);
}


void handleKeypress(unsigned char key, int x, int y)
{
    controls.keyPressed(key, x, y);
}

void handleKeyUp(unsigned char key, int x, int y)
{
    controls.keyUp(key, x, y);
}

void handleMousePress(int button, int state, int x, int y)
{
    controls.mousePressed(button, state, x, y);
}