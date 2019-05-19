/*************************************************************************
	> File Name: test.h
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月15日 星期二 13时59分53秒
 ************************************************************************/
#include<string.h>
#include<stdlib.h>
#ifndef _TEST_H
#define _TEST_H
typedef struct node{
    void (*func_test)();
    char * name1,* name2;
    int result_all,result_right;
    struct node* next;
}Node;

Node* head = NULL;
Node* preNode = NULL;

#define add_node(func,a,b) {\
    if(head == NULL){head = malloc(sizeof(Node));preNode = head;}\
    Node* newnode = malloc(sizeof(Node));\
    newnode -> func_test = func;\
    newnode -> name1 = #a;\
    newnode -> name2 = #b;\
    preNode -> next = newnode;\
    preNode = preNode -> next;\
}

#define TEST(name1,name2)  F_name(test, __COUNTER__,name1,name2)
#define F_name(a,b,c,d) _F_name(a,b,c,d)
#define _F_name(test,count,name1,name2) void test##count(Node*);\
        __attribute__((constructor))void add##test##count(){\
            add_node(test##count,name1,name2);}\
        void test##count(Node* nodeP)

#define EXPECT(a,b){\
    printf("%s\t == %s\t :",#a,#b);\
    if(a == b){nodeP -> result_right++;printf("True\n");}\
    else {printf("False\n");}\
    nodeP -> result_all ++;\
} 

int RUN_ALL_TEST(){
    head = head -> next;
    while(head){
        printf("[%s %s]\n",head->name1,head->name2);
        head->func_test(head);
        if(head->result_right == head->result_all)
        printf("[\033[42m %0.2f%%  \033[0m] total : %d pass : %d\n",100.0 * head->result_right/head -> result_all,head->result_all,head->result_right);
        else
        printf("[\033[41m %0.2f%%  \033[0m] total : %d pass : %d\n",100.0 * head->result_right/head -> result_all,head->result_all,head->result_right);
        preNode = head;
        head = head -> next;
        free(preNode);
    }
}

#endif
