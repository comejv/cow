#ifndef __AFFICHE_VACHE_H__
#define __AFFICHE_VACHE_H__

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE_VACHE 123

extern char ext_path[];

// Obtenir le chemin d'un fichier selon le wd
char *relative_path(char *relative_file_path)
{
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

// Fonction d'animation et affichage
void clear() { printf("\x1b[H\x1b[J"); }
void gotoxy(int x, int y) { printf("\x1b[%d;%df", x, y); }

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
    printf("\x1b[1mMANUEL D'UTILISATION DE COW\x1b[0m\n");
    for (char c = getc(f); c != EOF; c = getc(f))
        putc(c, stdout);
    printf("\n");
    fclose(f);
    printf("\n\x1b[7mAppuyez sur ENTREE pour quitter\x1b[27m");
    getchar();
    clear();
    exit(0);
}

int min(int a, int b)
{
    int c;
    (a < b) ? (c = a) : (c = b);
    return c;
}

// Affiche la bulle de texte de la vache par défaut
int affiche_bulle(char t[], int s_length, int animation)
{
    // Nombre lignes
    int n_lignes = 1;
    if (s_length > 50)
        // Divise par 51 car sinon si s_length%50 = 0 une ligne de trop
        n_lignes = s_length / 51 + 1;

    // Affichage cadre haut
    gotoxy(0, 0);
    putchar(' ');
    for (int i = 0; i < min(s_length + 2, 52); i++)
        putchar('_');
    putchar('\n');
    for (int l = 0; l < n_lignes; l++)
    {
        for (int c = 0; c < min(s_length + 2, 52); c++)
        {
            if (c == 0)
                fputs("| ", stdout);
            else if (c == min(s_length + 1, 51))
                fputs(" |", stdout);
            else
            {
                if (c - 1 + (50 * l) >= s_length && s_length > 50)
                    putchar(' ');
                else
                {

                    switch (animation)
                    {
                    case 1:
                        putchar(t[c - 1 + (50 * l)]);
                        nanosleep((const struct timespec[]){{0, 50000000L}}, NULL);
                        break;
                    case 2:
                        printf("\x1b[%im%c", (c % 7 == 0 ? 93 : c % 7 + 90), t[c - 1 + (50 * l)]);
                        break;
                    case 3:
                        printf("\x1b[%im%c", (c % 7 == 0 ? 93 : c % 7 + 90), t[c - 1 + (50 * l)]);
                        nanosleep((const struct timespec[]){{0, 50000000L}}, NULL);
                        break;
                    default:
                        putchar(t[c - 1 + (50 * l)]);
                        break;
                    }
                }
                fflush(stdout);
            }
            printf("\x1b[39m");
        }
        putchar('\n');
    }
    putchar(' ');
    // Affichage cadre bas
    for (int i = 0; i < min(s_length + 2, 52); i++)
        fputs("‾", stdout);
    putchar('\n');
    return n_lignes;
}

// Affiche la vache par défaut en remplassant pis et yeux si option argument donné
void afficher_vache_defaut(char *yeux, char *pis, char *langue, char t[], int animation)
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
    int l;
    int t_length = strlen(t);
    int mult_50 = t_length;
    if (t_length > 50)
        mult_50 = 50 * (t_length / 50 + 1);
    char s_vide[mult_50];
    for (int i = 0; i < mult_50; i++)
        s_vide[i] = ' ';
    s_vide[mult_50] = '\0';

    // Séléction type animation
    switch (animation)
    {
    case 0:
        l = affiche_bulle(t, t_length, 0);
        break;
    case 1:
    case 2:
    case 3:
        affiche_bulle(s_vide, mult_50, 0);
        break;
    default:
        exit(3);
        break;
    }

    // Affichage de la vache
    char *pi = "π";
    for (int i = 0; i < TAILLE_VACHE; i++)
    {
        switch (V[i])
        {
        case 'o':
            putchar(*yeux);
            break;
        case 'w':
            if (*pis == 'p')
                fputs(pi, stdout);
            else
                putchar(*pis);
            break;
        case 'l':
            putchar(*langue);
            break;
        default:
            putchar(V[i]);
            break;
        }
    }
    putchar('\n');
    fclose(f);

    // Animation du texte
    l = affiche_bulle(t, t_length, animation);
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