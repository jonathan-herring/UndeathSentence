#include <GL/glut.h>


void display(); // Display callback
void reshape(int, int); // Reshape callback

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0); // If we ever want to chang the background color
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(200, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Undeath Sentence");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    
    init();

    glutMainLoop(); // Takes care of all interactions with program and calls callback functions

    return 0;
}

void display() // Updates display
{
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers(); // Displays the frame buffer on the screen
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 40.0, 0.0, 40.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

