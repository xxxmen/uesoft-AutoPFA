# Microsoft Developer Studio Project File - Name="PCFInterface" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=PCFInterface - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "PCFInterface.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "PCFInterface.mak" CFG="PCFInterface - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "PCFInterface - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "PCFInterface - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""$/AutoPFA1.1/PCFINTERFACE/PCFInterface", XJCCAAAA"
# PROP Scc_LocalPath "."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "PCFInterface - Win32 Release"

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
# ADD LINK32 Persistent.lib PCFDriver.lib acge15.lib /nologo /subsystem:windows /dll /machine:I386

!ELSEIF  "$(CFG)" == "PCFInterface - Win32 Debug"

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
# ADD LINK32 Persistentd.lib PCFDriverd.lib acge15.lib /nologo /subsystem:windows /dll /debug /machine:I386 /out:"D:\pfalib\Libd\PCFInterfaced.dll" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "PCFInterface - Win32 Release"
# Name "PCFInterface - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\src\PCFAssignFlowFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFAssignPressFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFBendFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFBranchFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFCapFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFGasAccumFace.cpp
# End Source File
# Begin Source File

SOURCE=.\PCFInterface.cpp
# End Source File
# Begin Source File

SOURCE=.\PCFInterface.rc
# End Source File
# Begin Source File

SOURCE=..\src\PCFJunFaceFactory.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFLiquidAccumFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFPumpDataFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFReduceFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFReserviorFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFSprayFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFSteadyFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFSurgeFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFSysPropety.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFTeeFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFValveFace.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\inc\PCFAssignFlowFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFAssignPressFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFBendFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFBranchFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFCapFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFGasAccumFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFJunFaceFactory.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFLiquidAccumFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFPumpDataFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFReduceFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFReserviorFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFSprayFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFSteadyFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFSurgeFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFSysPropety.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFTeeFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFValveFace.h
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

SOURCE=.\res\PCFInterface.rc2
# End Source File
# End Group
# Begin Group "inc"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\inc\PCFFileFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFJunFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFJunMgrFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFPipeFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\PCFPipeMgrFace.h
# End Source File
# End Group
# Begin Group "src"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\src\PCFFileFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFJunFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFJunMgrFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFPipeFace.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PCFPipeMgrFace.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
