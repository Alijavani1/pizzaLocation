#include <string>
using namespace std;
#pragma once
class block {
	float x1, x2, x3, x4, y1, y2, y3, y4;
	string name;
public:
	block();
	void add_block(int x1,int x2,int x3,int x4, int y1, int y2, int y3, int y4,string name);
	string get_name();
	int get_w1();
	int get_w2();
	int get_h1();
	int get_h2();

};