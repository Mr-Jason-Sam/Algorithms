//
//  CList.hpp
//  List
//
//  Created by Jason_Sam on 21/03/2017.
//  Copyright © 2017 Jason_Sam. All rights reserved.
//

#ifndef CList_hpp
#define CList_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct CListElem_{
    void *data;
    struct CListElem_ *next;
}CListElem;

typedef struct CList_ {
    int size;
    void (*destroy)(void *data);
    CListElem_ *head;
}CList;

CList* clist_init(CList *list, void (*destroy)(void *data));
void clist_destroy(CList *list);
int  clist_ins_next(CList *list, CListElem *element, const void *data);
int  clist_rem_next(CList *list, CListElem *elemnet, void **data);
void clist_create(CList *list, const int num);
void clist_display(CList *list, CListElem *element);

#endif /* CList_hpp */
