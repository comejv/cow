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

int entier_aleatoire(int max)
{
    static int a = 0;

    if (a == 0)
    {
        srand(time(NULL));
        a = 1;
    }
    return (rand() % max);
}

void tamagoshi()
{
    // Var affichage vache
    char yeux = 'o';
    char pis = 'w';
    char langue = ' ';
    char text[200] = "Bonjour ! Vous etes mon nouveau gardien ? Le precedent a fuit la queue entre les jambes... Enfin treve de bavarderies, j'ai faim ! Combien de bottes de foin m'amenez-vous ?";

    // Var automate
    int sante = 5;
    int stock = 5;
    int n = 0;
    int c = 0;

    afficher_vache_defaut(&yeux, &pis, &langue, text, 1);
    printf("\x1b[1FStocks = %i\x1b[1E", stock);
    printf("\x1b[5mEntrez un montant...\x1b[25m");
    n = getchar() - 48;
    getchar(); //? Pour récupérer le \n

    while (sante > 0 && sante < 10 && n != 54)
    {
        switch (abs(sante - 5))
        {
        case 0:
            strcpy(text, "Bonne decision, je me sens tres bien ! Dites moi acombien de bottes de foin j'ai le droit.");
            break;
        case 1:
            strcpy(text, "Je ne me sens pas si mal ! Qu'est-ce que je mange maintenant ?");
            yeux = 'n';
            break;

        case 2:
        case 3:
            strcpy(text, "Je ne me sens pas au mieux de ma forme... Est-ce que je devrais manger encore ?");
            yeux = '-';
            break;
        case 5:
            strcpy(text, "Je ne me sens vraiment pas bien ! Qu'est-ce que je fait ?");
            yeux = '!';
            break;
        }
        if (c != 0)
        {
            afficher_vache_defaut(&yeux, &pis, &langue, text, 1);
            printf("\x1b[1FStocks = %i\x1b[1E", stock);
            printf("\x1b[5mEntrez un montant...\x1b[25m");
            n = getchar() - 48;
            getchar(); //? Pour récupérer le \n
        }

        // On enlève la quantité demandé plus un malus aléatoire
        stock -= n;
        stock += entier_aleatoire(3);
        sante += n;
        sante -= entier_aleatoire(3);
        c++;
    }

    yeux = 'x';
    pis = '-';
    langue = 'U';
    strcpy(text, "Baaahh...");
    afficher_vache_defaut(&yeux, &pis, &langue, text, 1);
    if (n == 54)
        printf("Vous avez mis fin au jeu apres %i tours. Votre vache avait un score fitness de %i et il restait %i bottes de foin.\n", c, sante, stock);
    else if (sante <= 0)
        printf("Votre vache est morte de faim apres %i tours ! Il vous restait %i bottes de foin.\n", c, stock);
    else if (sante >= 10)
        printf("Votre vache est morte de surpoid apres %i tours ! Il vous restait %i bottes de foin.\n", c, stock);

    exit(0);
}

#endif