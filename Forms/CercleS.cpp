//
// Created by mathi on 11/09/2024.
//

#include "CercleS.h"


CercleS::CercleS(int x, int y, int rayon, std::string couleur, std::string couleurInterieur, int transparence, int z) : Cercle(x, y, rayon, couleur, transparence, z) {
    this->couleurInterieur = couleurInterieur;
}

CercleS::~CercleS() {

}
