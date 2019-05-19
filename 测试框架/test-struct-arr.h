/*************************************************************************
	> File Name: test2.h
	> Author: 
	> Mail: 
	> Created Time: 2019年01月15日 星期二 11时08分41秒
 ************************************************************************/
#include<string.h>
#ifndef _TEST2_H
#define _TEST2_H
//str 第i个test 第j个EXPECT的a、b值和真值
char str[100][100][4][100];
int te_ex[100] = {0};
int ex[100] = {0};
int end = -1;



#define EXPECT(a, b) ({\
    int now = __COUNTER__;\
    if(now - end == 2) {\
        ++te_ex[0];\
        strcpy(str[te_ex[0]][0][3], __func__);\
    }\
    ++te_ex[te_ex[0]];\
    strcpy(str[te_ex[0]][te_ex[te_ex[0]]][0], #a);\
    strcpy(str[te_ex[0]][te_ex[te_ex[0]]][1], #b);\
    if(a == b) {\
        strcpy(str[te_ex[0]][te_ex[te_ex[0]]][2], "TRUE");\
        ex[te_ex[0]]++;\
    }\
    else {\
        strcpy(str[te_ex[0]][te_ex[te_ex[0]]][2], "FALSE");\
    }\
    end = now;\
})

#define _FUNC_NAME(a, b, c) b
#define FUNC_NAME(a, b, c) _FUNC_NAME(a, b, c)

#define TEST(a, b)\
    __attribute__((constructor)) void FUNC_NAME(a, b, __COUNTER__)()

#define RUN_ALL_TESTS() run_test()



int run_test() {
    char color[2][40] = {
        "[\033[0;32m%.2f%%\033[0m]total = %d, accept = %d\n",
        "[\033[0;31m%.2f%%\033[0m]total = %d, accept = %d\n"
    }
    for(int i = 1; i <= te_ex[0]; i++) {
        printf("[test %s]\n", str[i][0][3]);
        for(int j = 1; j <= te_ex[i]; j++) {
            printf("%s\t=\t%s\t%s\n", str[i][j][0], str[i][j][1], str[i][j][2]);
        }
        float per = ((float) ex[i] / (float)te_ex[i] * 100);
        if(per == 100.0) {
        printf("[\033[0;32m%.2f%%\033[0m]total = %d, accept = %d\n", per, te_ex[i], ex[i]);
        }
        else {
            printf("[\033[0;31m%.2f%%\033[0m]total = %d, accept = %d\n", per, te_ex[i], ex[i]);
        }

    }
    return 0;
}
#endif
