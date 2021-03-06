(*
 * The contents of this file are subject to the Mozilla Public License
 * Version 1.1 (the "License"); you may not use this file except in
 * compliance with the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS"
 * basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See the
 * License for the specific language governing rights and limitations
 * under the License.
 *
 * Copyright (C) 2011 John Hansen.
 * All Rights Reserved.
 *
 *)
library nxtspirit;

uses
{$IFDEF FPC}
  cmem,
{$ENDIF}
  FantomSpirit in 'bricktools\FantomSpirit.pas',
  brick_common in 'bricktools\brick_common.pas',
  fantomspiritlib in 'bricktools\fantomspiritlib.pas',
  uCommonUtils in 'uCommonUtils.pas';

{$IFNDEF FPC}
{$R *.RES}
{$ENDIF}

exports
  FantomSpiritCreate,
  FantomSpiritDestroy,
  FantomSpiritOpen,
  FantomSpiritClose,
  FantomSpiritPlayTone,
  FantomSpiritMotorsOn,
  FantomSpiritMotorsOff,
  FantomSpiritMotorsFloat,
  FantomSpiritSetFwd,
  FantomSpiritSetRwd,
  FantomSpiritSwitchDirection,
  FantomSpiritSetMotorPower,
  FantomSpiritSetSensorType,
  FantomSpiritSetSensorMode,
  FantomSpiritClearSensorValue,
  FantomSpiritPing,
  FantomSpiritPowerDownTime,
  FantomSpiritBatteryLevel,
  FantomSpiritBrickAlive,
  FantomSpiritShutdown,
  FantomSpiritSleep,
  FantomSpiritVersion,
  FantomSpiritStopAllTasks,
  FantomSpiritClearMemory,
  FantomSpiritGetOutputStatus,
  FantomSpiritGetInputValue,
  FantomSpiritGetTimerValue,
  FantomSpiritSendMessage,
  FantomSpiritDownloadFirmware,
  FantomSpiritClearTachoCounter,
  FantomSpiritMuteSound,
  FantomSpiritNXTStartProgram,
  FantomSpiritNXTStopProgram,
  FantomSpiritNXTPlaySoundFile,
  FantomSpiritDCGetOutputState,
  FantomSpiritDCSetOutputState,
  FantomSpiritDCGetInputValues,
  FantomSpiritSetNXTInputMode,
  FantomSpiritNXTResetInputScaledValue,
  FantomSpiritNXTResetOutputPosition,
  FantomSpiritNXTMessageWrite,
  FantomSpiritNXTKeepAlive,
  FantomSpiritNXTLSGetStatus,
  FantomSpiritNXTGetCurrentProgramName,
  FantomSpiritNXTGetButtonState,
  FantomSpiritNXTMessageRead,
  FantomSpiritNXTSetPropDebugging,
  FantomSpiritNXTGetPropDebugging,
  FantomSpiritNXTSetVMState,
  FantomSpiritNXTSetVMStateEx,
  FantomSpiritNXTGetVMState,
  FantomSpiritNXTOpenRead,
  FantomSpiritNXTOpenWrite,
  FantomSpiritNXTRead,
  FantomSpiritNXTWrite,
  FantomSpiritNXTCloseFile,
  FantomSpiritNXTDeleteFile,
  FantomSpiritNXTFindFirstFile,
  FantomSpiritNXTFindNextFile,
  FantomSpiritNXTFindClose,
  FantomSpiritNXTGetVersions,
  FantomSpiritNXTOpenWriteLinear,
  FantomSpiritNXTOpenReadLinear,
  FantomSpiritNXTOpenWriteData,
  FantomSpiritNXTOpenAppendData,
  FantomSpiritNXTCloseModuleHandle,
  FantomSpiritNXTBootCommand,
  FantomSpiritNXTSetBrickName,
  FantomSpiritNXTGetDeviceInfo,
  FantomSpiritNXTFreeMemory,
  FantomSpiritNXTDeleteUserFlash,
  FantomSpiritNXTBTFactoryReset,
  FantomSpiritNXTPollCommandLen,
  FantomSpiritNXTPollCommand,
  FantomSpiritNXTWriteIOMap,
  FantomSpiritNXTReadIOMap,
  FantomSpiritNXTFindFirstModule,
  FantomSpiritNXTFindNextModule,
  FantomSpiritNXTRenameFile,
  FantomSpiritNXTDownloadFile,
  FantomSpiritNXTUploadFile,
  FantomSpiritNXTInitializeResourceNames,
  FantomSpiritNXTUpdateResourceNames,
  FantomSpiritNXTDownloadStream,
  FantomSpiritNXTUploadFileToStream,
  FantomSpiritNXTListFiles,
  FantomSpiritNXTListModules,
  FantomSpiritNXTListBricks,
  FantomSpiritPoll,
  FantomSpiritGetVariableValue,
  FantomSpiritSendRawCommand,
  FantomSpiritPollMemory,
  FantomSpiritPollEEPROM,
  FantomSpiritIsOpen,
  FantomSpiritSetNXTLowSpeed,
  FantomSpiritGetNXTLowSpeed,
  FantomSpiritUseBluetooth,
  FantomSpiritBluetoothName,
  FantomSpiritGetSearchBluetooth,
  FantomSpiritSetSearchBluetooth,
  FantomSpiritGetBluetoothSearchTimeout,
  FantomSpiritSetBluetoothSearchTimeout,
  FantomSpiritGetBrickType,
  FantomSpiritSetBrickType,
  FantomSpiritGetPort,
  FantomSpiritSetPort,
  FantomSpiritGetPortName,
  FantomSpiritGetNicePortName,
  FantomSpiritGetFullPortName,
  FantomSpiritGetBrickTypeName,
  FantomSpiritNXTDefragmentFlash,
  FantomSpiritDownloadMemoryMap,
  FantomSpiritNXTFirmwareVersion,
  FantomSpiritNXTInstalledFirmware,
  FantomSpiritNXTGetBrickName,
  NXTNameToPBRFileType,
  LoadLSBlock;

end.