//
// Created by mathi on 11/09/2024.
//

#include "Cercle.h"


Cercle::Cercle(int x, int y, int rayon, std::string couleur, int transparence, int z) : Point(x, y, couleur, transparence, z) {
    this->rayon = rayon;
};

Cercle::~Cercle() {

};