#include "player.h"
#include "zombie.h"

#include <GL/glut.h>

Player player;
Zombie zombie1(player);
Zombie zombie2(player);
Zombie zombie3(player);

void display(); // Display callback
void reshape(int, int); // Reshape callback
void update(int);
void handleKeypress(unsigned char, int, int); // Keypress callback

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
    glutTimerFunc(60, update, 0);
    


    glutMainLoop(); // Takes care of all interactions with program and calls callback functions

    return 0;
}





void display() // Updates display
{
    glClear(GL_COLOR_BUFFER_BIT);
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
    switch (key)
    {
        case 'w':
            if (player.y + 0.01f + player.height / 2 <= 1)
            player.move(0, 0.01f);
            break;
        case 's':
            if (player.y - 0.01f - player.height / 2 >= 0)
            player.move(0, -0.01f);
            break;
        case 'a':
            if (player.x - 0.01f - player.width / 2 >= 0)
                player.move(-0.01f, 0);
            break;
        case 'd':
            if (player.x + 0.01f + player.height / 2 <= 1)
                player.move(0.01f, 0);
            break;
    }
}

