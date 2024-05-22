#pragma once
#include "pizza.h"


class hashT {
	int table[300]{0};
	//pizza pizza_table[300];
	int hashFunc(string name, int i);
	
public:
	void hash_insert(string name);
	void hash_delete(string name);
	int hash_search(string name);
};
