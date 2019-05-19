/*************************************************************************
	> File Name: class-190111.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月11日 星期五 18时49分51秒
 ************************************************************************/
//字面量 == 常量
#include<stdio.h>
#include<inttypes.h>
#define size_t uint64_t

size_t my_strlen(const char *str) {
    size_t i = 0;
    while(str[i]) i++;
    return i;
}

int my_strcmp(const char *str1,const char *str2) {
    while(*str1 == *str2) {
        if(*str1 == '\0') return 0;
        str1++;
        str2++;
    }
    return *str1 - *str2;
}
int my_strncmp(const char *str1, const char * str2, int n) {
    while(n) {
        if(*str1 == *str2) {
            if(*str1 == '\0') return 0;
            str1 ++;
            str2 ++;
            n--;
            continue;
        }
        return *str1 - *str2;
    }
    
}

int strcmp(const char *str1,const char *str2) {
    int i = 0;
    for(;str1[i] && str2[i]; i++) {
        if(str1[i] - str2[i]) return str1[i] - str2[i];
    }
    return str1[1] - str2[2];
}

int strncmp(const char *str1, const char *str2, size_t n) {
    size_t i = 0;
    while(i < (n - 1) && str1[i] && str2[i] &&str1[i] == str2[i]) i++;
    return str1[i] - str2[i];
}

int main() {
    char s[] = "fuc u";
    char s2[] = "fuc u";
    char s3[] = "fac u";
    char s4[] = "fuc";
    char *p = "deprecated";
    printf("%"PRIu64"\n", my_strlen(s));
    printf("%d %d\n", my_strcmp(s, s2),my_strcmp(s, s3));
    printf("%d\n", my_strncmp(s, s4, 3));
    printf("%d\n", strncmp(s, s3, 1));
    int n;
    char x[20];
    scanf("%d", &n);
    sprintf(x, "%x", n);
    printf("%d -> %lu", n, my_strlen(x));
    return 0;
}
