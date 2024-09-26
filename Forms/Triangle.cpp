//
// Created by mathi on 26/09/2024.
//

#include "Triangle.h"

Triangle::Triangle(int x, int y, int x2, int y2, int x3, int y3, std::string couleur, int transparence, int z) : Point(x, y, couleur, transparence, z) {
    this->x2 = x2;
    this->y2 = y2;
    this->x3 = x3;
    this->y3 = y3;
}

Triangle::~Triangle() {

}

