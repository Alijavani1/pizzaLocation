#include "pizza.h"
pizza::pizza()
{
	point[0] = 0;
	point[1] = 0;
	number_local = 0;
	origin = 0;
	name, local = "";
}

void pizza::add(int x, int y, string name, string local, int origin)
{
	point[0] = x;
	point[1] = y;
	this->name = name;
	this->local = local;
	this->origin = origin;
}

int pizza::get_x()
{
	return point[0];
}

int pizza::get_y()
{
	return point[1];
}

void pizza::set_x(int x)
{
	point[0] = x;
}

void pizza::set_y(int y)
{
	point[1] = y;
}

string pizza::get_name()
{
	return name;
}

void pizza::set_name(string name)
{
	this->name = name;
}

string pizza::get_local()
{
	return local;
}

int pizza::is_origin()
{
	return origin;
}

int pizza::get_numberLocal()
{
	return number_local;
}

void pizza::set_numberLocal(int n)
{
	number_local = n ;
}
