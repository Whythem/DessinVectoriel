//
// Created by mathi on 26/09/2024.
//

#ifndef FORMES_H
#define FORMES_H

#include "Forms/Point.h"

class Formes {
    private:
        float zoom;
        std::string nameFileBmp;
    protected:

    public:
        Formes(std::string vectorFile, std::string nameFileBmp, float zoom = 1);
        void getBmpFile();
        ~Formes();
};



#endif //FORMES_H
