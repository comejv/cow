#ifndef __JEUX_H__
#define __JEUX_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "affiche_vache.h"

void devine_nombre(int i, int s, char *yeux, char *pis, char *langue, int *animation)
{
    int g;
    int n = 1;
    char prompt[50];
    char r;
    while (r != '=')
    {
        if (r != '\n')
        {
            g = (i + s) / 2;
            snprintf(prompt, 50, "Je devine %i, est-ce +, - ou = ?", g);
            afficher_vache_defaut(yeux, pis, langue, prompt, *animation);
            scanf("%s", &r);
            switch (r)
            {
            case '+':
                n++;
                i = g;
                break;
            case '-':
                n++;
                s = g;
                break;
            case '=':
                break;
            default:
                puts("Caractère invalide. Réessayez.");
            }
        }
    }
    printf("Nombre deviné en %i essais !\nMerci d'avoir joué.\n", n);
    exit(0);
}

void lecture(char *yeux, char *pis, char *text)
{
    int s_length = strlen(text);
    char buff_text[s_length];
    for (int i = 0; i < s_length; i++)
    {
        strncat(buff_text, text + i, 1);
        afficher_vache_defaut(yeux, pis, &text[i], buff_text, 0);
        nanosleep((const struct timespec[]){{0, 500000000L}}, NULL);
    }
    exit(0);
}



#endif