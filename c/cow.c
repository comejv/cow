#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include <unistd.h> sleep

#define TAILLE_VACHE 123

void clear() { printf("\033[H\033[J"); }
void fin() {
    printf("Appuyez sur ENTREE pour quitter");
    getchar();
    clear();
    exit(0);
}

// Lis un fichier texte et renvoie un tableau "formatté"
char *lire_f_vache(FILE *f)
{
    static char V[TAILLE_VACHE];
    char c;
    for (int i = 0; i < TAILLE_VACHE; i++)
    {
        c = getc(f);
        switch (c)
        {
        case EOF:
            V[i] = '\n';
            break;
        case 'b':
            V[i] = '\\';
            break;
        default:
            V[i] = c;
        }
    }
    return V;
}

// Affiche le contenu du fichier cow_help.txt qui contient le manuel d'utilisation du programme
void afficher_aide()
{
    FILE *f = fopen("ressources/cow_help.txt", "r");
    if (f == NULL)
    {
        perror("ressources/cow_help.txt");
        exit(1);
    }
    clear();
    printf("%s\n", "\033[1mMANUEL D'UTILISATION DE COW\033[0m");
    for (char c = getc(f); c != EOF; c = getc(f))
        putc(c, stdout);
    printf("\n");
    fclose(f);
    fin();
}
// Affiche la bulle de texte de la vache par défaut
void affiche_bulle(char t[])
{
    int s = strlen(t);
    printf(" ");
    for (int i = 0; i < s + 2; i++)
        printf("_");
    printf("\n< %s >\n", t);
    printf(" ");
    for (int i = 0; i < s + 2; i++)
        printf("‾");
    printf("\n");
}

// Affiche la vache par défaut en remplassant pis et yeux si option argument donné
void afficher_vache_defaut(char *yeux, char *pis, char t[])
{
    FILE *f = fopen("ressources/cow_defaut.txt", "r");
    if (f == NULL)
    {
        perror("ressources/cow_defaut.txt");
        exit(1);
    }
    char *V = lire_f_vache(f);

    clear();
    affiche_bulle(t);
    for (int i = 0; i < TAILLE_VACHE; i++)
    {
        switch (V[i])
        {
        case 'o':
            printf("%c", *yeux);
            break;
        case 'w':
            printf("%c", *pis);
            break;
        default:
            printf("%c", V[i]);
            break;
        }
    }
    printf("\n");
    fclose(f);
    fin();
}

void afficher_vache_speciale(const char modele[])
{
    char dir[50];

    if (strcmp(modele, "portrait") == 0)
        strcpy(dir, "ressources/cow_portrait.txt");

    if (strcmp(modele, "assise") == 0)
        strcpy(dir, "ressources/cow_assise.txt");
    FILE *f = fopen(dir, "r");
    if (f == NULL)
    {
        perror(dir);
        exit(1);
    }

    clear();
    for (char c = getc(f); c != EOF; c = getc(f))
        putc(c, stdout);
    printf("\n");

    fclose(f);
    fin();
}

int main(int argc, char const *argv[])
{
    char yeux = 'o';
    char pis = 'w';
    char text[100] = "Bonjour !";

    // Lecture des arguments
    for (int i = 1; i < argc; i++)
    {
        // Si l'argument est une option
        if (argv[i][0] == '-')
        {
            // Pour afficher le manuel
            if (argv[i][1] == 'h')
                afficher_aide();

            // Pour afficher une vache spéciale
            if (argv[i][1] == 's')
                afficher_vache_speciale(argv[i + 1]);

            // Si modèle par défaut on peut changer yeux et pis
            if (argv[i][1] == 'y')
                yeux = argv[i][3];

            if (argv[i][1] == 'p')
                pis = argv[i][3];

            if (argv[i][1] == 't')
            {
                strcpy(text, argv[i + 1]);
                afficher_vache_defaut(&yeux, &pis, text);
            }
        }
    }

    afficher_vache_defaut(&yeux, &pis, text);

    return 0;
}
