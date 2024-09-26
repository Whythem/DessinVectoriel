//
// Created by mathi on 11/09/2024.
//

#include "Point.h"

using namespace std;

Point :: Point(int x, int y, int z, string couleur, int transparence) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->couleur = couleur;
    this->transparence = transparence;
};

Point :: Point(int x, int y, string couleur, int transparence) {
    this->x = x;
    this->y = y;
    this->z = 0;
    this->couleur = couleur;
    this->transparence = transparence;
};

Point :: ~Point() {

};
