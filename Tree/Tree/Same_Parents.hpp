//
//  Same_Parents.hpp
//  Tree
//
//  Created by Jason_Sam on 2017/4/5.
//  Copyright © 2017年 Jason_Sam. All rights reserved.
//

#ifndef Same_Parents_hpp
#define Same_Parents_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Bitree_Operation.hpp"
using namespace std;


//typedef struct BiTreeNode_ {
//    char data;
//    struct BiTreeNode_ *lchild;
//    struct BiTreeNode_ *rchild;
//}BiTreeNode;
//
//typedef struct BiTree_{
//    int size;
//    void (*destroy)(void *data);
//    BiTreeNode *root;
//}BiTree;

bool get_path(BiTNode *root, vector<BiTNode*> &path, BiTNode *node);
BiTNode *find_com_parent(BiTNode* root, BiTNode *a, BiTNode *b);

#endif /* Same_Parents_hpp */






