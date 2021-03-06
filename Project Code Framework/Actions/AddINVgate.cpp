#include "AddINVgate.h"
AddINVgate::AddINVgate(ApplicationManager* pApp) :Action(pApp)
{
}
AddINVgate::~AddINVgate(void)
{
}

void AddINVgate::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("BUFFER Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
}

void AddINVgate::Execute()
{
	Output * pOut = pManager->GetOutput();
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	 //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	if (pOut->ValidDrawing(GInfo))
	{
	INV* pA = new INV(GInfo, AND2_FANOUT);
	CID = pA->INDEX;
	pManager->AddComponent(pA);
	pManager->SET_ID(pA);
	}
	else
		pOut->PrintMsg(" You Can't Draw in tool bar or status bar");
}

void AddINVgate::Undo()
{
	pManager->DelComponent(CID);
}

void AddINVgate::Redo()
{
	INV* pA = new INV(GInfo, AND2_FANOUT);
	pA->SetINDX(CID);
	pManager->AddComponent(pA);
	pManager->SET_ID(pA);
}

GraphicsInfo AddINVgate::GetCompcoor()
{
	return GInfo;
}

void AddINVgate::SetCompcoor(GraphicsInfo GxInfo)
{
	GInfo = GxInfo;
}
