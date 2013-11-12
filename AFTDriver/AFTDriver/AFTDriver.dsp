# Microsoft Developer Studio Project File - Name="AFTDriver" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=AFTDriver - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "AFTDriver.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "AFTDriver.mak" CFG="AFTDriver - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "AFTDriver - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "AFTDriver - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""$/AutoPFA1.1/AFTDriver/AFTDriver", ISKBAAAA"
# PROP Scc_LocalPath "."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "AFTDriver - Win32 Release"

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
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /I "..\inc" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_AFXEXT" /D "SHARE_AFTDRIVER_DATA" /Yu"stdafx.h" /FD /c
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

!ELSEIF  "$(CFG)" == "AFTDriver - Win32 Debug"

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
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /ZI /Od /I "..\inc" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_AFXEXT" /D "SHARE_AFTDRIVER_DATA" /FR /Yu"stdafx.h" /FD /GZ /c
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
# ADD LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /out:"D:\pfalib\Libd\AFTDriverd.dll" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "AFTDriver - Win32 Release"
# Name "AFTDriver - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AFTDriver.cpp
# End Source File
# Begin Source File

SOURCE=.\AFTDriver.rc
# End Source File
# Begin Source File

SOURCE=..\Src\AreaChangeData.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\AssignFlowData.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\AssignPressData.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\BendData.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\BrachData.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\BreckerData.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\DeadEndData.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\GasAccumData.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\GeneralData.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\JunDataFactory.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\LiquidAccumData.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\PumpConfig.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\PumpConfigData.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\PumpData.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\ReliefData.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\ReserviorData.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\SprayData.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=..\Src\SurgeData.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\TableBase.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\TeeWyeData.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\ValveData.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\Inc\AreaChangeData.h
# End Source File
# Begin Source File

SOURCE=..\Inc\AssignFlowData.h
# End Source File
# Begin Source File

SOURCE=..\Inc\AssignPressData.h
# End Source File
# Begin Source File

SOURCE=..\Inc\BendData.h
# End Source File
# Begin Source File

SOURCE=..\Inc\BrachData.h
# End Source File
# Begin Source File

SOURCE=..\Inc\BreckerData.h
# End Source File
# Begin Source File

SOURCE=..\Inc\DeadEndData.h
# End Source File
# Begin Source File

SOURCE=..\Inc\GasAccumData.h
# End Source File
# Begin Source File

SOURCE=..\Inc\GeneralData.h
# End Source File
# Begin Source File

SOURCE=..\Inc\JunDataFactory.h
# End Source File
# Begin Source File

SOURCE=..\Inc\LiquidAccumData.h
# End Source File
# Begin Source File

SOURCE=..\Inc\PumpConfig.h
# End Source File
# Begin Source File

SOURCE=..\Inc\PumpConfigData.h
# End Source File
# Begin Source File

SOURCE=..\Inc\PumpData.h
# End Source File
# Begin Source File

SOURCE=..\Inc\RawDataTable.h
# End Source File
# Begin Source File

SOURCE=..\Inc\ReliefData.h
# End Source File
# Begin Source File

SOURCE=..\Inc\ReserviorData.h
# End Source File
# Begin Source File

SOURCE=..\Inc\RowObjectFace.h
# End Source File
# Begin Source File

SOURCE=..\Inc\SprayData.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=..\Inc\SurgeData.h
# End Source File
# Begin Source File

SOURCE=..\Inc\TableBase.h
# End Source File
# Begin Source File

SOURCE=..\Inc\TableData.h
# End Source File
# Begin Source File

SOURCE=..\Inc\TeeWyeData.h
# End Source File
# Begin Source File

SOURCE=..\Inc\ValveData.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\AFTDriver.rc2
# End Source File
# End Group
# Begin Group "Inc"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\Inc\AFTDriverHeader.h
# End Source File
# Begin Source File

SOURCE=..\Inc\AFTDriverMgr.h
# End Source File
# Begin Source File

SOURCE=..\Inc\AFTDriverRes.h
# End Source File
# Begin Source File

SOURCE=..\Inc\Annotations.h
# End Source File
# Begin Source File

SOURCE=..\Inc\ArchiveInfo.h
# End Source File
# Begin Source File

SOURCE=..\Inc\ArchiveMsg.h
# End Source File
# Begin Source File

SOURCE=..\Inc\CheckValveData.h
# End Source File
# Begin Source File

SOURCE=..\Inc\ControlValveData.h
# End Source File
# Begin Source File

SOURCE=..\Inc\Factory.h
# End Source File
# Begin Source File

SOURCE=..\Inc\FluidData.h
# End Source File
# Begin Source File

SOURCE=..\Inc\GraphItem.h
# End Source File
# Begin Source File

SOURCE=..\Inc\GraphSet.h
# End Source File
# Begin Source File

SOURCE=..\Inc\Grourps.h
# End Source File
# Begin Source File

SOURCE=..\Inc\Iterator.h
# End Source File
# Begin Source File

SOURCE=..\Inc\JunArchiveData.h
# End Source File
# Begin Source File

SOURCE=..\Inc\Junction.h
# End Source File
# Begin Source File

SOURCE=..\Inc\JunctionsMgr.h
# End Source File
# Begin Source File

SOURCE=..\Inc\JunTransData.h
# End Source File
# Begin Source File

SOURCE=..\Inc\ListFlyWeightImp.h
# End Source File
# Begin Source File

SOURCE=..\Inc\ModelDataRef.h
# End Source File
# Begin Source File

SOURCE=..\Inc\NetModelData.h
# End Source File
# Begin Source File

SOURCE=..\Inc\OutPutRef.h
# End Source File
# Begin Source File

SOURCE=..\Inc\OutPutRefItem.h
# End Source File
# Begin Source File

SOURCE=..\Inc\ParamRef.h
# End Source File
# Begin Source File

SOURCE=..\Inc\PersistentObj.h
# End Source File
# Begin Source File

SOURCE=..\Inc\PipeArchiveData.h
# End Source File
# Begin Source File

SOURCE=..\Inc\PipeData.h
# End Source File
# Begin Source File

SOURCE=..\Inc\PipesMgr.h
# End Source File
# Begin Source File

SOURCE=..\Inc\PrintFontRef.h
# End Source File
# Begin Source File

SOURCE=..\Inc\RawDataRef.h
# End Source File
# Begin Source File

SOURCE=..\Inc\RawDataSet.h
# End Source File
# Begin Source File

SOURCE=..\Inc\Refenrence.h
# End Source File
# Begin Source File

SOURCE=..\Inc\Resourcedefine.h
# End Source File
# Begin Source File

SOURCE=..\Inc\RowObject.h
# End Source File
# Begin Source File

SOURCE=..\Inc\ScenarioDataMgr.h
# End Source File
# Begin Source File

SOURCE=..\Inc\ScenarioInfo.h
# End Source File
# Begin Source File

SOURCE=..\Inc\SectionData.h
# End Source File
# Begin Source File

SOURCE=..\Inc\SettingData.h
# End Source File
# Begin Source File

SOURCE=..\Inc\ShareAFTDriver.h
# End Source File
# Begin Source File

SOURCE=..\Inc\ToolBoxItem.h
# End Source File
# Begin Source File

SOURCE=..\Inc\ToolBoxRef.h
# End Source File
# Begin Source File

SOURCE=..\Inc\TranContorlData.h
# End Source File
# Begin Source File

SOURCE=..\Inc\UnitRef.h
# End Source File
# Begin Source File

SOURCE=..\Inc\VersionInfo.h
# End Source File
# Begin Source File

SOURCE=..\Inc\VisualRefData.h
# End Source File
# Begin Source File

SOURCE=..\Inc\WorkSpace.h
# End Source File
# End Group
# Begin Group "Src"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\Src\AFTDriverMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\Annotations.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\ArchiveInfo.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\ArchiveMsg.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\CheckValveData.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\ControlValveData.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\FluidData.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\GraphItem.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\GraphSet.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\Grourps.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\JunArchiveData.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\Junction.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\JunctionsMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\JunTransData.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\ModelDataRef.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\NetModelData.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\OutPutRef.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\OutPutRefItem.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\ParamRef.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\PersistentObj.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\PipeArchiveData.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\PipeData.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\PipesMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\PrintFontRef.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\RawDataRef.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\RawDataSet.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\Refenrence.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\Resourcedefine.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\RowObject.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\ScenarioDataMgr.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\ScenarioInfo.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\SectionData.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\SettingData.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\ToolBoxItem.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\ToolBoxRef.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\TranContorlData.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\UnitRef.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\VersionInfo.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\VisualRefData.cpp
# End Source File
# Begin Source File

SOURCE=..\Src\WorkSpace.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
