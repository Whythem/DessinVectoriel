//
// Created by mathi on 11/09/2024.
//

#include "Point.h"

using namespace std;


Point :: Point(int x, int y, string couleur, int transparence, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->couleur = couleur;
    this->transparence = transparence;
};

int Point::getZ() {
    return this->z;
}

void Point::colorPixel(CPixel *pixel, std::string couleur, int transparence) {
    int newRed, newBlue, newGreen;
    int oldRed, oldBlue, oldGreen;;
    int red, blue, green;

    oldBlue = pixel->Blue();
    oldGreen = pixel->Green();
    oldRed = pixel->Red();

    if (couleur == "ROUGE") {
        newRed = 255;
        newBlue = 0;
        newGreen = 0;
    } else if (couleur == "BLEU") {
        newBlue = 255;
        newGreen = 0;
        newRed = 0;
    } else if (couleur == "VERT") {
        newGreen = 255;
        newRed = 0;
        newBlue = 0;
    } else if (couleur == "GOLD") {
        newRed = 255;
        newGreen = 215;
        newBlue = 0;
    } else if (couleur == "PURPLE") {
        newRed = 128;
        newGreen = 0;
        newBlue = 128;
    }else {
        newRed = 255;
        newBlue = 255;
        newGreen = 255;
    }

    red = (transparence * newRed + (100 - transparence) * oldRed) / 100;
    blue = (transparence * newBlue + (100 - transparence) * oldBlue) / 100;
    green = (transparence * newGreen + (100 - transparence) * oldGreen) / 100;

    pixel->RGB(red, green, blue);
}


void Point::draw(CImage* image) {
    if (x >= 0 && x < image->getLigne(0)->size() && y >= 0 && y < image->size()) {
        CPixel* pixel = image->getPixel(x, y);

        this->colorPixel(pixel, couleur, transparence);
    }
}

Point :: ~Point() {

};
