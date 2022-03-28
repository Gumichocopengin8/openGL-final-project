//
// Created by Fabien Delattre on 2019-04-19.
//

#ifndef PROJECT_WINDOW_H
#define PROJECT_WINDOW_H

class Window {
private:
  int default_width;
  int default_height;
  int width;
  int height;
public:
  explicit Window(int default_width, int default_height);

  void setWidth(int width);

  void setHeight(int height);

  [[nodiscard]] int getWidth() const;

  [[nodiscard]] int getHeight() const;
};


#endif //PROJECT_WINDOW_H
