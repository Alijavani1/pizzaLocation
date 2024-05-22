#include "hashT.h"

int hashT::hashFunc(string name, int i)
{
		int hashIndex = 0;
		for (int j = 0; j < name.length(); j++)
		{
			hashIndex += name[j] * pow(31, j);
		}
		return hashIndex % 300;
}

void hashT::hash_insert(string name)
{
	for (int i = 0; i < 20; i++)
	{
		if (table[hashFunc(name,i)]==0 or table[hashFunc(name, i)] == 2)
		{
			table[hashFunc(name, i)] = 1;
			break;
		}
	}
}

void hashT::hash_delete(string name)
{
	for (int i = 0; i < 20; i++)
	{
		if (table[hashFunc(name, i)] == 0)
		{
			table[hashFunc(name, i)] = 2;
			break;
		}
	}
}

int hashT::hash_search(string name)
{
	int i = 0;
	while (table[hashFunc(name, i)]!=0)
	{
		if (table[hashFunc(name, i)] == 1)
		{
			return 1;
		}
	}
	return 0;

}
