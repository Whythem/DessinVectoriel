//
// Created by mathi on 11/09/2024.
//

#include "Ligne.h"

using namespace std;


Ligne::Ligne(int x, int y, int Xbis, int Ybis, std::string couleur, int transparence, int z) : Point(x, y, couleur, transparence, z) {
    this->Xbis = Xbis;
    this->Ybis = Ybis;
};

Ligne :: ~Ligne() {
};