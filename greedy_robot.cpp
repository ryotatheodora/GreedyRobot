#include "greedy_robot.h"

GreedyRobot::GreedyRobot()
{
	Robot.x = 0;
	Robot.y = 0;
	Treasure.x = 0;
	Treasure.y = 0;
}

GreedyRobot::GreedyRobot(int x1, int y1, int x2, int y2, int max)
{
	this->Robot.x = x1;
	this->Robot.y = y1;
	this->Treasure.x = x2;
	this->Treasure.y = y2;
	this->max_ = max;
}

GreedyRobot::~GreedyRobot()
{
}

void GreedyRobot::FindTreasure() const
{
	vector<string> path_vector_;
	string path_ = "";

	findPath(Robot.x, Robot.y, Treasure.x, Treasure.y, max_, path_vector_, path_);
	printPath(path_vector_);
}

void GreedyRobot::findPath(const int& x1, const int& y1, const int& x2, const int& y2, const int& max, vector<string>& pathVector, const string& path) const
{
	//Base case
	if (x1 == x2 && y1 == y2)
	{
		int count = 0;

		for (int j = 0; j < path.length(); j++)
		{
			if (path[j] == path[j + 1])
			{
				count++;
				if (count >= max_)
				{
					break;
				}
			}
			else if (path[j] != path[j + 1])
			{
				count = 0;
			}
		}
		if (count < max_)
			pathVector.push_back(path);

	}

	//Robot goes North
	if (y1 < y2)
	{
		findPath(x1, y1 + 1, x2, y2, max, pathVector, path + "N");
	}

	//Robot goes South
	if (y1 > y2)
	{
		findPath(x1, y1 - 1, x2, y2, max, pathVector, path + "S");
	}

	//Robot goes East
	if (x1 < x2)
	{
		findPath(x1 + 1, y1, x2, y2, max, pathVector, path + "E");
	}

	//Robot goes West
	if (x1 > x2)
	{
		findPath(x1 - 1, y1, x2, y2, max, pathVector, path + "W");
	}
}

void GreedyRobot::printPath(const vector<string> pathVector_) const
{
	if (pathVector_[0] == "")
	{
		cout << "Number of possible path: 0" << endl;
		return;
	}

	cout << "Number of possible path: " << pathVector_.size() << endl;

	for (int i = 0; i < pathVector_.size(); i++)
	{
		cout << pathVector_[i] << endl;
	}
	cout << endl;
}

ostream& operator<<(ostream& out, const GreedyRobot& robot)
{
	return out;
}
