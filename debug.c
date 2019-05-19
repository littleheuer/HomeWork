/*************************************************************************
	> File Name: debug.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月09日 星期三 20时27分11秒
 ************************************************************************/

#include<stdio.h>

#define DEBUG
#ifdef DEBUG
#define P(a) {\
    printf("%s : %s : %d]%s : %d\n", __FILE__,__func__, __LINE__, #a, a);\
}
#else
#define Pa(a) {}
#endif

#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

#define MAX(a, b) ({\
    __typeof(a) __a = a;\
    __typeof(b) __b = b;\
    (__a) > (__b) ? (__a) : (__b);\
})
#define LINK a##b

//加入括号则变为整体了
//#ifdef 如果定义了DEBUG则执行随后的语句，未定义则不预处理如下语句。
//直接注释掉#define 则debug的语句不被执行。
//#a 替换成字符串a
int main() {
    P(MAX(2, 3));
    P(5 + MAX(2, 3));
    P(MAX(2, 3 > 4 ? 3: 4));
    int a = 7;
    P(MAX(a++, 6));
    P(a);
    printf("%s", )
    return 0;
}
