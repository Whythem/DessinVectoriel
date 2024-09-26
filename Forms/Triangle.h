//
// Created by mathi on 26/09/2024.
//

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h"

class Triangle: public Point{
  private:

  protected:
    int x2, y2, x3, y3;

  public:
    Triangle(int x, int y, int x2, int y2, int x3, int y3, std::string couleur, int transparence, int z = 0);
    ~Triangle();
};



#endif //TRIANGLE_H
