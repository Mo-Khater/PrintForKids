#include "CHexagon.h"
CHexagon::CHexagon(Point P1,GfxInfo FiguregfxInfo):CFigure(FiguregfxInfo)
{
	Center = P1;
}
void CHexagon::Draw(Output* pOut)const
{
	// Call Output::DrawHexagon to Draw Hexagon on the screen
	pOut->Drawhexagan(Center, FigGfxInfo, Selected);
}
// change fill color
void CHexagon::ChngFillClr(color Fclr)
{
	if (Selected)
		FigGfxInfo.FillClr = Fclr;
}
// change draw color
void CHexagon::ChngDrawClr(color Dclr)
{
	if (Selected)
		FigGfxInfo.DrawClr = Dclr;
}
// get figure name
string CHexagon::GetFigureName()
{
	return "Hexagons";
}
