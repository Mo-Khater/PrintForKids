#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include<fstream>
//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	static int count;
	
	/// Add more parameters if needed.

public:
	CFigure();
	CFigure(GfxInfo FigureGfxInfo);

	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	virtual bool IsInside(Point) const = 0;
	
	virtual void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	virtual void ChngFillClr(color Fclr);	//changes the figure's filling color
	virtual string GetFigureName() = 0;// get figure name
	virtual color GetFigureColor() = 0;// get figure color
	virtual bool IsFilled() = 0;// show if figure is filled or not
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure
	///Decide the parameters that you should pass to each function	
	virtual void save(ofstream& )=0;
	virtual void load(ifstream&) = 0;
	virtual void move(Point) = 0;
	//virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	//virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
	
};

#endif