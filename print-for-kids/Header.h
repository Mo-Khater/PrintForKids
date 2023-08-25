#include"Actions/Action.h"
#include<fstream>
class saveaction :public Action
{
private:
	ofstream outf;
public:
	saveaction(ApplicationManager* papp);
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();
};