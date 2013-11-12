// Annotations.cpp: implementation of the Annotations class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Annotations.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Annotations::Annotations()
{
	InitArray();
}

Annotations::~Annotations()
{

}

BOOL Annotations::Read(CStdioFile &file)
{
	//return ReadRow(file);
	return TRUE;
}

BOOL Annotations::Save(CStdioFile &file)
{
	//return SaveRow(file);
	return TRUE;
}

void Annotations::Init()
{

}

void Annotations::InitArray()
{

}
