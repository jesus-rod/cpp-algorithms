#include <vector>;
#include <iostream>;
using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
	
	int arrayCounter = 0;
	int sequenceCounter = 0;
	
	while (arrayCounter < array.size() && sequenceCounter < sequence.size()) {
		
		cout << "comparing " << array[arrayCounter] << " to " << sequence[sequenceCounter] << endl;
		if (array[arrayCounter] == sequence[sequenceCounter]) {
			sequenceCounter++;
		}
		arrayCounter++;
	}
	
	cout << sequenceCounter << endl;

	return sequenceCounter == sequence.size();
}
