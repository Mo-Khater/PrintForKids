#include "CFigure.h"
int CFigure::count = 0;//static data member 
CFigure::CFigure()
{
	ID = ++count;
	Selected = false;
}
CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	ID = ++count;
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	if (UI.FillColor != WHITE)
		FigGfxInfo.isFilled = true;

	Selected = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}


