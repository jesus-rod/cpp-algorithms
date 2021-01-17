//
//  moveElementToEnd.cpp
//  TestingCpp
//
//  Created by Jesus Rodriguez on 17.01.21.
//

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;
vector<int> moveElementToEnd(vector<int> array, int toMove) {

    int left = 0;
    int right = array.size() - 1;
    while (left < right) {
        int valueAtRightPtr = array[right];
        int valueAtLeftPtr = array[left];
        if (valueAtRightPtr == toMove) {
            right--;
            continue;
        } else if (valueAtLeftPtr == toMove) {
            swap(array[left], array[right]);
        }
        left++;
    }

  return array;
}
