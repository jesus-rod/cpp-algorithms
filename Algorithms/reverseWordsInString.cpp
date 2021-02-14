//
//  reverseWordsInString.cpp
//  TestingCpp
//
//  Created by Jesus Rodriguez on 14.02.21.
//

#include <stdio.h>
#include <iostream>

using namespace std;

string reverseWordsInString(string str) {

    int stringLength = str.length() - 1;
    int wordLength = 0;
    string outputString = "";

    for(int i=stringLength; i>=0; i--) {
        cout << "currentChar:" << str[i] << endl;
        char currentChar = str[i];
        if(currentChar == ' ' || i == 0) {

            int stringStart = i+1;
            string stringEnd = " ";

            if (i==0) {
                stringStart = i;
                stringEnd = "";
                wordLength +=1;
            }

            string newWord = str.substr(stringStart, wordLength);
            outputString += newWord + stringEnd;
            wordLength = 0;
        } else {
            wordLength += 1;
        }
    }


    cout << "final string->" << outputString << endl;
    return outputString;
}
