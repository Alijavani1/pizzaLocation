#include "kdTree.h"
#include "sort.h"


kdTree::kdTree()
{
	head = NULL;
	index = 0;
	index_origin = 0;
	for (int i = 0; i < 100; i++) {
		array_origin[i].set_numberLocal(-1);
		array[i].set_x(-1000);
		array[i].set_y(-1000);
	}
}

void kdTree::set_index(int i)
{
	index = i;
}
int kdTree::get_index()
{
	return index;
}
node* kdTree::new_node(pizza p)
{
	node* new_node = new node();
	new_node->data = p;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

//return all location pizza 
void kdTree::search_name(string name, node* root)
{
	if (root == NULL) {
		if (head == NULL) {
			head = root;
		}
		return;
	}
	search_name(name, root->left);
	if (root->data.get_local() == name && root->data.is_origin() == 0 ) {
		cout << "*Pizzeria branches" << endl;
		cout << "Pizza Name:" << root->data.get_name() << " | ";
		cout << "Pizza Location: (" << root->data.get_x() << "," << root->data.get_y() << ")" << endl;
	}
	search_name(name, root->right);
}
void kdTree::search_name(string name)
{
	search_name(name, head);
}
//delete pizza
void kdTree::mydelete(int x, int y)
{
	int temp = 0, size_arry = 0, count = 0;
	while (array[count].get_name() != "") {
		count++;
		size_arry++;
	}

	int i = 0;
	string local_del;
	for (; size_arry + 1 > i; i++) {
		if (array[i].get_x() == x && array[i].get_y() == y) {
			if (array[i].is_origin() == 0) {
				local_del = array[i].get_local();
				temp++;
			}
			break;
		}
	}


	if (temp == 1) {
		for (int i = 0; i < index; i++)
		{
			if (array[i].get_name() == local_del)
			{
				array[i].set_numberLocal(array[i].get_numberLocal() - 1);
			}
		}

		for (int j = 0, x = 0; size_arry + 1 > j; j++, x++) {
			if (i == j) {
				x--;
				continue;
			}
			array[x] = array[j];
		}

		if (isLeaf(head, x, y, 0))
		{
			if (!isBalanced(head))
			{
				head = NULL;
				balanceKdTree(head, array, 0);
			}
		}
		else {
			head = NULL;
			balanceKdTree(head, array, 0);
		}

	}
	else {
		cout << "There is no pizzeria in this location!!\n";
		return;
	}
}
//check is leaf
int kdTree::isLeaf(node* root, int x, int y, int depth)
{
	if (root->data.get_x() == x and root->data.get_y() == y)
	{
		if (root->left == nullptr and root->right == nullptr)
		{
			delete root;
			return 1;
		}
		else
		{
			return 0;
		}
	}

	int axis = depth % 2;
	if (axis == 0)
	{
		if (x < root->data.get_x())
		{
			isLeaf(root->left, x, y, depth + 1);
		}
		else {
			isLeaf(root->right, x, y, depth + 1);
		}
	}
	else if (axis == 1) {
		if (y < root->data.get_y())
		{
			isLeaf(root->left, x, y, depth + 1);
		}
		else {
			isLeaf(root->right, x, y, depth + 1);
		}
	}

}
// check balance
int kdTree::getHeight(node* leaf)
{
	if (leaf == nullptr)
	{
		return 0;
	}
	else
	{
		int leftheight = getHeight(leaf->left);
		int rightheight = getHeight(leaf->right);
		return max(leftheight, rightheight) + 1;
	}

}

int kdTree::get_hf(node* leaf)
{
	if (leaf == nullptr)
	{
		return 0;
	}
	else
	{
		int leftheight = getHeight(leaf->left);
		int rightheight = getHeight(leaf->right);
		return leftheight - rightheight;
	}

}

int kdTree::isBalanced(node* root)
{
	if (root == nullptr)
	{
		return 1;
	}
	if (abs(get_hf(root)) > 1)
	{
		return 0;
	}
	return isBalanced(root->right) && isBalanced(root->right);
}
//balanced Tree
node* kdTree::balanceKdTree(node* root, pizza arr[], int depth) {

	int arr_size = 0;
	for (int i = 0; arr[i].get_name() != ""; i++)
	{
		arr_size = i + 1;
	}

	int axis = depth % 2;

	if (axis == 0 and arr_size != 1)
	{
		mysort(arr, arr_size - 1, 0);
	}
	else if (axis == 1 and arr_size != 1) {
		mysort(arr, arr_size - 1, 1);
	}

	int mid = arr_size / 2;

	root = new_node(arr[mid]);

	if (head == NULL) {
		head = root;
	}

	if (arr_size != 1 and arr_size != 0)
	{
		pizza leftarr[50];
		pizza rightarr[50];

		for (int i = 0; i < mid; i++)
		{
			leftarr[i] = arr[i];
		}
		for (int i = mid + 1, j = 0; i < arr_size; j++, i++)
		{
			rightarr[j] = arr[i];
		}


		root->left = balanceKdTree(root->left, leftarr, depth + 1);
		root->right = balanceKdTree(root->right, rightarr, depth + 1);
	}
	if (root->data.get_x() == 0 && root->data.get_y() == 0)
	{
		return nullptr;
	}
	else
	{
		return root;
	}

}
//insert pizza 
node* kdTree::insert(pizza p)
{

	if (table_name.hash_search(p.get_name()) == 1)
	{
		cout << "There is a pizzeria with this name!!\n";
		return nullptr;
	}
	array[index] = p;
	index++;
	if (p.is_origin() == 1) {
		array_origin[index_origin] = p;
		index_origin++;
	}
	table_name.hash_insert(p.get_name());
	// increase local number
	if (p.get_local() != "")
	{
		for (int i = 0; i < index; i++)
		{
			if (array_origin[i].get_name() == p.get_local())
			{
				array_origin[i].set_numberLocal(array_origin[i].get_numberLocal() + 1);
			}
		}
	}


	head = insert(head, p, 0);
	if (!isBalanced(head))
	{
		head = NULL;
		balanceKdTree(head, array, 0);
		return nullptr;
	}

}

node* kdTree::insert(node* root, pizza p, int depth)
{

	if (root == NULL)
	{
		return new_node(p);
	}

	int axis = depth % 2;
	if (axis == 0)
	{
		if (p.get_x() < root->data.get_x())
		{
			root->left = insert(root->left, p, depth + 1);
		}
		else {
			root->right = insert(root->right, p, depth + 1);
		}
	}
	else if (axis == 1) {
		if (p.get_y() < root->data.get_y())
		{
			root->left = insert(root->left, p, depth + 1);
		}
		else {
			root->right = insert(root->right, p, depth + 1);
		}
	}
	return root;
}
// most of local pizza 
void kdTree::max_local()
{
	countSort(array_origin, index_origin);

	for (int i = index_origin - 1; i >= 0; i--)
	{
		int max = array_origin[index_origin - 1].get_numberLocal();
		if (array_origin[i].get_numberLocal() < max)
		{
			break;
		}
		cout << "*Most Pizzeria :" << endl;
		cout << array_origin[i].get_name() << ":" << array_origin[i].get_numberLocal() << endl;
	}


}

// search pizza in rectangle
void kdTree::search_block(node* root, block b, int depth)
{

	if (root == NULL) {
		if (head == NULL) {
			head = root;
		}
		return;
	}

	if (b.get_w1() <= root->data.get_x() && root->data.get_x() <= b.get_w2())
	{
		if (b.get_h1() <= root->data.get_y() && root->data.get_y() <= b.get_h2() ) {
			cout << "*Pizzerias in this neighborhood :" << endl;
			cout << "Pizza Name: " << root->data.get_name() << " | ";
			cout << "Pizza Location: (" << root->data.get_x() << "," << root->data.get_y() << ")" << endl;
		}
	}

	int axis = depth % 2;
	if (axis == 0)
	{
		if (root->data.get_x() < b.get_w1())
		{
			search_block(root->right, b, depth + 1);
		}
		if (root->data.get_x() > b.get_w2())
		{
			search_block(root->left, b, depth + 1);
		}
		if (root->data.get_x() > b.get_w1() && root->data.get_x() < b.get_w2())
		{
			search_block(root->left, b, depth + 1);
			search_block(root->right, b, depth + 1);
		}
	}
	else if (axis == 1)
	{
		if (root->data.get_y() < b.get_h1())
		{
			search_block(root->right, b, depth + 1);
		}
		if (root->data.get_y() > b.get_h2())
		{
			search_block(root->left, b, depth + 1);
		}
		if (root->data.get_y() > b.get_h1() && root->data.get_y() < b.get_h2())
		{
			search_block(root->left, b, depth + 1);
			search_block(root->right, b, depth + 1);
		}
	}

}
void kdTree::search_block(block b)
{
	search_block(head, b, 0);
}

//search pizza in circular by r
void kdTree::search_circular(node* root, int w1, int w2, int h1, int h2, int depth)
{
	if (root == NULL) {
		if (head == NULL) {
			head = root;
		}
		return;
	}

	if (w1 <= root->data.get_x() && root->data.get_x() <= w2)
	{
		if (h1 <= root->data.get_y() && root->data.get_y() <= h2 ) {
			cout << "Pizzerias in the radius:" << endl;
			cout << "Pizza Name:" << root->data.get_name() << " | ";
			cout << "Pizza Location: (" << root->data.get_x() << "," << root->data.get_y() << ")" << endl;
		}
	}

	int axis = depth % 2;
	if (axis == 0)
	{
		if (root->data.get_x() < w1)
		{
			search_circular(root->right, w1, w2, h1, h2, depth + 1);
		}
		if (root->data.get_x() >= w2)
		{
			search_circular(root->left, w1, w2, h1, h2, depth + 1);
		}
		if (root->data.get_x() > w1 && root->data.get_x() < w2)
		{
			search_circular(root->left, w1, w2, h1, h2, depth + 1);
			search_circular(root->right, w1, w2, h1, h2, depth + 1);
		}
	}
	else if (axis == 1)
	{
		if (root->data.get_y() < h1)
		{
			search_circular(root->right, w1, w2, h1, h2, depth + 1);
		}
		if (root->data.get_y() >= h2)
		{
			search_circular(root->left, w1, w2, h1, h2, depth + 1);
		}
		if (root->data.get_y() > h1 && root->data.get_y() < h2)
		{
			search_circular(root->left, w1, w2, h1, h2, depth + 1);
			search_circular(root->right, w1, w2, h1, h2, depth + 1);
		}
	}
}

void kdTree::search_circular(int x, int y, int r)
{
	int w1, w2, h1, h2;
	w1 = x - r;
	w2 = x + r;
	h1 = y - r;
	h2 = y + r;
	search_circular(head, w1, w2, h1, h2, 0);
}

// find near pizza from the my location
node* kdTree::near_neighbor(node* root, int &x, int &y, node* bestNode, float &best_dist, int depth)
{
	if (root == NULL)
	{
		return bestNode;
	}

	float r = sqrt(pow(root->data.get_x() - x, 2) + pow(root->data.get_y() - y, 2));
	if (r < best_dist)
	{
		bestNode = root;
		best_dist = r;
	}

	int axis = depth % 2;
	if (axis == 0)
	{
		if (root->data.get_x() < x)
		{


			bestNode = near_neighbor(root->right, x, y, bestNode, best_dist, depth + 1);

			if (best_dist > abs(root->data.get_x() - x))
			{

				bestNode = near_neighbor(root->left, x, y, bestNode, best_dist, depth + 1);
			}
		}
		else {

			bestNode = near_neighbor(root->left, x, y, bestNode, best_dist, depth + 1);

			if (best_dist > abs(root->data.get_x() - x))
			{

				bestNode = near_neighbor(root->right, x, y, bestNode, best_dist, depth + 1);
			}
		}
	}
	else if (axis == 1) {
		if (root->data.get_y() < y)
		{
			bestNode = near_neighbor(root->right, x, y, bestNode, best_dist, depth + 1);
			if (best_dist > abs(root->data.get_y() - y))
			{

				bestNode = near_neighbor(root->left, x, y, bestNode, best_dist, depth + 1);
			}
		}
		else {
			bestNode = near_neighbor(root->left, x, y, bestNode, best_dist, depth + 1);
			if (best_dist > abs(root->data.get_y() - y))
			{

				bestNode = near_neighbor(root->right, x, y, bestNode, best_dist, depth + 1);
			}
		}
	}

	return bestNode;
}

void kdTree::near_neighbor(int x, int y)
{
	head = NULL;
	balanceKdTree(head, array, 0);
	float bestdis = 1000.0;
	node* near_node = near_neighbor(head, x, y, nullptr, bestdis, 0);

	cout << "Near pizza location: \n" << "Name: " << near_node->data.get_name() <<
		" | location:(" << near_node->data.get_x() << "," << near_node->data.get_y() << ")" << endl;

}

// find near local pizza from my location
void kdTree::near_local(int x, int y, string name)
{
	kdTree local_t;
	for (int i = 0; i < index; i++)
	{
		if (array[i].get_local() == name)
		{
			local_t.insert(array[i]);
		}
	}

	local_t.near_neighbor(x, y);
}






