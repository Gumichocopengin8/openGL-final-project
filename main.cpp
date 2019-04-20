#include <cstdlib>
#include <cmath>
#include <GLUT/glut.h>

#include "main.h"

#include "camera/Camera.h"
#include "block/Block.h"
#include "mouse/mouse.h"
#include "keyboard/keyboard.h"
#include "player/Player.h"
#include "window/Window.h"

Player *playerPtr;
Window *windowPtr;

#define WINDOW_SIZE 400
int count = 0;

void display() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    playerPtr->camera.refresh();
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            for (int k = 0; k < 1; ++k) {
                Block(i, k, j).draw();
            }

        }
    }
    playerPtr->camera.idle(sin((float) count / 40), 0);
    glutSwapBuffers();
    glutPostRedisplay();
    count += 1;
}

void reshape(int w, int h) {
    glutWarpPointer(w/2, h/2);
    windowPtr->setWidth(w);
    windowPtr->setHeight(h);
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, (double) w / h, 1, 20);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {

    Window window(WINDOW_SIZE, WINDOW_SIZE);
    windowPtr = &window;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(WINDOW_SIZE, WINDOW_SIZE);
    glutCreateWindow("Terrain");

    Player player(Camera(0, 2, 0, 0, 0, 0));
    playerPtr = &player;

    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutPassiveMotionFunc(mouseMotion);
    glutKeyboardFunc(keyboard);
    glutWarpPointer(200, 200);
    glClearColor(0.439, 0.729, 0.988, 0.0);
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();

    return 0;
}