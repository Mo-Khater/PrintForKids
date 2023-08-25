#include"Actions/Action.h"

class deletefig:public Action
{

public:
	deletefig(ApplicationManager* papp);
	virtual void ReadActionParameters();
	virtual void Execute(bool);
};