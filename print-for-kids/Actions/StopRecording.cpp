#include"stoprecording.h"
#include"ApplicationManager.h"
#include"GUI/Output.h"
#include"GUI/Input.h"
stoprecording::stoprecording(ApplicationManager* papp)
	:Action(papp)
{}
void stoprecording::ReadActionParameters()
{

}
void stoprecording::Execute(bool executeaction)
{
	Output* pOut = pManager->GetOutput();
	
		pOut->PrintMessage("stop recording");
		pManager->setrecordingstate(false);

}