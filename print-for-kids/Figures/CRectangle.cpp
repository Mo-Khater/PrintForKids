#include "CRectangle.h"
#include<string>
#include<cmath>
CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}


void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}
bool CRectangle::IsInside(Point P) const
{
	bool TestX = false;
	bool TestY = false;
	if (Corner1.x > Corner2.x)
	{
		if (Corner1.x >= P.x && P.x >= Corner2.x)
			TestX = true;
	}
	else if (Corner1.x < Corner2.x)
	{
		if (Corner2.x >= P.x && P.x >= Corner1.x)
			TestX = true;
	}
	if (Corner1.y > Corner2.y)
	{
		if (Corner1.y >= P.y && P.y >= Corner2.y)
			TestY = true;
	}
	else if (Corner1.y < Corner2.y)
	{
		if (Corner2.y >= P.y && P.y >= Corner1.y)
			TestY = true;
	}
	if (TestX == true && TestY == true)
	{
		return true;
	}
	else
		return false;

}

void CRectangle::ChngFillClr(color Fclr)
{
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr;
}
void CRectangle::ChngDrawClr(color Dclr)
{
	FigGfxInfo.DrawClr = Dclr;
}
string CRectangle::GetFigureName()
{
	return "Rectangles";
}
void  CRectangle::save(ofstream& outf)
{
	//determine drawcolor of the rectangle
	string drawcolor;
	if (FigGfxInfo.DrawClr == BLACK)
		drawcolor = "BLACK";
	if (FigGfxInfo.DrawClr == YELLOW)
		drawcolor = "YELLOW";
	if (FigGfxInfo.DrawClr == ORANGE)
		drawcolor = "ORANGE";
	if (FigGfxInfo.DrawClr == RED)
		drawcolor = "RED";
	if (FigGfxInfo.DrawClr == GREEN)
		drawcolor = "GREEN";
	if (FigGfxInfo.DrawClr == BLUE)
		drawcolor = "BLUE";
	//determine fillcolor of the rectangle
	string fillcolor;
	if (FigGfxInfo.FillClr == BLACK)
		fillcolor = "BLACK";
	else if (FigGfxInfo.FillClr == YELLOW)
		fillcolor = "YELLOW";
	else if (FigGfxInfo.FillClr == ORANGE)
		fillcolor = "ORANGE";
	else if (FigGfxInfo.FillClr == RED)
		fillcolor = "RED";
	else if (FigGfxInfo.FillClr == GREEN)
		fillcolor = "GREEN";
	else if (FigGfxInfo.FillClr == BLUE)
		fillcolor = "BLUE";
	else
		fillcolor = "NO_FILL";


	//put in the file 

	string s = "RECT"; //its name
	outf << s << "\t" << ID << "\t" << Corner1.x << "\t" << Corner1.y << "\t" << Corner2.x << "\t" << Corner2.y << "\t"
		<< drawcolor << "\t" << fillcolor << "\n";


}
void  CRectangle::load(ifstream& inF)

{
	inF >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y;//load its parameters
	string drawcolor;
	inF >> drawcolor;

	if (drawcolor == "BLACK")
		FigGfxInfo.DrawClr = BLACK;
	if (drawcolor == "YELLOW")
		FigGfxInfo.DrawClr = YELLOW;
	if (drawcolor == "ORANGE")
		FigGfxInfo.DrawClr = ORANGE;
	if (drawcolor == "RED")
		FigGfxInfo.DrawClr = RED;
	if (drawcolor == "GREEN")
		FigGfxInfo.DrawClr = GREEN;
	if (drawcolor == "BLUE")
		FigGfxInfo.DrawClr = BLUE;

	string fillcolor;
	inF >> fillcolor;
	if (fillcolor == "BLACK")
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = BLACK;
	}
	if (fillcolor == "YELLOW")
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = YELLOW;
	}
	if (fillcolor == "ORANGE")
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = ORANGE;
	}
	if (fillcolor == "RED")
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = RED;
	}
	if (fillcolor == "GREEN")
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = GREEN;
	}
	if (fillcolor == "BLUE")
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = BLUE;
	}
	if (fillcolor == "NO_FILL")
		FigGfxInfo.isFilled = false;
}
void  CRectangle::move(Point movepoint)
{
	Point center;
	center.x = (Corner1.x + Corner2.x) / 2;
	center.y = (Corner1.y + Corner2.y) / 2;
	int moveinx, moveiny;//the distance of transition
	moveinx = abs(movepoint.x - center.x);
	moveiny = abs(movepoint.y - center.y);
	if (movepoint.x > center.x)
	{
		Corner1.x += moveinx;
		Corner2.x += moveinx;
	}
	else
	{
		Corner1.x -= moveinx;
		Corner2.x -= moveinx;
	}
	if (movepoint.y > center.y)
	{
		Corner1.y += moveiny;
		Corner2.y += moveiny;
	}
	else
	{
		Corner1.y -= moveiny;
		Corner2.y -= moveiny;
	}

}
// get Figure color
color CRectangle::GetFigureColor()
{
	return FigGfxInfo.FillClr;
}
bool CRectangle::IsFilled()
{
	return FigGfxInfo.isFilled;
}