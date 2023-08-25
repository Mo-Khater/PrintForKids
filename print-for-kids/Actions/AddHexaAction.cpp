#include "AddHexaAction.h"
#include "CHexagon.h"

#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"
AddHexaAction::AddHexaAction(ApplicationManager* pApp):Action(pApp)
{}
void AddHexaAction::ReadActionParameters()
{
	// get a pointer to output/ input interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("New Hexagon: click at the center");
	// read the center and store at P1
	pIn->GetPointClicked(P1.x, P1.y);
	
	HexaGfxInfo.isFilled = false;// Default is not filled
	// get drawing / filling color from interface
	HexaGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexaGfxInfo.FillClr = pOut->getCrntFillColor();
	
	pOut->ClearStatusBar();
}

//Execute the action
void AddHexaAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a Hexagon with the parameters read from the user
	CHexagon* H = new CHexagon(P1,HexaGfxInfo);

	//Add the Hexagon to the list of figures
	pManager->AddFigure(H);
}
