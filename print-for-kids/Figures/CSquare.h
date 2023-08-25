#pragma once
#include "Figures/CFigure.h"
class CSquare : public CFigure
{
private:
	Point Center;
public:
	CSquare(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual void ChngDrawClr(color Dclr);	
	virtual void ChngFillClr(color Fclr);
	virtual string GetFigureName();
};

