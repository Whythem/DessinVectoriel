//
// Created by mathi on 26/09/2024.
//

#include "RectangleS.h"

RectangleS::RectangleS(int x, int y, int z, int longueur, int largeur, std::string couleur, std::string couleurInterieur, int transparence) : Rectangle(x, y, z, longueur, largeur, couleur, transparence) {
    this->couleurInterieur = couleurInterieur;
}

RectangleS::RectangleS(int x, int y, int longueur, int largeur, std::string couleur, std::string couleurInterieur, int transparence) : Rectangle(x, y, longueur, largeur, couleur, transparence) {
    this->couleurInterieur = couleurInterieur;
}

RectangleS::~RectangleS() {

}
