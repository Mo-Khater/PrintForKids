#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include"fstream"
#include"Actions/Action.h"
//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure
	
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;
	int actcount;		//action number of actions
	Action* actlist[20];
	bool recordingstate;
	Action* lastaction;



public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	// -- Interface Management Functions
	CFigure* selectedFig(); // search for selected figure
	void UpdateSelected(); // updates the selected figure
	CFigure* GetRandomFigureName();// get random figure name for pick type
	color GetRandomColor();// get random Fill color
	bool CheckFill();// show if there is a filled figure
	int GetColorNum(color v);// get number of figure with special color
	int GetBothNum(string name, color c);// get number of figure with special color and shape
	int GetFigNum(string name);// get number of figure with the name passed
	CFigure* GetSelectedFig();//getter for the selected figure pointer
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window
	void saveall(ofstream&);
	int getfigcount();
	void deletefigures();
	void DeleteFig();
	void move(Point);
	bool checkifnofigures();//check if the figlist is empty
	void Addaction(Action* pact);
	void setrecordingstate(bool);
	bool getrecordingstate();
	void playrecording();
	bool checkifnoactions();
	void deleteactions();


};

#endif