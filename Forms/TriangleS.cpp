//
// Created by mathi on 26/09/2024.
//

#include "TriangleS.h"

TriangleS::TriangleS(int x, int y, int x2, int y2, int x3, int y3, std::string couleur, std::string couleurInterieur, int transparence, int z) : Triangle(x, y, x2, y2, x3, y3, couleur, transparence, z) {
    this->couleurInterieur = couleurInterieur;
}

void TriangleS::draw(CImage* image) {

};

TriangleS::~TriangleS() {
    
}
