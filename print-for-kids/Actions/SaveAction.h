#include"Actions/Action.h"
#include<fstream>
class saveaction :public Action
{
private:
	ofstream outf;
	string nameofile;
	bool S;
public:
	saveaction(ApplicationManager* papp,bool s);
	virtual void ReadActionParameters();

	
	virtual void Execute(bool);
};