//
//  balancedBrackets.cpp
//  TestingCpp
//
//  Created by Jesus Rodriguez on 14.02.21.
//

#include <stdio.h>
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

bool balancedBrackets(string str) {

    string openingBrackets = "({[";
    string closingBrackets = ")}]";

    stack<char> bracketsStack;
    unordered_map<char, char> matchingBrackets = { {']', '['}, {')', '('}, {'}', '{'}};
    for (int i=0; i<str.size(); i++) {
        cout << str[i] << endl;

        char currentChar = str[i];

        if(openingBrackets.find(currentChar) != string::npos) {
            bracketsStack.push(currentChar);
        } else if (closingBrackets.find(currentChar) != string::npos) {
            if (bracketsStack.empty()) {
                return false;
            }
            char topValue = bracketsStack.top();
            if (matchingBrackets[currentChar] == topValue) {
                bracketsStack.pop();
            } else {
                return false;
            }
        }
    }

    return bracketsStack.empty();
}
