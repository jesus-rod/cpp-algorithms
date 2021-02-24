#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> getUnvisitedNeighbors(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &visited) {
	vector<vector<int>> unvisitedNeighbors{};
	if (i > 0 && !visited[i - 1][j]) {
		unvisitedNeighbors.push_back({i - 1, j});
	}
	if (i < matrix.size() - 1 && !visited[i + 1][j]) {
		unvisitedNeighbors.push_back({ i + 1,j });
	}
	if (j > 0 && !visited[i][j - 1]) {
		unvisitedNeighbors.push_back({ i, j - 1 });
	}
	if (j < matrix[0].size() - 1 && !visited[i][j + 1]) {
		unvisitedNeighbors.push_back({i, j + 1 });
	}
	
	return unvisitedNeighbors;
}

void traverseNode(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &visited, vector<int> &riverSizes) {
	cout << "traversing" << endl;
	int currentRiverSize = 0;
	vector<vector<int>> nodesToExplore = { {i, j} };
	while (nodesToExplore.size() != 0) {
		vector<int> currentNode = nodesToExplore.back();
		nodesToExplore.pop_back();
		int i = currentNode[0];
		int j = currentNode[1];
		if (visited[i][j]) {
			continue;
		}
			
		visited[i][j] = true;
		if (matrix[i][j] == 0) {
			continue;
		}
			
		currentRiverSize++;
		vector<vector<int>> unvisitedNeighbors = getUnvisitedNeighbors(i, j, matrix, visited);
		for (vector<int> neighbor : unvisitedNeighbors) {
			nodesToExplore.push_back(neighbor);
		}
	}
	if (currentRiverSize > 0) {
		cout << "Adding to river sizes " << endl;
		riverSizes.push_back(currentRiverSize);
	}
		
}

vector<int> riverSizes(vector<vector<int>> matrix) {
	vector<int> riverSizes = {};
	vector<vector<int>> visited(matrix.size(), vector<int>(matrix[0].size(), false));

	cout << "matrix size -> " << matrix.size() << endl;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			if (visited[i][j]) {
				cout << "already visited " << endl;
				continue;
			}
			else {
				cout << "NOT visited " << endl;
			}
			traverseNode(i, j, matrix, visited, riverSizes);
				
		}
	}

	for (int size : riverSizes) {
		cout << "river size " << size << endl;
	}
		

	return riverSizes;
}
