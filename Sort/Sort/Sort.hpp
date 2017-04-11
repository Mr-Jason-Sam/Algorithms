//
//  Sort.hpp
//  Sort
//
//  Created by Jason_Sam on 2017/4/7.
//  Copyright © 2017年 Jason_Sam. All rights reserved.
//

#ifndef Sort_hpp
#define Sort_hpp

#include <stdio.h>

void select_sort(int *r, int n);
void insert_sort(int *r, int n);
void bubble_sort(int *r, int n);
void shell_sort(int *r, int n);
void quick_sort(int *r, int high,int low);
void sift(int *r, int n,int s);
void heap_sort(int *r, int n);
void merge_sort(int *r, int n);
void bin_sort(int *r, int n);
void merge_sort_recursive(int arr[], int reg[], int start, int end);

#endif /* Sort_hpp */
