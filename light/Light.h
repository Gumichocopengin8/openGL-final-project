//
// Created by Keita Nonaka on 2019-04-28.
//

#ifndef PROJECT_LIGHT_H
#define PROJECT_LIGHT_H


class Light {
private:
    float diffuse[4];
    float specular[4];
    float ambient[4];
    float position[4];
    float spotDirrection[3];
public:
    Light();
    void ApplyLight();
};


#endif //PROJECT_LIGHT_H
