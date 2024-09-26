//
// Created by mathi on 26/09/2024.
//

#include "CarreS.h"

CarreS::CarreS(int x, int y, int z, int cote, std::string couleur, std::string couleurInterieur, int transparence) : RectangleS(x, y, z, cote, cote, couleur, couleurInterieur, transparence) {

}

CarreS::CarreS(int x, int y, int cote, std::string couleur, std::string couleurInterieur, int transparence) : RectangleS(x, y, cote, cote, couleur, couleurInterieur, transparence) {

}

CarreS::~CarreS() {

}
