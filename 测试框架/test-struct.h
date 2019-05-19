/*************************************************************************
    > File Name: test22.h
	> Author: 
	> Mail: 
	> Created Time: 2019年01月15日 星期二 11时08分41秒
 ************************************************************************/
#ifndef _TEST22_H
#define _TEST22_H
#include<stdlib.h>

typedef struct testFuncData {
    int total, expect;
} TestFuncData;

typedef void (*test_func_p)(TestFuncData *);

typedef struct funcData{
    const char *a_name, *b_name;
    test_func_p test_func;
    struct funcData *next;
} FuncData;

FuncData* head = NULL;
FuncData* pre = NULL;
#define ADD(func, a, b) {\
    if(head == NULL) {\
        head = (FuncData *)malloc(sizeof(FuncData));\
        pre = head;\
    }\
    FuncData* newfunc = (FuncData *)malloc(sizeof(FuncData));\
    newfunc->a_name = #a;\
    newfunc->b_name = #b;\
    newfunc->test_func = func;\
    pre->next = newfunc;\
    pre = newfunc;\
}

#define TEST(a, b) FUNC_NAME(a, b, __COUNTER__)

#define FUNC_NAME(a, b, c) _FUNC_NAME(a, b, c)

#define _FUNC_NAME(name1, name2, count) \
    void name2##count(TestFuncData* ); \
    __attribute__((constructor)) void add##test##count() { \
    ADD(name2##count, name1, name2);\
    } \
    void name2##count(TestFuncData* data_p)

#define EXPECT(a, b) ({\
    printf("%s\t=\t%s\t%s\n", #a, #b, (a == b) ? "True" : "False");\
    data_p->total++;\
    data_p->expect += (a == b);\
})

#define RUN_ALL_TESTS() run_test()

int run_test() {
    char color[2][100] = {
        "[  \033[1;31m%.2f%%  \033[0m] total : %d expect : %d\n",
        "[  \033[1;32m%.2f%%  \033[0m] total : %d expect : %d\n"
    };
    head = head->next;
    while(head) {
        TestFuncData data = {0, 0};
        printf("[%s %s]\n", head->a_name, head->b_name);
        head->test_func(&data);
        int result = (data.total == data.expect);
        printf(color[result], 1.0 * data.expect / data.total * 100, data.total, data.expect);
        pre = head;
        head = head->next;
        free(pre);
    }
    return 0;
}
#endif
