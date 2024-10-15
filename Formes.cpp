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
#include "Forms/Triangle.h"
#include "Forms/TriangleS.h"

Formes::Formes(std::string vectorFile, std::string nameFileBmp, int zoom) {
    this->zoom = zoom;
    this->nameFileBmp = nameFileBmp;
    readVectorFile(vectorFile);
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
                paramStream >> x >> vir >> y >> vir;
                std::getline(paramStream >> std::ws, couleur, ',');
                paramStream >> transparence >> vir >> z;
                if (zoom >= 0.5 && zoom <=1.5) {
                    this->formes.push_back(new Point((int)(x * zoom), (int)(y * zoom), couleur, transparence, z));
                } else if (zoom > 1.5) {
                    this->formes.push_back(new CarreS((int)(x * zoom), (int)(y * zoom), (int)zoom, couleur, couleur, transparence, z));
                }
            }
            else if (typeForme == "LIGNE") {
                int x1, y1, x2, y2;
                std::string couleur;
                int transparence, z;

                char vir;
                paramStream >> x1 >> vir >> y1 >> vir >> x2 >> vir >> y2 >> vir;
                std::getline(paramStream >> std::ws, couleur, ',');
                paramStream >> transparence >> vir >> z;

                this->formes.push_back(new Ligne((int)(x1 * zoom), (int)(y1 * zoom), (int)(x2 * zoom), (int)(y2 * zoom), couleur, transparence, z));
            }
            else if (typeForme == "RECTANGLE") {
                int x, y, longueur, largeur;
                std::string couleur;
                int transparence, z;

                char vir;
                paramStream >> x >> vir >> y >> vir >> longueur >> vir >> largeur >> vir;
                std::getline(paramStream >> std::ws, couleur, ',');
                paramStream>> transparence >> vir >> z;

                this->formes.push_back(new Rectangle((int)(x * zoom), (int)(y * zoom), (int)(longueur * zoom), (int)(largeur * zoom), couleur, transparence, z));
            }
            else if (typeForme == "CARRE") {
                int x, y, cote;
                std::string couleur;
                int transparence, z;

                char vir;
                paramStream >> x >> vir >> y >> vir >> cote >> vir;
                std::getline(paramStream >> std::ws, couleur, ',');
                paramStream >> transparence >> vir >> z;

                this->formes.push_back(new Carre((int)(x * zoom), (int)(y * zoom), (int)(cote * zoom), couleur, transparence, z));
            }
            else if (typeForme == "CERCLE") {
                int x, y, rayon;
                std::string couleur;
                int transparence, z;

                char vir;
                paramStream >> x >> vir >> y >> vir >> rayon >> vir;
                std::getline(paramStream >> std::ws, couleur, ',');
                paramStream >> transparence >> vir >> z;

                this->formes.push_back(new Cercle((int)(x * zoom), (int)(y * zoom), (int)(rayon * zoom), couleur, transparence, z));
            }
            else if (typeForme == "TRIANGLE") {
                int x1, y1, x2, y2, x3, y3;
                std::string couleur;
                int transparence, z;

                char vir;
                paramStream >> x1 >> vir >> y1 >> vir >> x2 >> vir >> y2 >> vir >> x3 >> vir >> y3 >> vir;
                std::getline(paramStream >> std::ws, couleur, ',');
                paramStream >> transparence >> vir >> z;

                if (zoom == 1) {
                    this->formes.push_back(new Triangle(x1, y1, x2, y2, x3, y3, couleur, transparence, z));
                } else {
                    int recX, recY;
                    float axeX2, axeY2, axeX3, axeY3;
                    if (x2 > x3) {
                        recX = x2;
                    } else {
                        recX = x3;
                    }
                    if (y2 > y3) {
                        recY = y2;
                    } else {
                        recY = y3;
                    }

                    axeX2 = (x2 - x1) / (recX - x1);
                    axeX3 = (x3 - x1) / (recX - x1);
                    axeY2 = (y2 - y1) / (recY - y1);
                    axeY3 = (y3 - y1) / (recY - y1);
                    recX = (int)(recX * zoom);
                    recY = (int)(recY * zoom);
                    x1 = (int)(x1 * zoom);
                    y1 = (int)(y1 * zoom);
                    x2 = (int)((axeX2 * recX) + x1);
                    y2 = (int)((axeY2 * recY) + y1);
                    x3 = (int)((axeX3 * recX) + x1);
                    y3 = (int)((axeY3 * recY) + y1);
                    this->formes.push_back(new Triangle(x1, y1, x2, y2, x3, y3, couleur, transparence, z));
                }
            }
            else if (typeForme == "RECTANGLES") {
                int x, y, longueur, largeur;
                std::string couleur, couleurInterieur;
                int transparence, z;

                char vir;
                paramStream >> x >> vir >> y >> vir >> longueur >> vir >> largeur >> vir;
                std::getline(paramStream >> std::ws, couleur, ',');
                std::getline(paramStream >> std::ws, couleurInterieur, ',');
                paramStream>> transparence >> vir >> z;

                this->formes.push_back(new RectangleS((int)(x * zoom), (int)(y * zoom), (int)(longueur * zoom), (int)(largeur * zoom), couleur, couleurInterieur, transparence, z));
            }
            else if (typeForme == "CARRES") {
                int x, y, cote;
                std::string couleur, couleurInterieur;
                int transparence, z;

                char vir;
                paramStream >> x >> vir >> y >> vir >> cote >> vir;
                std::getline(paramStream >> std::ws, couleur, ',');
                std::getline(paramStream >> std::ws, couleurInterieur, ',');
                paramStream >> transparence >> vir >> z;

                this->formes.push_back(new CarreS((int)(x * zoom), (int)(y * zoom), (int)(cote * zoom), couleur, couleurInterieur, transparence, z));
            }
            else if (typeForme == "CERCLES") {
                int x, y, rayon;
                std::string couleur, couleurInterieur;
                int transparence, z;

                char vir;
                paramStream >> x >> vir >> y >> vir >> rayon >> vir;
                std::getline(paramStream >> std::ws, couleur, ',');
                std::getline(paramStream >> std::ws, couleurInterieur, ',');
                paramStream >> transparence >> vir >> z;

                this->formes.push_back(new CercleS((int)(x * zoom), (int)(y * zoom), (int)(rayon * zoom), couleur, couleurInterieur, transparence, z));
            } else if (typeForme == "TRIANGLES") {
                int x1, y1, x2, y2, x3, y3;
                std::string couleur, couleurInterieur;
                int transparence, z;

                char vir;
                paramStream >> x1 >> vir >> y1 >> vir >> x2 >> vir >> y2 >> vir >> x3 >> vir >> y3 >> vir;
                std::getline(paramStream >> std::ws, couleur, ',');
                std::getline(paramStream >> std::ws, couleurInterieur, ',');
                paramStream >> transparence >> vir >> z;

                if (zoom == 1) {
                    this->formes.push_back(new TriangleS(x1, y1, x2, y2, x3, y3, couleur, couleurInterieur, transparence, z));
                } else {
                    int recX, recY;
                    float axeX2, axeY2, axeX3, axeY3;
                    if (x2 > x3) {
                        recX = x2;
                    } else {
                        recX = x3;
                    }
                    if (y2 > y3) {
                        recY = y2;
                    } else {
                        recY = y3;
                    }

                    axeX2 = (x2 - x1) / (recX - x1);
                    axeX3 = (x3 - x1) / (recX - x1);
                    axeY2 = (y2 - y1) / (recY - y1);
                    axeY3 = (y3 - y1) / (recY - y1);
                    recX = (int)(recX * zoom);
                    recY = (int)(recY * zoom);
                    x1 = (int)(x1 * zoom);
                    y1 = (int)(y1 * zoom);
                    x2 = (int)((axeX2 * recX) + x1);
                    y2 = (int)((axeY2 * recY) + y1);
                    x3 = (int)((axeX3 * recX) + x1);
                    y3 = (int)((axeY3 * recY) + y1);
                    this->formes.push_back(new TriangleS(x1, y1, x2, y2, x3, y3, couleur, couleurInterieur, transparence, z));
                }
            }

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
    int imgWidth = (int)(400 * zoom);
    int imgHeight = (int)(400 * zoom);

    CImage* image = new CImage(imgWidth, imgHeight);

    CBitmap bmp = CBitmap();

    bmp.setImage(image);

    for (Point* forme : this->formes) {
        forme->draw(image);
    }

    bmp.SaveBMP(this->nameFileBmp);

    delete image;
}

Formes::~Formes() {

}


