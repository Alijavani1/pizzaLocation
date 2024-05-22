#include <iostream>
#include "node.h"
#include "block.h"
#include "hashT.h"
#include <math.h>
using namespace std;
#pragma once
class kdTree
{
private:
	node* head;
	node* new_node(pizza p);
	//node* insertk(node* root, pizza p,int depth);
	int getHeight(node* leaf);
	int get_hf(node* leaf);
	int isBalanced(node* root);
	node* balanceKdTree(node* root,pizza arr[], int depth = 0);
	void search_name(string name, node* root);
	void search_block(node* root,block b,int depth);
	void search_circular(node*root,int w1, int w2,int h1,int h2,int depth);
	int isLeaf(node* root, int x, int y,int depth);
	node* near_neighbor(node * root,int &x, int &y,node *bestNode,float &best_dist,int depth);
	node* insert(node* root,pizza p, int depth);
	pizza array[100];
	pizza array_origin[100];
	int index_origin;
	hashT table_name;
	int index;
public:
	kdTree();
	//node* insert(node *root,pizza p);
	node* insert(pizza p);
	void set_index(int  i);
	int get_index();
	void search_name(string name);
	void mydelete(int x, int y);
	void max_local();
	void search_block(block b);
	void search_circular(int x, int y, int r);
	void near_neighbor(int x, int y);
	void near_local(int x, int y, string name);
};
