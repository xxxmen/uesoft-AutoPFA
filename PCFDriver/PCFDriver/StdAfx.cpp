// stdafx.cpp : source file that includes just the standard includes
//	PCFDriver.pch will be the pre-compiled header
//	stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"
#include "ProjectionInfo.h"

AcGePoint3d Tran3dTo2d(AcGePoint3d &pt)
{
	ProjectionInfo Projection;
	Projection.SetScale(0.1);
	return Projection.GetTransformMatrix()*pt;
}



