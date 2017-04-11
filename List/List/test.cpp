//
//  test.cpp
//  List
//
//  Created by Jason_Sam on 28/03/2017.
//  Copyright © 2017 Jason_Sam. All rights reserved.
//

#include "test.hpp"


typedef struct BitreeElem_{
    int data;
    int layer;
    vector<struct BitreeElem_*> child;
}BitreeElem;

typedef struct Bitree_{
    int layer;
    BitreeElem *root;
}Bitree;


int num = 0;
Bitree* approximate(Bitree *tree,BitreeElem *parent,const int data,const int finish){
    BitreeElem *node;
    
    //if (parent == tree->root) {
    //  parent->layer = 1;
    //}
    if ((parent = (BitreeElem*)malloc(sizeof(BitreeElem))) == NULL) {
        return NULL;
    }
    for (int index = 1; index <= data; index++) {
        for (int values = 1; values <= index; values++) {
            if (data%values == 0) {
                if (values != 1 || values != data) {
                    if ((node = (BitreeElem*)malloc(sizeof(BitreeElem))) == NULL) {
                        return NULL;
                    }
                    node->data = values;
                    parent->child.push_back(node);
                    node->layer = parent->layer+1;
                    if (parent->data+node->data < finish) {
                        approximate(tree,node, parent->data+node->data, finish);
                    }else if(parent->data+node->data == finish){
                        if (num == 0) {
                            num = node->layer;
                            
                        }
                        if (num < node->layer) {
                            num = node->layer;
                        }
                    }
                }
            }
        }
    }
    return tree;
}


int pathTime(int begin,int finish){
    BitreeElem *node;
    Bitree *tree;
    if (((node = (BitreeElem*)malloc(sizeof(BitreeElem))) == NULL)||
        ((tree = (Bitree*)malloc(sizeof(Bitree))) == NULL)) {
        return -1;;
    }
    tree->root = node;
    node->data = begin;
    node->layer = 1;
    node->child.clear();
    
    tree = approximate(tree, node, 4, 24);
    node = tree->root;
    
    
    return 0;
}
