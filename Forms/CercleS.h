//
// Created by mathi on 11/09/2024.
//

#ifndef CERCLES_H
#define CERCLES_H

#include "Cercle.h"

class CercleS: public Cercle {
    private:

    protected:
       std::string couleurInterieur;

    public:
        CercleS(int x, int y, int rayon, std::string couleur, std::string couleurInterieur, int transparence, int z = 0);
        void draw(CImage* image);
        ~CercleS();
};



#endif //CERCLES_H
