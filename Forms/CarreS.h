//
// Created by mathi on 26/09/2024.
//

#ifndef CARRES_H
#define CARRES_H

#include "RectangleS.h"

class CarreS : public RectangleS {
    private:

    protected:

    public:
        CarreS(int x, int y, int z, int cote, std::string couleur, std::string couleurInterieur, int transparence);
        CarreS(int x, int y, int cote, std::string couleur, std::string couleurInterieur, int transparence);
        ~CarreS();
};



#endif //CARRES_H
