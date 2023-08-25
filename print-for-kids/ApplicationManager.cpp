#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include"Actions/AddCircleAction.h"
#include"Actions/AddSquareAction.h"
#include"Actions/AddTriangleAction.h"
#include"Actions/AddHexaAction.h"
#include"Actions/ExitAction.h"
#include"Actions/ChangeDrawAction.h"
#include"Actions/ChangeFillAction.h"
#include"Actions/SwitchToDAction.h"
#include"Actions/SwitchToPAction.h"
#include"Actions/PickTypeAction.h"
#include"SaveAction.h"
#include"LoadAction.h"
#include"SelectOneAction.h"
#include"DeleteFigure.h"
#include"MoveAction.h"
#include"startaction.h"
#include"stoprecording.h"
#include"PlayRecording.h"
#include"ClearAllAction.h"
#include"PickColorAction.h"
#include"PickBothAction.h"
// to get random number
#include<cstdlib>
#include"time.h"
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	FigCount = 0;
	actcount = 0;
	SelectedFig = NULL;

	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;
	lastaction = NULL;
	recordingstate = false;
	for (int i = 0; i <20; i++)
		FigList[i] = NULL;
	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;

	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAW_RECT:
		pAct = new AddRectAction(this);
		break;
	case DRAW_CIRCLE:
		pAct = new AddCircleAction(this);
		break;
	case DRAW_SQUARE:
		pAct = new AddSquareAction(this);
		break;
	case DRAW_TRIANGLE:
		pAct = new AddTriangleAction(this);
		break;
	case DRAW_HEXAGON:
		pAct = new AddHexaAction(this);
		break;
	case EXIT:
		///create ExitAction here
		pAct = new ExitAction(this);
		break;
	case CHANGE_DRAW:
		pAct = new ChangeDrawAction(this);
		break;
	case CHANGE_FILL:
		pAct = new ChangeFillAction(this);
		break;
	case ACT_BLACK:
		return;
	case ACT_YELLOW:
		return;
	case ACT_ORANGE:
		return;
	case ACT_RED:
		return;
	case ACT_GREEN:
		return;
	case ACT_BLUE:
		return;
	case TO_DRAW:
		pAct = new SwitchToDAction(this);
		break;
	case TO_PLAY:
		pAct = new SwitchToPAction(this);
		break;
	case STATUS:	//a click on the status bar ==> no action
		return;
	case PICK_TYPE:
		pAct = new PickTypeAction(this);
		break;
	case PICK_COLOR:
		pAct = new PickColorAction(this);
		break;
	case PICK_BOTH:
		pAct = new PickBothAction(this);
		break;
	case SAVE:
		pAct = new saveaction(this,true);
		break;
	case LOAD:
		pAct = new loadaction(this,true);
		break;
	case MOVE:
		pAct = new moveaction(this);
		break;
	case SELECT:
		pAct = new SelectOneAction(this);
		break;
	case ACT_DELETE:
		pAct = new deletefig(this);
		break;
	case START_RE:
		pAct = new startrecording(this);
		break;
	case STOP_RE:
		pAct = new stoprecording(this);
		break;
	case PLAY_RE:
		pAct = new PlayRecording(this);
		break;
	case CLEAR:
		pAct = new ClearAllAction(this);
		break;
	}

	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute(true);//Execute
		lastaction = pAct;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
		FigList[FigCount++] = pFig;


}
//////////////////////////////////////////////////////////////////////////////////
// search for selected figure 
CFigure* ApplicationManager::selectedFig()
{
	bool S;
	for (int i = 0; i < FigCount; i++)
	{
		S = FigList[i]->IsSelected();
		if (S)
			return FigList[i];
	}
	return NULL;
}
void ApplicationManager::UpdateSelected()
{
	bool selection = false;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
		{
			SelectedFig = FigList[i];
			selection = true;
		}
	}
	if (selection == false)
	{
		SelectedFig = NULL;
	}
}
//////////////////////////////////////////////////////////////////////////////////
// get random figure name
CFigure* ApplicationManager::GetRandomFigureName()
{
	if (FigCount == 0)
		return NULL;
	srand(time(0));
	return FigList[rand() % FigCount];
}
//////////////////////////////////////////////////////////////////////////////////
// get number of figure with the name passed for pick type game
int ApplicationManager::GetFigNum(string name)
{
	int count = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->GetFigureName() == name)
			count++;
	}
	return count;
}
////////////////////////////////////////////////////////////////////////////////////
// get random fill color
color ApplicationManager::GetRandomColor()
{
	while (true)
	{
		srand(time(0));
		int x = rand() % FigCount;
		if (FigList[x]->IsFilled())
			return FigList[x]->GetFigureColor();
	}
}
//////////////////////////////////////////////////////////////////////////
// show if there is a filled figure
bool ApplicationManager::CheckFill()
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsFilled())
			return true;
	}
	return false;
}
///////////////////////////////////////////////////////////////////////////
// get number of figure with special color
int ApplicationManager::GetColorNum(color v)
{
	int x = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->GetFigureColor() == v)
			x++;
	}
	return x;
}
////////////////////////////////////////////////////////////////////////////
// get number of figure with special color and shape
int ApplicationManager::GetBothNum(string name, color c)
{
	int count = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->GetFigureName() == name && FigList[i]->GetFigureColor() == c)
			count++;
	}
	return count;
}
////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetFigure(int x1, int y1) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.
	Point Click;
	Click.x = x1;
	Click.y = y1;
	bool SelectFlag = false;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsInside(Click) == true)
		{
			SelectFlag = true;
			return FigList[i];
		}
	}
	if (SelectFlag == false)
		return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	pOut->ClearDrawArea();
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetSelectedFig()
{
	return SelectedFig;
}
//Return a pointer to the input
Input* ApplicationManager::GetInput() const
{
	return pIn;
}
//Return a pointer to the output
Output* ApplicationManager::GetOutput() const
{
	return pOut;
}
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++)
		delete FigList[i];
	for (int i = 0; i < actcount; i++)
		delete actlist[i];
	delete pIn;
	delete pOut;

}
int ApplicationManager::getfigcount()
{
	return FigCount;
}
void ApplicationManager::saveall(ofstream& outF)
{

	for (int i = 0; i < FigCount; i++)
		FigList[i]->save(outF);

}
void ApplicationManager::deletefigures()
{
	for (int i = 0; i < FigCount; i++)
	{
		delete FigList[i];
		FigList[i] = NULL;

	}
	FigCount = 0;
}
void ApplicationManager::DeleteFig()
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
		{
			delete FigList[i];
			if (FigCount > 1)
			{
				FigList[i] = FigList[FigCount - 1];
				FigList[FigCount - 1] = NULL;
			}
			FigCount--;

		}
	}
}
void ApplicationManager::move(Point pointmove)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
		{
			FigList[i]->move(pointmove);
		}
	}
}
bool ApplicationManager::checkifnofigures()
{
	if (FigCount == 0)
		return true;
	else
		return false;
}
void ApplicationManager::Addaction(Action* pact)
{
	if (recordingstate == true)
	{
		if (actcount < 20)
		{
			actlist[actcount++] = pact;
		}
		else
			recordingstate = false;//the actlist is full
	}
	else
	{
		delete lastaction;//i didn't record so i will remove the last action 
		lastaction = NULL;
	}

}
void ApplicationManager::setrecordingstate(bool recordaction)
{
	recordingstate = recordaction;//so i can know if i record or not
}
bool ApplicationManager::getrecordingstate()
{
	return recordingstate;
}
void ApplicationManager::playrecording()
{
	if (actlist[0] != NULL)// there is a record
	{
		for (int i = 0; i < actcount; i++)
		{
			actlist[i]->Execute(false);
			UpdateInterface();
			Sleep(1000);
		}
	}
	else
		pOut->PrintMessage("you must record first");//if the kid doesn't record 

}
bool ApplicationManager::checkifnoactions()
{
	if (actcount == 0)
		return true;
	else
		return false;
}
void ApplicationManager::deleteactions()
{
	for (int i = 0; i < actcount; i++)
	{
		delete actlist[i];
		actlist[i] = NULL;

	}
	actcount = 0;
}