// MOCComponent.h: interface for the MOCComponent class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCCOMPONENT_H__0861D1C3_1EA2_45C1_8042_E876F60AD333__INCLUDED_)
#define AFX_MOCCOMPONENT_H__0861D1C3_1EA2_45C1_8042_E876F60AD333__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class MOCComponent  
{
public:
	void Key(int nKey);
	int Key();
	MOCComponent();
	virtual ~MOCComponent();
private:
	int m_nKey;

};
inline int MOCComponent::Key()
{
	return m_nKey;
}
inline void MOCComponent::Key(int nKey)
{
	m_nKey = nKey;
}
#endif // !defined(AFX_MOCCOMPONENT_H__0861D1C3_1EA2_45C1_8042_E876F60AD333__INCLUDED_)
