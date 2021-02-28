#pragma once
#include <vector>

using namespace std;


class AncestralTree {
public:
    char name;
    AncestralTree* ancestor;

    AncestralTree(char name) {
        this->name = name;
        this->ancestor = nullptr;
    }

    void addAsAncestor(vector<AncestralTree*> descendants);
    
};