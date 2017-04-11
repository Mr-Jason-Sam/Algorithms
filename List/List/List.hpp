//
//  List.hpp
//  List
//
//  Created by Jason_Sam on 21/03/2017.
//  Copyright © 2017 Jason_Sam. All rights reserved.
//

#ifndef List_hpp
#define List_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct ListElem_{
    void *data;
    struct ListElem_ *next;

}ListElem;

typedef struct List_{
    int size;
    void (*destroy)(void *data);
    ListElem *head;
    ListElem *tail;
}List;

List* list_init(List *list, void (*destroy)(void *data));
void list_destroy(List *list);
int  list_ins_next(List *list, ListElem *element, const void *data);
int  list_rem_next(List *list, ListElem *element, void **data);
void list_create(List *list, const int num);
void list_display(List *list, ListElem *element);



#endif /* List_hpp */




