#include "AddTriangleAction.h"
#include "CTriangle.h"

#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"
AddTriangleAction::AddTriangleAction(ApplicationManager* pApp):Action(pApp)
{}
void AddTriangleAction::ReadActionParameters()
{
	// get a pointer to the input/ output interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: click at first corner");
	// read first corner and store it in P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Triangle: click the second corner");
	// read second corner and store it in P2
	pIn->GetPointClicked(P2.x, P2.y);

	pOut->PrintMessage("New Triangle: click the third corner");
	// read third corner and store it in P3
	pIn->GetPointClicked(P3.x, P3.y);

	TriangleGfxInfo.isFilled = false;// default is not filled

	//get drawing and filling color from interface
	TriangleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriangleGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}
//  Execute the action
void AddTriangleAction::Execute()
{
	// read action parameters first
	ReadActionParameters();

	//Create a Triangle with the parameters read from the user
	CTriangle* T = new CTriangle(P1, P2,P3, TriangleGfxInfo);

	//Add the triangle to the list of figures
	pManager->AddFigure(T);
}