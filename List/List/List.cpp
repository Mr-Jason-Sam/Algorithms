//
//  List.cpp
//  List
//
//  Created by Jason_Sam on 21/03/2017.
//  Copyright © 2017 Jason_Sam. All rights reserved.
//

#include "List.hpp"
//inline fun
void diaplay(void *data);
//


List* list_init(List *list, void (*destroy)(void *data)){
    if ((list = (List*)malloc(sizeof(List))) == NULL){
        return NULL;
    }
    list->size    = 0;
    list->destroy = destroy;
    list->head    = NULL;
    list->tail    = NULL;
    
    return list;
}

void list_destroy(List *list){
    void *data;
    
    if ((list_rem_next(list, NULL, (void **)&data) == 0) && list->destroy != NULL) {
        list->destroy(data);
    }
    memset(list, 0, sizeof(List));
    return;
}

int  list_ins_next(List *list, ListElem *element, const void *data){
    ListElem *new_element;
    
    if ((new_element = (ListElem*)malloc(sizeof(ListElem))) == NULL) {
        return -1;
    }
    
    new_element->data = (void *)data;
    
    if (element == NULL) {
        if(list->size == 0){
            list->tail = new_element;
        }
        new_element->next = list->head;
        list->head = new_element;
        
    }else{
        if (element == list->tail) {
            list->tail = new_element;
        }
        new_element->next = element->next;
        element->next = new_element;
    }
    list->size++;
    return 0;
}

int  list_rem_next(List *list, ListElem *element, void **data){
    ListElem *old_element;
    
    if (list->size == 0) {
        return -1;
    }
    
    if (element == NULL) {
        data       = &list->head->data;
        old_element = list->head;
        list->head  = list->head->next;
        if (list->size == 1) {
            list->tail = NULL;
        }
    }else{
        if (element == list->tail) {
            return -1;
        }
        data = &element->next->data;
        old_element = element->next;
        element->next = element->next->next;
        if (element->next == NULL) {
            list->tail = element;
        }
    }
    free(old_element);
    list->size--;
    return 0;
}


void list_create(List *list, const int num){
    for (int index = 0; index < num; index++) {
        list_ins_next(list, NULL, (int *)index);
    }
}

void list_display(List *list, ListElem *element){
    ListElem *reach;
    reach = list->head;
    
    if (reach == NULL) {
        cout << "List is NULL" <<endl;
        exit(1);
    }

    while (reach) {
        diaplay(reach->data);
        if (reach == element)
            break;
        reach = reach->next;
    }
    return;
}

void diaplay(void *data){
    cout << data <<endl;
    return;
}





