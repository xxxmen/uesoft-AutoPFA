// PCFSteadyFace.cpp: implementation of the PCFSteadyFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFSteadyFace.h"
#include "SteadyPersistent.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFSteadyFace::PCFSteadyFace()
{

}

PCFSteadyFace::~PCFSteadyFace()
{

}

ErrorStatus::FileError PCFSteadyFace::Read(SteadyPersistent &model)
{
	model.AnalysisType(_T("0"));
	model.PresTolType(_T("1"));
	model.PresRelTol(_T("0.00001"));
	model.FlowTolType(_T("1"));
	model.FlowRelTol(_T("0.00001"));
	model.RelaxationType(_T("1"));
	model.FlowRelaxation(_T("0.9"));
	model.PresRelaxation(_T("0.9"));
	model.MaxIterations(_T("50000"));
	model.KeepHistory(_T("0"));
	model.MatrixMethod(_T("0"));
	model.AutoDetect(_T("100"));
	return ErrorStatus::eFileOK;
}
