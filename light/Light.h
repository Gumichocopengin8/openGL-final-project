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

    float spotDirection[3];
public:
    float position[4];

    Light();

    void ApplyLight();
};


#endif //PROJECT_LIGHT_H
