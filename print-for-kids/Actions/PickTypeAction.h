#pragma once
#include"Action.h"
class PickTypeAction :public Action
{
	string Name;// name of figure to be collected
	int Correct;// number of collect clicks
	int Incorrect;// number of incorrect clicks
	Point P;// to determine which figure is selected
	int x;  // Number of figure to be collected
public:
	PickTypeAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool);
};
