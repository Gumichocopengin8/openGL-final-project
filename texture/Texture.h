//
// Created by Keita Nonaka on 2019-04-20.
//

#ifndef PROJECT_TEXTURE_H
#define PROJECT_TEXTURE_H


class Texture {
private:
    float ambient[4];
    float diffuse[4];
    float specular[4];
    float shininess[4];
public:
    explicit Texture();

    void apply();

    void grass();

    void treeTrunk();

    void treeLeaves();

    void ground();

    void snow();

    void water();

    void cloud();

    void orange();

    void lawngreen();

    void sand();

    void rock();
};


#endif //PROJECT_TEXTURE_H
