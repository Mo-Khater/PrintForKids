#include"Actions/Action.h"
class startrecording :public Action
{
private:

public:
	startrecording(ApplicationManager* papp);
	virtual void ReadActionParameters();

	virtual void Execute(bool );
};