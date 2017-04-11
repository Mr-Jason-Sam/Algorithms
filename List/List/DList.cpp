//
//  DList.cpp
//  List
//
//  Created by Jason_Sam on 21/03/2017.
//  Copyright © 2017 Jason_Sam. All rights reserved.
//

#include "DList.hpp"

void display(void *data);

DList* dlist_init(DList *list, void (*destroy)(void *data)){
    if ((list = (DList*)malloc(sizeof(DList))) == NULL) {
        return NULL;
    }
    
    list->size    = 0;
    list->destroy = destroy;
    list->head    = NULL;
    list->tail    = NULL;
    
    return list;
}

void dlist_destroy(DList *list){
    void *data;
    if ((dlist_remove(list, list->tail, (void **)&data) == 0) && list->destroy != 0) {
        list->destroy(data);
    }
    memset(list, 0, sizeof(DList));
    
    return;
}

int  dlist_ins_next(DList *list, DListElem *element, const void *data){
    DListElem *new_element;
    
    if (element == NULL && list->size != 0) {
        return -1;
    }
    
    if ((new_element = (DListElem*)malloc(sizeof(DListElem))) == NULL) {
        return -1;
    }
    new_element->data = (void *)data;
    if (list->size == 0) {
        list->head = new_element;
        new_element->prev = NULL;
        new_element->next = NULL;
        list->tail = new_element;
    }else{
        if (element == list->tail)
            list->tail = new_element;
        else
            element->next->prev = new_element;
        new_element->next   = element->next;
        new_element->prev   = element;
        element->next       = new_element;
    }
    list->size++;
    return 0;
}

int  dlist_ins_prev(DList *list, DListElem *element, const void *data){
    DListElem *new_element;
    
    if (element == NULL && list->size != 0)
        return -1;
    
    if ((new_element = (DListElem*)malloc(sizeof(DListElem))) == NULL)
        return -1;
    
    new_element->data = (void *)data;
    if (list->size == 0) {
        list->head        = new_element;
        new_element->prev = NULL;
        new_element->next = NULL;
        list->tail        = new_element;
    }else{
        if (element == list->head)
            list->head = new_element;
        else
            element->prev->next = new_element;
        new_element->prev = element->prev;
        new_element->next = element;
        element->prev     = element;
    }
    list->size++;
    return 0;
}
int  dlist_remove(DList *list, DListElem *element, void **data){
    //DListElem *old_element;
    
    if (list->size == 0 ||element == NULL) {
        return -1;
    }
    data = &element->data;
    if (element == list->head) {
        if (list->head == NULL) {
            list->tail = NULL;
        }else{
            element->next->prev = NULL;
        }
        list->head = element->next;
    }else{
        if (element == list->tail) {
            list->tail = element->prev;
        }else{
            element->next->prev = element->prev;
        }
        element->prev->next = element->next;
    }
    free(element);
    list->size--;
    return 0;
}

int dlist_create(DList *list, const int num){
    DListElem *element;
    if ((element = (DListElem*)malloc(sizeof(DListElem))) == NULL) {
        return -1;
    }
    
    list->tail = element;
    
    for (int index = 0; index < num; index++) {
        dlist_ins_next(list, list->tail, (int*)index);
    }
    return 0;
}

void dlist_display(DList *list, DListElem *element){
    DListElem *reach;
    reach = list->head;
    
    if (reach == NULL) {
        cout << "List is NULL" <<endl;
        exit(1);
    }
    
    while (reach) {
        display(reach->data);
        if(reach == element)
            break;
        reach = reach->next;
    }
}

void display(void *data){
    cout << data <<endl;
}




