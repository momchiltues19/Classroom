#include <vector>
#include <iostream>
#include "turtle.hh"

using namespace std;

enum Direction
{
	DOWN = 0,
	RIGHT = 1,
	UP = 2,
	LEFT = 3,
	ALL = 4
};

class Cell
{
	static const int STEP = 20;
	bool visited_;
	bool walls_[4];
	int row_;
	int col_;
public:
	
	Cell(int row, int col)
	: visited_(false), row_(row), col_(col) 
	{
		for(int i=0; i < ALL; i++)
		{
			walls_[i] = true;
		}	
	}

	bool is_visited() const
	{
		return visited_;
	}

	void visit()
	{
		visited_ = true;
	}

	bool has_wall(Direction dir) const
	{
		return walls_[dir];
	}

	void drill_wall(Direction dir)
	{
		walls_[dir] = false;
	}

	void build_wall(Direction dir)
	{
		walls_[dir] = true;
	}

	void draw(Turtle& t)
	{
		t.set_pos((col_+1)*STEP, (row_+1)*STEP);
		t.set_heading(0);
		for(int i=0; i<ALL; ++i)
		{
			if(has_wall((Direction)i))
			{
				t.pendown();
			} 
			else
			{
				t.penup();
			}
			t.forward(STEP);
			t.left(90);		
		}
	}
};

class Board
{
	vector<Cell> board_;

public:

};

int main()
{
	PSTurtle t(1000, 1000);
	t.setup();
	t.penup();
	
	Cell c1(0,0);
	Cell c2(1,1);
		

return 0;
}
