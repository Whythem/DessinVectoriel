//
// Created by mathi on 11/09/2024.
//

#include "Point.h"

using namespace std;


Point :: Point(int x, int y, string couleur, int transparence, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->couleur = couleur;
    this->transparence = transparence;
};

int Point::getZ() {
    return this->z;
}

Point :: ~Point() {

};
