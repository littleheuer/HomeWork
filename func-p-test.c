/*************************************************************************
	> File Name: 190112-6.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月12日 星期六 15时42分12秒
 ************************************************************************/

#include<stdio.h>

int add(int a, int b) {
    return a + b;
}

typedef int (*func) (int, int);



int main() {
    func fun = (func)add;
    //printf("%p\n", func());
    printf("%d\n", fun(2, 3));
    return 0;
}
