#include <iostream>
#include "kdTree.h"
#include "chainHash.h"
#include <vector>
#include <list>
using namespace std;

int main()
{
	string input;
	vector<string> v;
	vector<block> blocks;
	block b;
	kdTree t;
	chainHash chainTable;
	int time = 0;

	cout << "#Please enter the commands as below: \n";
	cout << "#(For example): List-Brs [NAME] && Add-P [X,Y,NAME] && Avail-P [X,Y,R] && Del-Br [X,Y] .\n";
	cout << "#Add-N [X1,X2,X3,X4,Y1,Y2,Y3,Y4,NAME] && Most-Brs [] && Undo [TIME] && Add-Br [X,Y,NAME,LOCALNAME] && Del-Br[X,Y] .\n\n";
	cout << "#For exite and finish command enter: exit .\n\n";


	while (true)
	{
		do
		{
			cin >> input;
			v.push_back(input);
		} while (input != ".");

		//erase &&
		auto it = v.begin();
		while (it != v.end())
		{
			if (*it == "&&" or *it == ".")
			{
				it = v.erase(it);
			}
			else
			{
				it++;
			}
		}

		for (int i = 0; i < v.size(); i++) {
			if (v[i] == "Add-N")
			{
				vector<string> parametrs;
				int x1, x2, x3, x4, y1, y2, y3, y4;
				string name;
				string token;
				int pos = 0;
				v[i + 1].erase(0, 1);
				v[i + 1].erase(v[i + 1].size() - 1, v[i + 1].size());
				while (pos != -1) {
					pos = v[i + 1].find(",");
					token = v[i + 1].substr(0, pos);
					parametrs.push_back(token);
					v[i + 1].erase(0, pos + 1);

				}

				x1 = stoi(parametrs[0]);
				x2 = stoi(parametrs[1]);
				x3 = stoi(parametrs[2]);
				x4 = stoi(parametrs[3]);
				y1 = stoi(parametrs[4]);
				y2 = stoi(parametrs[5]);
				y3 = stoi(parametrs[6]);
				y4 = stoi(parametrs[7]);
				name = parametrs[8];

				b.add_block(x1, x2, x3, x4, y1, y2, y3, y4, name);
				blocks.push_back(b);
				time += 1;
			}

			if (v[i] == "Add-P")
			{
				vector<string> parametrs;
				pizza p;
				int x, y;
				string name;
				string token;
				int pos = 0;
				v[i + 1].erase(0, 1);
				v[i + 1].erase(v[i + 1].size() - 1, v[i + 1].size());
				while (pos != -1) {
					pos = v[i + 1].find(",");
					token = v[i + 1].substr(0, pos);
					parametrs.push_back(token);
					v[i + 1].erase(0, pos + 1);

				}
				x = stoi(parametrs[0]);
				y = stoi(parametrs[1]);
				name = parametrs[2];
				p.add(x, y, name, " ", 1);
				t.insert(p);
				time += 1;
			}

			if (v[i] == "Add-Br")
			{
				vector<string> parametrs;
				pizza p;
				int x, y;
				string name, local;
				string token;
				int pos = 0;
				v[i + 1].erase(0, 1);
				v[i + 1].erase(v[i + 1].size() - 1, v[i + 1].size());
				while (pos != -1) {
					pos = v[i + 1].find(",");
					token = v[i + 1].substr(0, pos);
					parametrs.push_back(token);
					v[i + 1].erase(0, pos + 1);

				}
				x = stoi(parametrs[0]);
				y = stoi(parametrs[1]);
				name = parametrs[2];
				local = parametrs[3];
				p.add(x, y, name, local, 0);
				t.insert(p);
				time += 1;
			}

			if (v[i] == "Del-Br")
			{
				vector<string> parametrs;
				int x, y;
				string token;
				int pos = 0;
				v[i + 1].erase(0, 1);
				v[i + 1].erase(v[i + 1].size() - 1, v[i + 1].size());
				while (pos != -1) {
					pos = v[i + 1].find(",");
					token = v[i + 1].substr(0, pos);
					parametrs.push_back(token);
					v[i + 1].erase(0, pos + 1);

				}
				x = stoi(parametrs[0]);
				y = stoi(parametrs[1]);
				t.mydelete(x, y);
				time += 1;
			}

			if (v[i] == "List-P")
			{
				string name;
				v[i + 1].erase(0, 1);
				v[i + 1].erase(v[i + 1].size() - 1, v[i + 1].size());
				name = v[i + 1];
				for (int j = 0; j < blocks.size(); j++)
				{
					if (blocks[j].get_name() == name)
					{
						t.search_block(blocks[j]);
					}
				}
				time += 1;
			}

			if (v[i] == "List-Brs")
			{
				string name;
				v[i + 1].erase(0, 1);
				v[i + 1].erase(v[i + 1].size() - 1, v[i + 1].size());
				name = v[i + 1];
				t.search_name(name);
				time += 1;
			}

			if (v[i] == "Near-P")
			{
				vector<string> parametrs;
				int x, y;
				string token;
				int pos = 0;
				v[i + 1].erase(0, 1);
				v[i + 1].erase(v[i + 1].size() - 1, v[i + 1].size());
				while (pos != -1) {
					pos = v[i + 1].find(",");
					token = v[i + 1].substr(0, pos);
					parametrs.push_back(token);
					v[i + 1].erase(0, pos + 1);

				}
				x = stoi(parametrs[0]);
				y = stoi(parametrs[1]);
				t.near_neighbor(x, y);
				time += 1;
			}

			if (v[i] == "Near-Br")
			{
				vector<string> parametrs;
				int x, y;
				string token, name;
				int pos = 0;
				v[i + 1].erase(0, 1);
				v[i + 1].erase(v[i + 1].size() - 1, v[i + 1].size());
				while (pos != -1) {
					pos = v[i + 1].find(",");
					token = v[i + 1].substr(0, pos);
					parametrs.push_back(token);
					v[i + 1].erase(0, pos + 1);

				}
				x = stoi(parametrs[0]);
				y = stoi(parametrs[1]);
				name = parametrs[2];
				t.near_local(x, y, name);
				time += 1;
			}

			if (v[i] == "Avail-P")
			{
				vector<string> parametrs;
				int x, y, r;
				string token;
				int pos = 0;
				v[i + 1].erase(0, 1);
				v[i + 1].erase(v[i + 1].size() - 1, v[i + 1].size());
				while (pos != -1) {
					pos = v[i + 1].find(",");
					token = v[i + 1].substr(0, pos);
					parametrs.push_back(token);
					v[i + 1].erase(0, pos + 1);

				}
				x = stoi(parametrs[0]);
				y = stoi(parametrs[1]);
				r = stoi(parametrs[2]);
				t.search_circular(x, y, r);
				time += 1;
			}

			if (v[i] == "Most-Brs")
			{
				t.max_local();
				time += 1;
			}

			if (v[i] == "Undo")
			{
				int key;
				v[i + 1].erase(0, 1);
				v[i + 1].erase(v[i + 1].size() - 1, v[i + 1].size());
				key = stoi(v[i + 1]);
				Node* node = chainTable.searchKey(key);
				t = node->tree;
				blocks = node->blocks;
				time = key;
			}

			if (v[i] == "exit")
			{
				exit(0);
			}
			chainTable.insertKey(time, t, blocks);
		}
		v.clear();

	}
}
//Add-P [2,3,ali] && Add-P [5,4,reza] && Add-P [4,6,amir] .
//Add-Br [0,1,mina,ali] && Add-Br [7,9,zohre,reza] && Add-Br [10,20,zahra,amir] .
//Add-Br [7,6,arash,ali] && Add-Br [5,5,ahmad,reza] && Add-Br [6,12,maryam,amir] .



//kdTree t;
//pizza p1, p2, p3, p4, p5, p6, p7, p8, p9;
//p1.add(0, 0, "ali", " ", 1);
//p2.add(5, 4, "reza", " ", 1);
//p3.add(4, 6, "amir", " ", 1);
//p4.add(10, 3, "mina", "ali", 0);
//p5.add(7, 6, "arash", "ali", 0);
//p6.add(7, 9, "zohre", "reza", 0);
//p7.add(10, 20, "zahra", "amir", 0);
//p8.add(5, 5, "ahnad", "reza", 0);
//p9.add(6, 12, "maryam", "amir", 0);
//t.insert(p1);
//t.insert(p2);
//t.insert(p3);
//t.insert(p4);
//t.insert(p5);
//t.insert(p6);
//t.insert(p7);
//t.insert(p8);
//t.insert(p9);
//t.near_neighbor(0, 1);


