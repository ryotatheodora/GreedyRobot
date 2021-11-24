#ifndef GREEDY_ROBOT_H_
#define GREEDY_ROBOT_H_

#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

class GreedyRobot
{
public:
	struct Point
	{
		int x;
		int y;
	}Robot, Treasure;

	GreedyRobot();
	GreedyRobot(int x1, int y1, int x2, int y2, int max);
	~GreedyRobot();

	void FindTreasure() const;
	
	friend ostream& operator<<(ostream& out, const GreedyRobot& robot);

private:
	int max_;
	void findPath(const int& x1, const int& y1, const int& x2, const int& y2, const int& max, vector<string>& pathVector, const string& path) const;
	void printPath(const vector<string> pathVector) const;
};

#endif
