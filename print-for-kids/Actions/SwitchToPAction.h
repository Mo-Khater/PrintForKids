#pragma once
#include "Actions/Action.h"
class SwitchToPAction :   public Action
{
public:
	SwitchToPAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool);
};

