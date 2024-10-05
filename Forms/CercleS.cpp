//
// Created by mathi on 11/09/2024.
//

#include "CercleS.h"


CercleS::CercleS(int x, int y, int rayon, std::string couleur, std::string couleurInterieur, int transparence, int z) : Cercle(x, y, rayon, couleur, transparence, z) {
    this->couleurInterieur = couleurInterieur;
}

void CercleS::draw(CImage* image) {

    int x0 = x;
    int y0 = y;
    int r = rayon;


    for (int i = x0 - r; i <= x0 + r; ++i) {
        for (int j = y0 - r; j <= y0 + r; ++j) {
            if (i >= 0 && i < image->getLigne(0)->size() && j >= 0 && j < image->size()) {
                int dx = i - x0;
                int dy = j - y0;
                if (dx * dx + dy * dy <= r * r) {
                    CPixel* pixel = image->getPixel(i, j);
                    pixel->RGB(255, 0, 0);
                }
            }
        }
    }

    Cercle::draw(image);
};

CercleS::~CercleS() {

}
