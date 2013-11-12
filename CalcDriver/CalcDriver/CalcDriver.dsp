# Microsoft Developer Studio Project File - Name="CalcDriver" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=CalcDriver - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "CalcDriver.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "CalcDriver.mak" CFG="CalcDriver - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "CalcDriver - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "CalcDriver - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""$/AutoPFA1.1/CalcDriver", YLUBAAAA"
# PROP Scc_LocalPath "."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "CalcDriver - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "D:\pfalib\Lib"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
F90=df.exe
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /I "..\inc" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_AFXEXT" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 /nologo /subsystem:windows /dll /machine:I386

!ELSEIF  "$(CFG)" == "CalcDriver - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "D:\pfalib\Libd"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
F90=df.exe
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /ZI /Od /I "..\inc" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_AFXEXT" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /out:"D:\pfalib\Libd/CalcDriverd.dll" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "CalcDriver - Win32 Release"
# Name "CalcDriver - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\src\CaclFuild.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CaclSteady.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcAssignFlow.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcAssignPress.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcBend.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcBrach.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcBrecker.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcCheck.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcControl.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcCurve.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcDeadEnd.cpp
# End Source File
# Begin Source File

SOURCE=.\CalcDriver.cpp
# End Source File
# Begin Source File

SOURCE=.\CalcDriver.rc
# End Source File
# Begin Source File

SOURCE=..\src\CalcGasAccum.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcGeneral.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcJun.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcJunFactory.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcJunMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcLiquidAccum.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcOrifice.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcPipe.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcPipeMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcPump.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcRelief.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcReservior.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcShortPipe.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcSpray.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcSurge.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcTeeWye.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcTrans.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcTransData.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcTriger.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcValve.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\inc\CaclFuild.h
# End Source File
# Begin Source File

SOURCE=..\inc\CaclSteady.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcAssignFlow.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcAssignPress.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcBend.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcBrach.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcBrecker.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcCheck.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcControl.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcCurve.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcDeadEnd.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcGasAccum.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcGeneral.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcJun.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcJunFactory.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcJunMgr.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcLiquidAccum.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcOrifice.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcPipe.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcPipeMgr.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcPump.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcRelief.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcReservior.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcShortPipe.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcSpray.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcSurge.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcTable.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcTeeWye.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcTrans.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcTransData.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcTriger.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcValve.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\CalcDriver.rc2
# End Source File
# End Group
# Begin Group "inc"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\inc\CaclDriverMgr.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcAreaChange.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcPeriodic.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcPumpConfig.h
# End Source File
# End Group
# Begin Group "src"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\src\CaclDriverMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcAreaChange.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcPeriodic.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcPumpConfig.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
