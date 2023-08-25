#include"SaveAction.h"
#include"ApplicationManager.h"
#include"GUI/Output.h"
#include"GUI/Input.h"
#include<string.h>
saveaction::saveaction(ApplicationManager* papp, bool s)
	:Action(papp)
{
	S = s;
	if (!S)
		nameofile = "PickAndHide";
};
void saveaction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->savesound();
	pOut->PrintMessage("save! enter your file name");
	nameofile = pIn->GetSrting(pOut) + ".txt";

	pOut->ClearStatusBar();
}
void saveaction::Execute(bool executeaction)
{
	Output* pOut = pManager->GetOutput();
	if (pManager->getrecordingstate() == false)
	{
		if(S)
		ReadActionParameters(); //read the file name from the user
		outf.open(nameofile);//open the file
		if (outf.is_open())//check if the file is opened
		{
			color currentdrawcolor = pOut->getCrntDrawColor();
			color currentfillcolor = pOut->getCrntFillColor();
			// determine the current drawcolor
			string drawcolor;
			if (currentdrawcolor == BLACK)
				drawcolor = "BLACK";
			if (currentdrawcolor == YELLOW)
				drawcolor = "YELLOW";
			if (currentdrawcolor == ORANGE)
				drawcolor = "ORANGE";
			if (currentdrawcolor == RED)
				drawcolor = "RED";
			if (currentdrawcolor == GREEN)
				drawcolor = "GREEN";
			if (currentdrawcolor == BLUE)
				drawcolor = "BLUE";

			//determine current fillcolor
			string fillcolor;
			if (currentfillcolor == BLACK)
				fillcolor = "BLACK";
			else if (currentfillcolor == YELLOW)
				fillcolor = "YELLOW";
			else if (currentfillcolor == ORANGE)
				fillcolor = "ORANGE";
			else if (currentfillcolor == RED)
				fillcolor = "RED";
			else if (currentfillcolor == GREEN)
				fillcolor = "GREEN";
			else if (currentfillcolor == BLUE)
				fillcolor = "BLUE";
			else
				fillcolor = "NO_FILL";
			outf << drawcolor << "\t" << fillcolor << "\n";
			outf << pManager->getfigcount() << "\n";
			pManager->saveall(outf);
			outf.close();
		}
		else
			pOut->PrintMessage("Error file name doesn't exist");
	}
	else
		pOut->PrintMessage("can't do this operation during recording");

}