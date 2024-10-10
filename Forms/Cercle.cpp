//
// Created by mathi on 11/09/2024.
//

#include "Cercle.h"


Cercle::Cercle(int x, int y, int rayon, std::string couleur, int transparence, int z) : Point(x, y, couleur, transparence, z) {
    this->rayon = rayon;
};

void Cercle::draw(CImage* image) {
    int x0 = x;  // Center of the circle (x0, y0)
    int y0 = y;
    int r = rayon;  // Radius of the circle

    int x = 0;
    int y = r;
    int d = 3 - 2 * r;  // Decision parameter

    //TODO SET color

    // Function to set the eight symmetrical points of the circle
    auto setPixelSymmetry = [&](int x, int y) {
        if (x0 + x >= 0 && x0 + x < image->getLigne(0)->size() &&
            y0 + y >= 0 && y0 + y < image->size()) {
            CPixel* pixel = image->getPixel(x0 + x, y0 + y);
            this->colorPixel(pixel, couleur, transparence);
        }
        if (x0 - x >= 0 && x0 - x < image->getLigne(0)->size() &&
            y0 + y >= 0 && y0 + y < image->size()) {
            CPixel* pixel = image->getPixel(x0 - x, y0 + y);
            this->colorPixel(pixel, couleur, transparence);
        }
        if (x0 + x >= 0 && x0 + x < image->getLigne(0)->size() &&
            y0 - y >= 0 && y0 - y < image->size()) {
            CPixel* pixel = image->getPixel(x0 + x, y0 - y);
            this->colorPixel(pixel, couleur, transparence);
        }
        if (x0 - x >= 0 && x0 - x < image->getLigne(0)->size() &&
            y0 - y >= 0 && y0 - y < image->size()) {
            CPixel* pixel = image->getPixel(x0 - x, y0 - y);
            this->colorPixel(pixel, couleur, transparence);
        }
        if (x0 + y >= 0 && x0 + y < image->getLigne(0)->size() &&
            y0 + x >= 0 && y0 + x < image->size()) {
            CPixel* pixel = image->getPixel(x0 + y, y0 + x);
            this->colorPixel(pixel, couleur, transparence);
        }
        if (x0 - y >= 0 && x0 - y < image->getLigne(0)->size() &&
            y0 + x >= 0 && y0 + x < image->size()) {
            CPixel* pixel = image->getPixel(x0 - y, y0 + x);
            this->colorPixel(pixel, couleur, transparence);
        }
        if (x0 + y >= 0 && x0 + y < image->getLigne(0)->size() &&
            y0 - x >= 0 && y0 - x < image->size()) {
            CPixel* pixel = image->getPixel(x0 + y, y0 - x);
            this->colorPixel(pixel, couleur, transparence);
        }
        if (x0 - y >= 0 && x0 - y < image->getLigne(0)->size() &&
            y0 - x >= 0 && y0 - x < image->size()) {
            CPixel* pixel = image->getPixel(x0 - y, y0 - x);
            this->colorPixel(pixel, couleur, transparence);
        }
    };

    // Start plotting the circle
    while (y >= x) {
        // Plot the points in all 8 octants
        setPixelSymmetry(x, y);

        x++;

        // Update decision parameter based on the previous value
        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        } else {
            d = d + 4 * x + 6;
        }

        // Plot the symmetrical points
        setPixelSymmetry(x, y);
    }
};

Cercle::~Cercle() {

};