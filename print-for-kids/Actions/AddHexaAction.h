#pragma once
#include "Actions/Action.h"
// Add Hexagon Action Class
class AddHexaAction :  public Action
{
private:
	Point P1; // Center of Hexagon
	GfxInfo HexaGfxInfo;
public:
	AddHexaAction(ApplicationManager* pApp);

	// Reads Hexagon Parameters
	virtual void ReadActionParameters();
	// Add Hexagon to the ApplicationManager
	virtual void Execute(bool);
};

