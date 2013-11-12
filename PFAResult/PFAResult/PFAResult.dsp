# Microsoft Developer Studio Project File - Name="PFAResult" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=PFAResult - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "PFAResult.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "PFAResult.mak" CFG="PFAResult - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "PFAResult - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "PFAResult - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""$/AutoPFA1.1/PFAResult/PFAResult", TBWBAAAA"
# PROP Scc_LocalPath "."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "PFAResult - Win32 Release"

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
# ADD LINK32 UnitSystem.lib AFTDriver.lib Persistent.lib /nologo /subsystem:windows /dll /machine:I386
# SUBTRACT LINK32 /profile

!ELSEIF  "$(CFG)" == "PFAResult - Win32 Debug"

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
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_AFXEXT" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 UnitSystemd.lib AFTDriverd.lib Persistentd.lib /nologo /subsystem:windows /dll /debug /machine:I386 /out:"D:\pfalib\Libd\PFAResultd.dll" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "PFAResult - Win32 Release"
# Name "PFAResult - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\src\ComponentStmOut.cpp
# End Source File
# Begin Source File

SOURCE=..\src\ComponentStmOutMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\src\ComponentTranOutMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\src\JunOut.cpp
# End Source File
# Begin Source File

SOURCE=..\src\JunOutShow.cpp
# End Source File
# Begin Source File

SOURCE=..\src\JunStmOut.cpp
# End Source File
# Begin Source File

SOURCE=..\src\JunStmOutMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\src\JunTranOut.cpp
# End Source File
# Begin Source File

SOURCE=..\src\JunTranOutMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\src\OutDataAttr.cpp
# End Source File
# Begin Source File

SOURCE=..\src\OutMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\src\OutPutSystem.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PFAOutModel.cpp
# End Source File
# Begin Source File

SOURCE=.\PFAResult.cpp
# End Source File
# Begin Source File

SOURCE=.\PFAResult.rc
# End Source File
# Begin Source File

SOURCE=..\src\PipeOutShow.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PipeStmOut.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PipeStmOutMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PipeTranOut.cpp
# End Source File
# Begin Source File

SOURCE=..\src\PipeTranOutMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\src\StationOut.cpp
# End Source File
# Begin Source File

SOURCE=..\src\StationStmOut.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=..\src\SteadyOutModel.cpp
# End Source File
# Begin Source File

SOURCE=..\src\StmOutMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\src\TranOutMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\src\TransOutModel.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\inc\ComponentStmOut.h
# End Source File
# Begin Source File

SOURCE=..\inc\ComponentStmOutMgr.h
# End Source File
# Begin Source File

SOURCE=..\inc\ComponentTranOutMgr.h
# End Source File
# Begin Source File

SOURCE=..\inc\JunOut.h
# End Source File
# Begin Source File

SOURCE=..\inc\JunOutShow.h
# End Source File
# Begin Source File

SOURCE=..\inc\JunStmOut.h
# End Source File
# Begin Source File

SOURCE=..\inc\JunStmOutMgr.h
# End Source File
# Begin Source File

SOURCE=..\inc\JunTranOut.h
# End Source File
# Begin Source File

SOURCE=..\inc\JunTranOutMgr.h
# End Source File
# Begin Source File

SOURCE=..\inc\OutDataAttr.h
# End Source File
# Begin Source File

SOURCE=..\inc\OutMgr.h
# End Source File
# Begin Source File

SOURCE=..\inc\OutPutSystem.h
# End Source File
# Begin Source File

SOURCE=..\inc\PFAOutModel.h
# End Source File
# Begin Source File

SOURCE=..\inc\PipeOutShow.h
# End Source File
# Begin Source File

SOURCE=..\inc\PipeStmOut.h
# End Source File
# Begin Source File

SOURCE=..\inc\PipeStmOutMgr.h
# End Source File
# Begin Source File

SOURCE=..\inc\PipeTranOut.h
# End Source File
# Begin Source File

SOURCE=..\inc\PipeTranOutMgr.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=..\inc\StationOut.h
# End Source File
# Begin Source File

SOURCE=..\inc\StationStmOut.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=..\inc\SteadyOutModel.h
# End Source File
# Begin Source File

SOURCE=..\inc\StmOutMgr.h
# End Source File
# Begin Source File

SOURCE=..\inc\TranOutMgr.h
# End Source File
# Begin Source File

SOURCE=..\inc\TransOutModel.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\PFAResult.rc2
# End Source File
# End Group
# Begin Group "inc"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\inc\ComponentTranOut.h
# End Source File
# End Group
# Begin Group "src"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\src\ComponentTranOut.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
