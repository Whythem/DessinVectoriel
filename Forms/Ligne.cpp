//
// Created by mathi on 11/09/2024.
//

#include "Ligne.h"

using namespace std;

Ligne::Ligne(int x, int y, int Xbis, int Ybis, int z, std::string couleur, int transparence) : Point(x, y, z, couleur, transparence) {
    this->Xbis = Xbis;
    this->Ybis = Ybis;
};

Ligne::Ligne(int x, int y, int Xbis, int Ybis, std::string couleur, int transparence) : Point(x, y, couleur, transparence) {
    this->Xbis = Xbis;
    this->Ybis = Ybis;
};

Ligne :: ~Ligne() {
};