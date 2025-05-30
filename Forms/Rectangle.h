//
// Created by mathi on 11/09/2024.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Point.h"

class Rectangle: public Point {
    private:

    protected:
        int longueur;
        int largeur;

    public:
        Rectangle(int x, int y, int longueur, int largeur, std::string couleur, int transparence, int z = 0);
        virtual void draw(CImage* image);
        ~Rectangle();
        
};



#endif //RECTANGLE_H
