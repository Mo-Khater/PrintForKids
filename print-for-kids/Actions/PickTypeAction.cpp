#include"PickTypeAction.h"
#include "..\ApplicationManager.h"
#include"string"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include"../LoadAction.h"
PickTypeAction::PickTypeAction(ApplicationManager* pApp) :Action(pApp)
{
	Correct = 0;
	Incorrect = 0;
}
void PickTypeAction::ReadActionParameters()
{
	//  get a pointer to  input interface
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	// get user click to know what figure he chose
	pIn->GetPointClicked(P.x, P.y);
	CFigure* ptr = pManager->GetFigure(P.x, P.y);
	if (ptr == NULL)
		return;
	else
	{
		if (ptr->GetFigureName() == Name)
		{
			// delete figure
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
			Correct++;
		}
		else
		{
			Incorrect++;
		}
	}

}
// execute action
void PickTypeAction::Execute(bool read)
{
	//  get a pointer to  output interface
	Output* pOut = pManager->GetOutput();
	// get random figure name
	CFigure* C = pManager->GetRandomFigureName();
	Name = C->GetFigureName();
	x = pManager->GetFigNum(Name);
	if (Name == "No Figure")
		return;
	
	// will be done later 

	while (Correct < x)
	{
		pOut->PrintMessage("Pick all " + Name + " Correct " + to_string(Correct) + " Incorrect " + to_string(Incorrect));
		ReadActionParameters();
		pOut->ClearStatusBar();
	}
	pOut->PrintMessage("Game over : correct figures:" + to_string(Correct) + " incorrect figures:" + to_string(Incorrect));
	// load the original graph 
	Action* ptr1 = new loadaction(pManager, false);
	ptr1->Execute(true);
	delete ptr1;
}