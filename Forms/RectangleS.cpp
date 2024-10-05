//
// Created by mathi on 26/09/2024.
//

#include "RectangleS.h"


RectangleS::RectangleS(int x, int y, int longueur, int largeur, std::string couleur, std::string couleurInterieur, int transparence, int z) : Rectangle(x, y, longueur, largeur, couleur, transparence, z) {
    this->couleurInterieur = couleurInterieur;
}

void RectangleS::draw(CImage* image) {
    Rectangle::draw(image);

    int x2 = x + longueur;
    int y2 = y + largeur;

    for (int i = x + 1; i < x2; ++i) {
        for (int j = y + 1; j < y2; ++j) {
            CPixel* pixel = image->getPixel(i, j);

            //TODO gerer couleur
            pixel->RGB(255, 0, 0);
        }
    }
};

RectangleS::~RectangleS() {

}
