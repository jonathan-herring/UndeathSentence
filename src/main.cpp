#include <GL/glut.h>



void display(); // Display callback function



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(200, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Undeath Sentence");
    glutDisplayFunc(display); // Argument display is a callback function that updates the display

    glutMainLoop(); // Takes care of all interactions with program and calls callback functions

    return 0;
}



void display() // Updates display
{
    glutSwapBuffers(); // Displays the frame buffer on the screen
}

