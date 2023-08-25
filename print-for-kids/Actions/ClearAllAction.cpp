#include "ClearAllAction.h"
#include"ApplicationManager.h"
ClearAllAction::ClearAllAction(ApplicationManager* papp)
	:Action(papp)
{}
void ClearAllAction::ReadActionParameters()
{}
void ClearAllAction::Execute(bool executeaction)
{
	(pManager->GetOutput())->PrintMessage("Cleared");
	pManager->deletefigures();
	pManager->deleteactions();
	UI.DrawColor = BLUE;
	UI.FillColor = WHITE;
}
