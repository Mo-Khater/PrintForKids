#include "CTriangle.h"
CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}
void CTriangle::Draw(Output* pOut)const
{
	// Call Output::Drawtriangle to draw triangle on the screen
	pOut->Drawtriangle(Corner1, Corner2, Corner3, FigGfxInfo, Selected);

}
// chaange fill color
void CTriangle::ChngFillClr(color Fclr)
{
	if (Selected)
		FigGfxInfo.FillClr = Fclr;
}
// change draw color
void CTriangle::ChngDrawClr(color Dclr)
{
	if (Selected)
		FigGfxInfo.DrawClr = Dclr;
}
// get figure name
string CTriangle::GetFigureName()
{
	return "Triangles";
}
