#include"DeleteFigure.h"
#include"ApplicationManager.h"

deletefig::deletefig(ApplicationManager* papp)
	:Action(papp)
{};
void deletefig::Execute(bool executeaction)
{
	Output* pOut = pManager->GetOutput();
	pOut->deletesound();
	if (pManager->GetSelectedFig())//check if the kid select a figure
	{
		pOut->PrintMessage("delete a selected figure");
		pManager->DeleteFig();
		pOut->ClearDrawArea();
		pOut->ClearStatusBar();
		pManager->Addaction(this);
	}
	else
		pOut->PrintMessage("please select the figure you want to delete");

	
}
void deletefig::ReadActionParameters()
{}
