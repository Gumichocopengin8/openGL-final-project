//
// Created by Keita Nonaka on 2019-04-20.
//

#ifndef PROJECT_TEXTURE_H
#define PROJECT_TEXTURE_H


class Texture {
public:
    GLfloat mat_ambient[4];
    GLfloat mat_diffuse[4];
    GLfloat mat_specular[4];
    GLfloat mat_shininess[4];

    Texture();
    void apply();
    void grass();
    void treeTrunk();
    void treeLeaves();
    void ground();
};


#endif //PROJECT_TEXTURE_H
