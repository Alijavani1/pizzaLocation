#pragma once
#include "kdTree.h"
#include <vector>



struct Node {
    int key;
    kdTree tree;
    vector<block> blocks;
    Node* next;

    Node(int k,kdTree t,vector<block>b){
        key = k;
        tree = t;
        blocks = b;
    }
};

class chainHash {
private:
    vector<Node*> hashTable;
public:
    chainHash();
    int hashFunction(int k);
    void insertKey(int k,kdTree t,vector<block> b);
    Node* searchKey(int k);
};