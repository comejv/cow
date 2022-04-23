#ifndef __ANIMATION_H__
#define __ANIMATION_H__
#include <stdio.h>

void clear() { printf("\033[H\033[J"); }
void gotoxy(int x, int y) { printf("\033[%d;%df", x, y); }

#endif