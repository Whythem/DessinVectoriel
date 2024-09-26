//
// Created by mathi on 26/09/2024.
//

#ifndef FORMES_H
#define FORMES_H

#include "Forms/Point.h"

class Formes {
    private:
        int zoom;
        std::string nameFileBmp;
    protected:

    public:
        Formes(std::string vectorFile, int zoom, std::string nameFileBmp);
        void getBmpFile();
        ~Formes();
};



#endif //FORMES_H
