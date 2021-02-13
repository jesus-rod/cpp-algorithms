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
    map<string,int> pointsTable;
    for(int i=0; i<results.size(); i++) {
        string winner = "";
        if (results[i] == 0) {
            winner = competitions[i][1];

        } else {
            winner = competitions[i][0];
        }
        cout << "winner is" << winner << endl;

        auto it = pointsTable.find(winner);
        if (it != pointsTable.end()) {
            it->second = it->second + 3;
        } else {
            pointsTable.insert(pair<string, int>(winner, 3));
        }
    }

    string winner = "";
    int highestPoints = 0;

    auto it = pointsTable.begin();

    while (it != pointsTable.end())
        {
            // Accessing KEY from element pointed by it.
//            std::string word = it->first;
            // Accessing VALUE from element pointed by it.
            int points = it->second;
            if (points > highestPoints) {
                highestPoints = points;
                winner = it->first;
            }
//            std::cout << word << " :: " << count << std::endl;
            // Increment the Iterator to point to next entry
            it++;
        }
    cout << "the winner is " << winner << endl;
  return winner;
}
