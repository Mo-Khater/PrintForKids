#pragma once
#include "Figures/CFigure.h"
class CCircle : public CFigure
{
private:
	Point Center;
	Point Radius;
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual void ChngDrawClr(color Dclr);
	virtual void ChngFillClr(color Fclr);
	virtual string GetFigureName();
};

