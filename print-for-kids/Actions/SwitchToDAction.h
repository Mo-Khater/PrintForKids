#pragma once
#include "Actions/Action.h"
class SwitchToDAction :   public Action
{
public:
	SwitchToDAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool);
};

