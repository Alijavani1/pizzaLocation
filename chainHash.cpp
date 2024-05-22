#include "chainHash.h"

const int HASH_SIZE = 10;

chainHash::chainHash()
{
	hashTable.resize(HASH_SIZE, nullptr);
}

int chainHash::hashFunction(int k)
{
	return k % HASH_SIZE;
}

void chainHash::insertKey(int k,kdTree t,vector<block> b)
{
    int index = hashFunction(k);
    Node* newNode = new Node(k,t,b);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

Node* chainHash::searchKey(int k)
{
    int index = hashFunction(k);

    Node* current = hashTable[index];
    while (current != nullptr) {
        if (current->key == k) {
            return current;
        }
        current = current->next;
    }
    return current;
}


