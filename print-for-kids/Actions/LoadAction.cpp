#include"LoadAction.h"
#include"ApplicationManager.h"
#include"GUI/Output.h"
#include"GUI/Input.h"
#include<string>
#include"Figures/CRectangle.h"
#include"CCircle.h"
#include"CTriangle.h"
#include"CHexagon.h"
#include"CSquare.h"
loadaction::loadaction(ApplicationManager* papp, bool s)
	:Action(papp)
{
	S = s;
	if (!S)
		nameofile = "PickAndHide";
};
void loadaction::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->loadsound();
	pOut->PrintMessage("load! enter your file name");
	string nameofile = pIn->GetSrting(pOut) + ".txt";
	inf.open(nameofile);
	pOut->ClearStatusBar();
}
void loadaction::Execute(bool executeaction)
{
	Output* pOut = pManager->GetOutput();
	if (pManager->getrecordingstate() == false)
	{
		if (S)
			ReadActionParameters();
		else
			inf.open(nameofile);

		if (inf.is_open())//check if it is opened
		{
			pManager->deletefigures();
			pOut->ClearDrawArea();
			int nof;
			string currentdrawcolor, currentfillcolor;
			inf >> currentdrawcolor >> currentfillcolor;
			color curntdrawcolor;
			color curntfillcolor;
			if (currentdrawcolor == "BLACK")
				curntdrawcolor = BLACK;
			if (currentdrawcolor == "YELLOW")
				curntdrawcolor = YELLOW;
			if (currentdrawcolor == "ORANGE")
				curntdrawcolor = ORANGE;
			if (currentdrawcolor == "RED")
				curntdrawcolor = RED;
			if (currentdrawcolor == "GREEN")
				curntdrawcolor = GREEN;
			if (currentdrawcolor == "BLUE")
				curntdrawcolor = BLUE;

			if (currentfillcolor == "BLACK")
			{
				curntfillcolor = BLACK;

			}
			if (currentfillcolor == "YELLOW")
				curntfillcolor = YELLOW;
			if (currentfillcolor == "ORANGE")
				curntfillcolor = ORANGE;
			if (currentfillcolor == "RED")
				curntfillcolor = RED;
			if (currentfillcolor == "GREEN")
				curntfillcolor = GREEN;
			if (currentfillcolor == "BLUE")
				curntfillcolor = BLUE;

			pOut->setcrntdrawcolor(curntdrawcolor);//set currentdrawcolor
			pOut->setcrntfillcolor(curntfillcolor);//set currentfillcolor
			inf >> nof;
			CFigure* myfigure;
			string s;
			for (int i = 0; i < nof; i++)
			{

				inf >> s;
				if (s == "RECT")
				{
					myfigure = new CRectangle;

				}
				if (s == "SQUA")
				{
					myfigure = new CSquare;

				}
				if (s == "TRIA")
				{
					myfigure = new CTriangle;

				}
				if (s == "HEXA")
				{
					myfigure = new CHexagon;

				}
				if (s == "CIRC")
				{
					myfigure = new CCircle;

				}

				if (myfigure) // if it points at a figure
				{
					myfigure->load(inf);
					pManager->AddFigure(myfigure);
				}

			}

			inf.close();

		}
		else
		{
			pOut->PrintMessage("error file isn't exist");
		}
	}
	else
		pOut->PrintMessage("can't do this operation during recording");
}