//
// Created by mathi on 11/09/2024.
//

#include "CercleS.h"

CercleS::CercleS(int x, int y, int rayon, int z, std::string couleur, std::string couleurInterieur, int transparence) : Cercle(int x, int y, int rayon, int z, std::string couleur, int transparence) {
    this->couleurInterieur = couleurInterieur;
}

CercleS::CercleS(int x, int y, int rayon, std::string couleur, std::string couleurInterieur, int transparence) : Cercle(int x, int y, int rayon, std::string couleur, int transparence) {
    this->couleurInterieur = couleurInterieur;
}

CercleS::~CercleS() {

}
