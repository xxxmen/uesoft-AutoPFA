// PCFSysPropety.h: interface for the PCFSysPropety class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFSYSPROPETY_H__F17A44D8_5C7C_4403_9909_F12BC5D66272__INCLUDED_)
#define AFX_PCFSYSPROPETY_H__F17A44D8_5C7C_4403_9909_F12BC5D66272__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "SysProperty.h"

class AFX_EXT_CLASS PCFSysPropety  
{
public:
	PCFSysPropety();
	virtual ~PCFSysPropety();
	ErrorStatus::FileError Read(PropertyPersistent& model);

};

#endif // !defined(AFX_PCFSYSPROPETY_H__F17A44D8_5C7C_4403_9909_F12BC5D66272__INCLUDED_)
