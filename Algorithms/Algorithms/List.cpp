//
//  List.cpp
//  Algorithms
//
//  Created by Jason_Sam on 2017/4/12.
//  Copyright © 2017年 Jason_Sam. All rights reserved.
//

#include "List.hpp"
/*-----------------List----Start-----------------*/

int list_init(List **list){
    if ((*list = (List*)malloc(sizeof(List))) == NULL) {
        return -1;
    }
    (*list)->head = NULL;
    (*list)->tail = NULL;
    (*list)->size = 0;
    return 0;
}

int list_create(List **list){
    char ch;
    list_init(list);
    while (cin >> ch) {
        if (ch == '#')
            break;
        if(list_ins_next(*list, NULL, ch) != 0)
            exit(1);
    }
    return 0;
}
int list_ins_next(List *list, ListElem *element, const char data){
    ListElem *new_elem;
    if ((new_elem = (ListElem*)malloc(sizeof(ListElem)))==NULL) {
        return -1;
    }
    new_elem->data = data;
    if (element == NULL) {
        if (list->size == 0) {
            list->head = list->tail = new_elem;
        }
//        头插法
//        new_elem->next = list->head;
//        list->head     = new_elem;
        
//        尾插法
        list->tail->next = new_elem;
        list->tail = new_elem;
    }else{
        if (element == list->tail) {
            list->tail = new_elem;
        }
        new_elem->next = element->next;
        element->next  = new_elem;
    }
    list->tail->next = NULL;
    list->size++;
    return 0;
}
int list_rem_next(List *list, ListElem *element, char *data){
    ListElem *old_elem;
    if (list->size == 0) {
        return -1;
    }
    if (element == NULL) {
        old_elem   = list->head;
        data       = &old_elem->data;
        list->head = old_elem->next;
    }else{
        if (element == list->tail) {
            return -1;
        }
        old_elem = element->next;
        data = &old_elem->data;
        element->next = old_elem->next;
        if (element->next == NULL) {
            list->tail = element;
        }
    }
    free(old_elem);
    return 0;
}
void list_display(const List *list){
    ListElem *find = list->head;
    while (find) {
        cout << find->data << "  ";
        if (find->next) {
            find = find->next;
        }else
            break;
    }
}
/*-----------------List----End-----------------*/


/*-----------------DList----Start--------------*/

int dlist_init(DList **dlist){
    if ((*dlist = (DList*)malloc(sizeof(DList))) == NULL) {
        return -1;
    }
    (*dlist)->size = 0;
    (*dlist)->head = NULL;
    (*dlist)->tail = NULL;
    return 0;
}
int dlist_create(DList **dlist){
    char ch;
    cin >> ch;
    dlist_init(dlist);
    while (cin >> ch) {
        if (ch == '#') {
            break;
        }
        //(*dlist)->tail->data = ch;
        if ((dlist_ins_next(*dlist, (*dlist)->tail, ch))) {
            exit(1);
        }
    }
    return 0;
}
int dlist_ins_next(DList *dlist, DListElem *element, const char data){
    DListElem *new_elem;
    if (element == NULL && dlist->size != 0) {
        return -1;
    }
    
    if ((new_elem = (DListElem*)malloc(sizeof(DListElem))) == NULL) {
        return -1;
    }
    new_elem->data = data;
    if (dlist->size == 0) {
        dlist->head = new_elem;
        new_elem->prev = NULL;
        new_elem->next = NULL;
        dlist->tail = new_elem;
    }else{
        if (element == dlist->tail)
            dlist->tail = new_elem;
        else
            element->next->prev = new_elem;
        new_elem->next   = element->next;
        new_elem->prev   = element;
        element->next       = new_elem;
    }
    dlist->size++;
    return 0;
}
int dlist_ins_prev(DList *dlist, DListElem *element, const char data){
    DListElem *new_elem;
    if (element == NULL && dlist->size != 0)
        return -1;
    
    if ((new_elem = (DListElem*)malloc(sizeof(DListElem))) == NULL)
        return -1;
    
    new_elem->data = data;
    if (dlist->size == 0) {
        dlist->head        = new_elem;
        new_elem->prev = NULL;
        new_elem->next = NULL;
        dlist->tail        = new_elem;
    }else{
        if (element == dlist->head)
            dlist->head = new_elem;
        else
            element->prev->next = new_elem;
        new_elem->prev = element->prev;
        new_elem->next = element;
        element->prev     = element;
    }
    dlist->size++;
    return 0;
}
int dlist_remove(DList *dlist, DListElem *element, char *data){
    DListElem *old_elem = nullptr;
    if (dlist->size == 0) {
        return -1;
    }
    if (element == NULL) {
        old_elem = dlist->tail;
        data = &old_elem->data;
        dlist->tail->prev->next = dlist->tail->next;
    }else{
        old_elem = element;
        data = &old_elem->data;
        if (element == dlist->head) {
            element->next->prev = NULL;
            dlist->head = element->next;
        }
        if (element == dlist->tail) {
            element->prev->next = NULL;
            dlist->tail = element->prev;
        }
        element->prev->next = element->next;
        element->next->prev = element->prev;
    }
    free(old_elem);
    dlist->size--;
    return 0;
}
void dlist_display(const DList *dlist){
    DListElem *reach = dlist->head;
    while (reach) {
        cout << reach->data << "  ";
        if (reach->next) {
            reach = reach->next;
        }else
            break;
    }
}

/*-----------------DList--End----------------*/

/*-----------------CList--Start--------------*/

int clist_init(CList **clist){
    if ((*clist = (CList*)malloc(sizeof(CList))) == NULL) {
        return -1;
    }
    (*clist)->size = 0;
    (*clist)->head = NULL;
    return 0;
}
int clist_create(CList **clist){
    char ch;
    clist_init(clist);
    while (cin >> ch) {
        if (ch == '#') {
            break;
        }
        if (clist_ins_next(*clist, (*clist)->head, ch)) {
            exit(1);
        }
    }
    
    return 0;
}
int clist_ins_next(CList *clist, CListElem *element, const char data){
    CListElem *new_elem;
    if ((new_elem = (CListElem*)malloc(sizeof(CListElem))) == NULL) {
        return -1;
    }
    new_elem->data = data;
    
    if (clist->size == 0) {
        clist->head = new_elem;
        new_elem->next = new_elem;
    }
    else{
        new_elem->next = element->next;
        element->next = new_elem;
    }
    clist->size++;
    return 0;
}
int clist_rem_next(CList *clist, CListElem *element, char *data){
    CListElem *old_elem;
    if (clist->size == 0 || element == NULL) {
        return -1;
    }
    old_elem = element->next;
    data = &old_elem->data;
    
    if (element->next == element) {
        clist->head = NULL;
    }else{
        if (element->next == clist->head) {
            clist->head = clist->head->next;
        }else{
            element->next = element->next->next;
        }
    }
    free(old_elem);
    clist->size--;
    return 0;
}
void clist_display(const CList *clist){
    CListElem *reach = clist->head;
    while (reach) {
        cout << reach->data << "  ";
        if (reach->next != clist->head) {
            reach = reach->next;
        }else
            break;
    }
}

void excute_list(){
//    List *list = NULL;
//    char data;
//    list_create(&list);
//    list_ins_next(list, list->head, 'w');
//    list_ins_next(list, list->tail, '2');
//    list_rem_next(list, list->head->next, &data);
//    list_display(list);
//    DList *dlist = NULL;
//    char data;
//    dlist_create(&dlist);
//    dlist_ins_next(dlist, dlist->head->next, 'w');
//    dlist_ins_prev(dlist, dlist->head->next, '4');
//    dlist_ins_next(dlist, dlist->tail, 't');
//    dlist_ins_prev(dlist, dlist->head, 'h');
//    dlist_remove(dlist, dlist->head->next->next, &data);
//    dlist_display(dlist);
    CList *clist = NULL;
    char data;
    clist_create(&clist);
    clist_ins_next(clist, clist->head->next, 'w');
    clist_rem_next(clist, clist->head->next->next, &data);
    clist_display(clist);
    cout << endl;
}



