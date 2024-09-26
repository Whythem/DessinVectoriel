//
// Created by mathi on 26/09/2024.
//

#ifndef TRIANGLES_H
#define TRIANGLES_H
#include "Triangle.h"


class TriangleS: public Triangle{
    private:
        std::string couleurInterieur;
    protected:

    public:
        TriangleS(int x, int y, int x2, int y2, int x3, int y3, std::string couleur, std::string couleurInterieur, int transparence, int z = 0);
        ~TriangleS();
};



#endif //TRIANGLES_H
