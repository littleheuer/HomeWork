/*************************************************************************
	> File Name: n-jiecheng.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月05日 星期六 14时34分48秒
 ************************************************************************/

#include<stdio.h>
#define max 100000

int num[max + 5] = {0};

void f(int n) {
    num[1] = num[0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= num[0]; j++) {
            num[j] *= n;
        }
        for(int j = 1;j <= num[0]; j++) {
            if(num[j] < 10) continue;
            num[i + 1] = num[i] / 10;
            num[i] %= num[i];
            num[0] += (i == num[0]);
        }
    }
}

int mi(int n) {
    if(n == 1) return 1;
    return n * mi(n - 1);
}

int main() {
    int n = 0;
    while(~scanf("%d", &n)) {
        int ans = mi(n);
        printf("%d\n", ans);   
    }
   ;
    return 0;
}
