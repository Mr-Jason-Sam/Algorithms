//
//  Bitree_Operation.hpp
//  Tree
//
//  Created by Jason_Sam on 2017/4/5.
//  Copyright © 2017年 Jason_Sam. All rights reserved.
//

#ifndef Bitree_Operation_hpp
#define Bitree_Operation_hpp

#include <stdio.h>

typedef struct BiTNode_ {
    char data;
    struct BiTNode_ *lchild, *rchild;
}BiTNode,*BiTree;

//typedef struct BiTree_{
//    int size;
//    void (*destroy)(void *data);
//    BiTNode *root;
//}BiTree;

typedef struct StackNode {
    BiTree data;
    struct StackNode *next;
}StackNode, *LinkStack;

void initStack(LinkStack &S);
int push(LinkStack &S,BiTree e);
int pop(LinkStack &S,BiTree &e);
BiTree getTop(LinkStack S);
bool stackEmpty(LinkStack S);
void createBiTree(BiTree &T);
void copyTree(BiTree T, BiTree &NewT);
void preOrderTraverse(BiTree T);
void inOrderTraverse(BiTree T);
void postOrderTraverse(BiTree T);
void feiDiGuiPreOrderTraverse(BiTree T);
void feiDiGuiInOrderTraverse(BiTree T);
void feiDiGuiPostOrderTraverse(BiTree T);
int depth(BiTree T);
int nodeCount(BiTree T);
int duYiNodeCount(BiTree T);
int duErNodeCount(BiTree T);
int leafNodeCount(BiTree T);
void swapChild(BiTree &T);



#endif /* Bitree_Operation_hpp */
