// ProjectionInfo.h: interface for the ProjectionInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROJECTIONINFO_H__B5887CCE_0887_46A9_B146_3A3C6F4DD205__INCLUDED_)
#define AFX_PROJECTIONINFO_H__B5887CCE_0887_46A9_B146_3A3C6F4DD205__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class AFX_EXT_CLASS ProjectionInfo  
{
public:
	ProjectionInfo();
	virtual ~ProjectionInfo();
public:
	void SetXYZPlaneProjection( const double  dScale = 1.0 ,
		                       const AcGePoint3d& ptCenter = AcGePoint3d::kOrigin);
	void Set_XYZPlaneProjection(  const double  dScale = 1.0 ,
		                       const AcGePoint3d& ptCenter = AcGePoint3d::kOrigin);
	void SetX_YZPlaneProjection(  const double  dScale = 1.0 ,
		                       const AcGePoint3d& ptCenter = AcGePoint3d::kOrigin);
	void Set_X_YZPlaneProjection(   const double  dScale = 1.0 ,
		                       const AcGePoint3d& ptCenter = AcGePoint3d::kOrigin);
	void SetXYPlaneProjection(   const double  dScale = 1.0 ,
		                       const AcGePoint3d& ptCenter = AcGePoint3d::kOrigin);
	void SetYZPlaneProjection(  const double  dScale = 1.0 ,
		                       const AcGePoint3d& ptCenter = AcGePoint3d::kOrigin);
	void SetZXPlaneProjection( const double  dScale = 1.0 ,
		                       const AcGePoint3d& ptCenter = AcGePoint3d::kOrigin);

	void SetScale( const double dScale ) ;
	void SetAdditionalScale( const double dAddScale ) ;
	const double GetAdditionalScale() ;
	const double GetScale() ;

	const AcGeMatrix3d& GetProjectionMatrix()   ;//得到转换到投影平面的矩阵
	const AcGeMatrix3d& GetToTargetPlaneMatrix();//得到从投影平面转换到目标平面的矩阵
	const AcGeMatrix3d& GetTransformMatrix()    ;//得到最终的转换矩阵	
	const AcGeVector3d& GetProjectionNormal()   ;//得到投影面的方向
	const AcGeVector3d& GetPlaneNormal()        ;//得到投影面的法向
	const AcGePlane&    GetProjectionPlane()    ;//得到投影面	
	const AcGePlane&    GetTargetPlane()        ;//得到目标平面	

		
public:
	void operator = ( const ProjectionInfo& prjInfo) ;
	CArchive& operator <<(CArchive &ar);
	CArchive& operator >>(CArchive &ar);

	//设置初始方向和最终目标的方向，这是为最终定位服务的
	void SetPrimaryAndTargetDir(const AcGeVector3d& vPrimary ,
								const AcGeVector3d& vTarget);
	void SetProject( const AcGeVector3d& vProjectionDir, //投影方向
					 const AcGePlane&    plProjectPlane, //投影的平面
					 const double         dScale        , //比例
					 const AcGeVector3d& vPrimaryDir   , //转换前的初始方向
					 const AcGeVector3d& vTargetDir    , //转换后的确定方向	
					 const AcGePlane&    plTargetPlane = AcGePlane::kXYPlane );//转换的平面
private:
	void InitMatrix();

private:
	AcGeVector3d m_vPalneNormal      ;//投影面的法向 
	AcGeVector3d m_vProjectionDir    ;//投影方向
	AcGePlane    m_plProjPlane       ;//投影面
	double       m_dScale            ;//比例
	double       m_dAddScale         ;//额外比例
	AcGeVector3d m_vPrimaryDir       ;//转换前的初始方向
	AcGeVector3d m_vTargetDir        ;//转换后的确定方向	
	AcGePlane    m_plTargerPlane     ;//转换后的目标平面 

	AcGeMatrix3d m_mtProjMatrix      ;//投影变换矩阵		
	AcGeMatrix3d m_mtToTargetPlane   ;//由投影平面转换到目标平面的矩阵 
	AcGeMatrix3d m_mtTransform       ;//由投影平面转换到目标平面的矩阵 
};


#endif // !defined(AFX_PROJECTIONINFO_H__B5887CCE_0887_46A9_B146_3A3C6F4DD205__INCLUDED_)
