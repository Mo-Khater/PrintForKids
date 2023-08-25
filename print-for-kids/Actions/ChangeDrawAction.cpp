#include "ChangeDrawAction.h"
#include "ApplicationManager.h"
#include"Figures/CFigure.h"
#include "GUI\input.h"
#include "GUI\Output.h"
ChangeDrawAction::ChangeDrawAction(ApplicationManager* pApp) :Action(pApp)
{
	C = WHITE;
}
void ChangeDrawAction::ReadActionParameters()
{
	// get pointer input / output from the interface
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	// get the color from user
	pOut->PrintMessage("Choose a new draw color");
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
// Change the Draw color
void ChangeDrawAction::Execute()
{
	// change current Draw color
	ReadActionParameters();
	UI.DrawColor = C;
	// change Draw color for selected figure
	//CFigure* F = pManager->selectedFig();
	//F->ChngDrawClr(C);
}