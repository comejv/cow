#ifndef __AFFICHE_VACHE_H__
#define __AFFICHE_VACHE_H__

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "animation.h"

#define TAILLE_VACHE 123

extern char ext_path[];

char *relative_path(char *relative_file_path)
{
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
int affiche_bulle(char t[], int s_length, int animation)
{
    // Nombre lignes
    int n_lignes = s_length / 50 +1;

    // Affichage cadre haut
    gotoxy(0, 0);
    printf(" ");
    // min(s_length, 52)
    for (int i = 0; i < (((s_length + 2) < (52)) ? (s_length + 2) : (52)); i++)
        printf("_");
    printf("\033[1E");

    // Si pas d'animation
    if (animation == 0)
    {
        //? Pourquoi -1 nécessaire en plus d'inégalité stricte ?!
        for (int i = 0; i < n_lignes-1; i++)
            // On affiche 50 char à la fois
            printf("| %.50s |\n", t + (i * 50));
        putchar(' ');
    }
    // Si animation
    else
    {
        gotoxy(2, 0);
        for (int l = 0; l < n_lignes; l++)
        {
            for (int c = 0; c < 52; c++)
            {
                if (c == 0)
                    printf("| ");
                else if (c == 51)
                    printf(" |");
                else
                {
                    if (c - 1 + (50 * l) >= s_length && s_length > 50)
                        putchar(' ');
                    else
                        printf("%c", t[c - 1 + (50 * l)]);
                    fflush(stdout);
                    nanosleep((const struct timespec[]){{0, 50000000L}}, NULL);
                }
            }
            printf("\033[1E");
        }
        putchar(' ');
    }
    // Affichage cadre bas
    // Min entre taille length et 52
    for (int i = 0; i < (((s_length + 2) < (52)) ? (s_length + 2) : (52)); i++)
        printf("‾");
    printf("\033[1E");
    fflush(stdout);
    return n_lignes;
}

// Affiche la vache par défaut en remplassant pis et yeux si option argument donné
void afficher_vache_defaut(char *yeux, char *pis, char t[])
{
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

    // Affichage d'une bulle vide
    int t_length = strlen(t);
    int mult_50 = t_length;
    if (t_length >= 50)
        mult_50 = 50 * (t_length / 50 + 1);
    char s_vide[mult_50];
    for (int i = 0; i < mult_50; i++)
        s_vide[i] = ' ';
    s_vide[mult_50] = '\0';
    affiche_bulle(s_vide, mult_50, 0);

    // Affichage de la vache
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

    // Animation du texte
    int l = affiche_bulle(t, t_length, 1);
    gotoxy(l + 8, 0);
}

void afficher_vache_speciale(const char modele[])
{
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