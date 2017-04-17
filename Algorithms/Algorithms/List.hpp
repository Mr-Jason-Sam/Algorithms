//
//  List.hpp
//  Algorithms
//
//  Created by Jason_Sam on 2017/4/12.
//  Copyright © 2017年 Jason_Sam. All rights reserved.
//

#ifndef List_hpp
#define List_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct ListElem_{
    char data;
    struct ListElem_ *next;
}ListElem;

typedef struct List_{
    int size;
    ListElem *head,*tail;
}List;

typedef struct DListElem_{
    char data;
    struct DListElem_ *next,*prev;
}DListElem;

typedef struct DList_{
    int size;
    DListElem *head,*tail;
}DList;

typedef struct CListElem_{
    char data;
    struct CListElem_ *next;
}CListElem;

typedef struct CList_{
    int size;
    CListElem *head;
}CList;

int list_init(List **list);
int list_create(List *list);
int list_ins_next(List *list, ListElem *element, const char data);
int list_rem_next(List *list, ListElem *element, char *data);
void list_display(const List *list);

int dlist_init(DList **dlist);
int dlist_create(DList *dlist);
int dlist_ins_prev(DList *dlist, DListElem *element, const char data);
int dlist_ins_next(DList *dlist, DListElem *element, const char data);
int dlist_remove(DList *dlist, DListElem *element, char *data);
void dlist_display(const DList *dlist);

int clist_init(CList **clist);
int clist_create(CList *clist);
int clist_ins_next(CList *clist, CListElem *element, const char data);
int clist_rem_next(CList *clist, CListElem *element, char *data);
void clist_display(const CList *clist);

void excute_list();



#endif /* List_hpp */
