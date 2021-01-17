//
//  smallestDifference.cpp
//  TestingCpp
//
//  Created by Jesus Rodriguez on 17.01.21.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {

    sort(arrayOne.begin(), arrayOne.end());
    sort(arrayTwo.begin(), arrayTwo.end());

    int ptrOne = 0;
    int ptrTwo = 0;

    vector<int> smallestPair;

    int minDiff = INT_MAX;

    while (ptrOne < arrayOne.size() && ptrTwo < arrayTwo.size()) {

        int arrayOneValue = (arrayOne[ptrOne]);
        int arrayTwoValue = (arrayTwo[ptrTwo]);


        int currentDiff = 0;
        if ((arrayOneValue) < (arrayTwoValue)) {
            currentDiff = (arrayTwoValue) - (arrayOneValue);
            cout << arrayTwoValue << " - " << arrayOneValue << endl;
            cout << "Current diff is ->" << currentDiff << endl;
            ptrOne++;
        } else if ((arrayOneValue) > (arrayTwoValue)) {
            currentDiff = (arrayOneValue) - (arrayTwoValue);
            cout << "Current diff is" << currentDiff << endl;
            ptrTwo++;
        } else {

            return {arrayOneValue, arrayTwoValue};
        }

        if (currentDiff < minDiff) {
            minDiff = currentDiff;
            smallestPair = {arrayOneValue, arrayTwoValue};
        }


    }


    cout << "Min diff is: " << minDiff << endl;
    cout << "From " << smallestPair[0] << " and " << smallestPair[1] << endl;
    return smallestPair;
}
