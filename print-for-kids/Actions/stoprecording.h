#include"Actions/Action.h"
class stoprecording :public Action
{
private:

public:
	stoprecording(ApplicationManager* papp);
	virtual void ReadActionParameters();


	virtual void Execute(bool);
};