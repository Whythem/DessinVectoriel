//
// Created by mathi on 26/09/2024.
//

#include "Triangle.h"

#include "Ligne.h"

Triangle::Triangle(int x, int y, int x2, int y2, int x3, int y3, std::string couleur, int transparence, int z) : Point(x, y, couleur, transparence, z) {
    this->x2 = x2;
    this->y2 = y2;
    this->x3 = x3;
    this->y3 = y3;
}

void Triangle::draw(CImage* image) {
    Ligne x1ToX2(x, y, x2, y2, couleur, transparence);
    Ligne x1ToX3(x, y, x3, y3, couleur, transparence);
    Ligne x2ToX3(x2, y2, x3, y3, couleur, transparence);

    x1ToX2.draw(image);
    x1ToX3.draw(image);
    x2ToX3.draw(image);
};

Triangle::~Triangle() {

}

