#include <iostream>
#include <vector>
#include <deque>

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

vector<string> Node::breadthFirstSearch(vector<string>* array) {
    deque <Node *> queue{ this };
    while (!queue.empty()) {
        Node current = *queue.front();
        queue.pop_front();
        array->push_back(current.name);
        for (Node* child : current.children) {
            queue.push_back(child);
        }
    }
    return *array;
}

Node* Node::addChild(string name) {
    Node* child = new Node(name);
    children.push_back(child);
    return this;
}

