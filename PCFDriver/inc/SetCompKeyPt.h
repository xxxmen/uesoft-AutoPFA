#ifndef		SETCOMPKEYPT_H
#define		SETCOMPKEYPT_H

class PCFPortPoint;

void SetSEBPoint(const CStringArray& wordArray, int &iPosition, int &pointNum, 
				  PCFPortPoint &listPt, AcGePoint3d &BasePt);
void SetSEFromBasePt(const CStringArray& wordArray, int &iPosition, int &pointNum, 
					 PCFPortPoint &listPt, AcGePoint3d &BasePt);
void SetBFromSEPt(const CStringArray& wordArray, int &iPosition, int &pointNum, 
					 PCFPortPoint &listPt, AcGePoint3d &BasePt);

BOOL IsEqual(const AcGePoint3d &Pt1, const AcGePoint3d &Pt2);

#endif
