#include <iostream>
#include <string>

#include "Formes.h"

int main(int argc, char* argv[]) {
    if (argc < 3 || argc > 4) {
        std::cerr << "Usage: " << argv[0] << " <fichier_initial.vec> <fichier_final.bmp> [echelle]" << std::endl;
        return 1;
    }

    std::string fichier_initial = argv[1];
    std::string fichier_final = argv[2];

    float echelle = 1.0f;
    if (argc == 4) {
        echelle = std::stof(argv[3]);
    }

    std::cout << "Fichier initial: " << fichier_initial << std::endl;
    std::cout << "Fichier final: " << fichier_final << std::endl;
    std::cout << "Echelle: " << echelle << std::endl;

    Formes DessinVectoriel = Formes(fichier_initial, fichier_final, echelle);

    DessinVectoriel.getBmpFile();

    return 0;
}
