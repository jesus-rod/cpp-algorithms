#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
   string name;
   vector<Node*> children;

    Node(string str) { name = str; }

    vector<string> depthFirstSearch(vector<string>* array);

    Node* addChild(string name);
};