//
// Created by mathi on 11/09/2024.
//

#include "Ligne.h"

using namespace std;


Ligne::Ligne(int x, int y, int Xbis, int Ybis, std::string couleur, int transparence, int z) : Point(x, y, couleur, transparence, z) {
    this->Xbis = Xbis;
    this->Ybis = Ybis;
};

void Ligne::draw(CImage* image) {
    int lengthX = abs(Xbis - x);
    int lengthY = abs(Ybis - y);
    int axeX = x < Xbis ? 1 : -1;
    int axeY = y < Ybis ? 1 : -1;

    int pente = lengthX - lengthY;

    int currentX = x;
    int currentY = y;

    while (true) {
        std::cout << currentX << "," << currentY << std::endl;
        CPixel* pixel = image->getPixel(currentX, currentY);

        //TODO Gérer couleur
        pixel->RGB(255, 255, 255);

        if (currentX == Xbis && currentY == Ybis) break;

        int pente2 = 2 * pente;

        if (pente2 > -lengthY) {
            pente -= lengthY;
            currentX += axeX;
        }

        if (pente2 < lengthX) {
            pente += lengthX;
            currentY += axeY;
        }
    }
}

Ligne :: ~Ligne() {
};