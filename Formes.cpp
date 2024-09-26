//
// Created by mathi on 26/09/2024.
//

#include <fstream>
#include "Formes.h"

Formes::Formes(std::string vectorFile, std::string nameFileBmp, float zoom) {
    this->zoom = zoom;
    this->nameFileBmp = nameFileBmp;
}

Formes::~Formes() {

}


