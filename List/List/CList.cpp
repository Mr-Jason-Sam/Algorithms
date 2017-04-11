//
//  CList.cpp
//  List
//
//  Created by Jason_Sam on 21/03/2017.
//  Copyright © 2017 Jason_Sam. All rights reserved.
//

#include "CList.hpp"

//inline fun
void print(void *data);
//

CList*  clist_init(CList *list, void (*destroy)(void *data)){
    if ((list = (CList*)malloc(sizeof(CList))) == NULL) {
        return NULL;
    }
    list->size    = 0;
    list->destroy = destroy;
    list->head    = NULL;
    return list;
}

void clist_destroy(CList *list){
    void *data;
    
    if ((clist_rem_next(list, list->head, (void **)&data) == 0) && (list->destroy != NULL)) {
        list->destroy(data);
    }
    memset(list, 0, sizeof(CList));
    return;
}

int  clist_ins_next(CList *list, CListElem *element, const void *data){
    CListElem *new_element;
    
//    if (element == NULL) {
//        return -1;
//    }
    
    if ((new_element = (CListElem*)malloc(sizeof(CListElem))) == NULL) {
        return -1;
    }
    
    new_element->data = (void *)data;
    if (list->size == 0) {
        new_element->next = new_element;
        list->head = new_element;
    }else{
        new_element->next = element->next;
        element->next     = new_element;
    }
    list->size++;
    return 0;
}

int  clist_rem_next(CList *list, CListElem *element, void **data){
    CListElem *old_element;
    
    if (list->size == 0) {
        return -1;
    }
    
    data = &element->next->data;
    old_element = element->next;
    
    if (element->next == element) {
        list->head = NULL;
    }else{
        element->next = element->next->next;
        if (old_element == list->head) {
            list->head = old_element->next;
        }
    }
    free(old_element);
    list->size--;
    return 0;
}

void clist_create(CList *list, const int num){
    for (int index = 0; index < num; index++) {
        clist_ins_next(list, list->head, (int *)index);
    }
    return;
}

void print(void *data){
    cout << data << endl;
}

void clist_display(CList *list, CListElem *element){
    CListElem *reach;
    
    reach = list->head;
    
    while (reach) {
        print(reach->data);
        if (reach == element) {
            break;
        }
        reach = reach->next;
    }
    return;
}





