#include "AncestralTree.h"
#include <iostream>

void AncestralTree::addAsAncestor(vector<AncestralTree*> descendants) {
    for (AncestralTree* descendant : descendants) {
        descendant->ancestor = this;
    }
}

int getTreeLevel(AncestralTree* topAncestor, AncestralTree* descendant) {
    cout << "getting level for: " << descendant->name << endl;

    int descendantLevel = 0;
    while (descendant != topAncestor) {
        descendantLevel++;
        descendant = descendant->ancestor;
    }
    cout << "level for " << descendant->name << " is: " << descendantLevel << endl;
    return descendantLevel;
}

AncestralTree* backtrackAncestralTree(AncestralTree* lowerDescendant,
    AncestralTree* higherDescendant, int diff) {
    while (diff > 0) {
        lowerDescendant = lowerDescendant->ancestor;
        diff--;
    }
    while (lowerDescendant != higherDescendant) {
        lowerDescendant = lowerDescendant->ancestor;
        higherDescendant = higherDescendant->ancestor;
    }

    return higherDescendant;
}

AncestralTree* getYoungestCommonAncestor(AncestralTree* topAncestor,
    AncestralTree* descendantOne,
    AncestralTree* descendantTwo) {
    
    
    int oneLevel = getTreeLevel(topAncestor, descendantOne);
    int twoLevel = getTreeLevel(topAncestor, descendantTwo);
    if (oneLevel > twoLevel) {
        return backtrackAncestralTree(descendantOne, descendantTwo, oneLevel - twoLevel);
    }
    else {
        return backtrackAncestralTree(descendantTwo, descendantOne, twoLevel - oneLevel);
    }

 
}


