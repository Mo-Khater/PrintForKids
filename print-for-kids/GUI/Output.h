#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"
#include<cmath>
#include<Windows.h>
class Output	//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();
	

	window* CreateWind(int, int, int, int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar

	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area

	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected = false) const;  //Draw a rectangle
	void Drawsquare(Point, GfxInfo RectGfxInfo, bool selected = false) const;
	void Drawcircle(Point, Point, GfxInfo RectGfxInfo, bool selected = false) const;
	void Drawtriangle(Point, Point, Point, GfxInfo RectGfxInfo, bool selected = false) const;
	void Drawhexagan(Point, GfxInfo RectGfxInfo, bool selected = false) const;
	///Make similar functions for drawing all other figure types.

	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width
	void setcrntdrawcolor(color);
	void setcrntfillcolor(color);
	void savesound();
	void movesound();
	void loadsound();
	void deletesound();
	void rectanglesound();

	~Output();
};

#endif