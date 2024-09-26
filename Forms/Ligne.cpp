//
// Created by mathi on 11/09/2024.
//

#include "Ligne.h"

using namespace std;


Ligne::Ligne(int x, int y, int Xbis, int Ybis, std::string couleur, int transparence, int z) : Point(x, y, couleur, transparence, z) {
    this->Xbis = Xbis;
    this->Ybis = Ybis;
};

void Ligne::draw(CImage* image) {
    int dx = abs(Xbis - x);
    int dy = abs(Ybis - y);
    int sx = (x < Xbis) ? 1 : -1;
    int sy = (y < Ybis) ? 1 : -1;
    int err = dx - dy;

    int currX = x;
    int currY = y;

    while (true) {
        // Check if the current point is within bounds of the image
        if (currX >= 0 && currX < image->getLigne(0)->size() && currY >= 0 && currY < image->size()) {
            // Get the pixel at the current point (currX, currY)
            CPixel* pixel = image->getPixel(currX, currY);
            // Set the pixel color to red (for now, using red as default)
            pixel->RGB(255, 0, 0);  // Red color
        }

        // If the current point is the end point, break
        if (currX == Xbis && currY == Ybis) {
            break;
        }

        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            currX += sx;
        }
        if (e2 < dx) {
            err += dx;
            currY += sy;
        }
    }
}

Ligne :: ~Ligne() {
};