# Microsoft Developer Studio Project File - Name="AutoPFA" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=AutoPFA - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "AutoPFA.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "AutoPFA.mak" CFG="AutoPFA - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "AutoPFA - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "AutoPFA - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""$/AutoPFA1.1/AutoPFA", DSKBAAAA"
# PROP Scc_LocalPath "."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "AutoPFA - Win32 Release"

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
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 Persistent.lib USChart.lib APQuantity10.lib MOCCacl.lib CalcDriver.lib PFAResult.lib UnitSystem.lib DBTableDriver.lib InterfaceMgr.lib CalcInterface.lib HTMLHELP.LIB ImpulseDriver.lib GetPropertyofMaterial10.lib APGlobalShare10.lib DataSource.lib /nologo /subsystem:windows /machine:I386
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "AutoPFA - Win32 Debug"

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
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /ZI /Od /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /D "_DEBUG" /FR /Yu"stdafx.h" /FD /GZ /c
# SUBTRACT CPP /WX
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 Persistentd.lib APQuantity10d.lib USChartd.lib MOCCacld.lib CalcDriverd.lib PFAResultd.lib UnitSystemd.lib DBTableDriverd.lib InterfaceMgrd.lib AFTInterfaced.lib CalcInterfaced.lib ImpulseDriverd.lib HTMLHELP.LIB AFTDriverd.lib APGlobalShare10d.lib GetPropertyofMaterial10d.lib DataSource.lib /nologo /stack:0xffffffff /subsystem:windows /debug /machine:I386 /pdbtype:sept
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "AutoPFA - Win32 Release"
# Name "AutoPFA - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AbruptContractionStrategy.cpp
# End Source File
# Begin Source File

SOURCE=.\AbruptExpansionStrategy.cpp
# End Source File
# Begin Source File

SOURCE=.\AreaChange.cpp
# End Source File
# Begin Source File

SOURCE=.\AreaChangeLossCalc.cpp
# End Source File
# Begin Source File

SOURCE=.\AreaChangeModel.cpp
# End Source File
# Begin Source File

SOURCE=.\AssignedFlow.cpp
# End Source File
# Begin Source File

SOURCE=.\AssignedPressure.cpp
# End Source File
# Begin Source File

SOURCE=.\AssignFlowPage1.cpp
# End Source File
# Begin Source File

SOURCE=.\AssignPressPage1.cpp
# End Source File
# Begin Source File

SOURCE=.\AutoPFA.cpp
# End Source File
# Begin Source File

SOURCE=.\AutoPFA.rc
# End Source File
# Begin Source File

SOURCE=.\AutoPFADoc.cpp
# End Source File
# Begin Source File

SOURCE=.\AutoPFAView.cpp
# End Source File
# Begin Source File

SOURCE=.\BaseDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Bend.cpp
# End Source File
# Begin Source File

SOURCE=.\Branch.cpp
# End Source File
# Begin Source File

SOURCE=.\BranchPage1.cpp
# End Source File
# Begin Source File

SOURCE=.\CalcManager.cpp
# End Source File
# Begin Source File

SOURCE=.\checklistbox.cpp
# End Source File
# Begin Source File

SOURCE=.\CheckValve.cpp
# End Source File
# Begin Source File

SOURCE=.\ChildFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\CircularTunnel.cpp
# End Source File
# Begin Source File

SOURCE=.\Component.cpp
# End Source File
# Begin Source File

SOURCE=.\ComponentFactory.cpp
# End Source File
# Begin Source File

SOURCE=.\ComponentManager.cpp
# End Source File
# Begin Source File

SOURCE=.\ComponentStatus.cpp
# End Source File
# Begin Source File

SOURCE=.\Condition.cpp
# End Source File
# Begin Source File

SOURCE=.\Configuration.cpp
# End Source File
# Begin Source File

SOURCE=.\ConicalContraction45Strategy.cpp
# End Source File
# Begin Source File

SOURCE=.\ConicalContraction90Strategy.cpp
# End Source File
# Begin Source File

SOURCE=.\Conicalexpansion90Strategy.cpp
# End Source File
# Begin Source File

SOURCE=.\ConicalExpansionStrategy.cpp
# End Source File
# Begin Source File

SOURCE=.\ControlValve.cpp
# End Source File
# Begin Source File

SOURCE=.\ControlWrapper.cpp
# End Source File
# Begin Source File

SOURCE=.\CurveWrapper.cpp
# End Source File
# Begin Source File

SOURCE=.\DeadEnd.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgAreaChange.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgAssignedFlow.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgAssigPress.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgBasisArea.cpp
# End Source File
# Begin Source File

SOURCE=.\dlgbend.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgBranch.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgChangeUnit.cpp
# End Source File
# Begin Source File

SOURCE=.\dlgchart.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgCheckList.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgCheckValve.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgColorFontRef.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgCommon.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgControlValve.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgCopyData.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgCScenarioManager.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgDeadEnd.cpp
# End Source File
# Begin Source File

SOURCE=.\dlgdesignfactor.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgFind.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgGasAccum.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgGeneral.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgGeneralOutView.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgGeneralView.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgGenralCurve.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgGraphRef.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgInerailTrans.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgInitiation.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgInitPressGuess.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgInitPumpIneria.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgJun.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgJunOutView.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgJunView.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgLiquidAccum.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgNoInerialTrans.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgOneEle.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgOneEnd.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgOptCheckIn.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgOption.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgOptProGress.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgParamTable.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgParamUnit.cpp
# End Source File
# Begin Source File

SOURCE=.\dlgperiodic.cpp
# End Source File
# Begin Source File

SOURCE=.\dlgpipemodel.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgPipeOutView.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgPipeView.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgPump.cpp
# End Source File
# Begin Source File

SOURCE=.\dlgpumpconfig.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgPumpTranData.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgRawDataTable.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgReliefValve.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgReservoir.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgRestrictorModel.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgScenarioName.cpp
# End Source File
# Begin Source File

SOURCE=.\dlgsectionpipe.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgSelGraphData.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgShortPipe.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgSprayDischarge.cpp
# End Source File
# Begin Source File

SOURCE=.\dlgsteadyset.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgSurge.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgSysProperties.cpp
# End Source File
# Begin Source File

SOURCE=.\dlgtabview.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgTarnsData.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgTeeWye.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgThreeTransSpecial.cpp
# End Source File
# Begin Source File

SOURCE=.\dlgtolerance.cpp
# End Source File
# Begin Source File

SOURCE=.\dlgtransientset.cpp
# End Source File
# Begin Source File

SOURCE=.\dlgtransspecial.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgTwoEnd.cpp
# End Source File
# Begin Source File

SOURCE=.\dlgtwotransspecial.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgUndefinedObjects.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgVacuumBreaker.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgValve.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgWorkspaceRef.cpp
# End Source File
# Begin Source File

SOURCE=.\DrawJunTool.cpp
# End Source File
# Begin Source File

SOURCE=.\DrawPipeTool.cpp
# End Source File
# Begin Source File

SOURCE=.\FileDialogEx.cpp
# End Source File
# Begin Source File

SOURCE=.\FilePreviewDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\FilePreviewDlgArea.cpp
# End Source File
# Begin Source File

SOURCE=.\FlyWeight.cpp
# End Source File
# Begin Source File

SOURCE=.\FlyWeightFactory.cpp
# End Source File
# Begin Source File

SOURCE=.\font.cpp
# End Source File
# Begin Source File

SOURCE=.\Fuild.cpp
# End Source File
# Begin Source File

SOURCE=.\GasAccumulator.cpp
# End Source File
# Begin Source File

SOURCE=.\GasPropertyWrapper.cpp
# End Source File
# Begin Source File

SOURCE=.\General.cpp
# End Source File
# Begin Source File

SOURCE=.\GlobalUse.cpp
# End Source File
# Begin Source File

SOURCE=.\graphframe.cpp
# End Source File
# Begin Source File

SOURCE=.\Graphics.cpp
# End Source File
# Begin Source File

SOURCE=.\GraphView.cpp
# End Source File
# Begin Source File

SOURCE=.\GridCell.cpp
# End Source File
# Begin Source File

SOURCE=.\GridCellBase.cpp
# End Source File
# Begin Source File

SOURCE=.\GridCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\GridDropTarget.cpp
# End Source File
# Begin Source File

SOURCE=.\ILossCalcStrategy.cpp
# End Source File
# Begin Source File

SOURCE=.\InPlaceEdit.cpp
# End Source File
# Begin Source File

SOURCE=.\ISupportStrategy.cpp
# End Source File
# Begin Source File

SOURCE=.\Jun.cpp
# End Source File
# Begin Source File

SOURCE=.\JunGraphics.cpp
# End Source File
# Begin Source File

SOURCE=.\JunManipulator.cpp
# End Source File
# Begin Source File

SOURCE=.\LiquidAccumulator.cpp
# End Source File
# Begin Source File

SOURCE=.\LossCalcFactory.cpp
# End Source File
# Begin Source File

SOURCE=.\MacroManipulator.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\Manipulator.cpp
# End Source File
# Begin Source File

SOURCE=.\MDIClientWnd.cpp
# End Source File
# Begin Source File

SOURCE=.\MinimumSquareSum.cpp
# End Source File
# Begin Source File

SOURCE=.\ModelDataFrame.cpp
# End Source File
# Begin Source File

SOURCE=.\ModelDataView.cpp
# End Source File
# Begin Source File

SOURCE=.\NetModel.cpp
# End Source File
# Begin Source File

SOURCE=.\NoInerialModel.cpp
# End Source File
# Begin Source File

SOURCE=.\NoTranFourquadInerialModel.cpp
# End Source File
# Begin Source File

SOURCE=.\numedit.cpp
# End Source File
# Begin Source File

SOURCE=.\NumFlyWeight.cpp
# End Source File
# Begin Source File

SOURCE=.\OneWayWrapper.cpp
# End Source File
# Begin Source File

SOURCE=.\OptContralTwo.cpp
# End Source File
# Begin Source File

SOURCE=.\OptControl.cpp
# End Source File
# Begin Source File

SOURCE=.\OptimitationConst.cpp
# End Source File
# Begin Source File

SOURCE=.\OptimizationParameter.cpp
# End Source File
# Begin Source File

SOURCE=.\OptionTypeNumWrapper.cpp
# End Source File
# Begin Source File

SOURCE=.\OutPutDataFrame.cpp
# End Source File
# Begin Source File

SOURCE=.\OutPutDataView.cpp
# End Source File
# Begin Source File

SOURCE=.\PageAreaChangeData.cpp
# End Source File
# Begin Source File

SOURCE=.\PageAreaChangeOption.cpp
# End Source File
# Begin Source File

SOURCE=.\PageAssignedFlowData.cpp
# End Source File
# Begin Source File

SOURCE=.\PageAssignedFlowOption.cpp
# End Source File
# Begin Source File

SOURCE=.\PageAssignedFlowTrans.cpp
# End Source File
# Begin Source File

SOURCE=.\PageAssignedPressOption.cpp
# End Source File
# Begin Source File

SOURCE=.\pageassignedpresstrans.cpp
# End Source File
# Begin Source File

SOURCE=.\PageAssignedPressureData.cpp
# End Source File
# Begin Source File

SOURCE=.\PageBendData.cpp
# End Source File
# Begin Source File

SOURCE=.\pagebendmodel.cpp
# End Source File
# Begin Source File

SOURCE=.\PageBranchData.cpp
# End Source File
# Begin Source File

SOURCE=.\PageBranchOption.cpp
# End Source File
# Begin Source File

SOURCE=.\PageBranchTrans.cpp
# End Source File
# Begin Source File

SOURCE=.\PageBreakerData.cpp
# End Source File
# Begin Source File

SOURCE=.\PageBreakerModel.cpp
# End Source File
# Begin Source File

SOURCE=.\pagechart.cpp
# End Source File
# Begin Source File

SOURCE=.\PageCheck.cpp
# End Source File
# Begin Source File

SOURCE=.\PageCheckModel.cpp
# End Source File
# Begin Source File

SOURCE=.\PageCheckOption.cpp
# End Source File
# Begin Source File

SOURCE=.\PageCheckTrans.cpp
# End Source File
# Begin Source File

SOURCE=.\PageComponentTable.cpp
# End Source File
# Begin Source File

SOURCE=.\PageCondition.cpp
# End Source File
# Begin Source File

SOURCE=.\pageconfigdata.cpp
# End Source File
# Begin Source File

SOURCE=.\PageConfiguration.cpp
# End Source File
# Begin Source File

SOURCE=.\PageControlData.cpp
# End Source File
# Begin Source File

SOURCE=.\PageControlModel.cpp
# End Source File
# Begin Source File

SOURCE=.\PageControlTrans.cpp
# End Source File
# Begin Source File

SOURCE=.\PageCurveData.cpp
# End Source File
# Begin Source File

SOURCE=.\PageDataList.cpp
# End Source File
# Begin Source File

SOURCE=.\PageDataTable.cpp
# End Source File
# Begin Source File

SOURCE=.\PageDeadEndData.cpp
# End Source File
# Begin Source File

SOURCE=.\PageDetail.cpp
# End Source File
# Begin Source File

SOURCE=.\PageFailTrans.cpp
# End Source File
# Begin Source File

SOURCE=.\PageFitLoss.cpp
# End Source File
# Begin Source File

SOURCE=.\pagefourquadtable.cpp
# End Source File
# Begin Source File

SOURCE=.\PageFuild.cpp
# End Source File
# Begin Source File

SOURCE=.\PageGasAccumData.cpp
# End Source File
# Begin Source File

SOURCE=.\PageGasAccumModel.cpp
# End Source File
# Begin Source File

SOURCE=.\PageGeneral.cpp
# End Source File
# Begin Source File

SOURCE=.\PageGeneralInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\PageGeneralModel.cpp
# End Source File
# Begin Source File

SOURCE=.\PageGraph.cpp
# End Source File
# Begin Source File

SOURCE=.\PageInertialData.cpp
# End Source File
# Begin Source File

SOURCE=.\PageJunData.cpp
# End Source File
# Begin Source File

SOURCE=.\PageJunGraph.cpp
# End Source File
# Begin Source File

SOURCE=.\PageLiquidAccumData.cpp
# End Source File
# Begin Source File

SOURCE=.\PageLiquidAccumModel.cpp
# End Source File
# Begin Source File

SOURCE=.\PageOptCheckInPipeNet.cpp
# End Source File
# Begin Source File

SOURCE=.\PageOther.cpp
# End Source File
# Begin Source File

SOURCE=.\PageOutTable.cpp
# End Source File
# Begin Source File

SOURCE=.\PagePipeData.cpp
# End Source File
# Begin Source File

SOURCE=.\PagePipeGraph.cpp
# End Source File
# Begin Source File

SOURCE=.\PagePipeOption.cpp
# End Source File
# Begin Source File

SOURCE=.\PagePumpData.cpp
# End Source File
# Begin Source File

SOURCE=.\PagePumpModel.cpp
# End Source File
# Begin Source File

SOURCE=.\PagePumpTrans.cpp
# End Source File
# Begin Source File

SOURCE=.\PageReliefData.cpp
# End Source File
# Begin Source File

SOURCE=.\pagereliefmodel.cpp
# End Source File
# Begin Source File

SOURCE=.\PageReliefTrans.cpp
# End Source File
# Begin Source File

SOURCE=.\PageReservoirData.cpp
# End Source File
# Begin Source File

SOURCE=.\PageReservoirTrans.cpp
# End Source File
# Begin Source File

SOURCE=.\PageSprayData.cpp
# End Source File
# Begin Source File

SOURCE=.\PageSprayModel.cpp
# End Source File
# Begin Source File

SOURCE=.\PageSprayTrans.cpp
# End Source File
# Begin Source File

SOURCE=.\PageStatus.cpp
# End Source File
# Begin Source File

SOURCE=.\PageStmOutTable.cpp
# End Source File
# Begin Source File

SOURCE=.\PageSummary.cpp
# End Source File
# Begin Source File

SOURCE=.\PageSurgeData.cpp
# End Source File
# Begin Source File

SOURCE=.\PageSurgeModel.cpp
# End Source File
# Begin Source File

SOURCE=.\PageSurgeTrans.cpp
# End Source File
# Begin Source File

SOURCE=.\PageTable.cpp
# End Source File
# Begin Source File

SOURCE=.\PageTeeWyeData.cpp
# End Source File
# Begin Source File

SOURCE=.\PageTeeWyeModel.cpp
# End Source File
# Begin Source File

SOURCE=.\PageTolerance.cpp
# End Source File
# Begin Source File

SOURCE=.\PageTranOutTable.cpp
# End Source File
# Begin Source File

SOURCE=.\PageTrans.cpp
# End Source File
# Begin Source File

SOURCE=.\PageTransientData.cpp
# End Source File
# Begin Source File

SOURCE=.\pagetrantriger.cpp
# End Source File
# Begin Source File

SOURCE=.\PageUnit.cpp
# End Source File
# Begin Source File

SOURCE=.\PageValveData.cpp
# End Source File
# Begin Source File

SOURCE=.\PageValveModel.cpp
# End Source File
# Begin Source File

SOURCE=.\PageValveOption.cpp
# End Source File
# Begin Source File

SOURCE=.\PageValveTrans.cpp
# End Source File
# Begin Source File

SOURCE=.\PageVariableSpeed.cpp
# End Source File
# Begin Source File

SOURCE=.\PageViscosModel.cpp
# End Source File
# Begin Source File

SOURCE=.\palette.cpp
# End Source File
# Begin Source File

SOURCE=.\PFAOptimitationData.cpp
# End Source File
# Begin Source File

SOURCE=.\PFAOptimize.cpp
# End Source File
# Begin Source File

SOURCE=.\picture.cpp
# End Source File
# Begin Source File

SOURCE=.\Pipe.cpp
# End Source File
# Begin Source File

SOURCE=.\PipeDepthLoss.cpp
# End Source File
# Begin Source File

SOURCE=.\PipeDirPage.cpp
# End Source File
# Begin Source File

SOURCE=.\PipeGraphics.cpp
# End Source File
# Begin Source File

SOURCE=.\PipeIDFlyWeight.cpp
# End Source File
# Begin Source File

SOURCE=.\PipeManipulator.cpp
# End Source File
# Begin Source File

SOURCE=.\PtFlyWeight.cpp
# End Source File
# Begin Source File

SOURCE=.\Pump.cpp
# End Source File
# Begin Source File

SOURCE=.\PumpTranModel.cpp
# End Source File
# Begin Source File

SOURCE=.\PumpTransient.cpp
# End Source File
# Begin Source File

SOURCE=.\ReliefValve.cpp
# End Source File
# Begin Source File

SOURCE=.\ReserviorPage1.cpp
# End Source File
# Begin Source File

SOURCE=.\Reservoir.cpp
# End Source File
# Begin Source File

SOURCE=.\RestrictorWrapper.cpp
# End Source File
# Begin Source File

SOURCE=.\ScenariManage.cpp
# End Source File
# Begin Source File

SOURCE=.\Scenario.cpp
# End Source File
# Begin Source File

SOURCE=.\ScenarioObject.cpp
# End Source File
# Begin Source File

SOURCE=.\SectionSet.cpp
# End Source File
# Begin Source File

SOURCE=.\ShortPipeWrapper.cpp
# End Source File
# Begin Source File

SOURCE=.\SprayDischarge.cpp
# End Source File
# Begin Source File

SOURCE=.\StartUpSpeedModel.cpp
# End Source File
# Begin Source File

SOURCE=.\StateName.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\SteadySet.cpp
# End Source File
# Begin Source File

SOURCE=.\StratUpFourquadInerialModel.cpp
# End Source File
# Begin Source File

SOURCE=.\StratUpInerialModel.cpp
# End Source File
# Begin Source File

SOURCE=.\StrFlyWeight.cpp
# End Source File
# Begin Source File

SOURCE=.\SupportStrategyFactory.cpp
# End Source File
# Begin Source File

SOURCE=.\Surge.cpp
# End Source File
# Begin Source File

SOURCE=.\SysProperFactory.cpp
# End Source File
# Begin Source File

SOURCE=.\SysProperties.cpp
# End Source File
# Begin Source File

SOURCE=.\TabSheet.cpp
# End Source File
# Begin Source File

SOURCE=.\TeeWye.cpp
# End Source File
# Begin Source File

SOURCE=.\ThickAnchorThroughoutStrategy.cpp
# End Source File
# Begin Source File

SOURCE=.\ThickAnchorUpstreamStrategy.cpp
# End Source File
# Begin Source File

SOURCE=.\ThickExpandThroughoutStrategy.cpp
# End Source File
# Begin Source File

SOURCE=.\ThinAnchorThroughoutStrategy.cpp
# End Source File
# Begin Source File

SOURCE=.\ThinAnchorUpstreamStrategy.cpp
# End Source File
# Begin Source File

SOURCE=.\ThinExpandThroughoutStrategy.cpp
# End Source File
# Begin Source File

SOURCE=.\TitleTip.cpp
# End Source File
# Begin Source File

SOURCE=.\Transient.cpp
# End Source File
# Begin Source File

SOURCE=.\TransientSet.cpp
# End Source File
# Begin Source File

SOURCE=.\TreeScenario.cpp
# End Source File
# Begin Source File

SOURCE=.\TripFourquadInerialModel.cpp
# End Source File
# Begin Source File

SOURCE=.\TripInerialModel.cpp
# End Source File
# Begin Source File

SOURCE=.\UnitComboBox.cpp
# End Source File
# Begin Source File

SOURCE=.\VacuumBreaker.cpp
# End Source File
# Begin Source File

SOURCE=.\Valve.cpp
# End Source File
# Begin Source File

SOURCE=.\WavespeedCalc.cpp
# End Source File
# Begin Source File

SOURCE=.\WorkSpaceDataFrame.cpp
# End Source File
# Begin Source File

SOURCE=.\WorkSpaceRef.cpp
# End Source File
# Begin Source File

SOURCE=.\workspaceview.cpp
# End Source File
# Begin Source File

SOURCE=.\ZoomManipulator.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AbruptContractionStrategy.h
# End Source File
# Begin Source File

SOURCE=.\AbruptExpansionStrategy.h
# End Source File
# Begin Source File

SOURCE=.\AreaChange.h
# End Source File
# Begin Source File

SOURCE=.\AreaChangeLossCalc.h
# End Source File
# Begin Source File

SOURCE=.\AreaChangeModel.h
# End Source File
# Begin Source File

SOURCE=.\ArrayFlyWeight.h
# End Source File
# Begin Source File

SOURCE=.\AssignedFlow.h
# End Source File
# Begin Source File

SOURCE=.\AssignedPressure.h
# End Source File
# Begin Source File

SOURCE=.\AssignFlowPage1.h
# End Source File
# Begin Source File

SOURCE=.\AssignPressPage1.h
# End Source File
# Begin Source File

SOURCE=.\AutoPFA.h
# End Source File
# Begin Source File

SOURCE=.\AutoPFADoc.h
# End Source File
# Begin Source File

SOURCE=.\AutoPFAView.h
# End Source File
# Begin Source File

SOURCE=.\BaseDlg.h
# End Source File
# Begin Source File

SOURCE=.\Bend.h
# End Source File
# Begin Source File

SOURCE=.\Branch.h
# End Source File
# Begin Source File

SOURCE=.\BranchPage1.h
# End Source File
# Begin Source File

SOURCE=.\CalcManager.h
# End Source File
# Begin Source File

SOURCE=.\CellRange.h
# End Source File
# Begin Source File

SOURCE=.\checklistbox.h
# End Source File
# Begin Source File

SOURCE=.\CheckValve.h
# End Source File
# Begin Source File

SOURCE=.\ChildFrm.h
# End Source File
# Begin Source File

SOURCE=.\CircularTunnel.h
# End Source File
# Begin Source File

SOURCE=.\Component.h
# End Source File
# Begin Source File

SOURCE=.\ComponentFactory.h
# End Source File
# Begin Source File

SOURCE=.\ComponentManager.h
# End Source File
# Begin Source File

SOURCE=.\ComponentStatus.h
# End Source File
# Begin Source File

SOURCE=.\Condition.h
# End Source File
# Begin Source File

SOURCE=.\Configuration.h
# End Source File
# Begin Source File

SOURCE=.\ConicalContraction45Strategy.h
# End Source File
# Begin Source File

SOURCE=.\ConicalContraction90Strategy.h
# End Source File
# Begin Source File

SOURCE=.\Conicalexpansion90Strategy.h
# End Source File
# Begin Source File

SOURCE=.\ConicalExpansionStrategy.h
# End Source File
# Begin Source File

SOURCE=.\ControlValve.h
# End Source File
# Begin Source File

SOURCE=.\ControlWrapper.h
# End Source File
# Begin Source File

SOURCE=.\CurveWrapper.h
# End Source File
# Begin Source File

SOURCE=.\DeadEnd.h
# End Source File
# Begin Source File

SOURCE=.\DlgAreaChange.h
# End Source File
# Begin Source File

SOURCE=.\DlgAssignedFlow.h
# End Source File
# Begin Source File

SOURCE=.\DlgAssigPress.h
# End Source File
# Begin Source File

SOURCE=.\DlgBasisArea.h
# End Source File
# Begin Source File

SOURCE=.\dlgbend.h
# End Source File
# Begin Source File

SOURCE=.\DlgBranch.h
# End Source File
# Begin Source File

SOURCE=.\DlgChangeUnit.h
# End Source File
# Begin Source File

SOURCE=.\dlgchart.h
# End Source File
# Begin Source File

SOURCE=.\DlgCheckList.h
# End Source File
# Begin Source File

SOURCE=.\DlgCheckValve.h
# End Source File
# Begin Source File

SOURCE=.\DlgColorFontRef.h
# End Source File
# Begin Source File

SOURCE=.\DlgCommon.h
# End Source File
# Begin Source File

SOURCE=.\DlgControlValve.h
# End Source File
# Begin Source File

SOURCE=.\DlgCopyData.h
# End Source File
# Begin Source File

SOURCE=.\DlgCScenarioManager.h
# End Source File
# Begin Source File

SOURCE=.\DlgDeadEnd.h
# End Source File
# Begin Source File

SOURCE=.\dlgdesignfactor.h
# End Source File
# Begin Source File

SOURCE=.\DlgFind.h
# End Source File
# Begin Source File

SOURCE=.\DlgGasAccum.h
# End Source File
# Begin Source File

SOURCE=.\DlgGeneral.h
# End Source File
# Begin Source File

SOURCE=.\DlgGeneralOutView.h
# End Source File
# Begin Source File

SOURCE=.\DlgGeneralView.h
# End Source File
# Begin Source File

SOURCE=.\DlgGenralCurve.h
# End Source File
# Begin Source File

SOURCE=.\DlgGraphRef.h
# End Source File
# Begin Source File

SOURCE=.\DlgInerailTrans.h
# End Source File
# Begin Source File

SOURCE=.\DlgInitiation.h
# End Source File
# Begin Source File

SOURCE=.\dlginitpressguess.h
# End Source File
# Begin Source File

SOURCE=.\DlgInitPumpIneria.h
# End Source File
# Begin Source File

SOURCE=.\DlgJun.h
# End Source File
# Begin Source File

SOURCE=.\DlgJunOutView.h
# End Source File
# Begin Source File

SOURCE=.\DlgJunView.h
# End Source File
# Begin Source File

SOURCE=.\DlgLiquidAccum.h
# End Source File
# Begin Source File

SOURCE=.\DlgNoInerialTrans.h
# End Source File
# Begin Source File

SOURCE=.\DlgOneEle.h
# End Source File
# Begin Source File

SOURCE=.\DlgOneEnd.h
# End Source File
# Begin Source File

SOURCE=.\DlgOptCheckIn.h
# End Source File
# Begin Source File

SOURCE=.\dlgoption.h
# End Source File
# Begin Source File

SOURCE=.\DlgOptProGress.h
# End Source File
# Begin Source File

SOURCE=.\DlgParamTable.h
# End Source File
# Begin Source File

SOURCE=.\dlgparamunit.h
# End Source File
# Begin Source File

SOURCE=.\dlgperiodic.h
# End Source File
# Begin Source File

SOURCE=.\dlgpipemodel.h
# End Source File
# Begin Source File

SOURCE=.\DlgPipeOutView.h
# End Source File
# Begin Source File

SOURCE=.\DlgPipeView.h
# End Source File
# Begin Source File

SOURCE=.\DlgPump.h
# End Source File
# Begin Source File

SOURCE=.\dlgpumpconfig.h
# End Source File
# Begin Source File

SOURCE=.\DlgPumpTranData.h
# End Source File
# Begin Source File

SOURCE=.\DlgRawDataTable.h
# End Source File
# Begin Source File

SOURCE=.\DlgReliefValve.h
# End Source File
# Begin Source File

SOURCE=.\DlgReservoir.h
# End Source File
# Begin Source File

SOURCE=.\DlgRestrictorModel.h
# End Source File
# Begin Source File

SOURCE=.\DlgScenarioName.h
# End Source File
# Begin Source File

SOURCE=.\dlgsectionpipe.h
# End Source File
# Begin Source File

SOURCE=.\DlgSelGraphData.h
# End Source File
# Begin Source File

SOURCE=.\DlgShortPipe.h
# End Source File
# Begin Source File

SOURCE=.\DlgSprayDischarge.h
# End Source File
# Begin Source File

SOURCE=.\dlgsteadyset.h
# End Source File
# Begin Source File

SOURCE=.\DlgSurge.h
# End Source File
# Begin Source File

SOURCE=.\DlgSysProperties.h
# End Source File
# Begin Source File

SOURCE=.\dlgtabview.h
# End Source File
# Begin Source File

SOURCE=.\DlgTarnsData.h
# End Source File
# Begin Source File

SOURCE=.\DlgTeeWye.h
# End Source File
# Begin Source File

SOURCE=.\DlgThreeTransSpecial.h
# End Source File
# Begin Source File

SOURCE=.\dlgtolerance.h
# End Source File
# Begin Source File

SOURCE=.\dlgtransientset.h
# End Source File
# Begin Source File

SOURCE=.\dlgtransspecial.h
# End Source File
# Begin Source File

SOURCE=.\DlgTwoEnd.h
# End Source File
# Begin Source File

SOURCE=.\dlgtwotransspecial.h
# End Source File
# Begin Source File

SOURCE=.\DlgUndefinedObjects.h
# End Source File
# Begin Source File

SOURCE=.\DlgVacuumBreaker.h
# End Source File
# Begin Source File

SOURCE=.\DlgValve.h
# End Source File
# Begin Source File

SOURCE=.\DlgWorkspaceRef.h
# End Source File
# Begin Source File

SOURCE=.\DrawJunTool.h
# End Source File
# Begin Source File

SOURCE=.\DrawPipeTool.h
# End Source File
# Begin Source File

SOURCE=.\FileDialogEx.h
# End Source File
# Begin Source File

SOURCE=.\FilePreviewDlg.h
# End Source File
# Begin Source File

SOURCE=.\FilePreviewDlgArea.h
# End Source File
# Begin Source File

SOURCE=.\FlyWeight.h
# End Source File
# Begin Source File

SOURCE=.\FlyWeightFactory.h
# End Source File
# Begin Source File

SOURCE=.\font.h
# End Source File
# Begin Source File

SOURCE=.\Fuild.h
# End Source File
# Begin Source File

SOURCE=.\GasAccumulator.h
# End Source File
# Begin Source File

SOURCE=.\GasPropertyWrapper.h
# End Source File
# Begin Source File

SOURCE=.\General.h
# End Source File
# Begin Source File

SOURCE=.\GlobalUse.h
# End Source File
# Begin Source File

SOURCE=.\graphframe.h
# End Source File
# Begin Source File

SOURCE=.\Graphics.h
# End Source File
# Begin Source File

SOURCE=.\GraphView.h
# End Source File
# Begin Source File

SOURCE=.\GridCell.h
# End Source File
# Begin Source File

SOURCE=.\GridCellBase.h
# End Source File
# Begin Source File

SOURCE=.\GridCtrl.h
# End Source File
# Begin Source File

SOURCE=.\GridDropTarget.h
# End Source File
# Begin Source File

SOURCE=.\htmlhelp.h
# End Source File
# Begin Source File

SOURCE=.\ILossCalcStrategy.h
# End Source File
# Begin Source File

SOURCE=.\InPlaceEdit.h
# End Source File
# Begin Source File

SOURCE=.\ISupportStrategy.h
# End Source File
# Begin Source File

SOURCE=.\Jun.h
# End Source File
# Begin Source File

SOURCE=.\JunGraphics.h
# End Source File
# Begin Source File

SOURCE=.\JunManipulator.h
# End Source File
# Begin Source File

SOURCE=.\LiquidAccumulator.h
# End Source File
# Begin Source File

SOURCE=.\LossCalcFactory.h
# End Source File
# Begin Source File

SOURCE=.\MacroManipulator.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\Manipulator.h
# End Source File
# Begin Source File

SOURCE=.\MDIClientWnd.h
# End Source File
# Begin Source File

SOURCE=.\MemDC.h
# End Source File
# Begin Source File

SOURCE=.\MinimumSquareSum.h
# End Source File
# Begin Source File

SOURCE=.\ModelDataFrame.h
# End Source File
# Begin Source File

SOURCE=.\ModelDataView.h
# End Source File
# Begin Source File

SOURCE=.\NetModel.h
# End Source File
# Begin Source File

SOURCE=.\NoInerialModel.h
# End Source File
# Begin Source File

SOURCE=.\NoTranFourquadInerialModel.h
# End Source File
# Begin Source File

SOURCE=.\numedit.h
# End Source File
# Begin Source File

SOURCE=.\NumFlyWeight.h
# End Source File
# Begin Source File

SOURCE=.\OneWayWrapper.h
# End Source File
# Begin Source File

SOURCE=.\OptContralOne.h
# End Source File
# Begin Source File

SOURCE=.\OptContralTwo.h
# End Source File
# Begin Source File

SOURCE=.\OptControl.h
# End Source File
# Begin Source File

SOURCE=.\OptimitationConst.h
# End Source File
# Begin Source File

SOURCE=.\OptimizationParameter.h
# End Source File
# Begin Source File

SOURCE=.\OptionTypeNumWrapper.h
# End Source File
# Begin Source File

SOURCE=.\OutPutDataFrame.h
# End Source File
# Begin Source File

SOURCE=.\OutPutDataView.h
# End Source File
# Begin Source File

SOURCE=.\PageAreaChangeData.h
# End Source File
# Begin Source File

SOURCE=.\pageareachangeoption.h
# End Source File
# Begin Source File

SOURCE=.\PageAssignedFlowData.h
# End Source File
# Begin Source File

SOURCE=.\pageassignedflowoption.h
# End Source File
# Begin Source File

SOURCE=.\PageAssignedFlowTrans.h
# End Source File
# Begin Source File

SOURCE=.\PageAssignedPressOption.h
# End Source File
# Begin Source File

SOURCE=.\pageassignedpresstrans.h
# End Source File
# Begin Source File

SOURCE=.\PageAssignedPressureData.h
# End Source File
# Begin Source File

SOURCE=.\PageBendData.h
# End Source File
# Begin Source File

SOURCE=.\pagebendmodel.h
# End Source File
# Begin Source File

SOURCE=.\PageBranchData.h
# End Source File
# Begin Source File

SOURCE=.\PageBranchOption.h
# End Source File
# Begin Source File

SOURCE=.\PageBranchTrans.h
# End Source File
# Begin Source File

SOURCE=.\PageBreakerData.h
# End Source File
# Begin Source File

SOURCE=.\pagebreakermodel.h
# End Source File
# Begin Source File

SOURCE=.\PageBreakerOption.h
# End Source File
# Begin Source File

SOURCE=.\pagechart.h
# End Source File
# Begin Source File

SOURCE=.\PageCheck.h
# End Source File
# Begin Source File

SOURCE=.\pagecheckmodel.h
# End Source File
# Begin Source File

SOURCE=.\PageCheckOption.h
# End Source File
# Begin Source File

SOURCE=.\PageCheckTrans.h
# End Source File
# Begin Source File

SOURCE=.\PageComponentTable.h
# End Source File
# Begin Source File

SOURCE=.\PageCondition.h
# End Source File
# Begin Source File

SOURCE=.\pageconfigdata.h
# End Source File
# Begin Source File

SOURCE=.\PageConfiguration.h
# End Source File
# Begin Source File

SOURCE=.\PageControlData.h
# End Source File
# Begin Source File

SOURCE=.\PageControlModel.h
# End Source File
# Begin Source File

SOURCE=.\PageControlOption.h
# End Source File
# Begin Source File

SOURCE=.\PageControlTrans.h
# End Source File
# Begin Source File

SOURCE=.\PageCurveData.h
# End Source File
# Begin Source File

SOURCE=.\PageDataList.h
# End Source File
# Begin Source File

SOURCE=.\PageDataTable.h
# End Source File
# Begin Source File

SOURCE=.\PageDeadEndData.h
# End Source File
# Begin Source File

SOURCE=.\PageDeadEndOption.h
# End Source File
# Begin Source File

SOURCE=.\PageDetail.h
# End Source File
# Begin Source File

SOURCE=.\PageFailTrans.h
# End Source File
# Begin Source File

SOURCE=.\PageFitLoss.h
# End Source File
# Begin Source File

SOURCE=.\pagefourquadtable.h
# End Source File
# Begin Source File

SOURCE=.\PageFuild.h
# End Source File
# Begin Source File

SOURCE=.\PageGasAccumData.h
# End Source File
# Begin Source File

SOURCE=.\PageGasAccumModel.h
# End Source File
# Begin Source File

SOURCE=.\PageGasAccumOption.h
# End Source File
# Begin Source File

SOURCE=.\PageGeneral.h
# End Source File
# Begin Source File

SOURCE=.\PageGeneralInfo.h
# End Source File
# Begin Source File

SOURCE=.\pagegeneralmodel.h
# End Source File
# Begin Source File

SOURCE=.\PageGeneralOption.h
# End Source File
# Begin Source File

SOURCE=.\PageGraph.h
# End Source File
# Begin Source File

SOURCE=.\PageInertialData.h
# End Source File
# Begin Source File

SOURCE=.\PageJunData.h
# End Source File
# Begin Source File

SOURCE=.\PageJunGraph.h
# End Source File
# Begin Source File

SOURCE=.\PageLiquidAccumData.h
# End Source File
# Begin Source File

SOURCE=.\pageliquidaccummodel.h
# End Source File
# Begin Source File

SOURCE=.\PageLiquidAccumOption.cpp
# End Source File
# Begin Source File

SOURCE=.\PageLiquidAccumOption.h
# End Source File
# Begin Source File

SOURCE=.\PageOptCheckInPipeNet.h
# End Source File
# Begin Source File

SOURCE=.\PageOther.h
# End Source File
# Begin Source File

SOURCE=.\PageOutTable.h
# End Source File
# Begin Source File

SOURCE=.\PagePipeData.h
# End Source File
# Begin Source File

SOURCE=.\PagePipeGraph.h
# End Source File
# Begin Source File

SOURCE=.\PagePipeOption.h
# End Source File
# Begin Source File

SOURCE=.\PagePumpData.h
# End Source File
# Begin Source File

SOURCE=.\PagePumpModel.h
# End Source File
# Begin Source File

SOURCE=.\PagePumpOption.cpp
# End Source File
# Begin Source File

SOURCE=.\PagePumpOption.h
# End Source File
# Begin Source File

SOURCE=.\PagePumpTrans.h
# End Source File
# Begin Source File

SOURCE=.\PageReliefData.h
# End Source File
# Begin Source File

SOURCE=.\pagereliefmodel.h
# End Source File
# Begin Source File

SOURCE=.\PageReliefOption.h
# End Source File
# Begin Source File

SOURCE=.\PageReliefTrans.h
# End Source File
# Begin Source File

SOURCE=.\PageReservoirData.h
# End Source File
# Begin Source File

SOURCE=.\PageReservoirOption.h
# End Source File
# Begin Source File

SOURCE=.\PageReservoirTrans.h
# End Source File
# Begin Source File

SOURCE=.\PageSprayData.h
# End Source File
# Begin Source File

SOURCE=.\PageSprayModel.h
# End Source File
# Begin Source File

SOURCE=.\PageSprayOption.cpp
# End Source File
# Begin Source File

SOURCE=.\PageSprayOption.h
# End Source File
# Begin Source File

SOURCE=.\PageSprayTrans.h
# End Source File
# Begin Source File

SOURCE=.\PageStatus.h
# End Source File
# Begin Source File

SOURCE=.\PageStmOutTable.h
# End Source File
# Begin Source File

SOURCE=.\PageSummary.h
# End Source File
# Begin Source File

SOURCE=.\PageSurgeData.h
# End Source File
# Begin Source File

SOURCE=.\pagesurgemodel.h
# End Source File
# Begin Source File

SOURCE=.\PageSurgeOption.h
# End Source File
# Begin Source File

SOURCE=.\PageSurgeTrans.h
# End Source File
# Begin Source File

SOURCE=.\PageTable.h
# End Source File
# Begin Source File

SOURCE=.\PageTeeWyeData.h
# End Source File
# Begin Source File

SOURCE=.\pageteewyemodel.h
# End Source File
# Begin Source File

SOURCE=.\PageTeeWyeOption.h
# End Source File
# Begin Source File

SOURCE=.\PageTolerance.h
# End Source File
# Begin Source File

SOURCE=.\PageTranOutTable.h
# End Source File
# Begin Source File

SOURCE=.\PageTrans.h
# End Source File
# Begin Source File

SOURCE=.\PageTransientData.h
# End Source File
# Begin Source File

SOURCE=.\pagetrantriger.h
# End Source File
# Begin Source File

SOURCE=.\PageUnit.h
# End Source File
# Begin Source File

SOURCE=.\PageValveData.h
# End Source File
# Begin Source File

SOURCE=.\PageValveModel.h
# End Source File
# Begin Source File

SOURCE=.\PageValveOption.h
# End Source File
# Begin Source File

SOURCE=.\PageValveTrans.h
# End Source File
# Begin Source File

SOURCE=.\PageVariableSpeed.h
# End Source File
# Begin Source File

SOURCE=.\PageViscosModel.h
# End Source File
# Begin Source File

SOURCE=.\palette.h
# End Source File
# Begin Source File

SOURCE=.\PFAOptimitationData.h
# End Source File
# Begin Source File

SOURCE=.\PFAOptimize.h
# End Source File
# Begin Source File

SOURCE=.\picture.h
# End Source File
# Begin Source File

SOURCE=.\Pipe.h
# End Source File
# Begin Source File

SOURCE=.\PipeDepthLoss.h
# End Source File
# Begin Source File

SOURCE=.\PipeDirPage.h
# End Source File
# Begin Source File

SOURCE=.\PipeGraphics.h
# End Source File
# Begin Source File

SOURCE=.\PipeIDFlyWeight.h
# End Source File
# Begin Source File

SOURCE=.\PipeManipulator.h
# End Source File
# Begin Source File

SOURCE=..\Persistent\inc\PipesManager.h
# End Source File
# Begin Source File

SOURCE=.\PtFlyWeight.h
# End Source File
# Begin Source File

SOURCE=.\Pump.h
# End Source File
# Begin Source File

SOURCE=.\PumpTranModel.h
# End Source File
# Begin Source File

SOURCE=.\PumpTransient.h
# End Source File
# Begin Source File

SOURCE=.\ReliefValve.h
# End Source File
# Begin Source File

SOURCE=.\ReserviorPage1.h
# End Source File
# Begin Source File

SOURCE=.\Reservoir.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\RestrictorWrapper.h
# End Source File
# Begin Source File

SOURCE=.\ScenariManage.h
# End Source File
# Begin Source File

SOURCE=.\Scenario.h
# End Source File
# Begin Source File

SOURCE=.\ScenarioObject.h
# End Source File
# Begin Source File

SOURCE=.\SectionSet.h
# End Source File
# Begin Source File

SOURCE=.\ShortPipeWrapper.h
# End Source File
# Begin Source File

SOURCE=.\SprayDischarge.h
# End Source File
# Begin Source File

SOURCE=.\StartUpSpeedModel.h
# End Source File
# Begin Source File

SOURCE=.\StateName.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\SteadySet.h
# End Source File
# Begin Source File

SOURCE=.\StratUpFourquadInerialModel.h
# End Source File
# Begin Source File

SOURCE=.\StratUpInerialModel.h
# End Source File
# Begin Source File

SOURCE=.\StrFlyWeight.h
# End Source File
# Begin Source File

SOURCE=.\SupportStrategyFactory.h
# End Source File
# Begin Source File

SOURCE=.\Surge.h
# End Source File
# Begin Source File

SOURCE=.\SysProperFactory.h
# End Source File
# Begin Source File

SOURCE=.\SysProperties.h
# End Source File
# Begin Source File

SOURCE=.\TableFlyWeigh.h
# End Source File
# Begin Source File

SOURCE=.\TabSheet.h
# End Source File
# Begin Source File

SOURCE=.\TeeWye.h
# End Source File
# Begin Source File

SOURCE=.\ThickAnchorThroughoutStrategy.h
# End Source File
# Begin Source File

SOURCE=.\ThickAnchorUpstreamStrategy.h
# End Source File
# Begin Source File

SOURCE=.\ThickExpandThroughoutStrategy.h
# End Source File
# Begin Source File

SOURCE=.\ThinAnchorThroughoutStrategy.h
# End Source File
# Begin Source File

SOURCE=.\ThinAnchorUpstreamStrategy.h
# End Source File
# Begin Source File

SOURCE=.\ThinExpandThroughoutStrategy.h
# End Source File
# Begin Source File

SOURCE=.\TitleTip.h
# End Source File
# Begin Source File

SOURCE=.\TransDataTable.h
# End Source File
# Begin Source File

SOURCE=.\Transient.h
# End Source File
# Begin Source File

SOURCE=.\TransientSet.h
# End Source File
# Begin Source File

SOURCE=.\TreeScenario.h
# End Source File
# Begin Source File

SOURCE=.\TripFourquadInerialModel.h
# End Source File
# Begin Source File

SOURCE=.\TripInerialModel.h
# End Source File
# Begin Source File

SOURCE=.\UnitComboBox.h
# End Source File
# Begin Source File

SOURCE=.\VacuumBreaker.h
# End Source File
# Begin Source File

SOURCE=.\Valve.h
# End Source File
# Begin Source File

SOURCE=.\WavespeedCalc.h
# End Source File
# Begin Source File

SOURCE=.\WorkSpaceDataFrame.h
# End Source File
# Begin Source File

SOURCE=.\WorkSpaceRef.h
# End Source File
# Begin Source File

SOURCE=.\workspaceview.h
# End Source File
# Begin Source File

SOURCE=.\ZoomManipulator.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\angel1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\angel21.bmp
# End Source File
# Begin Source File

SOURCE=.\res\AutoPFA.ico
# End Source File
# Begin Source File

SOURCE=.\res\AutoPFA.rc2
# End Source File
# Begin Source File

SOURCE=.\res\AutoPFADoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap10.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap11.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap12.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap13.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap14.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap15.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap16.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap17.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap18.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap19.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap20.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap5.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap6.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap7.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap8.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap9.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmapel.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmapmi.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00001.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00002.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00003.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00004.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00005.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00006.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00007.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00008.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00009.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00010.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00011.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00012.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00013.bmp
# End Source File
# Begin Source File

SOURCE=.\res\btmapnext.bmp
# End Source File
# Begin Source File

SOURCE=.\res\btmappre.bmp
# End Source File
# Begin Source File

SOURCE=.\res\cur00003.cur
# End Source File
# Begin Source File

SOURCE=.\res\cursor10.cur
# End Source File
# Begin Source File

SOURCE=.\res\cursor11.cur
# End Source File
# Begin Source File

SOURCE=.\res\cursor12.cur
# End Source File
# Begin Source File

SOURCE=.\res\cursor13.cur
# End Source File
# Begin Source File

SOURCE=.\res\cursor14.cur
# End Source File
# Begin Source File

SOURCE=.\res\cursor15.cur
# End Source File
# Begin Source File

SOURCE=.\res\cursor16.cur
# End Source File
# Begin Source File

SOURCE=.\res\cursor17.cur
# End Source File
# Begin Source File

SOURCE=.\res\cursor18.cur
# End Source File
# Begin Source File

SOURCE=.\res\cursor19.cur
# End Source File
# Begin Source File

SOURCE=.\res\cursor2.cur
# End Source File
# Begin Source File

SOURCE=.\res\cursor20.cur
# End Source File
# Begin Source File

SOURCE=.\res\cursor3.cur
# End Source File
# Begin Source File

SOURCE=.\res\cursor4.cur
# End Source File
# Begin Source File

SOURCE=.\res\cursor5.cur
# End Source File
# Begin Source File

SOURCE=.\res\cursor6.cur
# End Source File
# Begin Source File

SOURCE=.\res\cursor7.cur
# End Source File
# Begin Source File

SOURCE=.\res\cursor8.cur
# End Source File
# Begin Source File

SOURCE=.\res\cursor9.cur
# End Source File
# Begin Source File

SOURCE=.\res\graphbar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\icon1.ico
# End Source File
# Begin Source File

SOURCE=.\mdi.ico
# End Source File
# Begin Source File

SOURCE=.\PageBreakerOption.cpp
# End Source File
# Begin Source File

SOURCE=.\PageControlOption.cpp
# End Source File
# Begin Source File

SOURCE=.\PageDeadEndOption.cpp
# End Source File
# Begin Source File

SOURCE=.\PageGasAccumOption.cpp
# End Source File
# Begin Source File

SOURCE=.\PageGeneralOption.cpp
# End Source File
# Begin Source File

SOURCE=.\PageReliefOption.cpp
# End Source File
# Begin Source File

SOURCE=.\PageReservoirOption.cpp
# End Source File
# Begin Source File

SOURCE=.\PageSurgeOption.cpp
# End Source File
# Begin Source File

SOURCE=.\PageTeeWyeOption.cpp
# End Source File
# Begin Source File

SOURCE=.\res\palette.bmp
# End Source File
# Begin Source File

SOURCE=".\res\Prairie Wind.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\resvior25.bmp
# End Source File
# Begin Source File

SOURCE=.\res\resvior50.bmp
# End Source File
# Begin Source File

SOURCE=.\res\resvior75.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\toolbar1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\uesoftci.bmp
# End Source File
# Begin Source File

SOURCE=".\res\管道单位长度公式.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\水头损失公式.bmp"
# End Source File
# End Group
# Begin Source File

SOURCE=..\AFTDriver\AFTDriver\AFTDriver.dsp
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
# Section AutoPFA : {7BF80981-BF32-101A-8BBB-00AA00300CAB}
# 	2:5:Class:CPicture
# 	2:10:HeaderFile:picture.h
# 	2:8:ImplFile:picture.cpp
# End Section
# Section AutoPFA : {22A21987-4FA2-11D1-AF19-444553540000}
# 	2:21:DefaultSinkHeaderFile:checklistbox.h
# 	2:16:DefaultSinkClass:CCheckListBox1
# End Section
# Section AutoPFA : {BEF6E003-A874-101A-8BBA-00AA00300CAB}
# 	2:5:Class:COleFont
# 	2:10:HeaderFile:font.h
# 	2:8:ImplFile:font.cpp
# End Section
# Section AutoPFA : {22A21985-4FA2-11D1-AF19-444553540000}
# 	2:5:Class:CCheckListBox1
# 	2:10:HeaderFile:checklistbox.h
# 	2:8:ImplFile:checklistbox.cpp
# End Section
