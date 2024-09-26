//
// Created by mathi on 26/09/2024.
//

#include "Carre.h"

Carre::Carre(int x, int y, int cote, int z, std::string couleur, int transparence) : Rectangle(x, y, z, cote, cote, couleur, transparence) {

}

Carre::Carre(int x, int y, int cote, std::string couleur, int transparence) : Rectangle(x, y, cote, cote, couleur, transparence) {

}

Carre::~Carre() {

}

