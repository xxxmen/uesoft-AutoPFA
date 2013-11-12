# Microsoft Developer Studio Project File - Name="APQuantity" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=APQuantity - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "APQuantity.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "APQuantity.mak" CFG="APQuantity - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "APQuantity - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "APQuantity - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""$/AutoPDMS2.0/FrameWork/APQuantity", AKPAAAAA"
# PROP Scc_LocalPath ".."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "APQuantity - Win32 Release"

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
# ADD CPP /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "QUANTITY_EXPORT" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_AFXEXT" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 /nologo /subsystem:windows /dll /machine:I386 /out:"D:\pfalib\Lib/APQuantity10.dll"

!ELSEIF  "$(CFG)" == "APQuantity - Win32 Debug"

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
# ADD CPP /nologo /MD /W3 /Gm /GX /ZI /Od /D "QUANTITY_EXPORT" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_AFXEXT" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 cppunit_dll.lib /nologo /subsystem:windows /dll /debug /machine:I386 /out:"D:\pfalib\Libd/APQuantity10d.dll" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "APQuantity - Win32 Release"
# Name "APQuantity - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\APQuantity.cpp
# End Source File
# Begin Source File

SOURCE=.\APQuantity.rc
# End Source File
# Begin Source File

SOURCE=..\Src\QuantityManager.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\QuantityPersist.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\QuantitySystem.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=..\Src\UnitPFA.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\Inc\QuantityManager.h
# End Source File
# Begin Source File

SOURCE=..\Inc\QuantityPersist.h
# End Source File
# Begin Source File

SOURCE=..\Inc\QuantitySystem.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=..\Inc\UnitPFA.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\APQuantity.rc2
# End Source File
# End Group
# Begin Group "inc"

# PROP Default_Filter ".h"
# Begin Source File

SOURCE=..\Inc\angletrans.h
# End Source File
# Begin Source File

SOURCE=..\Inc\APQuantityresource.h
# End Source File
# Begin Source File

SOURCE=..\Inc\areatrans.h
# End Source File
# Begin Source File

SOURCE=..\Inc\DefaultUnitSetting.h
# End Source File
# Begin Source File

SOURCE=..\Inc\densitytrans.h
# End Source File
# Begin Source File

SOURCE=..\Inc\dimensiontype.h
# End Source File
# Begin Source File

SOURCE=..\Inc\ExpansionCoefTrans.h
# End Source File
# Begin Source File

SOURCE=..\Inc\forcetrans.h
# End Source File
# Begin Source File

SOURCE=..\Inc\lengthtrans.h
# End Source File
# Begin Source File

SOURCE=..\Inc\masstrans.h
# End Source File
# Begin Source File

SOURCE=..\Inc\MomentTrans.h
# End Source File
# Begin Source File

SOURCE=..\Inc\PFAQheader.h
# End Source File
# Begin Source File

SOURCE=..\Inc\powertrans.h
# End Source File
# Begin Source File

SOURCE=..\Inc\pressuretrans.h
# End Source File
# Begin Source File

SOURCE=..\Inc\quantity.h
# End Source File
# Begin Source File

SOURCE=..\Inc\Quantity_share.h
# End Source File
# Begin Source File

SOURCE=..\Inc\QuantityPFA.h
# End Source File
# Begin Source File

SOURCE=..\Inc\result.h
# End Source File
# Begin Source File

SOURCE=..\Inc\RigidityTrans.h
# End Source File
# Begin Source File

SOURCE=..\Inc\RSFTrans.h
# End Source File
# Begin Source File

SOURCE=..\Inc\speedtrans.h
# End Source File
# Begin Source File

SOURCE=..\Inc\temperaturetrans.h
# End Source File
# Begin Source File

SOURCE=..\Inc\timetrans.h
# End Source File
# Begin Source File

SOURCE=..\Inc\unit.h
# End Source File
# Begin Source File

SOURCE=..\Inc\unithead.h
# End Source File
# Begin Source File

SOURCE=..\Inc\UnitString.h
# End Source File
# Begin Source File

SOURCE=..\Inc\volumntrans.h
# End Source File
# Begin Source File

SOURCE=..\Inc\worktrans.h
# End Source File
# End Group
# Begin Group "src"

# PROP Default_Filter ".cpp"
# Begin Source File

SOURCE=..\Src\angletrans.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\areatrans.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\DefaultUnitSetting.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\densitytrans.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\ExpansionCoefTrans.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\forcetrans.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\lengthtrans.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\masstrans.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\MomentTrans.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\powertrans.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\pressuretrans.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\QuantityPFA.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\RigidityTrans.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\RSFTrans.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\speedtrans.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\temperaturetrans.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\timetrans.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\volumntrans.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\worktrans.cpp
# End Source File
# End Group
# Begin Group "Test"

# PROP Default_Filter ""
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
