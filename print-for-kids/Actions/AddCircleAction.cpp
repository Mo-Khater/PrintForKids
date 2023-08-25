#include "AddCircleAction.h"
#include"CCircle.h"

#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"
AddCircleAction::AddCircleAction(ApplicationManager* pApp):Action(pApp)
{}
void AddCircleAction::ReadActionParameters()
{
	// get a pointer to input/ output interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: click at the center");
	// read the center and store it in P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Circle: click to determine  radius");
	//read the radius and store it in P2
	pIn->GetPointClicked(P2.x, P2.y);

	CircleGfxInfo.isFilled = false;//default is not filled
	// get drawing and filling color from the interface
	CircleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircleGfxInfo.FillClr = pOut->getCrntFillColor();

	// clear status bar
	pOut->ClearStatusBar();
}
// Execute the Action
void AddCircleAction::Execute()
{
	// read parameters first
	ReadActionParameters();
	// create circle with the parameters read from user
	CCircle* C = new CCircle(P1, P2, CircleGfxInfo);
	// add the circle to the list of figures
	pManager->AddFigure(C);

}