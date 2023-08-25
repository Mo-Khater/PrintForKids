#include"MoveAction.h"
#include"ApplicationManager.h"
#include"GUI/Output.h"
#include"GUI/Input.h"

moveaction::moveaction(ApplicationManager* papp)
	:Action(papp)
{

}
void moveaction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->movesound();
	if (pManager->GetSelectedFig())//check if the kid select a figure
	{
		pOut->PrintMessage("move action click a point");
		pIn->GetPointClicked(movepoint.x, movepoint.y);
		pOut->ClearStatusBar();
	}
	else 
		pOut->PrintMessage("please select the figure you want to move");

}
void moveaction::Execute(bool executeaction)
{
	Output* pOut = pManager->GetOutput();
	if (executeaction)
	ReadActionParameters();
	pManager->move(movepoint);
	pOut->ClearDrawArea();
	pManager->Addaction(this);

}

