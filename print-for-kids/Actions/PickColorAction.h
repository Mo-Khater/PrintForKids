#pragma once
#include "Actions/Action.h"
class PickColorAction : public Action
{
private:
	color C; // color of figure to be collected
	int Correct;// number of collect clicks
	int Incorrect;// number of incorrect clicks
	Point P;// to determine which figure is selected
	int x;  // Number of figure to be collected
public:
	PickColorAction(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute(bool);
};

