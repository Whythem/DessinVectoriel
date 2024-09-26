#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    // Check if the correct number of arguments is provided
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <fichier_initial.vec> <fichier_final.bmp> <echelle>" << std::endl;
        return 1;
    }

    // Get the arguments
    std::string fichier_initial = argv[1];
    std::string fichier_final = argv[2];
    int echelle = std::stoi(argv[3]);

    // Output the parameters to verify
    std::cout << "Fichier initial: " << fichier_initial << std::endl;
    std::cout << "Fichier final: " << fichier_final << std::endl;
    std::cout << "Echelle: " << echelle << std::endl;

    // You can now use these parameters as needed in your program.

    return 0;
}
