#include "PickColorAction.h"
#include "ApplicationManager.h"
#include"string"
#include "GUI\input.h"
#include "GUI\Output.h"
#include"SaveAction.h"
#include"LoadAction.h"
PickColorAction::PickColorAction(ApplicationManager* pApp) :Action(pApp)
{
	C = WHITE;
	Incorrect = 0;
	Correct = 0;
}
void PickColorAction::ReadActionParameters()
{
	// get a pointer to input interface
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	// get user selected figure
	pIn->GetPointClicked(P.x, P.y);
	CFigure* H = pManager->GetFigure(P.x, P.y);
	if (H == NULL)
		return;
	else
	{
		color B;
		B = H->GetFigureColor();
		if (B == C && H->IsFilled())
		{
			// delete figure
			if (H->IsSelected() == false && pManager->GetSelectedFig() != NULL)
			{
				H->SetSelected(true);
				(pManager->GetSelectedFig())->SetSelected(false);
				pManager->UpdateSelected();
			}
			else if (H->IsSelected() == false && pManager->GetSelectedFig() == NULL) {
				H->SetSelected(true);
				pManager->UpdateSelected();
			}
			pManager->DeleteFig();
			pOut->ClearDrawArea();
			pManager->UpdateInterface();
			Correct++;
		}
		else
			Incorrect++;
	}
}
void PickColorAction::Execute(bool read)
{
	Output* pOut = pManager->GetOutput();
	/////////////
	if (pManager->CheckFill())
	{
		C = pManager->GetRandomColor();
		x = pManager->GetColorNum(C);
		if (C == RED)
		{
			while (Correct < x)
			{
				pOut->PrintMessage("Pick all red figures: Correct:" + to_string(Correct) + " Incorrect:" + to_string(Incorrect));
				ReadActionParameters();
				pOut->ClearStatusBar();
			}
		}
		else if (C == GREEN)
		{
			while (Correct < x)
			{
				pOut->PrintMessage("Pick all green figures: Correct:" + to_string(Correct) + " Incorrect:" + to_string(Incorrect));
				ReadActionParameters();
				pOut->ClearStatusBar();
			}
		}
		else if (C == YELLOW)
		{
			while (Correct < x)
			{
				pOut->PrintMessage("Pick all yellow figures: Correct:" + to_string(Correct) + " Incorrect:" + to_string(Incorrect));
				ReadActionParameters();
				pOut->ClearStatusBar();
			}
		}
		else if (C == BLACK)
		{
			while (Correct < x)
			{
				pOut->PrintMessage("Pick all black figures: Correct:" + to_string(Correct) + " Incorrect:" + to_string(Incorrect));
				ReadActionParameters();
				pOut->ClearStatusBar();
			}
		}
		else if (C == ORANGE)
		{
			while (Correct < x)
			{
				pOut->PrintMessage("Pick all orange figures: Correct:" + to_string(Correct) + " Incorrect:" + to_string(Incorrect));
				ReadActionParameters();
				pOut->ClearStatusBar();
			}
		}
		else
		{
			while (Correct < x)
			{
				pOut->PrintMessage("Pick all blue figures: Correct:" + to_string(Correct) + " Incorrect:" + to_string(Incorrect));
				ReadActionParameters();
				pOut->ClearStatusBar();
			}
		}
		// load graph
		Action* ptr1 = new loadaction(pManager, false);
		ptr1->Execute(true);
		delete ptr1;
		////// 
		pOut->PrintMessage("Game over : Correct:" + to_string(Correct) + " Incorrect : " + to_string(Incorrect));
	}
	else
		pOut->PrintMessage("No Filled Figures");
}