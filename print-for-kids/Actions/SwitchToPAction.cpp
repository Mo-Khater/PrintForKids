#include "SwitchToPAction.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include"SaveAction.h"
SwitchToPAction::SwitchToPAction(ApplicationManager* pApp):Action(pApp)
{}
void SwitchToPAction::ReadActionParameters()
{}
void SwitchToPAction::Execute(bool executeaction)
{
	Output* pOut = pManager->GetOutput();
	if (pManager->getrecordingstate() == false)
	{
		pOut->CreatePlayToolBar();
		Action* ptr1 = new saveaction(pManager, false);
		ptr1->Execute(true);
		delete ptr1;
	}
	else
		pOut->PrintMessage("can't do this operation during recording ");
	
}
