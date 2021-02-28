#pragma once

#include <vector>
#include "AncestralTree.h"


using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum);
bool isValidSubsequence(vector<int> array, vector<int> sequence);
vector<vector<int>> threeNumberSum(vector<int> array, int targetSum);
vector<int> riverSizes(vector<vector<int>> matrix);
AncestralTree* getYoungestCommonAncestor(AncestralTree* topAncestor, AncestralTree* descendantOne, AncestralTree* descendantTwo);
vector<vector<int>> removeIslands(vector<vector<int>> matrix);
