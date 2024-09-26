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
        Carre(int x, int y, int cote, int z, std::string couleur, int transparence);
        Carre(int x, int y, int cote, std::string couleur, int transparence);
        ~Carre();
};



#endif //CARRE_H
