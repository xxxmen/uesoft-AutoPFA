// UnitInfo.h: interface for the UnitInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UNITINFO_H__14F13EB0_0426_4955_AF4F_DDE0A49E2D85__INCLUDED_)
#define AFX_UNITINFO_H__14F13EB0_0426_4955_AF4F_DDE0A49E2D85__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class AFX_EXT_CLASS UnitInfo  
{
public:
	UnitInfo();
	virtual ~UnitInfo();

public:
	void Init(const CStringArray &strSet);
	const CString& GetBoreUnit() const {
		return m_strBoreUnit ;
	}
	const CString& GetCoordinateUnit() const {
		return m_strCoordinateUnit ;
	}
	const CString& GetWeightUnit() const {
		return m_strWeightUnit ;
	}
	const CString& GetBoltDiaUnit() const {
		return m_strBoltDiaUnit ;
	}
	const CString& GetBoltLengthUnit() const {
		return m_strBoltLengthUnit ;
	}
	
	void SetBoreUnit( const CString& strBoreUnit ){
		m_strBoreUnit = strBoreUnit ;
	}
	void SetCoordinateUnit( const CString& strCorUnit ){
		m_strCoordinateUnit = strCorUnit ;
	}
	void SetWeightUnit(const CString& strWeightUnit ){
		m_strWeightUnit = strWeightUnit ;
	}
	void SetBoltDiaUnit(const CString& strBolitDiaUnit ){
		m_strBoltDiaUnit = strBolitDiaUnit ;
	}
	void SetBoltLengthUnit(const CString& strBoltLengthUnit ){
		m_strBoltLengthUnit = strBoltLengthUnit ;
	}

private:
	CString m_strBoreUnit;
	CString m_strCoordinateUnit;
	CString m_strWeightUnit;
	CString m_strBoltDiaUnit;
	CString m_strBoltLengthUnit;
};

#endif // !defined(AFX_UNITINFO_H__14F13EB0_0426_4955_AF4F_DDE0A49E2D85__INCLUDED_)
