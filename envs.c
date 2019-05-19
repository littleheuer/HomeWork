/*************************************************************************
	> File Name: 190112-7.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月12日 星期六 15时48分00秒
 ************************************************************************/

#include<stdio.h>


int main(int argc, char *argv[],char *env[]) {
    for(int i = 0; i < argc; i++) {
        printf("%s\n", argv[0]);
    }
    for(char **p = env; p[0] != NULL; p++) {
        printf("%s\n", p[0]);
    }
    return 0;
}
