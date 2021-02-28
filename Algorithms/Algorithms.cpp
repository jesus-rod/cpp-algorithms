// Algorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "algorithms.h"
#include "Node.h"
#include "AncestralTree.h"
#include <unordered_map>

unordered_map<char, AncestralTree*> getAncestralTrees() {
    unordered_map<char, AncestralTree*> trees;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (char a : alphabet) {
        trees.insert({ a, new AncestralTree(a) });
    }
    return trees;
}

int main()
{
    std::cout << "Algorithmssss!\n";
    
    

    //twoNumberSum({ 3, 5, -4, 8, 11, 1, -1, 6 }, 10);
    //isValidSubsequence({ 5, 1, 22, 25, 6, -1, 8, 10 }, { 1, 6, -1, 10 });
    //threeNumberSum({ 12, 3, 1, 2, -6, 5, -8, 6 }, 0);
    

    // Create graph for DFS
    /*Node graph("A");
    graph.addChild("B")->addChild("C")->addChild("D");
    graph.children[0]->addChild("E")->addChild("F");
    graph.children[2]->addChild("G")->addChild("H");
    graph.children[0]->children[1]->addChild("I")->addChild("J");
    graph.children[2]->children[0]->addChild("K");
    vector<string> inputArray{};*/
    //graph.depthFirstSearch(&inputArray);
    //graph.breadthFirstSearch(&inputArray);
    /*auto output = riverSizes({ { 1, 0, 0, 1, 0 }, { 1, 0, 1, 0, 0 }, { 0, 0, 1, 0, 1 },
        { 1, 0, 1, 0, 1 }, { 1, 0, 1, 1, 0 } });*/

 
    //Build ancestral tree
    /*auto trees = getAncestralTrees();
    trees.at('A')->addAsAncestor({ trees.at('B'), trees.at('C') });
    trees.at('B')->addAsAncestor({ trees.at('D'), trees.at('E') });
    trees.at('D')->addAsAncestor({ trees.at('H'), trees.at('I') });
    trees.at('C')->addAsAncestor({ trees.at('F'), trees.at('G') });

    AncestralTree* youngestCommon = getYoungestCommonAncestor(trees.at('A'), trees.at('E'), trees.at('I'));
    cout << "youngestCommon is: " << youngestCommon->name;*/


    removeIslands({{1, 0, 0, 0, 0, 0},
        { 0, 1, 0, 1, 1, 1 },
        { 0, 0, 1, 0, 1, 0 },
        { 1, 1, 0, 0, 1, 0 }
        });
    

    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
