//
//  Stack.cpp
//  Algorithms
//
//  Created by Jason_Sam on 2017/4/16.
//  Copyright © 2017年 Jason_Sam. All rights reserved.
//

#include "Stack.hpp"
#include "List.hpp"

int stack_create(Stack **stack){
    if ((*stack = (Stack*)malloc(sizeof(Stack))) == NULL) {
        return -1;
    }
    (*stack)->top  = 0;
    return 0;
}
bool stack_empty(Stack *stack){
    return stack->top == 0;
}
bool stack_full(Stack *stack){
    return stack->top == MAX;
}
int stack_pop(Stack *stack){
    if (stack_empty(stack)) {
        return -1;
    }
    stack->top--;
    return 0;
}
int stack_push(Stack *stack, const int data){
    if (stack_full(stack)) {
        return -1;
    }
    stack->data[stack->top++] = data;
    return 0;
}
int stack_gettop(Stack *stack){
    return stack->data[stack->top-1];
}

/*--------------link stack------------------*/

int link_stack_create(SLink **link){
    if ((*link = (SLink*)malloc(sizeof(SLink))) == NULL) {
        return -1;
    }
    (*link)->size = 0;
    (*link)->head= NULL;
    return 0;
}

int link_stack_pop(SLink *link){
    LSElem *old_elem;
    if (link->head == NULL) {
        return -1;
    }
    int data = link->head->data;
    old_elem = link->head;
    if(link->head->next != NULL)
        link->head = link->head->next;
    free(old_elem);
    return data;
}
int link_stack_push(SLink *link, const int data){
    LSElem *new_elem;
    if ((new_elem = (LSElem*)malloc(sizeof(LSElem))) == NULL) {
        return -1;
    }
    new_elem->data = data;
    if (link->head != NULL) {
        new_elem->next = link->head;
    }
    link->head = new_elem;
    return 0;
}
int link_stack_gettop(SLink *link){
    return link->head->data;
}

/*--------------link stack------------------*/

void excute_stack(){
    Stack *elem = NULL;
    stack_create(&elem);
    for (int i =0; i < MAX; i++) {
        stack_push(elem,i);
    }
    cout << stack_gettop(elem);
    stack_pop(elem);
    cout << stack_gettop(elem);
    stack_pop(elem);
    cout << stack_gettop(elem);
    cout <<endl;
    
//    SLink *list = NULL;
//    link_stack_create(&list);
//    for (int i =0; i < MAX; i++) {
//        link_stack_push(list, i);
//    }
//    cout << link_stack_gettop(list);
//    link_stack_pop(list);
//    cout << link_stack_gettop(list);
//    link_stack_pop(list);
//    cout << link_stack_gettop(list);
//    cout << endl;
    
}

