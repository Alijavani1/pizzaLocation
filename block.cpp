#include "block.h"

block::block()
{
}

void block::add_block(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4, string name)
{
	this->x1 = x1;
	this->x2 = x2;
	this->x3 = x3;
	this->x4 = x4;
	this->y1 = y1;
	this->y2 = y2;
	this->y3 = y3;
	this->y4 = y4;
	this->name = name;
}

string block::get_name()
{
	return name;
}

int block::get_w1()
{
	if (x1<=x2 and x1<=x3 and x1<=x4)
	{
		return x1;
	}
	else if (x2 <= x1 and x2 <= x3 and x2 <= x4)
	{
		return x2;
	}
	else if (x3 <= x1 and x3 <= x2 and x3 <= x4)
	{
		return x3;
	}
	else if (x4 <= x1 and x4 <= x2 and x4 <= x3)
	{
		return x4;
	}
}

int block::get_w2()
{
	if (x1 >= x2 and x1 >= x3 and x1 >= x4)
	{
		return x1;
	}
	else if (x2 >= x1 and x2 >= x3 and x2 >= x4)
	{
		return x2;
	}
	else if (x3 >= x1 and x3 >= x2 and x3 >= x4)
	{
		return x3;
	}
	else if (x4 >= x1 and x4 >= x2 and x4 >= x3)
	{
		return x4;
	}
}

int block::get_h1()
{
	if (y1 <= y2 and y1 <= y3 and y1 <= y4)
	{
		return y1;
	}
	else if (y2 <= y1 and y2 <= y3 and y2 <= y4)
	{
		return y2;
	}
	else if (y3 <= y1 and y3 <= y2 and y3 <= y4)
	{
		return y3;
	}
	else if (y4 <= y1 and y4 <= y2 and y4 <= y3)
	{
		return y4;
	}
}

int block::get_h2()
{
	if (y1 >= y2 and y1 >= y3 and y1 >= y4)
	{
		return y1;
	}
	else if (y2 >= y1 and y2 >= y3 and y2 >= y4)
	{
		return y2;
	}
	else if (y3 >= y1 and y3 >= y2 and y3 >= y4)
	{
		return y3;
	}
	else if (y4 >= y1 and y4 >= y2 and y4 >= y3)
	{
		return y4;
	}
}
