#include"PlayRecording.h"
#include"ApplicationManager.h"
#include"GUI/Output.h"
#include"GUI/Input.h"

PlayRecording::PlayRecording(ApplicationManager* papp)
	:Action(papp)
{}
void PlayRecording::ReadActionParameters()
{

}
void  PlayRecording::Execute(bool executeaction)
{
	Output* pOut = pManager->GetOutput();
	if (pManager->getrecordingstate() == false)
	{
		pOut->PrintMessage("play the last record");
		pManager->deletefigures();
		pOut->ClearDrawArea();
		pManager->playrecording();
	}
	else
		pOut->PrintMessage("can't do this operation during recording");
}