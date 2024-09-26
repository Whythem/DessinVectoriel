//
// Created by mathias on 11/09/2024.
//

#ifndef POINT_H
#define POINT_H

#include <string>

class Point {
    private:

    protected:
        int x;
        int y;
        int z;
        std::string couleur;
        int transparence;

    public:
        Point(int x, int y, std::string couleur, int transparence, int z = 0);
        int getZ() ;
        ~Point();

};



#endif //POINT_H
