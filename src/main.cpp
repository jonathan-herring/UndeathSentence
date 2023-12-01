#include "player.h"
#include "zombie.h"

#include <GL/glut.h>

Player player;
Zombie zombie;

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
    if(player.x > zombie.x){
        zombie.move(0.0075f, 0);
    }else if(player.x =< zombie.x){
        zombie.move(-0.0075f, 0);
    }
    if(player.y > zombie.y){
        zombie.move(0, 0.0075f);
    }else if(player.y =< zombie.y){
        zombie.move(0, -0.0075f);
    }
    
    zombie.draw();
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
            player.move(0, 0.01f);
            break;
        case 's':
            player.move(0, -0.01f);
            break;
        case 'a':
            player.move(-0.01f, 0);
            break;
        case 'd':
            player.move(0.01f, 0);
            break;
    }
}

