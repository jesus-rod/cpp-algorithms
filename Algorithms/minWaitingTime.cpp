//
//  minWaitingTime.cpp
//  TestingCpp
//
//  Created by Jesus Rodriguez on 13.02.21.
//

#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int minimumWaitingTime(vector<int> queries) {

    sort(queries.begin(), queries.end());
    int minTime = 0;

    for(int i=0; i<queries.size(); i++) {
        int queriesLeft = queries.size() - (i+1);
        int queryCost = queries[i] * queriesLeft;
        minTime += queryCost;

    }
  return minTime;
}
