#include "AddSquareAction.h"
#include"CSquare.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
AddSquareAction::AddSquareAction(ApplicationManager* pApp):Action(pApp)
{}
void AddSquareAction::ReadActionParameters()
{
	//Get a pointer to the input / output interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square : click at the center");
	
	//Read the center and store it at P1
	pIn->GetPointClicked(P1.x, P1.y);
	
	SquareGfxInfo.isFilled = false;//default is not filled
	//get drawing ,filling color from the interface
	SquareGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SquareGfxInfo.FillClr = pOut->getCrntFillColor();
	// clear status bar
	pOut->ClearStatusBar();
}
// Execute Action
void AddSquareAction::Execute()
{
	// read parameters
	ReadActionParameters();
	// create square with the parameter read from user
	CSquare* S = new CSquare(P1, SquareGfxInfo);
	// Add the square to the list of figure
	pManager->AddFigure(S);
}
