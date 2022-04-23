#ifndef __DEVINE_NOMBRE_H__
#define __DEVINE_NOMBRE_H__

#include <stdio.h>
#include <stdlib.h>
#include "affiche_vache.h"

void devine_nombre(int i, int s, char *yeux, char *pis, int *animation)
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
            afficher_vache_defaut(yeux, pis, prompt, animation);
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

#endif