#pragma once
#include "Figures/CFigure.h"
class CHexagon : public CFigure
{
private:
	Point Center;
public:
	CHexagon(Point, GfxInfo FigureGfxinfo);
	virtual void Draw(Output* pOut)const;
	virtual void ChngDrawClr(color Dclr);	
	virtual void ChngFillClr(color Fclr);
	virtual string GetFigureName();
};

