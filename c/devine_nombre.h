#ifndef __DEVINE_NOMBRE_H__
#define __DEVINE_NOMBRE_H__

#include <stdio.h>
#include <stdlib.h>
#include "affiche_vache.h"

void devine_nombre(int i, int s)
{
    int g = (i + s) / 2;
    int n = 0;
    char prompt[50];
    snprintf(prompt, 50, "Je devine %i, est-ce +, - ou = ?", g);
    affiche_bulle(prompt);
    char r = getchar();
    while (r != '=')
    {
        n++;
        switch (r)
        {
        case '+':
            i = g;
            break;
        case '-':
            s = g;
            break;
        }
        g = (i + s) / 2;
        snprintf(prompt, 50, "Je devine %i, est-ce +, - ou = ?", g);
        affiche_bulle(prompt);
        r = getchar();
    }
    printf("Nombre deviné en %i essais !\nMerci d'avoir joué.\n", n);
    exit(0);
}

#endif