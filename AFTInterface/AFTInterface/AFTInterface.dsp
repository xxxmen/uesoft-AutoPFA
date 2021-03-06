# Microsoft Developer Studio Project File - Name="AFTInterface" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=AFTInterface - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "AFTInterface.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "AFTInterface.mak" CFG="AFTInterface - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "AFTInterface - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "AFTInterface - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""$/AutoPFA1.1/AFTINTERFACE/AFTInterface", RHCCAAAA"
# PROP Scc_LocalPath "."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "AFTInterface - Win32 Release"

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
# ADD LINK32 AFTDriver.lib Persistent.lib /nologo /subsystem:windows /dll /machine:I386

!ELSEIF  "$(CFG)" == "AFTInterface - Win32 Debug"

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
# ADD LINK32 AFTDriverd.lib Persistentd.lib /nologo /subsystem:windows /dll /debug /machine:I386 /out:"D:\pfalib\libd\AFTInterfaced.dll" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "AFTInterface - Win32 Release"
# Name "AFTInterface - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AFTInterface.cpp
# End Source File
# Begin Source File

SOURCE=.\AFTInterface.rc
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

SOURCE=.\res\AFTInterface.rc2
# End Source File
# End Group
# Begin Group "inc"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\inc\AFTAreaChangeFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\AFTAssignFlowFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\AFTAssignPressFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\AFTBendFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\AFTBranchFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\AFTBreakerFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\AFTCheckFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\AFTConfigFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\AFTConfigItemFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\AFTControlFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\AFTDeadEndFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\AFTGasAccumFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\AFTGeneralFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\AFTJunFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\AFTJunMgr.h
# End Source File
# Begin Source File

SOURCE=..\inc\AFTLiquidAccumFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\AFTNetModel.h
# End Source File
# Begin Source File

SOURCE=..\inc\AFTOutputRef.h
# End Source File
# Begin Source File

SOURCE=..\inc\AFTPipeFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\AFTPipeMgr.h
# End Source File
# Begin Source File

SOURCE=..\inc\AFTPumpFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\AFTReliefFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\AFTReserviorFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\AFTScenarioMgr.h
# End Source File
# Begin Source File

SOURCE=..\inc\AFTSectionPipeFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\AFTSprayFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\AFTSteadyFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\AFTSurgeFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\AFTSysPropety.h
# End Source File
# Begin Source File

SOURCE=..\inc\AFTTeeWyeFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\AFTTransControlFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\AFTTransDataFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\AFTTwoDTableFace.h
# End Source File
# Begin Source File

SOURCE=..\inc\AFTValveFace.h
# End Source File
# End Group
# Begin Group "src"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\Src\aftareachangeface.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\aftassignflowface.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\aftassignpressface.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\AFTBendFace.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\aftbranchface.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\aftbreakerface.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\aftcheckface.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\AFTConfigFace.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\AFTConfigItemFace.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\aftcontrolface.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\aftdeadendface.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\aftgasaccumface.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\aftgeneralface.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\aftjunface.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\aftjunmgr.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\aftliquidaccumface.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\aftnetmodel.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\AFTOutputRef.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\aftpipeface.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\aftpipemgr.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\aftpumpface.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\aftreliefface.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\aftreserviorface.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\aftscenariomgr.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\AFTSectionPipeFace.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\aftsprayface.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\AFTSteadyFace.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\aftsurgeface.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\aftsyspropety.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\aftteewyeface.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\AFTTransControlFace.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\AFTTransDataFace.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\AFTTwoDTableFace.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\aftvalveface.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\junfacefactory.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
