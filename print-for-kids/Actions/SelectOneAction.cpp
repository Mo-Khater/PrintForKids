#include "SelectOneAction.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "ApplicationManager.h"
SelectOneAction::SelectOneAction(ApplicationManager* pApp):Action(pApp)
{}
void SelectOneAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Please Select a Figure");
	pIn->GetPointClicked(P.x, P.y);
	pOut->ClearStatusBar();
}
void SelectOneAction::Execute(bool executeaction)
{
	if (executeaction)
	ReadActionParameters();
	CFigure* Selected;
	if (pManager->GetFigure(P.x, P.y) != NULL)
	{
		Selected = pManager->GetFigure(P.x, P.y);
		if (Selected->IsSelected() == false && pManager->GetSelectedFig() != NULL)
		{
			Selected->SetSelected(true);
			(pManager->GetSelectedFig())->SetSelected(false);
			pManager->UpdateSelected();
			pManager->Addaction(this);
		}
		else if (Selected->IsSelected())
		{
			Selected->SetSelected(false);
			pManager->UpdateSelected();
			pManager->Addaction(this);

		}
		else if (Selected->IsSelected() == false && pManager->GetSelectedFig() == NULL) {
			Selected->SetSelected(true);
			pManager->UpdateSelected();
			pManager->Addaction(this);
		}
	}

}
