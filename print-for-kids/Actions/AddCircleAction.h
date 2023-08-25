#pragma once
#include"Actions/Action.h"
// Add circle Action class
class AddCircleAction :  public Action
{
private:
	GfxInfo CircleGfxInfo;
	Point P1;// Center of circle
	Point P2;// determine the radius
public:
	AddCircleAction(ApplicationManager* pApp);

	//Reads cirlce parameters
	virtual void ReadActionParameters();

	//Add circle to the ApplicationManager
	virtual void Execute(bool);
};

