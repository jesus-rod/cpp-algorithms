#include <map>;
#include <iostream>;
#include <vector>;

using namespace std;

// given array and targer 
// twoNumberSum({ 3, 5, -4, 8, 11, 1, -1, 6 }, 10);
// should return 11 and -1  because equals 10

vector<int> twoNumberSum(vector<int> array, int targetSum) {
	map<int, bool> possibleMatches;
	
	for (int i = 0; i < array.size(); i++) {
		int possibleMatch = targetSum - array[i];
		auto it = possibleMatches.find(possibleMatch);
		if (it != possibleMatches.end()) {
			cout << array[i] << " -- " << it->first << endl;
			return vector<int>{ array[i], it->first };
		}
		else {
			possibleMatches.insert(pair<int, bool>(array[i], true));
		}
	}

	return { -1, -1 };
}