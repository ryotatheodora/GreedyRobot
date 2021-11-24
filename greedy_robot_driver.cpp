/*
*  This program is designed to be tested with command arguments
*/

#include <iostream>
#include <string>
#include "greedy_robot.h"

int main(int argc, char* argv[])
{
	GreedyRobot r1(stoi(argv[1]), stoi(argv[2]), stoi(argv[3]), stoi(argv[4]), stoi(argv[5]));
	r1.FindTreasure();
}
