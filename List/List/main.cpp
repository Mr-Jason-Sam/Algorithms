//
//  main.cpp
//  List
//
//  Created by Jason_Sam on 21/03/2017.
//  Copyright © 2017 Jason_Sam. All rights reserved.
//

#include <iostream>
#include "List.hpp"
#include "DList.hpp"
#include "CList.hpp"
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    
    return 0;
}
//void **old_data;
//old_data = (void*)malloc(sizeof(4));

//list operate
//    List *list;
//    ListElem *temp_list_ele;
/*   list = list_init(list, NULL);
 list_create(list, 10);
 temp_list_ele = list->head;
 list_ins_next(list, temp_list_ele, (int *)11);
 list_display(list, NULL);
 cout << "remove list tail" << endl;
 temp_list_ele = list->head->next;
 list_rem_next(list, temp_list_ele, old_data);
 list_display(list, NULL);
 //cout << "This is " <<  *(*old_data) << endl;
 list_destroy(list);
 list_display(list, NULL);*/
//

//dlist operate
//    DList *d_list;
//    DListElem *temp_dlist_ele;
//    d_list = dlist_init(d_list, NULL);
//    dlist_create(d_list, 10);
//    temp_dlist_ele = d_list->head;
//    dlist_ins_next(d_list, temp_dlist_ele, (int *)13);
//    temp_dlist_ele = d_list->tail;
//    dlist_ins_prev(d_list, temp_dlist_ele, (int *)15);
//    dlist_display(d_list, NULL);
//    cout << "remove double list!" <<endl;
//    dlist_remove(d_list, d_list->head->next->next, old_data);
//    dlist_display(d_list, NULL);
//    dlist_destroy(d_list);
//    dlist_display(d_list, NULL);
//

//clist operate
//    CList *c_list;
//    CListElem *temp_clist_ele;
//    if((c_list = clist_init(c_list, NULL)) == NULL)
//        exit(1);
//    clist_create(c_list, 10);
//    cout << c_list->size <<endl;
//    temp_clist_ele = c_list->head->next;
//    clist_ins_next(c_list, temp_clist_ele, (int *)15);
//    clist_display(c_list, c_list->head->next->next->next);
//    cout << "remove" <<endl;
//    clist_rem_next(c_list, c_list->head, old_data);
//    clist_display(c_list, c_list->head->next->next->next);
//    cout << "destroy List" << endl;
//    clist_destroy(c_list);
//    clist_display(c_list, NULL);
//
