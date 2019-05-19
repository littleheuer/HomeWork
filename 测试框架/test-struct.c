/*************************************************************************
	> File Name: 190115-test-2.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月15日 星期二 10时54分26秒
 ************************************************************************/

#include<stdio.h>
#include"test-struct.h"
int add(int a, int b) {
    return a + b;
}

int is_prime(int x) {
    if(x <= 1) return 0;
    for(int i = 2; i * i < x; i++) {
        if(x % i == 0) return 0;
    }
    return 1;
}
int sum(int x) {
    if(x < 0) return -1;
    int sum = 0;
    for(int i = 1; i <= x; i++) {
        sum += i;
    }
    return sum;
}
TEST(test, is_prime_func) {
    EXPECT(is_prime(2), 0);
    EXPECT(is_prime(-1), 0);
    EXPECT(is_prime(15), 0);
    EXPECT(is_prime(9973), 1);
}

TEST(test, add_func) {
    EXPECT(add(1, 4), 5);
    EXPECT(add(3, 4), 7);
}

TEST(test, sum) {
    EXPECT(sum(-1), -1);
    EXPECT(sum(2), 3);
    EXPECT(sum(4), 28);
}

int main() {

    return RUN_ALL_TESTS();
}
