#include <GL/glut.h>


void display(); // Display callback
// Make a reshape callback function if worried about user resizing the window

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
    glutDisplayFunc(display); // Argument display is a callback function that updates the display
    
    init();

    glutMainLoop(); // Takes care of all interactions with program and calls callback functions

    return 0;
}

void display() // Updates display
{
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers(); // Displays the frame buffer on the screen
}

