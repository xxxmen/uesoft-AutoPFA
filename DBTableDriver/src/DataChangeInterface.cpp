// DataChangeInterface.cpp: implementation of the CDataChangeInterface class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DataChangeInterface.h"
#include "EduceFromFile.h"
#include "InputToFile.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDataChangeInterface::CDataChangeInterface()
{

}

CDataChangeInterface::~CDataChangeInterface()
{

}

void CDataChangeInterface::PutDataInotFile(CalcTable<2> &DBTable)
{
	CEduceFromFile educeFromFile;
	educeFromFile.ReadFile(DBTable);
}

void CDataChangeInterface::GetDataFrom(CalcTable<2> &DBTable)
{
	CInputToFile inputToFile;
	inputToFile.SetDAtaToFile(DBTable);
}
