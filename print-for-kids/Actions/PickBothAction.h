#pragma once
#include "Actions/Action.h"
class PickBothAction : public Action
{
	color C; // color of figure to be collected
	string Name;// name of figure to be collected
	int Correct;// number of collect clicks
	int Incorrect;// number of incorrect clicks
	Point P;// to determine which figure is selected
	int x;  // Number of figure to be collected
public:
	PickBothAction(ApplicationManager* pApp);
	int GetRandomBoth();
	void ReadActionParameters();
	void Execute(bool);
};

