#include "AddANDgate2.h"

AddANDgate2::AddANDgate2(ApplicationManager *pApp):Action(pApp)
{
}

AddANDgate2::~AddANDgate2(void)
{
}

void AddANDgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input AND Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
	
}

void AddANDgate2::Execute()
{
	Output * pOut= pManager->GetOutput();
	//Get Center point of the Gate
	ReadActionParameters();
	
	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;
	
	 //Gfx info to be used to construct the AND2 gate
	
	GInfo.x1 = Cx - Len/2;
	GInfo.x2 = Cx + Len/2;
	GInfo.y1 = Cy - Wdth/2;
	GInfo.y2 = Cy + Wdth/2;
	if (pOut->ValidDrawing(GInfo))
	{
		AND2 *pA = new AND2(GInfo, AND2_FANOUT);
		CID = pA->INDEX;
		pManager->AddComponent(pA);
		pManager->SET_ID(pA);
	}
	else 
		pOut->PrintMsg(" You Can't Draw in tool bar or status bar");
}

void AddANDgate2::Undo()
{
	pManager->DelComponent(CID);
}

void AddANDgate2::Redo()
{
	AND2* pA = new AND2(GInfo, AND2_FANOUT);
	pA->SetINDX(CID);
	pManager->AddComponent(pA);
}

GraphicsInfo AddANDgate2::GetCompcoor()
{
	return GInfo;
}

void AddANDgate2::SetCompcoor(GraphicsInfo GxInfo)
{
	GInfo = GxInfo;
}

