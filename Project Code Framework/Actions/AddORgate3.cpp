#include "AddORgate3.h"
AddORgate3::AddORgate3(ApplicationManager* pApp) :Action(pApp)
{
}

AddORgate3::~AddORgate3(void)
{
}

void AddORgate3::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("3-Input OR Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
}

void AddORgate3::Execute()
{
	Output * pOut = pManager->GetOutput();
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
	OR3* pA = new OR3(GInfo, AND2_FANOUT);
	CID = pA->INDEX;
	pManager->AddComponent(pA);
	pManager->SET_ID(pA);
	}
	else
		pOut->PrintMsg(" You Can't Draw in tool bar or status bar");
}

void AddORgate3::Undo()
{
	pManager->DelComponent(CID);
}

void AddORgate3::Redo()
{
	OR3* pA = new OR3(GInfo, AND2_FANOUT);
	pA->SetINDX(CID);
	pManager->AddComponent(pA);
	pManager->SET_ID(pA);
}

GraphicsInfo AddORgate3::GetCompcoor()
{
	return GInfo;
}

void AddORgate3::SetCompcoor(GraphicsInfo GxInfo)
{
	GInfo = GxInfo;
}
