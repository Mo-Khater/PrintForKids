#include "SwitchToDAction.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include"LoadAction.h"
SwitchToDAction::SwitchToDAction(ApplicationManager*pApp):Action(pApp)
{}
void SwitchToDAction::ReadActionParameters()
{}
void SwitchToDAction::Execute(bool executeaction)
{
	Output* pOut = pManager->GetOutput();
	if (pManager->getrecordingstate() == false)
	{
		pOut->CreateDrawToolBar();
		pOut->ClearStatusBar();
	}
	else
		pOut->PrintMessage("can't do this operation during recording ");
	
}
