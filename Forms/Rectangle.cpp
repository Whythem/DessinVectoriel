//
// Created by mathi on 11/09/2024.
//

#include "Rectangle.h"

#include "Ligne.h"


Rectangle::Rectangle(int x, int y, int longueur, int largeur, std::string couleur, int transparence, int z) : Point(x, y, couleur, transparence, z) {
    this->longueur = longueur;
    this->largeur = largeur;
}

void Rectangle::draw(CImage* image) {
    int x2 = x + longueur;
    int y2 = y + largeur;

    Ligne hautDroit(x, y, x2, y, couleur, transparence, z);
    Ligne basDroit(x, y2, x2, y2, couleur, transparence, z);
    Ligne gaucheBas(x, y, x, y2, couleur, transparence, z);
    Ligne droiteBas(x2, y, x2, y2, couleur, transparence, z);

    hautDroit.draw(image);
    basDroit.draw(image);
    gaucheBas.draw(image);
    droiteBas.draw(image);
}

Rectangle::~Rectangle() {

}

