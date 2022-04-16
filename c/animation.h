#ifndef __ANIMATION_H__
#define __ANIMATION_H__
#include <stdio.h>

void clear() { printf("\033[H\033[J"); }
void gotoxy(x, y) { printf(" \033[% d;% dH", x, y); }

#endif