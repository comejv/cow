#ifndef __READING_COW_H__
#define __READING_COW_H__

#include <string.h>
#include <time.h>
#include "affiche_vache.h"

void lecture(char *yeux, char *pis, char *text){
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