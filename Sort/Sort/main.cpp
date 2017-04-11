//
//  main.cpp
//  Sort
//
//  Created by Jason_Sam on 2017/4/7.
//  Copyright © 2017年 Jason_Sam. All rights reserved.
//

#include <iostream>
#include "Sort.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    int a[10] = {3,4,5,2,1,7,8,9,0,6};
    //select_sort(a, 10);
    //insert_sort(a, 10);
//    bubble_sort(a, 10);
//    shell_sort(a,10);
// bin_sort(a,10);
    merge_sort(a,10);
    for (int i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
