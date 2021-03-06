#ifndef _XNOR3_H
#define _XNOR3_H

/*
  Class XNOR2
  -----------
  represent the 2-input XNOR2 gate
*/

#include "Gate.h"

class XNOR3 :public Gate
{
public:
	XNOR3(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the AND gate
	virtual void Draw(Output* pOut, bool select);	//Draws 2-input gate
	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1
	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class
	virtual OutputPin& getm_outputpin();//return the OutPutPin of the Component
	virtual InputPin* getm_InpPutpin(int n);//return the InPutPin of the Component
	virtual pincoor* getinppcoor();//return the InPut Pin Coordinates  of the Component
	virtual pincoor getouppcoor();//return the InPut Pin Coordinates  of the Component
	virtual bool freeinpp();//bool function to see weather there is a free Input Pin (false = free , true = connected)
	virtual int getcurrentpin();//return the index of the free input pin
	virtual void setinpconn(int n, bool validation);//set the bool input pin to false in case of deleting
	virtual void DoAllConnections();//go to the outpin of the gate then operate all the connection connect to that gate
	XNOR3(const XNOR3& C);//copy
	~XNOR3();

	virtual void SAVE(ofstream &Infofile,int e);
	
	virtual void setID(int id);
	virtual int get_ID();
	
	virtual void Get_String(Input* pIn,Output* pOut);
	
	virtual void set_string(string t);
	virtual string getLabel();
	void SetCompCoordinates(GraphicsInfo Coordinate);
	
	
	void ComponentLow(Output * POut);//Make the outpin low when switch to design mode

};

#endif

