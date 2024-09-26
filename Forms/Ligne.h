//
// Created by mathi on 11/09/2024.
//

#ifndef LIGNE_H
#define LIGNE_H

#include "Point.h"

class Ligne: public Point {
    private:
      int Xbis;
      int Ybis;

    protected:

    public:
      Ligne(int x, int y, int Xbis, int Ybis, std::string couleur, int transparence, int z = 0);
      void draw(CImage* image);
      ~Ligne();
};



#endif //LIGNE_H
