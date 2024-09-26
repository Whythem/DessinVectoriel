//
// Created by mathi on 11/09/2024.
//

#include "Cercle.h"

Cercle::Cercle(int x, int y, int rayon, int z, std::string couleur, int transparence) : Point(int x, int y, int z, std::string couleur, int transparence) {
    this->rayon = rayon;
};

Cercle::Cercle(int x, int y, int rayon, std::string couleur, int transparence) : Point(int x, int y, std::string couleur, int transparence) {
    this->rayon = rayon;
};

Cercle::~Cercle() {

};