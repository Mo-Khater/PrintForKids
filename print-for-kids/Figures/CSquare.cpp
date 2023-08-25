#include "CSquare.h"
CSquare::CSquare(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
}
void CSquare::Draw(Output* pOut)const
{
	pOut->Drawsquare(Center, FigGfxInfo, Selected);
}
// change fill color
void CSquare::ChngFillClr(color Fclr)
{
	if (Selected)
		FigGfxInfo.FillClr = Fclr;
}
// change draw color
void CSquare::ChngDrawClr(color Dclr)
{
	if (Selected)
		FigGfxInfo.DrawClr = Dclr;
}
// get figure name
string CSquare::GetFigureName()
{
	return "Squares";
}