/*************************************************************************
	> File Name: test.h
	> Author: 
	> Mail: 
	> Created Time: 2019年01月15日 星期二 09时32分36秒
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H
#define _FUNC_NAME(a, b) a##b
#define FUNC_NAME(a, b) _FUNC_NAME(a, b)

#define TEST(a, b)\
__attribute__((constructor)) void FUNC_NAME(test, __COUNTER__)()\

#endif
