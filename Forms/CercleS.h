//
// Created by mathi on 11/09/2024.
//

#ifndef CERCLES_H
#define CERCLES_H

#include "Cercle.h"

class CercleS: public Cercle {
    private:
        std::string couleurInterieur;

    protected:

    public:
        CercleS(int x, int y, int rayon, int z, std::string couleur, std::string couleurInterieur, int transparence);
        CercleS(int x, int y, int rayon, std::string couleur, std::string couleurInterieur, int transparence);
        ~CercleS();
};



#endif //CERCLES_H
