//
// Created by Keita Nonaka on 2019-04-20.
//

#ifndef PROJECT_LIGHT_H
#define PROJECT_LIGHT_H


class Light {
public:
    GLfloat mat_ambient[];
    GLfloat mat_diffuse[];
    GLfloat mat_specular[];
    GLfloat mat_shininess[];

    Light();
    void apply();
    void grass();
    void treeTrunk();
    void treeLeaves();
    void ground();
};


#endif //PROJECT_LIGHT_H
