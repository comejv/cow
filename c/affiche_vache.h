#ifndef __AFFICHE_VACHE_H__
#define __AFFICHE_VACHE_H__

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "animation.h"

#define TAILLE_VACHE 123

char *relative_path(char *relative_file_path)
{
    extern char ext_path[];
    // int total_size = strlen(ext_path) + strlen(relative_file_path) + 1;
    static char path_to_file[100];
    strcpy(path_to_file, ext_path);
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
void afficher_aide()
{
    extern char ext_path[];
    char dir[] = "/ressources/cow_help.txt";

    char *path = relative_path(dir);

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
    printf("Appuyez sur ENTREE pour quitter");
    getchar();
    clear();
    exit(0);
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
    extern char ext_path[];
    char dir[] = "ressources/cow_defaut.txt";
    char *path = relative_path(dir);

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
}

void afficher_vache_speciale(const char modele[])
{
    extern char ext_path[];
    char dir[50];

    if (strcmp(modele, "portrait") == 0)
        strcpy(dir, "ressources/cow_portrait.txt");

    if (strcmp(modele, "assise") == 0)
        strcpy(dir, "ressources/cow_assise.txt");

    if (strcmp(modele, "sauvage") == 0)
        strcpy(dir, "ressources/cow_sauvage.txt");

    if (strcmp(modele, "canadienne") == 0)
        strcpy(dir, "ressources/cow_canadienne.txt");

    char *path = relative_path(dir);

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
    printf("Appuyez sur ENTREE pour quitter");
    getchar();
    clear();
    exit(0);
}

#endif