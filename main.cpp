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

#include "biome/BiomeType.h"

// Ugly but GLUT is a C lib not C++ so not easy to do clean OOP...
Player *playerPtr;
Window *windowPtr;
World *worldPtr;

#define WINDOW_SIZE 512
int count = 0;
Light light;

void init() {

    light.ApplyLight();
}


void display() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    playerPtr->takeAction();
    playerPtr->camera.refresh(light);

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
    glutWarpPointer(w / 2, h / 2);
    windowPtr->setWidth(w);
    windowPtr->setHeight(h);
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, (double) w / h, 0.5, 60);
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

    Player player(Camera(0, 20, 0, 0, 0, 0));
    playerPtr = &player;
    init();
    glEnable(GL_CULL_FACE);
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutPassiveMotionFunc(mouseMotion);

    glutKeyboardFunc(keydown);
    glutKeyboardUpFunc(keyup);


    glutWarpPointer(200, 200);
    glClearColor(0.439, 0.729, 0.988, 0.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glShadeModel(GL_SMOOTH);

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glutMainLoop();

    return 0;
}
