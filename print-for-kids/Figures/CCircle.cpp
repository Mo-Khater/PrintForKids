#include "CCircle.h"
#include"cmath"
CCircle::CCircle(Point P1, Point P2,GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Center = P1;
	Radius = P2;
}
void CCircle::Draw(Output* pOut) const
{
	// call Output::DrawCircle to draw circle on the screen
	pOut->Drawcircle(Center, Radius, FigGfxInfo, Selected);
}
// change fill color
void CCircle::ChngFillClr(color Fclr)
{
	if(Selected)
		FigGfxInfo.FillClr = Fclr;
}
// change draw color
void CCircle::ChngDrawClr(color Dclr)
{
	if (Selected)
		FigGfxInfo.DrawClr = Dclr;
}
// get figure name
string CCircle::GetFigureName()
{
	return "Circles";
}