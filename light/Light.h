//
// Created by Keita Nonaka on 2019-04-28.
//

#ifndef PROJECT_LIGHT_H
#define PROJECT_LIGHT_H


class Light {
private:
    GLfloat diffuse[4];
    GLfloat specular[4];
    GLfloat ambient[4];
    GLfloat position[4];
public:
    Light();
    void ApplyLight();
};


#endif //PROJECT_LIGHT_H
