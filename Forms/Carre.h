//
// Created by mathi on 26/09/2024.
//

#ifndef CARRE_H
#define CARRE_H

#include "Rectangle.h"

class Carre : public Rectangle {
    private:

    protected:

    public:
        Carre(int x, int y, int cote, std::string couleur, int transparence, int z = 0);
        void draw(CImage* image);
        ~Carre();
};



#endif //CARRE_H
