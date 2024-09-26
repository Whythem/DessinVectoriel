//
// Created by mathi on 11/09/2024.
//

#ifndef CERCLE_H
#define CERCLE_H

#include "Point.h"

class Cercle: public Point {
    private:

    protected:
      int rayon;

    public:
      Cercle(int x, int y, int rayon, std::string couleur, int transparence, int z = 0);
      ~Cercle();
};



#endif //CERCLE_H
