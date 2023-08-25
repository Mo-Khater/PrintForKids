#pragma once
#include "Actions/Action.h"
// Add Exit Action Class
class ExitAction :  public Action
{
public:
	ExitAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool);
};

