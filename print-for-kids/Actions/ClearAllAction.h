#pragma once
#include"Actions/Action.h"
class ClearAllAction :
    public Action
{
public:
    ClearAllAction(ApplicationManager* papp);
    virtual void ReadActionParameters();
    virtual void Execute(bool);
};

