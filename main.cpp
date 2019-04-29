#include <cstdlib>
#include <cmath>
#include <GLUT/glut.h>

#include "main.h"

#include "camera/Camera.h"
//#include "chunk/Chunk.h"
#include "block/Block.h"
#include "light/Light.h"
#include "mouse/mouse.h"
#include "keyboard/keyboard.h"
#include "player/Player.h"
#include "window/Window.h"
#include "world/world.h"


// Ugly but GLUT is a C lib not C++ so not easy to do clean OOP...
Player *playerPtr;
Window *windowPtr;
World *worldPtr;

#define WINDOW_SIZE 400
int count = 0;

void init() {
    Light light;
    light.ApplyLight();
}

void display() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    //std::cout << int(playerPtr->camera.camera_x) / 16 << std::endl;
    glLoadIdentity();

    playerPtr->camera.refresh();

    /**
     * TODO: Getter for the player position
     */
    worldPtr->update(playerPtr->camera.camera_x, playerPtr->camera.camera_z);


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

    World world;
    worldPtr = &world;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(WINDOW_SIZE, WINDOW_SIZE);
    glutCreateWindow("Terrain");

    Player player(Camera(0, 2, 0, 0, 0, 0));
    playerPtr = &player;
    init();
    glEnable(GL_CULL_FACE);
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutPassiveMotionFunc(mouseMotion);
    glutKeyboardFunc(keyboard);
    glutWarpPointer(200, 200);
    glClearColor(0.439, 0.729, 0.988, 0.0);
    glEnable(GL_DEPTH_TEST);

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glutMainLoop();

    return 0;
}
