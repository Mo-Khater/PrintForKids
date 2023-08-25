#pragma once
#include "Actions/Action.h"
class ChangeFillAction :   public Action
{
private:
	color C;
public:
	ChangeFillAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool);
};

