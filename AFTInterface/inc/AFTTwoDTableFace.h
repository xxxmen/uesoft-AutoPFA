// AFTTwoDTableFace.h: interface for the AFTTwoDTableFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AFTTWODTABLEFACE_H__CD988D81_1B71_4B0A_873E_1D5D8F9246F2__INCLUDED_)
#define AFX_AFTTWODTABLEFACE_H__CD988D81_1B71_4B0A_873E_1D5D8F9246F2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "TableData.h"
#include "TwoDTablePersistent.h"
#include "CalcTable.h"

class AFX_EXT_CLASS AFTTableFace  
{
public:
	AFTTableFace();
	virtual ~AFTTableFace();

	template<UINT size> ErrorStatus::FileError Read(Table<size> &Data,GridTablePersistent<size> &Model)
	{
		Model.Unit(Data.Unit());
		Model.Data(Data.Data());
		return ErrorStatus::eFileOK;
	};
	template<UINT size> ErrorStatus::FileError Save(Table<size> &Data,GridTablePersistent<size> &Model)
	{
		Data.Unit(Model.Unit());
		Data.Data(Model.Data());
		return ErrorStatus::eFileOK;
	};
};

#endif // !defined(AFX_AFTTWODTABLEFACE_H__CD988D81_1B71_4B0A_873E_1D5D8F9246F2__INCLUDED_)
