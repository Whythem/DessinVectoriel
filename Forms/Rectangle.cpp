//
// Created by mathi on 11/09/2024.
//

#include "Rectangle.h"

Rectangle::Rectangle(int x, int y, int z, int longueur, int largeur, std::string couleur, int transparence) : Point(x, y, z, couleur, transparence) {
    this->longueur = longueur;
    this->largeur = largeur;
}

Rectangle::Rectangle(int x, int y, int longueur, int largeur, std::string couleur, int transparence) : Point(x, y, couleur, transparence) {
    this->longueur = longueur;
    this->largeur = largeur;
}

Rectangle::~Rectangle() {

}

