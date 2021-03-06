#include "Buff.h"

Buff::Buff(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(1, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	inpp = new pincoor[1];
	inpp[0].x = r_GfxInfo.x1;
	inpp[0].y = r_GfxInfo.y1 +25;
	
	outp.x = r_GfxInfo.x2;
	outp.y = r_GfxInfo.y2 - 25;
	inpconn = new bool[1];
	inpconn[0] = false;
	
}


void Buff::Operate()
{



	int a1;
	a1=GetInputPinStatus(1); 
	if (a1)
		m_OutputPin.setStatus(HIGH);
	else
		m_OutputPin.setStatus(LOW);
}

// Function Draw
// Draws Buff gate
void Buff::Draw(Output* pOut, bool select)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawBuff(m_GfxInfo, select);
}

//returns status of outputpin
int Buff::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}

//////////////////////////
int Buff::GetInputPinStatus(int n)	
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void Buff::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}

pincoor Buff::getouppcoor()
{
	return outp;
}

pincoor* Buff::getinppcoor()
{
	return inpp;
}
OutputPin& Buff::getm_outputpin()
{
	return m_OutputPin;
}
////////////////

void Buff::setinpconn(int n, bool valid)
{
	inpconn[n] = valid;
}




bool Buff::freeinpp()
{
	for (int i = 0; i < 1; i++)
	{
		if (inpconn[i] == false)
		{
			inpconn[i] = true;
			
			return true;
		}
	}
	return false;
}

int Buff::getcurrentpin()
{
	for (int i = 0; i < 1; i++)
	{
		if (inpconn[i] == false)
		{
			currentinpp = i;
			break;
		}
	}
	return currentinpp;
}
InputPin* Buff::getm_InpPutpin(int n)
{
	return &m_InputPins[n];
}
void Buff::DoAllConnections()
{
	m_OutputPin.getAllConnection();
}

Buff::Buff(const Buff& C) :Gate(1, AND2_FANOUT)
{
	m_GfxInfo.x1 = C.m_GfxInfo.x1;
	m_GfxInfo.y1 = C.m_GfxInfo.y1;
	m_GfxInfo.x2 = C.m_GfxInfo.x2;
	m_GfxInfo.y2 = C.m_GfxInfo.y2;
	inpp = new pincoor[1];
	inpp[0].x = C.m_GfxInfo.x1;
	inpp[0].y = C.m_GfxInfo.y1 +25;
	
	outp.x = C.m_GfxInfo.x2;
	outp.y = C.m_GfxInfo.y2 - 25;
	inpconn = new bool[1];
	
		inpconn[0] = false;
	

}
Buff::~Buff()
{
	delete[]inpp;
	delete[]inpconn;
	
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Buff::Get_String(Input* pIn,Output* pOut)
{
	
	set_string(pIn->GetSrting(pOut,m_GfxInfo));
}

void Buff:: SAVE(ofstream &Infofile,int e)
{
	if(e==0)
	Infofile<<"BUFFER\t"<<ID<<"\t"<<getLabel()<<"\t"<<(m_GfxInfo.x1)<<"\t"<<(m_GfxInfo.y1)<<"\n";//no tab after"AND2"
}

void Buff:: setID(int id)
{
	ID=id;
}
int Buff:: get_ID()
 {
	 return ID ;
 }
 void Buff::set_string(string t)
 {
	 Component::set_string(t);
 }
string Buff::getLabel()
{
	return (Component::getLabel());
}
void Buff::SetCompCoordinates(GraphicsInfo Coordinate) 
{


	m_GfxInfo.x1 = Coordinate.x1;
	m_GfxInfo.y1 = Coordinate.y1;
	m_GfxInfo.x2 = Coordinate.x2;
	m_GfxInfo.y2 = Coordinate.y2;
	
	inpp[0].x = Coordinate.x1;
	inpp[0].y = Coordinate.y1 + 25;

	outp.x = Coordinate.x2;
	outp.y = Coordinate.y2 - 25;

}
void Buff::ComponentLow(Output * POut)
{
	m_OutputPin.setStatus(LOW);
}