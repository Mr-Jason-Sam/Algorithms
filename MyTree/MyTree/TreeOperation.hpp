//
//  TreeOperation.hpp
//  MyTree
//
//  Created by Jason_Sam on 2017/4/6.
//  Copyright © 2017年 Jason_Sam. All rights reserved.
//

#ifndef TreeOperation_hpp
#define TreeOperation_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct BiTNode_{
    char data;
    struct BiTNode_ *lchild,*rchild;
}BiTNode;

typedef struct BiTree_{
    int size;
    BiTNode *root;
}BiTree;

BiTNode *create_bitree(BiTNode *tree){
    BiTNode *new_node = tree;
    char ch;
    cin >> ch;
    if (ch == '#') {
        new_node = NULL;
    }else{
        new_node = (BiTNode*)malloc(sizeof(BiTNode));
        new_node->data = ch;
        create_bitree(new_node->lchild);
        create_bitree(new_node->rchild);
    }
    return tree;
}

void pre_order_bitree(BiTNode *node){
    if (node) {
        cout << node->data ;
        pre_order_bitree(node->lchild);
        pre_order_bitree(node->rchild);
    }
}

void in_order_bitree(BiTNode *node){
    if (node) {
        in_order_bitree(node->lchild);
        cout << node->data ;
        in_order_bitree(node->rchild);
    }
}

void post_order_bitree(BiTNode *node){
    if (node) {
        in_order_bitree(node->lchild);
        in_order_bitree(node->rchild);
        cout << node->data ;
    }
}





#endif /* TreeOperation_hpp */
