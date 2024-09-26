//
// Created by mathi on 26/09/2024.
//

#ifndef FORMES_H
#define FORMES_H

#include <vector>
#include "Forms/Point.h"

class Formes {
    private:
        std::vector<Point*> formes;
        float zoom;
        std::string nameFileBmp;
    protected:

    public:
        Formes(std::string vectorFile, std::string nameFileBmp, float zoom = 1);
        void readVectorFile(std::string vectorFile);
        void orderForms();
        void getBmpFile();
        ~Formes();
};



#endif //FORMES_H
