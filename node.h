#include "pizza.h"
#pragma once
class node {
	friend class kdTree;
	pizza data;
	node* left;
	node* right;
public:
	node();
};