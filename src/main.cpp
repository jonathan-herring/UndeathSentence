#include "game.h"

#include <GL/glut.h>

Game game;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    game.render();
    glutSwapBuffers();
}

void update(int value)
{
    game.update(0.01667f);
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void handleKeypress(unsigned char key, int x, int y) {
    game.handleKeyPress(key, x, y);
}

void handleKeyUp(unsigned char key, int x, int y) {
    game.handleKeyUp(key, x, y);
}

void handleMousePress(int button, int state, int x, int y) 
{
    game.handleMousePress(button, state, x, y);
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 1, 0, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(560, 140);
    glutInitWindowSize(800, 800); // Set the window size
    glutCreateWindow("Undeath Sentence"); // Set the window title

    game.init();

    glutDisplayFunc(display);
    // glutIdleFunc(display); // Register display as the idle function as well
    glutReshapeFunc(reshape);
    glutKeyboardFunc(handleKeypress);
    glutKeyboardUpFunc(handleKeyUp);
    glutMouseFunc(handleMousePress);

    glutTimerFunc(16, update, 0);

    glutMainLoop();

    return 0;
}