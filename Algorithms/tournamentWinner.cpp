//
//  tournamentWinner.cpp
//  TestingCpp
//
//  Created by Jesus Rodriguez on 13.02.21.
//

#include <vector>
#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

string tournamentWinner(vector<vector<string>> competitions,
                        vector<int> results) {

    int highestPoints = 0;
    string finalWinner = "";

    map<string,int> pointsTable;
    for(int i=0; i<results.size(); i++) {
        string roundWinner = "";
        if (results[i] == 0) {
            roundWinner = competitions[i][1];

        } else {
            roundWinner = competitions[i][0];
        }
        cout << "round winner is" << roundWinner << endl;

        auto it = pointsTable.find(roundWinner);
        if (it != pointsTable.end()) {
            it->second = it->second + 3;
            int points = it->second;
            if (points > highestPoints) {
                highestPoints = points;
                finalWinner = it->first;
            }
        } else {
            pointsTable.insert(pair<string, int>(roundWinner, 3));
        }
    }


    cout << "the final winner is " << finalWinner << endl;
    return finalWinner;
}
