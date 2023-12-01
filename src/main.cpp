#include "player.h"
#include "zombie.h"
#include "input.h"

#include <GL/glut.h>

Player player;
MovementHandler movement(player);
Zombie zombie1(player);
Zombie zombie2(player);
Zombie zombie3(player);

void display(); // Display callback
void reshape(int, int); // Reshape callback
void update(int);
void handleKeypress(unsigned char, int, int); // Keypress callback
void handleKeyUp(unsigned char, int, int);

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0); // If we ever want to chang the background color
}





int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    // glutInitWindowPosition(200, 100);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Undeath Sentence");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(handleKeypress);
    glutKeyboardUpFunc(handleKeyUp);
    glutTimerFunc(16, update, 0);
    


    glutMainLoop(); // Takes care of all interactions with program and calls callback functions

    return 0;
}





void display() // Updates display
{
    glClear(GL_COLOR_BUFFER_BIT);
    movement.update(0.01667);
    player.draw();

    //zombie movement towards player
    zombie1.move(player.x, player.y);
    zombie2.move(player.x, player.y);
    zombie3.move(player.x, player.y);
    
    zombie1.draw();
    zombie2.draw();
    zombie3.draw();
    glutSwapBuffers(); // Displays the frame buffer on the screen
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
    movement.keyPressed(key, x, y);
}

void handleKeyUp(unsigned char key, int x, int y)
{
    movement.keyUp(key, x, y);
}