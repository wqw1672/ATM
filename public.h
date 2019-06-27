#ifndef _PUBLIC_H_
#define _PUBLIC_H_
#include<windows.h>
#include<conio.h>
#include<stdio.h>
#include <time.h>
#include<stdlib.h>
#include <string.h>
int Gotoxy(int x, int y);
int glb_putString(char str[], int maxLen, int putType, int isPlaintext);
#endif