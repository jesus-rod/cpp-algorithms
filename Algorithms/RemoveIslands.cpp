#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> getNeighbors(int row, int col, vector<vector<int>> &matrix) {
	vector<vector<int>> neighbors{};

	int numRows = matrix.size();
	int numCols = matrix[row].size();

	if (row - 1 >= 0) {
		//up
		neighbors.push_back({ row - 1, col });
	}
	if (row + 1 < numRows) {
		// down
		neighbors.push_back({ row + 1, col });
	}
	if (col - 1 >= 0) {
		// left
		neighbors.push_back({ row, col - 1 });
	}
	if (col + 1 < numCols) {
		// rights
		neighbors.push_back({ row, col + 1 });
	}

	return neighbors;
}


void findOnesConnectedToBorder(int startRow, int startCol,
	vector<vector<int>> &matrix,
	vector<vector<int>> &onesConnectedToBorder) {
	vector<vector<int>> stack = { {startRow, startCol} };

	while (stack.size() > 0) {
		vector<int> currentPosition = stack.back();
		stack.pop_back();
		int currentRow = currentPosition[0];
		int currentCol = currentPosition[1];

		bool alreadyVisited = onesConnectedToBorder[currentRow][currentCol];

		if (alreadyVisited)
			continue;

		onesConnectedToBorder[currentRow][currentCol] = true;

		vector<vector<int>> neighbors = getNeighbors(currentRow, currentCol, matrix);

		for (auto neighbor : neighbors) {
			int row = neighbor[0];
			int col = neighbor[1];

			if (matrix[row][col] != 1)
				continue;

			stack.push_back(neighbor);
		}
	}
}

void printMatrix(vector<vector<int>> matrix);
vector<vector<int>> removeIslands(vector<vector<int>> matrix) {
	
	printMatrix(matrix);
	vector<vector<int>> onesConnectedToBorder(matrix.size(), vector<int>(matrix[0].size(), false));

	for (int row = 0; row < matrix.size(); row++) {
		for (int col = 0; col < matrix[row].size(); col++) {
			bool rowIsBorder = row == 0 || row == matrix.size() - 1;
			bool colIsBorder = col == 0 || col == matrix[row].size() - 1;
			bool isBorder = rowIsBorder || colIsBorder;
			if (isBorder) {
				cout << matrix[col][row] << " ";
			}
			else {
				cout << "-" << " ";
			}

			if (!isBorder) {
				continue;
			}
			if (matrix[row][col] != 1)
				continue;

			findOnesConnectedToBorder(row, col, matrix, onesConnectedToBorder);
		}
	}

	
	for (int row = 1; row < matrix.size() - 1; row++) {
		for (int col = 1; col < matrix[row].size() - 1; col++) {
			if (onesConnectedToBorder[row][col])
				continue;
			matrix[row][col] = 0;
		}
	}

	printMatrix(matrix);
	return matrix;
}

void printMatrix(vector<vector<int>> matrix) {
	for (int i = 0; i < matrix.size(); i++) {
		cout << endl;
		for (int j = 0; j < matrix[0].size(); j++) {
			cout << matrix[i][j] << " ";
		}
	}

	cout << endl;
}