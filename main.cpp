#include <cstdlib>
#include <GLUT/glut.h>

#include "cube/Cube.h"
#include "mouse/mouse.h"
#include "keyboard/keyboard.h"

#define WINDOW_SIZE 512

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    gluLookAt(eyex, eyey, eyez, 0, 0, 0, 0, 1, 0);

    Cube cube(0, 0, 0);
    cube.draw();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, (double) w / h, 1, 20);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(WINDOW_SIZE, WINDOW_SIZE);
    glutCreateWindow("Terrain");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glEnable(GL_DEPTH_TEST);

    glClearColor(1.0, 1.0, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();

    return 0;
}