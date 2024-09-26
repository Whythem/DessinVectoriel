//
// Created by mathi on 11/09/2024.
//

#include "CercleS.h"

CercleS::CercleS(int x, int y, int rayon, int z, std::string couleur, std::string couleurInterieur, int transparence) : Cercle(x, y, rayon, z, couleur, transparence) {
    this->couleurInterieur = couleurInterieur;
}

CercleS::CercleS(int x, int y, int rayon, std::string couleur, std::string couleurInterieur, int transparence) : Cercle(x, y, rayon, couleur, transparence) {
    this->couleurInterieur = couleurInterieur;
}

CercleS::~CercleS() {

}
