#pragma once
#include "Figures/CFigure.h"
class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut)const;
	virtual void ChngDrawClr(color Dclr);	
	virtual void ChngFillClr(color Fclr);
	virtual string GetFigureName();
};

