#include <string.h>
#include "devine_nombre.h"
#include "affiche_vache.h"
#include "animation.h"

// Comme il est utilisé par toutes les fonctions, on passe le chemin d'appel en externe
char ext_path[50];

int main(int argc, char const *argv[])
{
    char yeux = 'o';
    char pis = 'w';
    char text[200] = "Bonjour !";
    char opterr[21];

    // Pour obtenir le chemin d'appel de main
    int path_size = strlen(argv[0]) - 4;
    char temp_path[path_size];
    strncpy(temp_path, argv[0], path_size + 1);
    temp_path[path_size] = '\0';
    if (temp_path[0] == '.' || temp_path[0] == '~')
        memmove(temp_path, temp_path + 2, path_size);
    strcpy(ext_path, temp_path);

    // Lecture des arguments
    // (J'aurais pu utiliser optget de unistd.h mais je ne l'ai découvert qu'après)
    for (int i = 1; i < argc; i++)
    {
        // Si l'argument est une option
        if (argv[i][0] == '-')
        {
            switch (argv[i][1])
            {
            // Pour afficher le manuel
            case 'h':
                afficher_aide();
                break;

            // Pour afficher une vache spéciale
            case 's':
                afficher_vache_speciale(argv[i + 1]);
                break;

            // Pour deviner un nombre
            case 'd':
                devine_nombre(0, 15, &yeux, &pis);
                break;

            // Si modèle par défaut on peut changer yeux et pis
            case 'y':
                yeux = argv[i][3];
                break;

            case 'p':
                pis = argv[i][3];
                break;

            // Pour préciser le texte de la bulle
            case 't':
                strcpy(text, argv[i + 1]);
                afficher_vache_defaut(&yeux, &pis, text);
                return 0;

            default:
                snprintf(opterr, 21, "Option -%c inconnue.\n", argv[i][1]);
                fputs(opterr, stderr);
                break;
            }
        }
    }

    // Si aucun argument donné, on affiche la vache par défaut
    afficher_vache_defaut(&yeux, &pis, text);

    return 0;
}
