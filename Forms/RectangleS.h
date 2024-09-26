//
// Created by mathi on 26/09/2024.
//

#ifndef RECTANGLES_H
#define RECTANGLES_H

#include "Rectangle.h"

class RectangleS : public Rectangle {
    private:

    protected:
        std::string couleurInterieur;

    public:
        RectangleS(int x, int y, int z, int longueur, int largeur, std::string couleur, std::string couleurInterieur, int transparence);
        RectangleS(int x, int y, int longueur, int largeur, std::string couleur, std::string couleurInterieur, int transparence);
        ~RectangleS();
};



#endif //RECTANGLES_H
