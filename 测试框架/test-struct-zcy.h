#include <string.h>

#ifndef _TEST_H
#define _TEST_H

//以下是全局变量
int last = -1;    //设置上一个EXPECT的位置，初始值为-1
char s[105][105][3][105] = {0};  //s[i][j][0],s[i][j][1]分别用来存储第i个TEST的第j个EXPECT(a, b)中的a, b
//s[i][j][2]用来存储true或false
int num[105] = {0};    //num[i]用来存储第i个TEST有多少个EXPECT，其中num[0]用于存储TEST个数
int acc[105] = {0};    //acc[i]用来存储第i个TEST有多少个正确的EXPECT

//以下是TEST(a, b)宏定义，每执行一个TEST时__COUNTER__加1
#define _FUNC(a, b, c) a##_##b
#define FUNC(a, b, c) _FUNC(a, b, c) //直到此时，c(也就是__COUNTER__)才会加1
#define TEST(a, b) \
__attribute__((constructor)) void FUNC(a, b, __COUNTER__)()

//以下是EXPECT(a, b)宏定义
#define EXPECT(a, b) {\    
    __COUNTER__;\    //上下两句可知，每执行一个EXPECT时__COUNTER__会加2
    int now = __COUNTER__;\
    if (now  - last == 3) {\  //因此当两次差值为3时，代表到了下一个TEST
        num[0]++;\
    }\
    num[num[0]]++;\
    strcpy(s[num[0]][num[num[0]]][0], #a);\
    strcpy(s[num[0]][num[num[0]]][1], #b);\
    if(a == b) {\
        acc[num[0]]++;\
        strcpy(s[num[0]][num[num[0]]][2], "True");\
    } else {\
        strcpy(s[num[0]][num[num[0]]][2], "False");\
    }\
    last = now;\      //每次执行EXPECT后更新LAST
}

int run() {
    for (int i = 1; i <= num[0]; i++) {
        for (int j = 1; j <= num[i]; j++) {
            printf("%s == %s  %s\n", s[i][j][0], s[i][j][1], s[i][j][2]);
        }
        printf("num = %d, acc = %d\n", num[i], acc[i]);
    }
    return 0;
}

#define RUN_ALL_TEST() run()   //宏替换为run()函数

#endif
