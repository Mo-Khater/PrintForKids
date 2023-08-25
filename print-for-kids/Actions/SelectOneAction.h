#pragma once
#include "Actions/Action.h"
#include "DEFS.h"
class SelectOneAction :
    public Action
{
private:
    Point P;
public:
    SelectOneAction(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute(bool);
};

