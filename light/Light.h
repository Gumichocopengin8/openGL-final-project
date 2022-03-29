//
// Created by Keita Nonaka on 2019-04-28.
//

#ifndef PROJECT_LIGHT_H
#define PROJECT_LIGHT_H


class Light {
private:
  static constexpr float diffuse[4]{0.3, 0.3, 0.3, 0.3};
  static constexpr float specular[4]{1.3, 1.3, 1.3,1.3};
  static constexpr float ambient[4]{0.65, 0.65, 0.65, 0.65};
  static constexpr float spotDirection[3]{};

public:
  float position[4]{0, 0, 0, 1.0}; // TODO: getter setter

  explicit Light() = default;

  void ApplyLight();
};


#endif //PROJECT_LIGHT_H
