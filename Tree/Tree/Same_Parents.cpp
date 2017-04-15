//
//  Same_Parents.cpp
//  Tree
//
//  Created by Jason_Sam on 2017/4/5.
//  Copyright © 2017年 Jason_Sam. All rights reserved.
//

#include "Same_Parents.hpp"

bool get_path(BiTNode *root, vector<BiTNode*> &path, BiTNode *node){
    if (root == NULL) {
        return false;
    }
    path.push_back(root);
    if (root == node) {
        return true;
    }
    if (get_path(root->lchild, path, node)) {
        return true;
    }
    if (get_path(root->rchild, path, node)) {
        return true;
    }else{
        path.pop_back();
        return false;
    }
}
BiTNode *find_com_parent(BiTNode* root, BiTNode *a, BiTNode *b){
    if (root == NULL) {
        return NULL;
    }
    vector<BiTNode*> va,vb;
    BiTNode* com_parent = (BiTNode*)malloc(sizeof(BiTNode));
    get_path(root, va, a);
    get_path(root, vb, b);
    size_t i = 0;
    while (i<va.size()&&i<vb.size()&&vb[i]==va[i]) {
        com_parent = va[i];
        i++;
    }
    return com_parent;
}
