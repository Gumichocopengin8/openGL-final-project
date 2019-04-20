#include <cstdlib>
#include <GLUT/glut.h>

#include "main.h"
#include "camera/Camera.h"
#include "cube/Cube.h"
#include "mouse/mouse.h"
#include "keyboard/keyboard.h"



void display() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    cameraPtr->refresh();

    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 15; ++j) {
            Cube(i, 0, j).draw();
        }
    }

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
    glutInitWindowSize(400, 400);
    glutCreateWindow("Computer Graphic project");

    Camera camera(0, 2, 0, 0, 0, 0);
    cameraPtr = &camera;

    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutPassiveMotionFunc(mouseMotion);
    glutKeyboardFunc(keyboard);
    glEnable(GL_DEPTH_TEST);
    glutWarpPointer(200, 200);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();

    return 0;
}