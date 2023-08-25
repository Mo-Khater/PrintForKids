#include"Actions/Action.h"
class PlayRecording :public Action
{
private:

public:
	PlayRecording(ApplicationManager* papp);
	virtual void ReadActionParameters();


	virtual void Execute(bool);
};