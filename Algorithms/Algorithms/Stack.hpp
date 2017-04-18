//
//  Stack.hpp
//  Algorithms
//
//  Created by Jason_Sam on 2017/4/16.
//  Copyright © 2017年 Jason_Sam. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>
#include <iostream>
#define MAX 5
using namespace std;


typedef struct Stack_{
    int data[MAX];
    int top;
}Stack;

int stack_create(Stack **stack);
bool stack_empty(Stack *stack);
bool stack_full(Stack *stack);
int stack_pop(Stack *stack);
int stack_push(Stack *stack, const int data);
int stack_gettop(Stack *stack);

/*--------------link stack------------------*/
typedef struct LSElem_{
    int data;
    struct LSElem_ *next;
}LSElem;

typedef struct SLink_{
    int size;
    LSElem *head;
}SLink;

int link_stack_create(SLink **link);
int link_stack_pop(SLink *top);
int link_stack_push(SLink *top, const int data);
int link_stack_gettop(SLink *top);

/*--------------link stack------------------*/

void excute_stack();

#endif /* Stack_hpp */


