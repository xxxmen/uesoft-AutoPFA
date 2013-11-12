# Microsoft Developer Studio Project File - Name="PCFDriver" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=PCFDriver - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "PCFDriver.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "PCFDriver.mak" CFG="PCFDriver - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "PCFDriver - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "PCFDriver - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""$/AutoPFA1.1/PCFDriver/PCFDriver", NWBCAAAA"
# PROP Scc_LocalPath "."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "PCFDriver - Win32 Release"

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
# ADD LINK32 acge15.lib AFTDriver.lib /nologo /subsystem:windows /dll /machine:I386

!ELSEIF  "$(CFG)" == "PCFDriver - Win32 Debug"

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
# ADD LINK32 acge15.lib AFTDriverd.lib /nologo /stack:0xffffffff,0xffffff /subsystem:windows /dll /debug /machine:I386 /out:"D:\pfalib\Libd\PCFDriverd.dll" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "PCFDriver - Win32 Release"
# Name "PCFDriver - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\PCFDriver.cpp
# End Source File
# Begin Source File

SOURCE=.\PCFDriver.rc
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\PCFDriver.rc2
# End Source File
# End Group
# Begin Group "inc"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\inc\FCFComponentMgr.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFAssignFlow.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFAssignPress.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFBend.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFCap.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFCoupling.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFCross.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFDriverModel.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFElbow.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFFBlind.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFFilter.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFFlange.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFGasAccum.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFGasket.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFInstrument.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFJun.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFJunFactory.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFJunsMgr.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFLiquidAccum.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFLJSE.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFPipe.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFPipesMgr.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFPortPoint.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFPumpConfig.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFPumpConfigData.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFPumpData.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFReduce.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFReservior.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFSetOnTee.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFSpray.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFSupport.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFSurge.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFTee.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFTrap.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFValve.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFWeld.h
# End Source File
# Begin Source File

SOURCE=..\inc\PipeLineHead.h
# End Source File
# Begin Source File

SOURCE=..\inc\ProjectionInfo.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=..\inc\SetCompKeyPt.h
# End Source File
# Begin Source File

SOURCE=..\inc\UnitInfo.h
# End Source File
# End Group
# Begin Group "Src"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\src\FCFComponentMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFAssignFlow.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFAssignPress.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFBend.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFCap.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFCoupling.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFCross.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFDriverModel.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFElbow.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFFBlind.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFFilter.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFFlange.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFGasAccum.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFGasket.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFInstrument.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFJun.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFJunFactory.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFJunsMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFLiquidAccum.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFLJSE.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFPipe.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFPipesMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFPortPoint.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFPumpConfig.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFPumpConfigData.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFPumpData.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFReduce.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFReservior.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFSetOnTee.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFSpray.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFSupport.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFSurge.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFTee.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFTrap.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFValve.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFWeld.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PipeLineHead.cpp
# End Source File
# Begin Source File

SOURCE=..\src\ProjectionInfo.cpp
# End Source File
# Begin Source File

SOURCE=..\src\SetCompKeyPt.cpp
# End Source File
# Begin Source File

SOURCE=..\src\UnitInfo.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
