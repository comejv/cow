#ifndef __ANIMATION_H__
#define __ANIMATION_H__
#include <stdio.h>

void clear() { printf("\e[H\e[J"); }
void gotoxy(int x, int y) { printf("\e[%d;%df", x, y); }

#endif