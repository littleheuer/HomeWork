/*************************************************************************
	> File Name: 190112-3-arr.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月12日 星期六 11时06分18秒
 ************************************************************************/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
typedef struct number {
    int type;// 0 -> int ,1 -> double
    union {
        int a;
        double b;
    } N;
} Number;

void set(Number *n, int num) {
    n -> type = 0;
    n -> N.a = num;
    return ;
}

void set(Number *n, double num) {
    n -> type = 1;
    n -> N.b = num;
    return ;
}

void print(Number *n) {
    switch (n -> type) {
        case 0: printf("%d", n -> N.a); break;
        case 1: printf("%lf", n -> N.b); break;
    }
    return ;
}

void my_input(Number *ar, int i, int x) {
    ar[i].type = 0;
    ar[i].N.a = x;
    return ;
}

void my_input(Number *ar,int i, double x) {
    ar[i].type = 1;
    ar[i].N.b = x;
}
int main() {
    #define max_n 20
    srand(time(0));
    Number arr[max_n];
    for(int i = 0; i < max_n; i++) {
        int op = rand() % 2;
        switch (op) {
            case 0 : {
                int value = rand() % 100;
                set(arr + i, value);
            } break;
            case 1 : {
                double value =(1.0 * (rand() % 10000) / 10000) * 100;
                set(arr + i, value);
            } break;
        }
    }
    for(int i = 0; i < max_n; i++) {
        print(arr + i);
        if(i != max_n - 1) printf(" ");
    }
    return 0;
}
