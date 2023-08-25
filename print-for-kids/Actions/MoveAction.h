#include"Actions/Action.h"

class moveaction :public Action
{
private:
	Point movepoint;
public:
	moveaction(ApplicationManager* papp);
	virtual void ReadActionParameters();


	virtual void Execute(bool);
};