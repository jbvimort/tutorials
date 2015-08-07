#include <iostream>
#include <fstream>

int main(int argc, char **argv )
{
    std::ifstream fichier("FileName.txt", std::ios::in);  // on ouvre le fichier en lecture

    if(fichier)
    {
        std::string verif;
        getline(fichier, verif);

        if(verif!="inputText")
        {
            std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
            fichier.close();
            remove("FileName.txt");
            return 1;
        }

        fichier.close();
        remove("FileName.txt");
    }
    else
    {
        std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
        return 1;
    }

    return 0;
}

