//
// Created by mathi on 11/09/2024.
//

#include "Rectangle.h"


Rectangle::Rectangle(int x, int y, int longueur, int largeur, std::string couleur, int transparence, int z) : Point(x, y, couleur, transparence, z) {
    this->longueur = longueur;
    this->largeur = largeur;
}

Rectangle::~Rectangle() {

}

