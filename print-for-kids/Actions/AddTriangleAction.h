#pragma once
#include "Actions/Action.h"
// Add triangle action class
class AddTriangleAction :   public Action
{
private:
	Point P1, P2, P3;// triangle corners
	GfxInfo TriangleGfxInfo;
public:
	AddTriangleAction(ApplicationManager* pApp);
	// read triangle parameters
	virtual void ReadActionParameters();
	// Add triangle to the ApplicationManager
	virtual void Execute(bool);
};

