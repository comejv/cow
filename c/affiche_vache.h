#ifndef __AFFICHE_VACHE_H__
#define __AFFICHE_VACHE_H__

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "animation.h"

#define TAILLE_VACHE 123

// Pour garder afficher une vache jusqu'à ce qu'ENTER soit pressé
void fin()
{
    printf("Appuyez sur ENTREE pour quitter");
    getchar();
    clear();
    exit(0);
}

char *relative_path(char *path_to_main, char *relative_file_path)
{
    // int total_size = strlen(path_to_main) + strlen(relative_file_path) + 1;
    static char path_to_file[100];
    strcpy(path_to_file, path_to_main);
    strcat(path_to_file, relative_file_path);
    return path_to_file;
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
void afficher_aide(char *path_to_main)
{
    char dir[] = "/ressources/cow_help.txt";

    char *path = relative_path(path_to_main, dir);

    FILE *f = fopen(path, "r");
    if (f == NULL)
    {
        perror(path);
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
void afficher_vache_defaut(char *path_to_main, char *yeux, char *pis, char t[])
{
    char dir[] = "ressources/cow_defaut.txt";
    char *path = relative_path(path_to_main, dir);

    FILE *f = fopen(path, "r");
    if (f == NULL)
    {
        perror(path);
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

void afficher_vache_speciale(char *path_to_main, const char modele[])
{
    char dir[50];

    if (strcmp(modele, "portrait") == 0)
        strcpy(dir, "ressources/cow_portrait.txt");

    if (strcmp(modele, "assise") == 0)
        strcpy(dir, "ressources/cow_assise.txt");

    char *path = relative_path(path_to_main, dir);

    FILE *f = fopen(path, "r");
    if (f == NULL)
    {
        perror(path);
        exit(1);
    }

    clear();
    for (char c = getc(f); c != EOF; c = getc(f))
        putc(c, stdout);
    printf("\n");

    fclose(f);
    fin();
}

#endif