#include"startaction.h"
#include"ApplicationManager.h"
#include"GUI/Output.h"
#include"GUI/Input.h"

startrecording::startrecording(ApplicationManager* papp)
	:Action(papp)
{

};
void startrecording::ReadActionParameters()
{

}
void startrecording::Execute(bool executeaction)
{
	Output* pOut = pManager->GetOutput();
	if (!pManager->checkifnoactions())//check if there is already another record
	{
		pManager->deleteactions();
	}
	else
	{ 
		if (pManager->getrecordingstate() == false)
		{
			if (pManager->checkifnofigures())
			{
				pOut->PrintMessage("record is on start to play");
				pManager->setrecordingstate(true);
			}
			else
				pOut->PrintMessage("can't record ");
		}
		else
			pOut->PrintMessage("can't do this operation during recording ");
	}
	


}