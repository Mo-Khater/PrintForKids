#include"Actions/Action.h"
#include<fstream>
class loadaction :public Action
{
private:
	ifstream inf;
	string nameofile;
	bool S;
public:
	loadaction(ApplicationManager* papp,bool s);
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute(bool);
};