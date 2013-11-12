# Microsoft Developer Studio Project File - Name="CalcInterface" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=CalcInterface - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "CalcInterface.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "CalcInterface.mak" CFG="CalcInterface - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "CalcInterface - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "CalcInterface - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""$/AutoPFA1.1/CALCINTERFACE/CalcInterface", YGCCAAAA"
# PROP Scc_LocalPath "."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "CalcInterface - Win32 Release"

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
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_AFXEXT" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 Persistent.lib CalcDriver.lib APQuantity10.lib /nologo /subsystem:windows /dll /machine:I386

!ELSEIF  "$(CFG)" == "CalcInterface - Win32 Debug"

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
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_AFXEXT" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 Persistentd.lib CalcDriverd.lib /nologo /subsystem:windows /dll /debug /machine:I386 /out:"D:\pfalib\Libd\CalcInterfaced.dll" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "CalcInterface - Win32 Release"
# Name "CalcInterface - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\CalcInterface.cpp
# End Source File
# Begin Source File

SOURCE=.\CalcInterface.rc
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
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

SOURCE=.\res\CalcInterface.rc2
# End Source File
# End Group
# Begin Group "inc"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\inc\CalcAreaChangeFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcAssignFlowFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcAssignPressFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcBendFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcBranchFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcBreakerFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcCheckFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcControlFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcCurveFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcDeadEndFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcFileFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcFuildFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcGasAccumFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcGeneralFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcJunFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcJunFaceFactory.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcJunMgrFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcLiquidAccumFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcOrificeFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcPeriodicFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcPipeFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcPipeMgrFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcPumpConfigFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcPumpFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcReliefFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcReserviorFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcShortPipeFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcSprayFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcSteadyFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcSurgeFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcTeeWyeFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcTransDataFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcTransFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcTrigerFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\CalcValveFace.h
# End Source File
# End Group
# Begin Group "src"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\src\CalcAreaChangeFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcAssignFlowFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcAssignPressFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcBendFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcBranchFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcBreakerFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcCheckFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcControlFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcCurveFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcDeadEndFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcFileFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcFuildFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcGasAccumFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcGeneralFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcJunFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcJunFaceFactory.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcJunMgrFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcLiquidAccumFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcOrificeFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcPeriodicFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcPipeFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcPipeMgrFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcPumpConfigFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcPumpFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcReliefFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcReserviorFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcShortPipeFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcSprayFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcSteadyFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcSurgeFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcTeeWyeFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcTransDataFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcTransFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcTrigerFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\CalcValveFace.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
