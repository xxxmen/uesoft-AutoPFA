#ifndef UNITSYSHEADER_H
#define UNITSYSHEADER_H

#pragma warning(disable:4146 4995 4290 4786)
typedef enum TypeID{
	    None                    = -1,
		Area					= 1,
		Density					= 2,
		Diameter				= 3,
		HeadGradient			= 4,
		Inertia					= 5,
		Length					= 6,
		MassFlow				= 7,
		Mass					= 8,
		PercentFractional		= 9,
		Power					= 10,
		PressGradient			= 11,
		Pressure				= 12,
		Resistance				= 13,
		Temperature				= 14,
		Time					= 15,
		Torque					= 16,
		Velocity				= 17,
		Viscosity				= 18,
		Volume					= 19,
		VolumetricFlow			= 20,
		WeightperLength			= 21,
		PressPerMeter           = 22,
	}UnitTypeID;

typedef CString StdString;
#endif 