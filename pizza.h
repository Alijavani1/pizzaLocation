#include<string>
using namespace std;
#pragma once
class pizza
{
	int point[2];
	string name;
	string local;
	int origin;
	int number_local;
public:
	pizza();
	void add(int x, int y, string name, string local, int origin);
	int get_x();
	int get_y();
	void set_x(int x);
	void set_y(int y);
	string get_name();
	void set_name(string name);
	string get_local();
	int is_origin();
	int get_numberLocal();
	void set_numberLocal(int n);
};

