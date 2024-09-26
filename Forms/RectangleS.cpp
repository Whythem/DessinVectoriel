//
// Created by mathi on 26/09/2024.
//

#include "RectangleS.h"


RectangleS::RectangleS(int x, int y, int longueur, int largeur, std::string couleur, std::string couleurInterieur, int transparence, int z) : Rectangle(x, y, longueur, largeur, couleur, transparence, z) {
    this->couleurInterieur = couleurInterieur;
}

RectangleS::~RectangleS() {

}
