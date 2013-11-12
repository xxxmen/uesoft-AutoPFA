// CalcFriction.cpp: implementation of the CalcFriction class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcFriction.h"
#include "MOCFluid.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcFriction::CalcFriction()
{
	m_nFrictionModel=0;			
	m_dRe=0;
	m_dDia=0;
	m_dV=0;                  
	m_dQ=0;				
	m_dFriction=0;
	m_dArea = 0;
}

CalcFriction::~CalcFriction()
{

}

double CalcFriction::CalcF()
{
	double dF = 0.1;
	switch(m_nFrictionModel)
	{
	case 0:
		m_dFriction = m_dFriction / m_dDia;
		dF = Colebrook();
		break;
	case 1:
		dF = Colebrook();
		break;
	case 2:
		m_dFriction = 0;
		dF = Colebrook();
		break;
	case 3:
		dF = HazenWilliams();
		break;
	case 4:
		dF = m_dFriction;
		break;
	case 5:
		dF = MITEquation();
		break;
	case 6:
		dF = MillerTurbulent();
		break;
	case 7:
		dF = 0;
		break;
	default:
		ASSERT(FALSE);
		break;
	}
	return dF;
}
//先使用根的搜索方法得到一个近似根，再使用这个根作为牛顿迭代初始值求解
double CalcFriction::Colebrook()
{
	double dF = 1E-6;
	if(m_dRe < MOCFluid::ReTransLam())
	{
		if(m_dRe < 1E-3)
		{
			return 0;
		}
		dF = 64.0/m_dRe;
	}	
	else
	{
		double dFun =0;
		double dGrad = 0;
		double dStep = 1;
		double dSign = 0;
		GetColebrook(dF,m_dRe,dSign,dGrad);
		while(TRUE)
		{//查找根区间
			dF = dF + dStep;
			GetColebrook(dF,m_dRe,dFun,dGrad);
			if(dFun/dSign <0)
				break;
		}
		
		while(TRUE)
		{//二分法
			dStep = dStep / 2;
			if(dFun < 0)
			{
				dF = dF - dStep;
			}
			else
			{
				dF = dF + dStep;
			}	
			GetColebrook(dF,m_dRe,dFun,dGrad);
			if(dStep < 0.01||fabs(dFun)<1E-2)
			{
				break;	 
			}
		}
		int n=0;
		while (n<100)
		{//牛顿迭代
			if(fabs(dGrad)<1E-6)
				break;
			dF = dF -dFun/dGrad;
			GetColebrook(dF,m_dRe,dFun,dGrad);
			if(-1E-8<dFun&&dFun<1E-8)
				break;
			n++;
		}
	}
	return dF;
}
//牛顿下山法(只测试了几个例子)
double CalcFriction::Colebrook1()
{
	double dF = 0.01;
	if(m_dRe < MOCFluid::ReTransLam())
	{
		if(m_dRe < 1E-3)
		{
			return 0;
		}
		dF = 64.0/m_dRe;
	}	
	else
	{
		double dFun0 =0;
		double dF0 = 0;
		double dGrad0 = 0;
		double dFun =0;
		double dGrad = 0;
		double dt = 1;
		GetColebrook(dF,m_dRe,dFun,dGrad);
		while (TRUE)
		{
			if(fabs(dGrad)<1E-6)
				break;
			dt = 1;
			dF0 = dF;
			dFun0 = dFun;
			dGrad0 = dGrad;
			dF = dF -dt*dFun/dGrad;
			GetColebrook(dF,m_dRe,dFun,dGrad);
			while(fabs(dFun0)<fabs(dFun))
			{
				dt /= 2.0;
				dF = dF0 - dt*dFun0/dGrad0;
				GetColebrook(dF,m_dRe,dFun,dGrad);	
			}
			if(-1E-8<dFun&&dFun<1E-8)
				break;
		}
	}
	return dF;
}
void CalcFriction::GetColebrook(double df, double dRe, double &dFun, double &dGrad)
{
	double dE = 2.7182818284590452353602874713527;
	double dBuf1 = 1.0/sqrt(fabs(df));
	double dBuf2 = 2.0*log10(m_dFriction/3.76+2.51*dBuf1/dRe);
	dFun = dBuf1+dBuf2;
	dGrad = -0.5*dBuf1/df
		    -9.35*dBuf1*log10(dE)/df/dRe/(m_dFriction+9.35*dBuf1/dRe);
}

//海曾-威廉公式：为了算法通用根据aft提供的公式推导
//Converts the Hazen-Williams factor to a Darcy-Weisbach friction factor
double CalcFriction::HazenWilliams()
{
	double dF = 0.1;
	if(-0.00001<m_dV && m_dV < 0.00001)
		return dF;
	dF = 17.25 / (m_dFriction*pow(m_dV*m_dDia/0.0929,0.081));
	dF = pow(dF,1.0/0.54);
	return dF;
}

double CalcFriction::MillerTurbulent()
{
	double dn;
	double dm;
	double dk = 0;
	double dF = 0;
	dm = pow(m_dDia*39.37,2.5) * (1609.344/6894.76)/(5.9113*sqrt(MOCFluid::Density()/1000));     //0.00044541219
	dn = pow(m_dDia*39.37, 3) *(1609.344/6894.76) * (MOCFluid::Density()/1000)
		/pow(MOCFluid::Viscos()*MOCFluid::Density()*1000,2);
	dk = 77.47846293 * dn * m_dQ*22641.5094 / dm;                              //0.00030564846293
	if (fabs(dk)>1E-6|| dk < -exp( -1.0 ) + 0.0001 )
	{
		dF = 2*m_dDia*pow(m_dArea,2)*22641.5094/(MOCFluid::Density()*m_dQ*dm*LambertW(dk));
	}
	return dF;
}
double CalcFriction::MITEquation()
{
	double dkViscos = MOCFluid::Viscos()* 1000000;
    double dSSU = (dkViscos + sqrt(pow(dkViscos, 2) + 4 * 180 * 0.22))/(2 * 0.22);//这是美国的赛氏粘度
	//下面对MIT的公式取了绝对值，以防浮点益出，有更好的方法以后再深究。
    double dRe = fabs(( 5784873.953587 * m_dQ * dSSU ) / ( m_dDia * ( dSSU  * dSSU - 818.56 )));
	double df = 0;
	double dF = 0;
	df = fabs(1.964 * log(dRe) - 3.8215);
	df = dRe / df;
	df = 1.0 / (4 * pow(0.86859*log(df),2));
	//下面3233.24876303295为MIT Equation for crude oil中单位转化成国际单位的比例
	dF = 3233.24876303295 * df * PI * PI / ( 8 * 1000);
	return dF;
}
double CalcFriction::LambertW(const double dK )
{
	//来源：http://keithbriggs.info/software/LambertW.c
	int i; 
	const double eps=4.0e-16, em1=0.3678794411714423215955237701614608; 
	double p,e,t,w;
	double test = -em1;
	if ( dK<-em1 )//此时方程无解 
	{
		return 0; 
	}
	if ((-1E-6<dK&&dK<1E-6)) return 0.0;
	if (dK<-em1+1e-4) { // series near -em1 in sqrt(q)
		double q=dK+em1,r=sqrt(q),q2=q*q,q3=q2*q;
		return 
			-1.0
			+2.331643981597124203363536062168*r
			-1.812187885639363490240191647568*q
			+1.936631114492359755363277457668*r*q
			-2.353551201881614516821543561516*q2
			+3.066858901050631912893148922704*r*q2
			-4.175335600258177138854984177460*q3
			+5.858023729874774148815053846119*r*q3
			-8.401032217523977370984161688514*q3*q;  // error approx 1e-16
	}
	/* initial approx for iteration... */
	if (dK<1.0) { /* series near 0 */
		p=sqrt(2.0*(2.7182818284590452353602874713526625*dK+1.0));
		w=-1.0+p*(1.0+p*(-0.333333333333333333333+p*0.152777777777777777777777)); 
	} else 
		w=log(dK); /* asymptotic */
	if (dK>3.0) w-=log(w); /* useful? */
	for (i=0; i<10; i++) { /* Halley iteration */
		e=exp(w); 
		t=w*e-dK;
		p=w+1.0;
		t/=e*p-0.5*(p+1.0)*t/p; 
		w-=t;
		if (fabs(t)<eps*(1.0+fabs(w))) return w; /* rel-abs error */
	}
	/* should never get here */
	exit(1);	
}