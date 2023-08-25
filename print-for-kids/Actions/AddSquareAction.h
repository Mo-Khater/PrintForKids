#pragma once
#include"Actions/Action.h"
// Add square action class
class AddSquareAction : public Action
{
private:
	Point P1;// square center
	GfxInfo SquareGfxInfo;
public:
	AddSquareAction(ApplicationManager* pApp);
	// Read Circle Parameters
	virtual void ReadActionParameters();
	// Add to Circle to the ApplicationManager 
	virtual void Execute(bool);
};

