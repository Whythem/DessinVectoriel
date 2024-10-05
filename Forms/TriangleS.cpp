//
// Created by mathi on 26/09/2024.
//

#include "TriangleS.h"

TriangleS::TriangleS(int x, int y, int x2, int y2, int x3, int y3, std::string couleur, std::string couleurInterieur, int transparence, int z) : Triangle(x, y, x2, y2, x3, y3, couleur, transparence, z) {
    this->couleurInterieur = couleurInterieur;
}

void TriangleS::draw(CImage* image) {
    //TODO set couleurInterieur
    int x1 = x, y1 = y;
    int x2 = this->x2, y2 = this->y2;
    int x3 = this->x3, y3 = this->y3;

    if (y1 > y2) {
        std::swap(x1, x2);
        std::swap(y1, y2);
    }
    if (y1 > y3) {
        std::swap(x1, x3);
        std::swap(y1, y3);
    }
    if (y2 > y3) {
        std::swap(x2, x3);
        std::swap(y2, y3);
    }

    for (int y = y1; y <= y3; ++y) {
        int xStart, xEnd;

        if (y < y2) {
            xStart = x1 + (y - y1) * (x2 - x1) / (y2 - y1);
            xEnd = x1 + (y - y1) * (x3 - x1) / (y3 - y1);
        } else {
            xStart = x2 + (y - y2) * (x3 - x2) / (y3 - y2);
            xEnd = x1 + (y - y1) * (x3 - x1) / (y3 - y1);
        }

        if (xStart > xEnd) std::swap(xStart, xEnd);

        for (int x = xStart; x <= xEnd; ++x) {
            if (x >= 0 && x < image->getLigne(0)->size() &&
                y >= 0 && y < image->size()) {
                CPixel* pixel = image->getPixel(x, y);
                pixel->RGB(255, 0, 0);
                }
        }
    }

    Triangle::draw(image);
};

TriangleS::~TriangleS() {
    
}
