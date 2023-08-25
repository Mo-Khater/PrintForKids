#include "ChangeFillAction.h"
#include "ApplicationManager.h"
#include"Figures/CFigure.h"
#include "GUI\input.h"
#include "GUI\Output.h"
ChangeFillAction::ChangeFillAction(ApplicationManager* pApp):Action(pApp)
{
	C = WHITE;
}
void ChangeFillAction::ReadActionParameters()
{
	// get pointer input / output from the interface
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	// get the color from user
	pOut->PrintMessage("Choose a new fill color");
	ActionType Color;
	do
	{
	    Color = pIn->GetUserAction();
	    //Color = pManager->GetUserAction();
	    // check which color is choosen
		switch (Color)
		{
		case ACT_BLACK:
			C = BLACK;
			break;
		case ACT_BLUE:
			C = BLUE;
			break;
		case ACT_GREEN:
			C = GREEN;
			break;
		case ACT_ORANGE:
			C = ORANGE;
			break;
		case ACT_RED:
			C = RED;
			break;
		case ACT_YELLOW:
			C = YELLOW;
			break;
		}
	} while (C == WHITE);
	pOut->ClearStatusBar();
} 
// Change the fill color
void ChangeFillAction::Execute()
{
	// change current fill color
	ReadActionParameters();
	UI.FillColor = C;
	// change fill color for selected figure
	//CFigure* F = pManager->selectedFig();
	//F->ChngFillClr(C);
}