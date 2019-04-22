//
// Created by Keita Nonaka on 2019-04-20.
//

#ifndef PROJECT_TEXTURE_H
#define PROJECT_TEXTURE_H


class Texture {
public:
    GLfloat mat_ambient[];
    GLfloat mat_diffuse[];
    GLfloat mat_specular[];
    GLfloat mat_shininess[];

    Texture();
    void apply();
    void grass();
    void treeTrunk();
    void treeLeaves();
    void ground();
};


#endif //PROJECT_TEXTURE_H
