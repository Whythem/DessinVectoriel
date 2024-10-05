//
// Created by mathi on 26/09/2024.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>

#include "Formes.h"

#include "Format/CBitmap.h"

#include "Forms/Carre.h"
#include "Forms/Point.h"
#include "Forms/Cercle.h"
#include "Forms/CercleS.h"
#include "Forms/CarreS.h"
#include "Forms/Rectangle.h"
#include "Forms/RectangleS.h"
#include "Forms/Ligne.h"

Formes::Formes(std::string vectorFile, std::string nameFileBmp, float zoom) {
    readVectorFile(vectorFile);
    this->zoom = zoom;
    this->nameFileBmp = nameFileBmp;
    orderForms();
}

void Formes::readVectorFile(std::string vectorFile) {
    std::ifstream fichier(vectorFile);
    std::string line;

    if (fichier.is_open()) {
        while (std::getline(fichier, line)) {
            std::stringstream ss(line);
            std::string typeForme;
            std::getline(ss, typeForme, ':');


            std::string parametres;
            std::getline(ss, parametres);
            std::stringstream paramStream(parametres);
            if (typeForme == "POINT") {
                int x, y;
                std::string couleur;
                int transparence, z;

                char vir;  // Pour lire les virgules
                paramStream >> x >> vir >> y >> vir >> couleur >> vir >> transparence >> vir >> z;

                this->formes.push_back(new Point(x, y, couleur, transparence, z));
            }
            else if (typeForme == "LIGNE") {
                int x1, y1, x2, y2;
                std::string couleur;
                int transparence, z;

                char vir;
                paramStream >> x1 >> vir >> y1 >> vir >> x2 >> vir >> y2 >> vir >> couleur >> vir >> transparence >> vir >> z;

                this->formes.push_back(new Ligne(x1, y1, x2, y2, couleur, transparence, z));
            }
            else if (typeForme == "RECTANGLE") {
                int x, y, longueur, largeur;
                std::string couleur;
                int transparence, z;

                char vir;
                paramStream >> x >> vir >> y >> vir >> longueur >> vir >> largeur >> vir >> couleur >> vir >> transparence >> vir >> z;

                this->formes.push_back(new Rectangle(x, y, longueur, largeur, couleur, transparence, z));
            }
            else if (typeForme == "CARRE") {
                int x, y, cote;
                std::string couleur;
                int transparence, z;

                char vir;
                paramStream >> x >> vir >> y >> vir >> cote >> vir >> couleur >> vir >> transparence >> vir >> z;

                this->formes.push_back(new Carre(x, y, cote, couleur, transparence, z));
            }
            else if (typeForme == "CERCLE") {
                int x, y, rayon;
                std::string couleur;
                int transparence, z;

                char vir;
                paramStream >> x >> vir >> y >> vir >> rayon >> vir >> couleur >> vir >> transparence >> vir >> z;

                this->formes.push_back(new Cercle(x, y, rayon, couleur, transparence, z));
            }
            else if (typeForme == "RECTANGLES") {
                int x, y, longueur, largeur;
                std::string couleur, couleurInterieur;
                int transparence, z;

                char vir;
                paramStream >> x >> vir >> y >> vir >> longueur >> vir >> largeur >> vir >> couleur >> vir >> couleurInterieur >> vir >> transparence >> vir >> z;

                this->formes.push_back(new RectangleS(x, y, longueur, largeur, couleur, couleurInterieur, transparence, z));
            }
            else if (typeForme == "CARRES") {
                int x, y, cote;
                std::string couleur, couleurInterieur;
                int transparence, z;

                char vir;
                paramStream >> x >> vir >> y >> vir >> cote >> vir >> couleur >> couleurInterieur >> vir >> transparence >> vir >> z;

                this->formes.push_back(new CarreS(x, y, cote, couleur, couleurInterieur, transparence, z));
            }
            else if (typeForme == "CERCLES") {
                int x, y, rayon;
                std::string couleur, couleurInterieur;
                int transparence, z;

                char vir;
                paramStream >> x >> vir >> y >> vir >> rayon >> vir >> couleur >> couleurInterieur >> vir >> transparence >> vir >> z;

                this->formes.push_back(new CercleS(x, y, rayon, couleur, couleurInterieur, transparence, z));
            }
            //TODO ADD TRIANGLE
        }
        fichier.close();
    } else {
        std::cerr << "Erreur d'open file" << std::endl;
    };
}

void Formes::orderForms() {
    std::sort(this->formes.begin(), this->formes.end(), [](Point* a, Point* b) {
        return a->getZ() < b->getZ(); // Ascending order
    });
}

void Formes::getBmpFile() {
    int imgWidth = 800;
    int imgHeight = 600;

    CImage* image = new CImage(imgWidth, imgHeight);

    CBitmap bmp = CBitmap();

    bmp.setImage(image);

    for (Point* forme : this->formes) {
        std::cout << forme << "\n";
        forme->draw(image);
    }

    bmp.SaveBMP(this->nameFileBmp);

    delete image;
}

Formes::~Formes() {

}


