# Microsoft Developer Studio Project File - Name="Persistent" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=Persistent - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Persistent.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Persistent.mak" CFG="Persistent - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Persistent - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Persistent - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""$/AutoPFA1.1/Persistent/Persistent", SBLBAAAA"
# PROP Scc_LocalPath "."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Persistent - Win32 Release"

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
# ADD LINK32 APQuantity10.lib /nologo /subsystem:windows /dll /machine:I386

!ELSEIF  "$(CFG)" == "Persistent - Win32 Debug"

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
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /ZI /Od /I "..\inc" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_AFXEXT" /FR /Yu"stdafx.h" /FD /GZ /c
# SUBTRACT CPP /WX
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 APQuantity10d.lib /nologo /subsystem:windows /dll /debug /machine:I386 /out:"D:\pfalib\Libd\Persistentd.dll" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Persistent - Win32 Release"
# Name "Persistent - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\Src\AreaChangePerisist.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\AssignFlowPerisist.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\AssignPressPerisist.cpp
# End Source File
# Begin Source File

SOURCE=..\src\BendPerisist.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\BranchPerisist.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\BreakerPerisist.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\CheckPerisist.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\ControlPerisist.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\DeadEndPerisist.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\GasAccumPerisist.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\GeneralPerisist.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\JunPerisistFactory.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\LiquidAccumPerisist.cpp
# End Source File
# Begin Source File

SOURCE=..\src\onfigItemPerisist.cpp
# End Source File
# Begin Source File

SOURCE=..\src\onfigPerisist.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\OutputRefPersist.cpp
# End Source File
# Begin Source File

SOURCE=.\Persistent.rc
# End Source File
# Begin Source File

SOURCE=..\src\PersistentHeader.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\PumpPerisist.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\ReliefPerisist.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\ReservoirPerisist.cpp
# End Source File
# Begin Source File

SOURCE=..\src\SectionPipePersistent.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\SprayPerisist.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=..\src\SteadyPersistent.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\SurgePerisist.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\TeeWyePerisist.cpp
# End Source File
# Begin Source File

SOURCE=..\src\TransDataPersistent.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\ValvePerisist.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\inc\AreaChangePerisist.h
# End Source File
# Begin Source File

SOURCE=..\inc\AssignFlowPerisist.h
# End Source File
# Begin Source File

SOURCE=..\inc\AssignPressPerisist.h
# End Source File
# Begin Source File

SOURCE=..\inc\BendPerisist.h
# End Source File
# Begin Source File

SOURCE=..\inc\BranchPerisist.h
# End Source File
# Begin Source File

SOURCE=..\inc\BreakerPerisist.h
# End Source File
# Begin Source File

SOURCE=..\inc\CheckPerisist.h
# End Source File
# Begin Source File

SOURCE=..\inc\ControlPerisist.h
# End Source File
# Begin Source File

SOURCE=..\inc\DeadEndPerisist.h
# End Source File
# Begin Source File

SOURCE=..\inc\GasAccumPerisist.h
# End Source File
# Begin Source File

SOURCE=..\inc\GeneralPerisist.h
# End Source File
# Begin Source File

SOURCE=..\inc\JunFaceFactory.h
# End Source File
# Begin Source File

SOURCE=..\inc\JunPerisistFactory.h
# End Source File
# Begin Source File

SOURCE=..\inc\LiquidAccumPerisist.h
# End Source File
# Begin Source File

SOURCE=..\inc\onfigItemPerisist.h
# End Source File
# Begin Source File

SOURCE=..\inc\onfigPerisist.h
# End Source File
# Begin Source File

SOURCE=..\Inc\OutputRefPersist.h
# End Source File
# Begin Source File

SOURCE=..\inc\PersistentHeader.h
# End Source File
# Begin Source File

SOURCE=..\inc\PipeIDList.h
# End Source File
# Begin Source File

SOURCE=..\inc\PumpPerisist.h
# End Source File
# Begin Source File

SOURCE=..\inc\ReliefPerisist.h
# End Source File
# Begin Source File

SOURCE=..\inc\ReservoirPerisist.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=..\inc\SectionPipePersistent.h
# End Source File
# Begin Source File

SOURCE=..\inc\SprayPerisist.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=..\inc\SteadyPersistent.h
# End Source File
# Begin Source File

SOURCE=..\inc\SurgePerisist.h
# End Source File
# Begin Source File

SOURCE=..\inc\TeeWyePerisist.h
# End Source File
# Begin Source File

SOURCE=..\inc\TransDataPersistent.h
# End Source File
# Begin Source File

SOURCE=..\inc\TwoDTablePersistent.h
# End Source File
# Begin Source File

SOURCE=..\inc\ValvePerisist.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\Persistent.rc2
# End Source File
# End Group
# Begin Group "Inc"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\inc\JunManager.h
# End Source File
# Begin Source File

SOURCE=..\inc\Junperisist.h
# End Source File
# Begin Source File

SOURCE=..\inc\NetModelPersist.h
# End Source File
# Begin Source File

SOURCE=..\inc\PersistenModel.h
# End Source File
# Begin Source File

SOURCE=..\inc\PipePerisist.h
# End Source File
# Begin Source File

SOURCE=..\inc\PipesManager.h
# End Source File
# Begin Source File

SOURCE=..\inc\ScenarioPersistMgr.h
# End Source File
# Begin Source File

SOURCE=..\inc\SysProperty.h
# End Source File
# Begin Source File

SOURCE=..\inc\TransControlPerisistent.h
# End Source File
# End Group
# Begin Group "Src"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\Src\JunManager.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\Junperisist.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\NetModelPersist.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\PersistenModel.cpp
# End Source File
# Begin Source File

SOURCE=.\Persistent.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\PipePerisist.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\PipesManager.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\ScenarioPersistMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\SysProperty.cpp
# End Source File
# Begin Source File

SOURCE=..\src\TransControlPerisistent.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
