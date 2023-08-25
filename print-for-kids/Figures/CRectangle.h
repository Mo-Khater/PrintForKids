#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:

	CRectangle() {};
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual bool IsInside(Point P) const;
	virtual void ChngDrawClr(color Dclr);	
	virtual void ChngFillClr(color Fclr);
	virtual string GetFigureName();
	virtual color GetFigureColor();// get figure color
	virtual bool IsFilled();// show if figure is filled or not
	void save(ofstream& );
	void load(ifstream&);
	void move(Point);
};

#endif