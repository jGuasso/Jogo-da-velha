#include <stdio.h>
#include "ansi_colors.h"

char* bg_color(int r, int g, int b){
    static char str[100];
    sprintf(str,"\033[48;2;%d;%d;%dm",r,g,b);
    return str;
}

char* text_color(int r, int g, int b){
    static char str[100];
    sprintf(str,"\033[38;2;%d;%d;%dm",r,g,b);
    return str;
}
