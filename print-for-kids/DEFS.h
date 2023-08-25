#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_RECT,		//Draw Rectangle
	EXIT,			//Exit
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,		//Switch interface to Play mode
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	DRAW_SQUARE,    // draw square
	DRAW_TRIANGLE,  // draw triangle
	DRAW_HEXAGON,   // draw hexagon
	DRAW_CIRCLE,   // draw circle
	SELECT,        // a click on select item
	CHANGE_DRAW,   // change draw color of a figure
	CHANGE_FILL,  // change fill color of a figure
	ACT_BLACK, // black color is choosen
	ACT_YELLOW,
	ACT_ORANGE,
	ACT_RED,
	ACT_GREEN,
	ACT_BLUE,
	ACT_DELETE,//delete a figure
	MOVE, // move a figure
	UNDO,
	REDO,
	CLEAR,
	START_RE,
	STOP_RE,
	PLAY_RE,
	SAVE,
	LOAD,
	PICK_TYPE,
	PICK_COLOR,
	PICK_BOTH

	///TODO: Add the other action types of the two modes
};

struct Point	//To be used for figures points
{
	int x, y;
	Point()
	{}
	Point(int x1, int y1)
	{
		x = x1;
		y = y1;
	}
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif