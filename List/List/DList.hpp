//
//  DList.hpp
//  List
//
//  Created by Jason_Sam on 21/03/2017.
//  Copyright © 2017 Jason_Sam. All rights reserved.
//

#ifndef DList_hpp
#define DList_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct DListElem_{
    void   *data;
    struct DListElem_ *prev;
    struct DListElem_ *next;
}DListElem;

typedef struct DList_{
    int       size;
    void      (*destroy)(void *data);
    DListElem *head;
    DListElem *tail;
}DList;

DList* dlist_init(DList *list, void (*destroy)(void *data));
void dlist_destroy(DList *list);
int  dlist_ins_next(DList *list, DListElem *element, const void *data);
int  dlist_ins_prev(DList *list, DListElem *element, const void *data);
int  dlist_remove(DList *list, DListElem *element, void **data);
int  dlist_create(DList *list, const int num);
void dlist_display(DList *list, DListElem *element);


#endif /* DList_hpp */
