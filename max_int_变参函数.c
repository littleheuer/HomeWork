/*************************************************************************
	> File Name: max_int.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月05日 星期六 15时57分35秒
 ************************************************************************/

#include<stdio.h>
#include<stdarg.h>

int max_int(int n, ...) {
    va_list arg;
    va_start(arg, n);
    int ans = 0;
    while(n--) {
        int temp = va_arg(arg, int);
        ans = temp > ans ? temp : ans;
    }
    va_end(arg);
    return ans;
}
