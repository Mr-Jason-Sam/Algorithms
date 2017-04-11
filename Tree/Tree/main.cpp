//
//  main.cpp
//  Tree
//
//  Created by Jason_Sam on 2017/4/5.
//  Copyright © 2017年 Jason_Sam. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include "Same_Parents.hpp"
#include "Bitree_Operation.hpp"
using namespace std;

int main() {
    BiTree T;
    BiTNode *a,*b,*com_parent;
    a = (BiTNode*)malloc(sizeof(BiTNode));
    b = (BiTNode*)malloc(sizeof(BiTNode));
    com_parent = (BiTNode*)malloc(sizeof(BiTNode));
    createBiTree(T);
    //cout << T->data;
    cout << "第一个公共父亲" <<endl;
    a = T->lchild->lchild;
    b = T->lchild->rchild;
    com_parent = find_com_parent(T, a, b);
    cout << com_parent->data << endl;
    cout << endl;
    return 0;
}


//int main()
//{
//    BiTree T;
//    createBiTree(T);
//    cout << "先序遍历：  ";
//    preOrderTraverse(T);
//    cout <<endl<< "中序遍历：  ";
//    inOrderTraverse(T);
//    cout <<endl<< "后序遍历：  ";
//    postOrderTraverse(T);
//    BiTree newT;
//    copyTree(T, newT);
//    cout <<endl<< "T的复制二叉树的中序遍历:  ";
//    inOrderTraverse(newT);
//    cout << "结点个数：" << nodeCount(T)<<endl;
//    cout << "度为1的结点个数：" << duYiNodeCount(T) << endl;
//    cout << "度为2的结点个数：" << duErNodeCount(T) << endl;
//    cout << "叶结点个数：" << leafNodeCount(T) << endl;
//    cout << "交换左右孩子后：" << endl;
//    swapChild(T);
//    cout << "先序遍历：  ";
//    preOrderTraverse(T);
//    cout << endl << "中序遍历：  ";
//    inOrderTraverse(T);
//    cout << endl << "后序遍历：  ";
//    postOrderTraverse(T);
//    copyTree(T, newT);
//    cout << endl << "T的复制二叉树的中序遍历:  ";
//    inOrderTraverse(newT);
//    cout << "结点个数：" << nodeCount(T) << endl;
//    cout << "度为1的结点个数：" << duYiNodeCount(T) << endl;
//    cout << "度为2的结点个数：" << duErNodeCount(T) << endl;
//    cout << "叶结点个数：" << leafNodeCount(T) << endl;
//}
