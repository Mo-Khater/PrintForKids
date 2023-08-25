#include "PickBothAction.h"
#include "ApplicationManager.h"
#include"string"
#include "GUI\input.h"
#include "GUI\Output.h"
#include"SaveAction.h"
#include"LoadAction.h"
PickBothAction::PickBothAction(ApplicationManager* pApp) :Action(pApp)
{
	Correct = 0;
	Incorrect = 0;
}
int PickBothAction::GetRandomBoth()
{
	CFigure* ptr;
	while (true)
	{
		ptr = pManager->GetRandomFigureName();
		if (!ptr)
			return 0;
		else
		{
			if (ptr->GetFigureColor() != WHITE)
			{
				Name = ptr->GetFigureName();
				C = ptr->GetFigureColor();
				return pManager->GetBothNum(Name, C);
			}
		}
	}
}
void  PickBothAction::ReadActionParameters()
{
	// get a pointer to input interface
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	// get user selected figure
	pIn->GetPointClicked(P.x, P.y);
	CFigure* ptr = pManager->GetFigure(P.x, P.y);
	if (ptr == NULL)
		return;
	else
	{
		if (ptr->GetFigureName() == Name && ptr->GetFigureColor() == C)
		{
			Correct++;
			// delete Figure
			if (ptr->IsSelected() == false && pManager->GetSelectedFig() != NULL)
			{
				ptr->SetSelected(true);
				(pManager->GetSelectedFig())->SetSelected(false);
				pManager->UpdateSelected();
			}
			else if (ptr->IsSelected() == false && pManager->GetSelectedFig() == NULL) {
				ptr->SetSelected(true);
				pManager->UpdateSelected();
			}
			pManager->DeleteFig();
			pOut->ClearDrawArea();
			pManager->UpdateInterface();
		}
		else
			Incorrect++;
	}
}
void PickBothAction::Execute(bool read )
{
	Output* pOut = pManager->GetOutput();
	////////
	if (pManager->CheckFill())
	{
		x = GetRandomBoth();
		if (C == RED)
		{
			while (Correct < x)
			{
				pOut->PrintMessage("Pick all red " + Name + ": Correct:" + to_string(Correct) + " Incorrect : " + to_string(Incorrect));
				ReadActionParameters();
			}
		}
		else if (C == GREEN)
		{
			while (Correct < x)
			{
				pOut->PrintMessage("Pick all green " + Name + ": Correct:" + to_string(Correct) + " Incorrect:" + to_string(Incorrect));
				ReadActionParameters();
			}
		}
		else if (C == YELLOW)
		{
			while (Correct < x)
			{
				pOut->PrintMessage("Pick all yellow " + Name + ": Correct:" + to_string(Correct) + " Incorrect:" + to_string(Incorrect));
				ReadActionParameters();
			}
		}
		else if (C == BLACK)
		{
			while (Correct < x)
			{
				pOut->PrintMessage("Pick all black " + Name + ": Correct:" + to_string(Correct) + " Incorrect:" + to_string(Incorrect));
				ReadActionParameters();
			}
		}
		else if (C == ORANGE)
		{
			while (Correct < x)
			{
				pOut->PrintMessage("Pick all orange " + Name + ": Correct:" + to_string(Correct) + " Incorrect:" + to_string(Incorrect));
				ReadActionParameters();
			}
		}
		else
		{
			while (Correct < x)
			{
				pOut->PrintMessage("Pick all blue " + Name + ": Correct:" + to_string(Correct) + " Incorrect:" + to_string(Incorrect));
				ReadActionParameters();
			}
		}
		// load graph
		Action* ptr1 = new loadaction(pManager, false);
		ptr1->Execute(true);
		delete ptr1;
		pOut->PrintMessage("Game over : Correct:" + to_string(Correct) + " Incorrect : " + to_string(Incorrect));
	}
	else
		pOut->PrintMessage("No filled figures");


}
