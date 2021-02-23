#include <iostream>
#include <vector>

#include "Node.h"

using namespace std;

vector<string> Node::depthFirstSearch(vector<string>* array) {
    array->push_back(name);
    cout << name << endl;
    for (Node* child : children) {
        child->depthFirstSearch(array);
    }
    return *array;
}

Node* Node::addChild(string name) {
    Node* child = new Node(name);
    children.push_back(child);
    return this;
}

