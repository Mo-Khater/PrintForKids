#pragma once
#include "Actions/Action.h"
class ChangeDrawAction :    public Action
{
private:
	color C;
public:
	ChangeDrawAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool);
};

