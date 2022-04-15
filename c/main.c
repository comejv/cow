#include <string.h>
#include "devine_nombre.h"
#include "affiche_vache.h"
#include "animation.h"

int main(int argc, char const *argv[])
{
    char yeux = 'o';
    char pis = 'w';
    char text[100] = "Bonjour !";

    // Pour obtenir le chemin d'appel de main
    int path_size = strlen(argv[0]) - 4;
    char path[path_size];
    strncpy(path, argv[0], path_size+1);
    path[path_size] = '\0';
    if (path[0] == '.' || path[0] == '~')
        memmove(path, path + 2, path_size);

    // Lecture des arguments
    for (int i = 1; i < argc; i++)
    {
        // Si l'argument est une option
        if (argv[i][0] == '-')
        {
            // Pour afficher le manuel
            if (argv[i][1] == 'h')
                afficher_aide(path);

            // Pour afficher une vache spéciale
            if (argv[i][1] == 's')
                afficher_vache_speciale(path, argv[i + 1]);

            // Si modèle par défaut on peut changer yeux et pis
            if (argv[i][1] == 'y')
                yeux = argv[i][3];

            if (argv[i][1] == 'p')
                pis = argv[i][3];

            if (argv[i][1] == 't')
            {
                strcpy(text, argv[i + 1]);
                afficher_vache_defaut(path, &yeux, &pis, text);
            }
        }
    }

    afficher_vache_defaut(path, &yeux, &pis, text);

    return 0;
}
