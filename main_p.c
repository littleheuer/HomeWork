/*************************************************************************
	> File Name: main_p.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月05日 星期六 18时21分40秒
 ************************************************************************/

#include<stdio.h>
#include<stdarg.h>
#include<inttypes.h>
//fprintf(stderr, "error unknow %%%c\n", frm[i]);
int my_printf(const char *p, ...) {
    char *arg = (char *) p;
    va_list s;
    va_start(s, *p);
    
    while(*arg){
        if('%' == *arg) {
            arg++;
            if(*arg == 'd') {
                int temp = va_arg(s, int);
                if(temp < 0) {
                    putchar('-');
                    if(temp == INT32_MIN) {
                        temp = INT32_MAX;   
                    } else {
                    temp = -temp;
                    }         
                }
                int num[15] = {0};
                while(temp != 0) {
                    num[++num[0]] = temp % 10;
                    temp /= 10;
                }
                while(num[0]) {
                    putchar('0' + num[num[0]]);
                    num[0]--;
                }
                
            }
        }
            
         else {
            putchar(*arg);
        }
    arg++;
    }
    va_end(s);
    return 0;
}
int main() {
    
    my_printf("hello haizei\n");
    my_printf("n = %d\n", 12000);
    my_printf("n = %d\n", -456);
    my_printf("n = %d\n", INT32_MAX);
    my_printf("n = %d\n", INT32_MIN);
    return 0;
}
