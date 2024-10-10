//
// Created by mathias on 11/09/2024.
//

#ifndef POINT_H
#define POINT_H

#include <string>

#include "../Image/CImage.h"

class Point {
    private:

    protected:
        int x;
        int y;
        int z;
        std::string couleur;

    public:
        int transparence;
        Point(int x, int y, std::string couleur, int transparence, int z = 0);
        int getZ();
        virtual void draw(CImage* image);
        void colorPixel(CPixel* pixel, std::string couleur, int transparence);
        ~Point();
};



#endif //POINT_H
