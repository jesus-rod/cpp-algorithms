#include <vector>;
#include <iostream>;
#include <algorithm>;
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
	
	sort(array.begin(), array.end());

	vector<vector<int>> triplets;

	for (int i = 0; i < array.size() - 2; i++) {
		cout << array[i] << endl;
		
		int left = i + 1;
		int right = array.size() - 1;

		while (left < right) {
			int current = array[i];
			int leftNum = array[left];
			int rightNum = array[right];
			int currentSum = current + leftNum + rightNum;

			if (currentSum > targetSum) {
				right--;
			}
			else if (currentSum < targetSum) {
				left++;
			}
			else {
				triplets.push_back({ current, leftNum, rightNum });
				left++;
				right--;
			}
		}
	}
	return triplets;
}