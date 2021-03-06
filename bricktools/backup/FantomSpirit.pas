unit FantomSpirit;

interface

uses
  Classes, SysUtils, rcx_cmd, uSpirit;

type
  TFantomSpirit = class(TBrickComm)
  private
    fResPort : string;
    fNXTHandle : Cardinal;
    fResourceNames : TStrings;
//    fNXTFileHandle : Cardinal;
//    fNXTFileIteratorHandle : Cardinal;
    dcResponse : array [0..63] of byte;
    function TransferFirmware(aStream: TStream): boolean;
  protected
    function  GetDownloadWaitTime: Integer; override;
    function  GetEEPROM(addr: Byte): Byte; override;
    function  GetEEPROMBlock(idx: Integer): EEPROMBlock; override;
    function  GetIsOpen: boolean; override;
    function  GetLSBlock(aPort: byte): NXTLSBlock; override;
    function  GetFullPortName: string; override;
    function  GetNicePortName: string; override;
    function  GetOmitHeader: Boolean; override;
    function  GetPortName: string; override;
    function  GetQuiet: Boolean; override;
    function  GetRCXFirmwareChunkSize: Integer; override;
    function  GetRxTimeout: Word; override;
    function  GetLinkLog: string; override;
    function  GetUseBT: Boolean; override;
    procedure SetDownloadWaitTime(const Value: Integer); override;
    procedure SetEEPROM(addr: Byte; const Value: Byte); override;
    procedure SetLSBlock(aPort: byte; const Value: NXTLSBlock); override;
    procedure SetOmitHeader(const Value: Boolean); override;
    procedure SetPort(const Value: string); override;
    procedure SetQuiet(const Value: Boolean); override;
    procedure SetRCXFirmwareChunkSize(const Value: Integer); override;
    procedure SetRxTimeout(const Value: Word); override;
  protected
    function  dcBuffer: PByte;
    function  GetReplyByte(index: integer): Byte;
    function  GetReplyCardinal(index: integer): Cardinal;
    function  GetReplyWord(index: integer): Word;
    procedure SetResourcePort(const name : string);
    procedure LookupResourceName;
  public
    constructor Create(aType : TBrickType = 0; const aPort : string = 'COM1'); override;
    destructor Destroy; override;

    function  Open : boolean; override;
    function  Close : boolean; override;

    // PBrick sound commands
    function PlayTone(aFreq, aTime : word) : boolean; override;
    function PlaySystemSound(aSnd : byte) : boolean; override;

    // PBrick output control commands
    function MotorsOn(aMotorList : Byte) : boolean; override;
    function MotorsOff(aMotorList : Byte) : boolean; override;
    function MotorsFloat(aMotorList : Byte) : boolean; override;
    function SetFwd(aMotorList : Byte) : boolean; override;
    function SetRwd(aMotorList : Byte) : boolean; override;
    function SwitchDirection(aMotorList : Byte) : boolean; override;
    function SetMotorPower(aMotorList : Byte; aSrc, aNum : integer) : boolean; override;

    // PBrick input control commands
    function SetSensorType(aNum, aType : integer) : boolean; override;
    function SetSensorMode(aNum, aMode, aSlope : integer) : boolean; override;
    function ClearSensorValue(aNum : integer) : boolean; override;

    // general
    function TowerExists : boolean; override;
    function Ping : boolean; override;
    function PrepareBrick : boolean; override;
    function UnlockFirmware : boolean; override;
    function UnlockBrick : string; override;
    function DownloadMemoryMap : TStrings; override;
    function MonitorIR(aSeconds: integer): TStrings; override;
    function PowerDownTime(aTime : integer) : boolean; override;
    function BatteryLevel : integer; override;
    function BrickAlive : boolean; override;
    function Shutdown : boolean; override;
    function Sleep(aVal : integer) : boolean; override;
	  function Version(var rom : Cardinal; var ram : Cardinal) : boolean; override;
    function TransmitPower(aLevel : TTransmitLevel) : boolean; override;

    function Poll(aSrc, aNum : integer) : integer; override;
    function StartTask(aTask : integer) : boolean; override;
    function StopTask(aTask : integer) : boolean; override;
    function StopAllTasks : boolean; override;
    function DeleteTask(aTask : integer) : boolean; override;
    function DeleteAllTasks : boolean; override;
    function DeleteSub(aSub : integer) : boolean; override;
    function DeleteAllSubs : boolean; override;
    function ClearTimer(aNum : integer) : boolean; override;
    function ClearMemory : boolean; override;

    function GetOutputStatus(aOut : integer) : integer; override;
    function GetVariableValue(aVar: integer): integer; override;
    function GetInputValue(aIn: integer): integer; override;
    function GetMessageValue(aNum : integer) : integer; override;
    function GetTimerValue(aNum : integer) : integer; override;
    function GetCounterValue(aNum : integer) : integer; override;

    // PBrick arithmetic/logical commands
    function SetVar(aVar, aSrc, aNum : integer) : boolean; override;
    function SumVar(aVar, aSrc, aNum : integer) : boolean; override;
    function SubVar(aVar, aSrc, aNum : integer) : boolean; override;
    function DivVar(aVar, aSrc, aNum : integer) : boolean; override;
    function MulVar(aVar, aSrc, aNum : integer) : boolean; override;
    function SgnVar(aVar, aSrc, aNum : integer) : boolean; override;
    function AbsVar(aVar, aSrc, aNum : integer) : boolean; override;
    function AndVar(aVar, aSrc, aNum : integer) : boolean; override;
    function OrVar(aVar, aSrc, aNum : integer) : boolean; override;

    // communication to brick
    function SendRawCommand(aCmd : string; bRetry : boolean) : string; override;
    function SendRemote(aEvent : string; aRepeat : integer = 1) : boolean; overload; override;
    function SendRemote(aEvent : Word; aRepeat : integer = 1) : boolean; overload; override;
    function SendMessage(aMsg : integer) : boolean; overload; override;

    // RCX/2 only
    function SelectProgram(aProg : integer) : boolean; override;
    function SelectDisplay(aSrc, aNumber : integer) : boolean; override;
    function SetWatch(aHrs, aMins : integer) : boolean; overload; override;
    function SetWatch(aTime : string) : boolean; overload; override;
    function DownloadFirmware(aFile : string; bFast, bComp, bUnlock : boolean) : boolean; override;
    function SetDatalog(aSize : integer) : boolean; override;
    function DatalogNext(aSrc, aNum : integer) : boolean; override;
    function UploadDatalog(aFrom, aSize : integer) : TStrings; overload; override;
    function UploadDatalog(bVerbose : boolean) : TStrings; overload; override;

    // CM only methods
    function Drive(aLeft, aRight : integer) : boolean; override;
    function ClearTachoCounter(aMotorList : Byte) : boolean; override;
    function OnWait(aMotorList : Byte; aNum : integer; aTime : Byte) : boolean; override;
    function OnWaitDifferent(aMotorList : Byte; aNum0, aNum1, aNum2 : integer; aTime : Byte) : boolean; override;

    // Scout only methods
    function Scout(aVal : integer) : boolean; overload; override;
    function Scout(bPower : boolean = true) : boolean; overload; override;
    function CalibrateLightSensor : boolean; override;
    function SetFeedback(src, val : integer) : boolean; override;
    function SetLightSensorUpperThreshold(src : TLSSource; val : TThresholdValue) : boolean; override;
    function SetLightSensorLowerThreshold(src : TLSSource; val : TThresholdValue) : boolean; override;
    function SetLightSensorHysteresis(src : TLSSource; val : TThresholdValue) : boolean; override;
    function SetLightSensorBlinkTime(src : TLSSource; val : TBlinkTimeValue) : boolean; override;
    function SetTimerLimit(num : TTimerNumber; src : TTCSource; val : integer) : boolean; override;
    function SetCounterLimit(num : TCounterNumber; src : TTCSource; val : integer) : boolean; override;
    function ScoutRules(motion : TScoutMotion; touch : TScoutTouch;
      light : TScoutLight; time : TScoutScale; fx : TScoutEffects) : boolean; override;
    function ScoutSound(bSoundEnable : boolean; bSoundOff : boolean; aNum : TSoundSetNumber) : boolean; override;

    // Scout & Spybot only methods
    function SendVLL(aSrc, aNum : integer) : boolean; override;
    function SetLight(bOn : boolean) : boolean; override;

    // RCX2, Scout, & Spybot methods
    function PollMemory(address : Integer; size : Integer = 128) : TStrings; override;
    function SetGlobalOutput(motors : TMotorsNum; action : TGlobalOutAction) : boolean; override;
    function SetGlobalDirection(motors : TMotorsNum; action : TGlobalDirAction) : boolean; override;
    function SetMaxPower(motors : TMotorsNum; src, num : integer) : boolean; override;
    function IncCounter(num : TCounterNumber) : boolean; override;
    function DecCounter(num : TCounterNumber) : boolean; override;
    function ClearCounter(num : TCounterNumber) : boolean; override;

    // RCX2 & spybot only methods
    function ClearSound : boolean; override;
    function UnmuteSound : boolean; override;
    function SendUARTData(start, size : integer) : boolean; override;
    function SetEvent(enum, snum, etype : integer) : boolean; override;
    function CalibrateEvent(enum, upper, lower, hysteresis : integer) : boolean; override;
    function ClearAllEvents : boolean; override;
    function SetSourceValue(aDestSrc, aDestVal, aOrigSrc: Byte; aOrigVal: Smallint): boolean; override;

    // RCX2, Spy, & NXT
    function MuteSound : boolean; override;

    // RCX2 only methods
    function ViewSourceValue(prec, src, value : integer) : boolean; override;

    // Spybot only methods
    function PollEEPROM(block : Integer = -1) : TStrings; override;

    // NXT only methods
    // NXT direct commands
    function StartProgram(const filename : string) : boolean; override;
    function StopProgram : boolean; override;
    function PlaySoundFile(const filename : string; bLoop : boolean) : boolean; override;
    function DCGetOutputState(const aPort : byte; var power : integer;
      var mode, regmode : byte; var turnratio : integer;
      var runstate : byte; var tacholimit : cardinal; var tachocount,
      blocktachocount, rotationcount : longint) : boolean; override;
    function DCSetOutputState(const aPort : byte; const power : integer;
      const mode, regmode : byte; const turnratio : integer;
      const runstate : byte; const tacholimit : cardinal) : boolean; override;
    function DCGetInputValues(const aPort : byte; var valid, calibrated : boolean;
      var stype, smode : byte; var raw, normalized : word;
      var scaled, calvalue : smallint) : boolean; override;
    function DCSetInputMode(const aPort, stype, smode : byte) : boolean; override;
    function ResetInputScaledValue(const aPort : byte) : boolean; override;
    function ResetOutputPosition(const aPort : byte; const Relative : boolean) : boolean; override;
    function MessageWrite(const inbox : byte; const msg : string) : boolean; overload; override;
    function KeepAlive(var time : cardinal; const chkResponse : boolean = true) : boolean; override;
    function LSGetStatus(aPort : byte; var bytesReady : byte) : boolean; override;
    function GetCurrentProgramName(var name : string) : boolean; override;
    function GetButtonState(const idx : byte; const reset : boolean;
      var pressed : boolean; var count : byte) : boolean; override;
    function MessageRead(const remote, local : byte; const remove : boolean; var Msg : PBRMessage) : boolean; override;
    // NXT system commands
    function SCOpenRead(const filename : string; var handle : cardinal;
      var size : cardinal) : boolean; override;
    function SCOpenWrite(const filename : string; const size : cardinal;
      var handle : cardinal) : boolean; override;
    function SCRead(var handle : cardinal; var count : word;
      var buffer : PBRDataBuffer) : boolean; override;
    function SCWrite(var handle : cardinal; const buffer : PBRDataBuffer;
      var count : word; const chkResponse : boolean = false) : boolean; override;
    function SCCloseFile(var handle : cardinal; const chkResponse: boolean = false) : boolean; override;
    function SCDeleteFile(var filename : string; const chkResponse: boolean = false) : boolean; override;
    function SCFindFirstFile(var filename : string; var handle : cardinal; var filesize : cardinal) : boolean; override;
    function SCFindNextFile(var handle : cardinal; var filename : string; var filesize : cardinal) : boolean; override;
    function SCGetVersions(var protmin, protmaj, firmmin, firmmaj : byte) : boolean; override;
    function SCOpenWriteLinear(const filename : string; const size : cardinal;
      var handle : cardinal) : boolean; override;
    function SCOpenReadLinear(const filename : string; var handle : cardinal;
      var size : cardinal) : boolean; override;
    function SCOpenWriteData(const filename : string; const size : cardinal;
      var handle : cardinal) : boolean; override;
    function SCOpenAppendData(const filename : string; var size : cardinal;
      var handle : cardinal) : boolean; override;
    function SCCloseModuleHandle(var handle : cardinal; const chkResponse: boolean = false) : boolean; override;
    function SCBootCommand(const chkResponse: boolean = false) : boolean; override;
    function SCSetBrickName(const name : string; const chkResponse: boolean = false) : boolean; override;
    function SCGetDeviceInfo(var name : string; BTAddress : PByte;
      var BTSignal : Cardinal; var memFree : Cardinal) : boolean; override;
    function SCFreeMemory : integer; override;
    function SCDeleteUserFlash(const chkResponse: boolean = false) : boolean; override;
    function SCBTFactoryReset(const chkResponse: boolean = false) : boolean; override;
    function SCPollCommandLen(const bufNum : byte; var count : byte) : boolean; override;
    function SCPollCommand(const bufNum : byte; var count : byte;
      var buffer : PBRDataBuffer) : boolean; override;
    function SCWriteIOMap(var ModID : Cardinal; const Offset : Word;
      var count : Word; const buffer : PBRDataBuffer; chkResponse : Boolean = False) : boolean; override;
    function SCReadIOMap(var ModID : Cardinal; const Offset : Word;
      var count : Word; var buffer : PBRDataBuffer) : boolean; override;
    function SCFindFirstModule(var ModName : string; var Handle : cardinal;
      var ModID, ModSize : Cardinal; var IOMapSize : Word) : boolean; override;
    function SCFindNextModule(var Handle : cardinal; var ModName : string;
      var ModID, ModSize : Cardinal; var IOMapSize : Word) : boolean; override;
    function SCRenameFile(const old, new : string; const chkResponse: boolean = false) : boolean; override;
{
  kNXT_SCGetBTAddress          = $9A;
}
    // wrapper functions
    function DownloadFile(const filename : string; const filetype : TPBRFileType) : boolean; override;
    function DownloadStream(aStream : TStream; const dest : string; const filetype : TPBRFileType) : boolean; override;
    function UploadFile(const filename : string; const dir : string = '') : boolean; override;
    function ListFiles(const searchPattern : string; Files : TStrings) : boolean; override;
    function ListModules(const searchPattern : string; Modules : TStrings) : boolean; override;
    function ListBricks(Bricks : TStrings) : boolean; override;
    procedure InitializeResourceNames; override;
  end;

implementation

uses
  rcx_constants, Contnrs, Math, uNXTConstants,
  {$IFNDEF FPC}FANTOM{$ELSE}FANTOMFPC{$ENDIF};

function NXTModuleIDToName(const modID : cardinal) : string;
var
  i : integer;
begin
  Result := '*.*';
  for i := Low(NXTModuleMap) to High(NXTModuleMap) do
  begin
    if NXTModuleMap[i].ID = modID then
    begin
      Result := NXTModuleMap[i].Name;
      Break;
    end;
  end;
end;

{ TFantomSpirit }

constructor TFantomSpirit.Create(aType: TBrickType; const aPort: string);
begin
  inherited Create(aType, aPort);
  fResPort := '';
  fResourceNames := TStringList.Create;
end;

destructor TFantomSpirit.Destroy;
begin
  FreeAndNil(fResourceNames);
  inherited Destroy;
end;

function TFantomSpirit.BatteryLevel: integer;
var
  bopen : boolean;
  cmd : TNINxtCmd;
  status : integer;
begin
  Result := -1;
  bopen := IsOpen;
  if bopen then
  begin
    cmd := TNINxtCmd.Create;
    try
      status := kStatusNoError;
      cmd.SetVal(kNXT_DirectCmd, kNXT_DCGetBatteryLevel);
      iNXT_sendDirectCommand(fNXTHandle, 1, cmd.BytePtr, cmd.Len, dcBuffer, 4, status);
      if status < kStatusNoError then
      begin
        result := kRCX_ReplyError;
        Exit;
      end;
      Result := GetReplyWord(0);
    finally
      cmd.Free;
    end;
  end;
end;

function TFantomSpirit.Shutdown: boolean;
var
  modID : Cardinal;
  count : Word;
  buffer : PBRDataBuffer;
begin
  Result := IsOpen;
  if not Result then Exit;
  modID := kNXT_ModuleIOCtrl;
  count := 2;
  buffer.Data[0] := $0;
  buffer.Data[1] := $5a;
  Result := SCWriteIOMap(modID, IOCtrlOffsetPowerOn, count, buffer);
end;

const
  MotorBits : array[0..2] of byte = (1, 2, 4);

function TFantomSpirit.MotorsOn(aMotorList: Byte): boolean;
var
  mode, regmode, runstate : byte;
  oldpower, power, turnratio : integer;
  tacholimit : cardinal;
  tachocount, blocktachocount, rotationcount : integer;
  i : integer;
begin
  Result := IsOpen;
  if not Result then Exit;
  for i := 0 to 2 do
  begin
    if (MotorBits[i] and aMotorList) = MotorBits[i] then
    begin
      fMotorOn[i] := True;
      Result := Result and DCGetOutputState(i, oldpower, mode, regmode, turnratio,
        runstate, tacholimit, tachocount, blocktachocount, rotationcount);
      power := fMotorPower[i] * 14;
      if not fMotorForward[i] then
        power := power * -1;
      if (oldpower <> power) or
         ((mode and OUT_MODE_MOTORON) <> OUT_MODE_MOTORON) or
         ((runstate and OUT_RUNSTATE_RUNNING) <> OUT_RUNSTATE_RUNNING) then
      begin
        mode := OUT_MODE_MOTORON+OUT_MODE_BRAKE;
        runstate := OUT_RUNSTATE_RUNNING;
        Result := Result and DCSetOutputState(i, power, mode, regmode, turnratio,
          runstate, tacholimit);
      end;
    end;
    if not Result then Break;
  end;
end;

function TFantomSpirit.MotorsOff(aMotorList: Byte): boolean;
var
  mode, regmode, runstate : byte;
  power, turnratio : integer;
  tacholimit : cardinal;
  i : integer;
begin
  Result := IsOpen;
  if not Result then Exit;
  for i := 0 to 2 do
  begin
    if (MotorBits[i] and aMotorList) = MotorBits[i] then
    begin
      fMotorOn[i] := False;
      power := 0;
      mode  := OUT_MODE_MOTORON+OUT_MODE_BRAKE;
      regmode := OUT_REGMODE_IDLE;
      runstate := OUT_RUNSTATE_RUNNING;
      turnratio := 0; // straight (side effect of stopping motors is to reset turn ratio)
      tacholimit := 0; // no limit (side effect of stopping motors is to reset tacho limit)
      Result := Result and DCSetOutputState(i, power, mode, regmode, turnratio,
        runstate, tacholimit);
    end;
    if not Result then Break;
  end;
end;

function TFantomSpirit.MotorsFloat(aMotorList: Byte): boolean;
var
  mode, regmode, runstate : byte;
  power, turnratio : integer;
  tacholimit : cardinal;
  i : integer;
begin
  Result := IsOpen;
  if not Result then Exit;
  for i := 0 to 2 do
  begin
    if (MotorBits[i] and aMotorList) = MotorBits[i] then
    begin
      fMotorOn[i] := False;
      power := 0;
      mode  := 0; // OUT_MODE_COAST;
      regmode := 0; // OUT_REGMODE_IDLE;
      runstate := 0; // OUT_RUNSTATE_IDLE;
      turnratio := 0; // straight (side effect of stopping motors is to reset turn ratio)
      tacholimit := 0; // no limit (side effect of stopping motors is to reset tacho limit)
      Result := Result and DCSetOutputState(i, power, mode, regmode, turnratio,
        runstate, tacholimit);
    end;
    if not Result then Break;
  end;
end;

function TFantomSpirit.SetFwd(aMotorList: Byte): boolean;
var
  mode, regmode, runstate : byte;
  power, turnratio : integer;
  tacholimit : cardinal;
  tachocount, blocktachocount, rotationcount : integer;
  i : integer;
begin
  Result := IsOpen;
  if not Result then Exit;
  for i := 0 to 2 do
  begin
    if (MotorBits[i] and aMotorList) = MotorBits[i] then
    begin
      fMotorForward[i] := True;
      Result := Result and DCGetOutputState(i, power, mode, regmode, turnratio,
        runstate, tacholimit, tachocount, blocktachocount, rotationcount);
      if power < 0 then
      begin
        power := power * -1;
        if not fMotorOn[i] then
        begin
          // make sure we are idle
          mode := 0;
          regmode := 0;
          runstate := 0;
        end;
        Result := Result and DCSetOutputState(i, power, mode, regmode, turnratio,
          runstate, tacholimit);
      end;
    end;
    if not Result then Break;
  end;
end;

function TFantomSpirit.SetRwd(aMotorList: Byte): boolean;
var
  mode, regmode, runstate : byte;
  power, turnratio : integer;
  tacholimit : cardinal;
  tachocount, blocktachocount, rotationcount : integer;
  i : integer;
begin
  Result := IsOpen;
  if not Result then Exit;
  for i := 0 to 2 do
  begin
    if (MotorBits[i] and aMotorList) = MotorBits[i] then
    begin
      fMotorForward[i] := False;
      Result := Result and DCGetOutputState(i, power, mode, regmode, turnratio,
        runstate, tacholimit, tachocount, blocktachocount, rotationcount);
      if power > 0 then
      begin
        power := power * -1;
        if not fMotorOn[i] then
        begin
          // make sure we are idle
          mode := 0;
          regmode := 0;
          runstate := 0;
        end;
        Result := Result and DCSetOutputState(i, power, mode, regmode, turnratio,
          runstate, tacholimit);
      end;
    end;
    if not Result then Break;
  end;
end;

function TFantomSpirit.SwitchDirection(aMotorList: Byte): boolean;
var
  mode, regmode, runstate : byte;
  power, turnratio : integer;
  tacholimit : cardinal;
  tachocount, blocktachocount, rotationcount : integer;
  i : integer;
begin
  Result := IsOpen;
  if not Result then Exit;
  for i := 0 to 2 do
  begin
    if (MotorBits[i] and aMotorList) = MotorBits[i] then
    begin
      fMotorForward[i] := not fMotorForward[i];
      Result := Result and DCGetOutputState(i, power, mode, regmode, turnratio,
        runstate, tacholimit, tachocount, blocktachocount, rotationcount);
      power := power * -1;
      Result := Result and DCSetOutputState(i, power, mode, regmode, turnratio,
        runstate, tacholimit);
    end;
    if not Result then Break;
  end;
end;

function TFantomSpirit.SetMotorPower(aMotorList: Byte; aSrc, aNum: integer): boolean;
var
  mode, regmode, runstate : byte;
  oldpower, power, turnratio : integer;
  tacholimit : cardinal;
  tachocount, blocktachocount, rotationcount : integer;
  i : integer;
begin
  Result := IsOpen;
  if not Result then Exit;
  if aSrc <> 2 then
  begin
    Result := False;
    Exit;
  end
  else
  begin
    for i := 0 to 2 do
    begin
      if (MotorBits[i] and aMotorList) = MotorBits[i] then
      begin
        fMotorPower[i] := Abs(aNum) mod 8;
        Result := Result and DCGetOutputState(i, oldpower, mode, regmode, turnratio,
          runstate, tacholimit, tachocount, blocktachocount, rotationcount);
        power := fMotorPower[i] * 14;
        if fMotorPower[i] = 7 then
          power := 100;
        if not fMotorForward[i] then
          power := power * -1;
        if oldpower <> power then
        begin
          if not fMotorOn[i] then
          begin
            // make sure we are idle
            mode := 0;
            regmode := 0;
            runstate := 0;
          end;
          Result := Result and DCSetOutputState(i, power, mode, regmode, turnratio,
            runstate, tacholimit);
        end;
      end;
      if not Result then Break;
    end;
  end;
end;

function TFantomSpirit.PlayTone(aFreq, aTime: word): boolean;
var
  cmd : TNINxtCmd;
  status : integer;
begin
  Result := IsOpen;
  if not Result then Exit;
  cmd := TNINxtCmd.Create;
  try
    status := kStatusNoError;
    cmd.SetVal(kNXT_DirectCmdNoReply, kNXT_DCPlayTone, Lo(aFreq), Hi(aFreq), Lo(aTime), Hi(aTime));
    iNXT_sendDirectCommand(fNXTHandle, 0, cmd.BytePtr, cmd.Len, nil, 0, status);
    Result := status >= kStatusNoError;
  finally
    cmd.Free;
  end;
end;

function TFantomSpirit.SetSensorType(aNum, aType: integer): boolean;
begin
  Result := IsOpen;
  if not Result then Exit;
  fSensorType[aNum] := aType;
  Result := DCSetInputMode(aNum, aType, fSensorMode[aNum]);
end;

function TFantomSpirit.SetSensorMode(aNum, aMode, aSlope: integer): boolean;
begin
  Result := IsOpen;
  if not Result then Exit;
  fSensorMode[aNum] := ((aMode and $7) shl 5) or (aSlope and $F);
  Result := DCSetInputMode(aNum, fSensorType[aNum], fSensorMode[aNum]);
end;

function TFantomSpirit.ClearSensorValue(aNum: integer): boolean;
begin
  Result := ResetInputScaledValue(aNum);
end;

function TFantomSpirit.Close: boolean;
var
  status : integer;
begin
  Result := True;
  if IsOpen then
  begin
    fResPort := ''; // clear this so that it gets looked up again when opening
    status := kStatusNoError;
    destroyNXT(fNXTHandle, status);
    fActive := False;
    fNXTHandle := 0;
    Result := status >= kStatusNoError;
  end;
end;

function TFantomSpirit.Open: boolean;
var
  nih : Cardinal;
  status, status2 : integer;
  resNamePC : array[0..54] of Char;
  pairedResNamePC : array[0..54] of Char;
  resName, pName, bName : string;
begin
  Result := IsOpen;
  if not FantomAPILoaded then Exit;
  if not Result then begin
    if fResPort = '' then
      LookupResourceName;
    if fResPort = '' then
      fResPort := fPort;
    resName := '';
    pName := AnsiUpperCase(fResPort);
    bName := AnsiUpperCase(BluetoothName);
    if (Length(pName) > 4) and (Pos('::', pName) > 0) then
    begin
      // we think this is a resource string
      // if we are using bluetooth then we need to make sure we are paired
      // with the brick
      status := kStatusNoError;
      if UseBluetooth then // resource string starts with BTH == use bluetooth
      begin
//        unpairBluetooth(PChar(pName), status);
        pairBluetooth(PChar(pName), '1234', pairedResNamePC, status);
        pName := pairedResNamePC;
      end;
      if status >= kStatusNoError then
      begin
        status := kStatusNoError;
        fNXTHandle := createNXT(PChar(pName), status, 0);
        if status >= kStatusNoError then
        begin
          fActive := True;
          Result := True;
        end;
      end;
    end
    else
    begin
      // use Fantom API to obtain a handle to an NXT on either USB or bluetooth
      status := kStatusNoError;
      nih := createNXTIterator(Ord(UseBluetooth), BluetoothSearchTimeout, status);
      while status >= kStatusNoError do
      begin
        status2 := kStatusNoError;
        iNXTIterator_getName(nih, resNamePC, status2);
        resName := AnsiUpperCase(resNamePC);
        if UseBluetooth then
        begin
          if bName = '' then
            bName := 'BTH';
          if Pos(bName, resName) > 0 then
            Break;
        end
        else if Pos(pName, resName) > 0 then
          Break;
        iNXTIterator_advance(nih, status);
      end;
      // if we are using bluetooth then we need to make sure we are paired
      // with the brick
      if UseBluetooth then
      begin
        status := kStatusNoError;
        pairBluetooth(resNamePC, '1234', pairedResNamePC, status);
        resName := AnsiUpperCase(pairedResNamePC);
      end;
      if status >= kStatusNoError then
      begin
        fNXTHandle := iNXTIterator_getNXT(nih, status);
        if status >= kStatusNoError then
        begin
          SetResourcePort(resName);
          fActive := True;
          Result := True;
        end;
      end;
      status := kStatusNoError;
      destroyNXTIterator(nih, status);
    end;
  end;
end;

function TFantomSpirit.ClearMemory: boolean;
begin
  Result := SCDeleteUserFlash(True);
end;

function TFantomSpirit.Sleep(aVal: integer): boolean;
begin
  Result := PowerDownTime(aVal);
end;

function TFantomSpirit.GetInputValue(aIn : integer) : integer;
var
  bOpen : boolean;
begin
  Result := -1;
  bopen := Open;
  if bOpen then
  begin
    Result := Poll(kRCX_InputValueType, aIn);
  end;
end;

procedure TFantomSpirit.SetPort(const Value: string);
begin
  if (Value <> fPort) or (fResPort = '') then
  begin
    Close;
    inherited SetPort(Value);
    fResPort := fPort;
    LookupResourceName;
  end;
end;

function TFantomSpirit.DownloadFirmware(aFile: string; bFast : Boolean;
  bComp : Boolean; bUnlock : boolean): boolean;
var
  MS : TMemoryStream;
begin
  if not IsOpen then
    Open;
  Result := FileExists(aFile);
  if Result then
  begin
    MS := TMemoryStream.Create;
    try
      MS.LoadFromFile(aFile);
      DoDownloadStart;
      Result := DownloadStream(MS, aFile, nftFirmware);
      DoDownloadDone;
    finally
      MS.Free;
    end;
  end;
end;

function TFantomSpirit.Ping: boolean;
var
  time : cardinal;
begin
  Result := IsOpen;
  if not Result then Exit;
  Result := KeepAlive(time);
end;

function TFantomSpirit.MuteSound: boolean;
var
  cmd : TNINxtCmd;
  status : integer;
begin
  Result := IsOpen;
  if not Result then Exit;
  cmd := TNINxtCmd.Create;
  try
    status := kStatusNoError;
    cmd.SetVal(kNXT_DirectCmdNoReply, kNXT_DCStopSoundPlayback);
    iNXT_sendDirectCommand(fNXTHandle, 0, cmd.BytePtr, cmd.Len, nil, 0, status);
    Result := status >= kStatusNoError;
  finally
    cmd.Free;
  end;
end;

function TFantomSpirit.UnmuteSound: boolean;
var
  cmd : TNINxtCmd;
begin
  Result := IsOpen;
  if not Result then Exit;
  cmd := TNINxtCmd.Create;
  try
  // TODO : Implement Unmute Sound
  finally
    cmd.Free;
  end;
end;

function TFantomSpirit.GetPortName: string;
begin
  Result := FPort;
end;

function TFantomSpirit.GetFullPortName: string;
begin
  Result := fResPort;
end;

function TFantomSpirit.GetNicePortName: string;
var
  i : integer;
begin
  i := Pos('::', fResPort);
  if i > 0 then
    Result := Copy(fResPort, 1, i-1)
  else
    Result := fResPort;
end;

function TFantomSpirit.GetIsOpen: boolean;
begin
  Result := inherited GetIsOpen;
  Result := Result and FantomAPILoaded;
end;

function TFantomSpirit.StartProgram(const filename: string): boolean;
var
  cmd : TNINxtCmd;
  status : integer;
begin
  Result := IsOpen;
  if not Result then Exit;
  cmd := TNINxtCmd.Create;
  try
    status := kStatusNoError;
    cmd.MakeCmdWithFilename(kNXT_DirectCmd, kNXT_DCStartProgram, filename);
    iNXT_sendDirectCommand(fNXTHandle, 1, cmd.BytePtr, cmd.Len, dcBuffer, 2, status);
    Result := status >= kStatusNoError;
  finally
    cmd.Free;
  end;
end;

function TFantomSpirit.StopProgram: boolean;
var
  cmd : TNINxtCmd;
  status : integer;
begin
  Result := IsOpen;
  if not Result then Exit;
  cmd := TNINxtCmd.Create;
  try
    status := kStatusNoError;
    cmd.SetVal(kNXT_DirectCmd, kNXT_DCStopProgram);
    iNXT_sendDirectCommand(fNXTHandle, 1, cmd.BytePtr, cmd.Len, dcBuffer, 2, status);
    Result := status >= kStatusNoError;
  finally
    cmd.Free;
  end;
end;

function TFantomSpirit.PlaySoundFile(const filename: string; bLoop: boolean): boolean;
var
  i : integer;
  cmd : TNINxtCmd;
  orig : PByte;
  nxtFilename : string;
  status : integer;
begin
  Result := IsOpen;
  if not Result then Exit;
  cmd := TNINxtCmd.Create;
  try
    status := kStatusNoError;
    // filename is limited to 19 bytes + null terminator
    cmd.SetLength(23);
    orig := cmd.GetBody;
    orig^ := kNXT_DirectCmdNoReply;
    inc(orig);
    orig^ := kNXT_DCPlaySoundFile;
    inc(orig);
    orig^ := Ord(bLoop);
    inc(orig);
    i := 1;
    nxtFilename := MakeValidNXTFilename(filename);
    while i <= 19 do
    begin
      // copy the first nineteen bytes from the filename provided
      if i > Length(nxtFilename) then
        orig^ := 0
      else
        orig^ := Ord(nxtFilename[i]);
      inc(orig);
      inc(i);
    end;
    orig^ := 0; // set last byte to null
    iNXT_sendDirectCommand(fNXTHandle, 0, cmd.BytePtr, cmd.Len, nil, 0, status);
    Result := status >= kStatusNoError;
  finally
    cmd.Free;
  end;
end;

function TFantomSpirit.DCGetOutputState(const aPort: byte; var power: integer;
  var mode, regmode: byte; var turnratio: integer; var runstate: byte;
  var tacholimit: cardinal; var tachocount, blocktachocount, rotationcount: Integer): boolean;
var
  cmd : TNINxtCmd;
  status : integer;
begin
  Result := IsOpen;
  if not Result then Exit;
  cmd := TNINxtCmd.Create;
  try
    status := kStatusNoError;
    cmd.SetVal(kNXT_DirectCmd, kNXT_DCGetOutputState, aPort);
    iNXT_sendDirectCommand(fNXTHandle, 1, cmd.BytePtr, cmd.Len, dcBuffer, 24, status);
    Result := status >= kStatusNoError;
    if not Result then
      Exit;
//    port      := GetReplyByte(0)
    power     := ShortInt(GetReplyByte(1));
    mode      := GetReplyByte(2);
    regmode   := GetReplyByte(3);
    turnratio := ShortInt(GetReplyByte(4));
    runstate  := GetReplyByte(5);
    tacholimit := GetReplyCardinal(6);
    tachocount := Integer(GetReplyCardinal(10));
    blocktachocount := Integer(GetReplyCardinal(14));
    rotationcount := Integer(GetReplyCardinal(18));
  finally
    cmd.Free;
  end;
end;

function TFantomSpirit.DCSetOutputState(const aPort: byte;
  const power: integer; const mode, regmode: byte;
  const turnratio: integer; const runstate: byte;
  const tacholimit: cardinal): boolean;
var
  cmd : TNINxtCmd;
//  orig : PByte;
  status : integer;
begin
  Result := IsOpen;
  if not Result then Exit;
  cmd := TNINxtCmd.Create;
  try
    status := kStatusNoError;
    cmd.MakeSetOutputState(aPort, mode, regmode, runstate, power, turnratio, tacholimit, False);
    iNXT_sendDirectCommand(fNXTHandle, 0, cmd.BytePtr, cmd.Len, nil, 0, status);
    Result := status >= kStatusNoError;
  finally
    cmd.Free;
  end;
end;

function TFantomSpirit.DCGetInputValues(const aPort: byte; var valid,
  calibrated: boolean; var stype, smode: byte; var raw, normalized: word;
  var scaled, calvalue: smallint): boolean;
var
  cmd : TNINxtCmd;
  status : integer;
begin
  Result := IsOpen;
  if not Result then Exit;
  cmd := TNINxtCmd.Create;
  try
    status := kStatusNoError;
    cmd.SetVal(kNXT_DirectCmd, kNXT_DCGetInputValues, aPort);
    iNXT_sendDirectCommand(fNXTHandle, 1, cmd.BytePtr, cmd.Len, dcBuffer, 15, status);
    Result := status >= kStatusNoError;
    if not Result then
      Exit;
//    port       := GetReplyByte(0);
    valid      := GetReplyByte(1) <> 0;
    calibrated := GetReplyByte(2) <> 0;
    stype      := GetReplyByte(3);
    smode      := GetReplyByte(4);
    raw        := GetReplyWord(5);
    normalized := GetReplyWord(7);
    scaled     := SmallInt(GetReplyWord(9));
    calvalue   := SmallInt(GetReplyWord(11));
  finally
    cmd.Free;
  end;
end;

function TFantomSpirit.DCSetInputMode(const aPort, stype, smode: byte): boolean;
var
  cmd : TNINxtCmd;
  status : integer;
begin
  Result := IsOpen;
  if not Result then Exit;
  cmd := TNINxtCmd.Create;
  try
    status := kStatusNoError;
    cmd.SetVal(kNXT_DirectCmdNoReply, kNXT_DCSetInputMode, aPort, stype, smode);
    iNXT_sendDirectCommand(fNXTHandle, 0, cmd.BytePtr, cmd.Len, nil, 0, status);
    Result := status >= kStatusNoError;
  finally
    cmd.Free;
  end;
end;

function TFantomSpirit.ResetInputScaledValue(const aPort: byte): boolean;
var
  cmd : TNINxtCmd;
  status : integer;
begin
  Result := IsOpen;
  if not Result then Exit;
  cmd := TNINxtCmd.Create;
  try
    status := kStatusNoError;
    cmd.SetVal(kNXT_DirectCmdNoReply, kNXT_DCResetInputScaledValue, aPort);
    iNXT_sendDirectCommand(fNXTHandle, 0, cmd.BytePtr, cmd.Len, nil, 0, status);
    Result := status >= kStatusNoError;
  finally
    cmd.Free;
  end;
end;

function TFantomSpirit.ResetOutputPosition(const aPort: byte;
  const Relative: boolean): boolean;
var
  cmd : TNINxtCmd;
  status : integer;
begin
  Result := IsOpen;
  if not Result then Exit;
  cmd := TNINxtCmd.Create;
  try
    status := kStatusNoError;
    cmd.SetVal(kNXT_DirectCmdNoReply, kNXT_DCResetMotorPosition, aPort, Ord(Relative));
    iNXT_sendDirectCommand(fNXTHandle, 0, cmd.BytePtr, cmd.Len, nil, 0, status);
    Result := status >= kStatusNoError;
  finally
    cmd.Free;
  end;
end;

function TFantomSpirit.MessageWrite(const inbox: byte; const msg: string): boolean;
var
  i, len : integer;
  cmd : TNINxtCmd;
  orig : PByte;
  status : integer;
begin
  Result := IsOpen;
  if not Result then Exit;
  cmd := TNINxtCmd.Create;
  try
    status := kStatusNoError;
    // message is limited to 59 bytes + null terminator
    len := Min(Length(msg), kNXT_MaxBytes-5);
    cmd.SetLength(len+5);
    orig := cmd.GetBody;
    orig^ := kNXT_DirectCmdNoReply;
    inc(orig);
    orig^ := kNXT_DCMessageWrite;
    inc(orig);
    orig^ := inbox;
    inc(orig);
    orig^ := len+1; // add null terminator
    inc(orig);
    i := 1;
    while i <= len do
    begin
      orig^ := Ord(msg[i]);
      inc(orig);
      inc(i);
    end;
    orig^ := 0; // set last byte to null
    iNXT_sendDirectCommand(fNXTHandle, 0, cmd.BytePtr, cmd.Len, nil, 0, status);
    Result := status >= kStatusNoError;
  finally
    cmd.Free;
  end;
end;

function TFantomSpirit.KeepAlive(var time: cardinal; const chkResponse : boolean): boolean;
var
  cmd : TNINxtCmd;
  b : byte;
  status : integer;
begin
  Result := IsOpen;
  if not Result then Exit;
  cmd := TNINxtCmd.Create;
  try
    status := kStatusNoError;
    result := False;
    if chkResponse then
      b := kNXT_DirectCmd
    else
      b := kNXT_DirectCmdNoReply;
    cmd.SetVal(b, kNXT_DCKeepAlive);
    if chkResponse then
      iNXT_sendDirectCommand(fNXTHandle, 1, cmd.BytePtr, cmd.Len, dcBuffer, 6, status)
    else
      iNXT_sendDirectCommand(fNXTHandle, 0, cmd.BytePtr, cmd.Len, nil, 0, status);
    Result := status >= kStatusNoError;
    if chkResponse then
    begin
      if not Result then
        Exit;
      time := Integer(GetReplyCardinal(0));
    end;
  finally
    cmd.Free;
  end;
end;

function TFantomSpirit.LSGetStatus(aPort : byte; var bytesReady: byte): boolean;
var
  cmd : TNINxtCmd;
  status : integer;
begin
  Result := IsOpen;
  if not Result then Exit;
  cmd := TNINxtCmd.Create;
  try
    status := kStatusNoError;
    cmd.SetVal(kNXT_DirectCmd, kNXT_DCLSGetStatus, aPort);
    iNXT_sendDirectCommand(fNXTHandle, 1, cmd.BytePtr, cmd.Len, dcBuffer, 3, status);
    Result := status >= kStatusNoError;
    if not Result then
      Exit;
    bytesReady := GetReplyByte(0);
  finally
    cmd.Free;
  end;
end;

function TFantomSpirit.GetLSBlock(aPort: byte): NXTLSBlock;
var
  cmd : TNINxtCmd;
  i : integer;
  status : integer;
begin
  // LSRead
  Result.TXCount := 0;
  if not IsOpen then Exit;
  cmd := TNINxtCmd.Create;
  try
    status := kStatusNoError;
    cmd.SetVal(kNXT_DirectCmd, kNXT_DCLSRead, aPort);
    iNXT_sendDirectCommand(fNXTHandle, 1, cmd.BytePtr, cmd.Len, dcBuffer, 19, status);
    if status < kStatusNoError then
    begin
      Result.RXCount := 0;
      Exit;
    end;
    Result.RXCount := GetReplyByte(0);
    for i := 1 to 16 do
    begin
      Result.Data[i-1] := GetReplyByte(i);
    end;
  finally
    cmd.Free;
  end;
end;

procedure TFantomSpirit.SetLSBlock(aPort: byte; const Value: NXTLSBlock);
var
  i, len : integer;
  cmd : TNINxtCmd;
  orig : PByte;
  status : integer;
begin
  // LSWrite
  if not IsOpen then Exit;
  cmd := TNINxtCmd.Create;
  try
    status := kStatusNoError;
    len := Min(Value.TXCount, 16);
    cmd.SetLength(len+5); // up to a max of 21 bytes
    orig := cmd.GetBody;
    orig^ := kNXT_DirectCmdNoReply;
    inc(orig);
    orig^ := kNXT_DCLSWrite;
    inc(orig);
    orig^ := aPort;
    inc(orig);
    orig^ := len;
    inc(orig);
    orig^ := Min(Value.RXCount, 16);
    inc(orig);
    i := 0;
    while i < len do
    begin
      orig^ := Value.Data[i];
      inc(orig);
      inc(i);
    end;
    orig^ := 0; // set last byte to null
    iNXT_sendDirectCommand(fNXTHandle, 0, cmd.BytePtr, cmd.Len, nil, 0, status);
  finally
    cmd.Free;
  end;
end;

function TFantomSpirit.GetCurrentProgramName(var name: string): boolean;
var
  cmd : TNINxtCmd;
  i : integer;
  Buf : array[0..19] of Char;
  status : integer;
begin
  Result := IsOpen;
  if not Result then Exit;
  cmd := TNINxtCmd.Create;
  try
    status := kStatusNoError;
    cmd.SetVal(kNXT_DirectCmd, kNXT_DCGetCurrentProgramName);
    iNXT_sendDirectCommand(fNXTHandle, 1, cmd.BytePtr, cmd.Len, dcBuffer, 22, status);
    Result := status >= kStatusNoError;
    if not Result then
    begin
      name   := '';
      Exit;
    end;
    for i := 0 to 19 do
    begin
      Buf[i] := Char(GetReplyByte(i));
    end;
    name := Buf;
  finally
    cmd.Free;
  end;
end;

function TFantomSpirit.GetButtonState(const idx: byte; const reset: boolean;
  var pressed: boolean; var count: byte): boolean;
var
  cmd : TNINxtCmd;
  status : integer;
begin
  Result := IsOpen;
  if not Result then Exit;
  cmd := TNINxtCmd.Create;
  try
    status := kStatusNoError;
    cmd.SetVal(kNXT_DirectCmd, kNXT_DCGetButtonState, idx, Ord(reset));
    iNXT_sendDirectCommand(fNXTHandle, 1, cmd.BytePtr, cmd.Len, dcBuffer, 3, status);
    Result := status >= kStatusNoError;
    if not Result then
      Exit;
    pressed := Boolean(GetReplyByte(0));
    count   := GetReplyByte(1);
  finally
    cmd.Free;
  end;
end;

function TFantomSpirit.MessageRead(const remote, local: byte;
  const remove: boolean; var Msg: PBRMessage): boolean;
var
  cmd : TNINxtCmd;
  i : integer;
  status : integer;
begin
  Msg.Inbox := 0;
  Msg.Size  := 0;
  Result := IsOpen;
  if not Result then Exit;
  cmd := TNINxtCmd.Create;
  try
    status := kStatusNoError;
    cmd.SetVal(kNXT_DirectCmd, kNXT_DCMessageRead, remote, local, Ord(remove));
    iNXT_sendDirectCommand(fNXTHandle, 1, cmd.BytePtr, cmd.Len, dcBuffer, 63, status);
    Result := status >= kStatusNoError;
    if not Result then
      Exit;
    Msg.Inbox := GetReplyByte(0);
    Msg.Size  := GetReplyByte(1);
    for i := 2 to 60 do
    begin
      Msg.Data[i-2] := GetReplyByte(i);
    end;
  finally
    cmd.Free;
  end;
end;

function TFantomSpirit.SCOpenRead(const filename: string; var handle: cardinal;
  var size: cardinal): boolean;
var
  status : integer;
begin
  Result := IsOpen;
  if not Result then Exit;
  status := kStatusNoError;
  handle := iNXT_createFile(fNXTHandle, PChar(filename), status);
  Result := status >= kStatusNoError;
  if Result then
  begin
    iFile_openForRead(handle, status);
    Result := status >= kStatusNoError;
    if Result then
    begin
      size := iFile_getSize(handle, status);
      Result := status >= kStatusNoError;
    end;
    if not Result then
    begin
      status := kStatusNoError;
      iNXT_destroyFile(fNXTHandle, handle, status);
    end;
  end;
end;

function TFantomSpirit.SCOpenReadLinear(const filename: string;
  var handle: cardinal; var size: cardinal): boolean;
begin
  Result := SCOpenRead(filename, handle, size);
end;

function TFantomSpirit.SCOpenAppendData(const filename: string;
  var size: cardinal; var handle: cardinal): boolean;
var
  status : integer;
begin
  Result := IsOpen;
  if not Result then Exit;
  status := kStatusNoError;
  handle := iNXT_createFile(fNXTHandle, PChar(filename), status);
  Result := status >= kStatusNoError;
  if Result then
  begin
    iFile_openForDataAppend(handle, status);
    Result := status >= kStatusNoError;
    if Result then
    begin
      size := iFile_getSize(handle, status);
      Result := status >= kStatusNoError;
    end;
    if not Result then
    begin
      status := kStatusNoError;
      iNXT_destroyFile(fNXTHandle, handle, status);
    end;
  end;
end;

function TFantomSpirit.SCOpenWrite(const filename: string;
  const size: cardinal; var handle: cardinal): boolean;
var
  status : integer;
begin
  Result := IsOpen;
  if not Result then Exit;
  status := kStatusNoError;
  handle := iNXT_createFile(fNXTHandle, PChar(filename), status);
  Result := status >= kStatusNoError;
  if Result then
  begin
    iFile_openForWrite(handle, size, status);
    Result := status >= kStatusNoError;
    if not Result then
    begin
      status := kStatusNoError;
      iNXT_destroyFile(fNXTHandle, handle, status);
    end;
  end;
end;

function TFantomSpirit.SCOpenWriteData(const filename: string;
  const size: cardinal; var handle: cardinal): boolean;
var
  status : integer;
begin
  Result := IsOpen;
  if not Result then Exit;
  status := kStatusNoError;
  handle := iNXT_createFile(fNXTHandle, PChar(filename), status);
  Result := status >= kStatusNoError;
  if Result then
  begin
    iFile_openForDataWrite(handle, size, status);
    Result := status >= kStatusNoError;
    if not Result then
    begin
      status := kStatusNoError;
      iNXT_destroyFile(fNXTHandle, handle, status);
    end;
  end;
end;

function TFantomSpirit.SCOpenWriteLinear(const filename: string;
  const size: cardinal; var handle: cardinal): boolean;
var
  status : integer;
begin
  Result := IsOpen;
  if not Result then Exit;
  status := kStatusNoError;
  handle := iNXT_createFile(fNXTHandle, PChar(filename), status);
  Result := status >= kStatusNoError;
  if Result then
  begin
    iFile_openForLinearWrite(handle, size, status);
    Result := status >= kStatusNoError;
    if not Result then
    begin
      status := kStatusNoError;
      iNXT_destroyFile(fNXTHandle, handle, status);
    end;
  end;
end;

function TFantomSpirit.SCRead(var handle: cardinal; var count: word;
  var buffer: PBRDataBuffer): boolean;
var
  status : integer;
begin
  Result := IsOpen;
  if not Result then Exit;
  status := kStatusNoError;
  iFile_read(handle, @buffer.Data[0], count, status);
  Result := status >= kStatusNoError;
end;

function TFantomSpirit.SCWrite(var handle: cardinal; const buffer: PBRDataBuffer;
  var count: word; const chkResponse: boolean): boolean;
var
  status : integer;
begin
  Result := IsOpen;
  if not Result then Exit;
  status := kStatusNoError;
  iFile_write(handle, @buffer.Data[0], count, status);
  Result := status >= kStatusNoError;
end;

function TFantomSpirit.SCCloseFile(var handle: cardinal; const chkResponse: boolean): boolean;
var
  status : integer;
begin
  Result := IsOpen;
  if not Result then Exit;
  status := kStatusNoError;
  iFile_close(handle, status);
  Result := status >= kStatusNoError;
  if Result then
  begin
    iNXT_destroyFile(FNXTHandle, handle, status);
    Result := status >= kStatusNoError;
  end;
end;

function TFantomSpirit.SCDeleteFile(var filename: string; const chkResponse: boolean): boolean;
var
  handle : cardinal;
  status : integer;
begin
  Result := IsOpen;
  if not Result then Exit;
  status := kStatusNoError;
  handle := iNXT_createFile(FNXTHandle, PChar(filename), status);
  Result := status >= kStatusNoError;
  if Result then
  begin
    iFile_remove(handle, status);
    Result := status >= kStatusNoError;
    status := kStatusNoError;
    iNXT_destroyFile(FNXTHandle, handle, status);
  end;
end;

function TFantomSpirit.SCFindFirstFile(var filename: string;
  var handle: cardinal; var filesize : cardinal): boolean;
var
  status : integer;
  buf : array[0..19] of Char;
begin
  Result := IsOpen;
  if not Result then Exit;
  status := kStatusNoError;
  handle := iNXT_createFileIterator(FNXTHandle, PChar(filename), status);
  Result := status >= kStatusNoError;
  if Result then
  begin
    iFileIterator_getName(handle, buf, status);
    filename := buf;
    status := kStatusNoError;
    filesize := iFileIterator_getSize(handle, status);
  end;
end;

function TFantomSpirit.SCFindNextFile(var handle: cardinal; var filename: string;
  var filesize : cardinal): boolean;
var
  status : integer;
  Buf : array[0..19] of Char;
begin
  Result := IsOpen;
  if not Result then Exit;
  status := kStatusNoError;
  iFileIterator_advance(handle, status);
  Result := status >= kStatusNoError;
  if Result then
  begin
    iFileIterator_getName(handle, buf, status);
    filename := buf;
    status := kStatusNoError;
    filesize := iFileIterator_getSize(handle, status);
  end
  else
  begin
    // destroy the iterator
    status := kStatusNoError;
    iNXT_destroyFileIterator(fNXTHandle, handle, status);
    handle := 0;
    filename := '';
  end;
end;

function TFantomSpirit.SCGetVersions(var protmin, protmaj, firmmin, firmmaj : byte): boolean;
var
  status : integer;
begin
  Result := IsOpen;
  if not Result then Exit;
  status := kStatusNoError;
  iNXT_getFirmwareVersion(fNXTHandle, protmaj, protmin, firmmaj, firmmin, status);
  Result := status >= kStatusNoError;
end;

function TFantomSpirit.SCCloseModuleHandle(var handle: cardinal; const chkResponse: boolean): boolean;
var
  status : integer;
begin
  Result := IsOpen;
  if not Result then Exit;
  status := kStatusNoError;
  iNXT_destroyModule(fNXTHandle, handle, status);
  Result := status >= kStatusNoError;
end;

function TFantomSpirit.SCBootCommand(const chkResponse: boolean): boolean;
var
  status : integer;
  resBuf : array[0..60] of Char;
begin
  Result := IsOpen;
  if not Result then Exit;
  status := kStatusNoError;
  iNXT_getResourceString(fNXTHandle, resBuf, status);
  Result := status >= kStatusNoError;
  if Result then
  begin
    iNXT_bootIntoFirmwareDownloadMode(resBuf, status);
    Result := status >= kStatusNoError;
  end;
end;

function TFantomSpirit.SCSetBrickName(const name: string; const chkResponse: boolean): boolean;
var
  status : integer;
begin
  Result := IsOpen;
  if not Result then Exit;
  status := kStatusNoError;
  iNXT_setName(fNXTHandle, PChar(name), status);
  Result := status >= kStatusNoError;
end;

function TFantomSpirit.SCGetDeviceInfo(var name: string;
  BTAddress : PByte; var BTSignal : Cardinal; var memFree : Cardinal): boolean;
var
  status : integer;
  buf : array[0..20] of Char;
begin
  Result := IsOpen;
  if not Result then Exit;
  status := kStatusNoError;
  iNXT_getDeviceInfo(fNXTHandle, buf, BTAddress, @BTSignal, memFree, status);
  name := buf;
  Result := status >= kStatusNoError;
end;

function TFantomSpirit.SCDeleteUserFlash(const chkResponse: boolean): boolean;
var
  status : integer;
begin
  Result := IsOpen;
  if not Result then Exit;
  status := kStatusNoError;
  iNXT_eraseUserFlash(fNXTHandle, status);
  Result := status >= kStatusNoError;
end;

function TFantomSpirit.SCBTFactoryReset(const chkResponse: boolean): boolean;
var
  status : integer;
begin
  Result := IsOpen;
  if not Result then Exit;
  status := kStatusNoError;
  iNXT_bluetoothFactoryReset(fNXTHandle, status);
  Result := status >= kStatusNoError;
end;

type
  TFileInfoRec = class
  public
    FileHandle : Cardinal;
    TotalSize : Cardinal;
    AvailableSize : Cardinal;
    Name : string;
  end;

function TFantomSpirit.UploadFile(const filename: string; const dir : string): boolean;
var
  handle : cardinal;
  size, totalSize, availableSize : Cardinal;
  MS : TMemoryStream;
  tmpFilename : string;
  NXTFileIteratorHandle : Cardinal;
  status, i : integer;
  buf : array[0..20] of Char;
  fileBuf : PByte;
  bEOFOnRead : boolean;
  FIR : TFileInfoRec;
  OL : TObjectList;
begin
  Result := IsOpen;
  if not Result then Exit;
  // upload means from NXT to PC
  OL := TObjectList.Create;
  try
    status := kStatusNoError;
    NXTFileIteratorHandle := iNXT_createFileIterator(fNXTHandle, PChar(filename), status);
    Result := status >= kStatusNoError;
    if Result then
    begin
      while status >= kStatusNoError do
      begin
        iFileIterator_getName(NXTFileIteratorHandle, buf, status);
        tmpFilename := buf;
        status := kStatusNoError;
        totalSize := iFileIterator_getSize(NXTFileIteratorHandle, status);
        status := kStatusNoError;
        handle := iFileIterator_getFile(NXTFileIteratorHandle, status);
        status := kStatusNoError;
        availableSize := iFile_getAvailableSize(handle, status);
        // save the info for this file into our object list
        FIR := TFileInfoRec.Create;
        OL.Add(FIR);
        FIR.FileHandle    := handle;
        FIR.Name          := tmpFilename;
        FIR.TotalSize     := totalSize;
        FIR.AvailableSize := availableSize;
        // advance to the next file
        status := kStatusNoError;
        iFileIterator_advance(NXTFileIteratorHandle, status);
      end;
      status := kStatusNoError;
      iNXT_destroyFileIterator(fNXTHandle, NXTFileIteratorHandle, status);
      Result := OL.Count > 0;
      for i := 0 to OL.Count - 1 do
      begin
        FIR := TFileInfoRec(OL.Items[i]);
        tmpFilename := FIR.Name;
        handle      := FIR.FileHandle;
        size        := FIR.TotalSize - FIR.AvailableSize;
        status      := kStatusNoError;
        iFile_openForRead(handle, status);
        MS := TMemoryStream.Create;
        try
          GetMem(fileBuf, size);
          try
            FillChar(fileBuf^, size, 0);
            status := kStatusNoError;
            iFile_read(handle, fileBuf, size, status);
            bEOFOnRead := status = kStatusFWEndOfFile;
            Result := (status >= kStatusNoError) or bEOFOnRead;
            if Result then
              MS.Write(fileBuf^, size);
          finally
            FreeMem(fileBuf);
          end;
          // hmmm we may have a problem here.  If we encountered an EOF on
          // read then that means the file we are trying to upload is one of
          // those files which has been created using the syscall file io
          // functions and it's contents are less than its reported size.
          // In that case we need to discard what we just did and try to
          // read the file one byte at a time.
          if bEOFOnRead then
          begin
            status := kStatusNoError;
            iFile_close(handle, status); // close the file and reopen it
            status := kStatusNoError;
            iFile_openForRead(handle, status);
            Result := status >= kStatusNoError;
            MS.Clear; // empty the stream
            GetMem(fileBuf, 1);
            try
              FillChar(fileBuf^, 1, 0);
              while status >= kStatusNoError do
              begin
                iFile_read(handle, fileBuf, 1, status);
                if status >= kStatusNoError then
                  MS.Write(fileBuf^, 1);
              end;
            finally
              FreeMem(fileBuf);
            end;
          end;
          // now try to save the file
          if dir <> '' then
            tmpFilename := IncludeTrailingPathDelimiter(dir) + tmpFilename;
          if Result then
            MS.SaveToFile(tmpFilename);
        finally
          MS.Free;
        end;
        SCCloseFile(handle);
      end;
    end;
  finally
    OL.Free;
  end;
end;

function TFantomSpirit.ListFiles(const searchPattern: string; Files: TStrings): boolean;
var
  size : Cardinal;
  tmpfilename : string;
  NXTFileIteratorHandle : Cardinal;
  buf : array[0..20] of Char;
  status : integer;
begin
  Result := IsOpen;
  if not Result then Exit;
  status := kStatusNoError;
  NXTFileIteratorHandle := iNXT_createFileIterator(fNXTHandle, PChar(searchPattern), status);
  Result := status >= kStatusNoError;
  while status >= kStatusNoError do
  begin
    iFileIterator_getName(NXTFileIteratorHandle, buf, status);
    tmpFilename := buf;
    size := iFileIterator_getSize(NXTFileIteratorHandle, status);
    Files.Add(tmpfilename + '=' + IntToStr(size));
    Result := status >= kStatusNoError;
    iFileIterator_advance(NXTFileIteratorHandle, status);
  end;
  status := kStatusNoError;
  iNXT_destroyFileIterator(fNXTHandle, NXTFileIteratorHandle, status);
end;

function TFantomSpirit.ListModules(const searchPattern: string;
  Modules: TStrings): boolean;
var
  size, mID, NXTModuleIteratorHandle, handle : Cardinal;
  buf : array[0..20] of Char;
  status : integer;
  iosize : Word;
  tmpname : string;
begin
  Result := IsOpen;
  if not Result then Exit;
  status := kStatusNoError;
  NXTModuleIteratorHandle := iNXT_createModuleIterator(fNXTHandle, PChar(searchPattern), status);
  Result := status >= kStatusNoError;
  while status >= kStatusNoError do
  begin
    handle := iModuleIterator_getModule(NXTModuleIteratorHandle, status);
    iModule_getName(handle, buf, status);
    tmpname := buf;
    status := kStatusNoError;
    iosize := iModule_getIOMapSize(handle, status);
    status := kStatusNoError;
    mID    := iModule_getModuleID(handle, status);
    status := kStatusNoError;
    size   := iModule_getModuleSize(handle, status);
    Modules.Add(Format('%s=%d, %d, %d', [tmpname, mID, size, iosize]));
    status := kStatusNoError;
    iNXT_destroyModule(fNXTHandle, handle, status);
    status := kStatusNoError;
    iModuleIterator_advance(NXTModuleIteratorHandle, status);
  end;
  status := kStatusNoError;
  iNXT_destroyModuleIterator(fNXTHandle, NXTModuleIteratorHandle, status);
end;

function TFantomSpirit.DownloadFile(const filename: string;
  const filetype: TPBRFileType): boolean;
var
  MS : TMemoryStream;
begin
  Result := IsOpen;
  if not Result then Exit;
  // download means from PC to NXT
  Result := FileExists(filename);
  if Result then
  begin
    MS := TMemoryStream.Create;
    try
      MS.LoadFromFile(filename);
      Result := DownloadStream(MS, filename, filetype);
    finally
      MS.Free;
    end;
  end;
end;

function TFantomSpirit.TransferFirmware(aStream : TStream) : boolean;
var
  size : Cardinal;
  resBuf : array[0..255] of Char;
  status : integer;
  buf : PByte;
  elapsedTime : Cardinal;
  bStop : boolean;
  cur, i : integer;
const
  K_SEC = 1000;
  MaximumWait = 15*K_SEC; // 15 seconds
  K_STEPS = 30;
begin
  Result := IsOpen;
  size := aStream.Size;
  bStop := False;
  status := kStatusNoError;
  cur := 0;
  DoDownloadStatus(cur, K_STEPS, bStop);
  if bStop then begin
    Result := False;
    Exit;
  end;
  if Result then
  begin
    // if we could open the NXT then it isn't in firmware download mode
    iNXT_getResourceString(fNXTHandle, resBuf, status);
    Result := status >= kStatusNoError;
    if Result then
    begin
      iNXT_bootIntoFirmwareDownloadMode(resBuf, status);
      Result := status >= kStatusNoError;
      if Result then
        destroyNXT(fNXTHandle, status);
    end;
    inc(cur);
    DoDownloadStatus(cur, K_STEPS, bStop);
    if bStop then begin
      Result := False;
      Exit;
    end;
  end;
  // the device should now be in firmware download mode
  elapsedTime := 0;
  repeat
    SysUtils.Sleep(K_SEC);
    inc(elapsedTime, K_SEC);
    status := kStatusNoError;
    iNXT_findDeviceInFirmwareDownloadMode(resBuf, status);
    inc(cur);
    DoDownloadStatus(cur, K_STEPS, bStop);
    if bStop then begin
      Result := False;
      Exit;
    end;
  until (status >= kStatusNoError) or (elapsedTime >= MaximumWait);
  cur := 16;
  DoDownloadStatus(cur, K_STEPS, bStop);
  if bStop then begin
    Result := False;
    Exit;
  end;
  // now download the firmware
  if status >= kStatusNoError then
  begin
    fNXTHandle := createNXT(resBuf, status, 0);
    inc(cur);
    DoDownloadStatus(cur, K_STEPS, bStop);
    if bStop then begin
      Result := False;
      Exit;
    end;
    GetMem(buf, size);
    try
      aStream.Position := 0; // start at the beginning
      aStream.Read(buf^, size);
      status := kStatusNoError;
      iNXT_downloadFirmware(fNXTHandle, buf, size, status);
      inc(cur);
      DoDownloadStatus(cur, K_STEPS, bStop);
      if bStop then begin
        Result := False;
        Exit;
      end;
    finally
      FreeMem(buf);
    end;
    for i := 0 to 9 do begin
      SysUtils.Sleep(K_SEC);
      inc(cur);
      DoDownloadStatus(cur, K_STEPS, bStop);
      if bStop then begin
        Result := False;
        Exit;
      end;
    end;
    Close;
    Result := status >= kStatusNoError;
  end;
end;

function TFantomSpirit.DownloadStream(aStream: TStream; const dest : string;
  const filetype: TPBRFileType): boolean;
var
  size : Cardinal;
  handle : cardinal;
  status : integer;
  buf : PByte;
  nxtFilename, delname : string;
begin
  Result := IsOpen;
  if not FantomAPILoaded then Exit;
  status := kStatusNoError;
  if filetype = nftFirmware then
  begin
    Result := TransferFirmware(aStream);
  end
  else
  begin
    if not Result then Exit;
    size := aStream.Size;
    // download means from PC to NXT
    // make destination filename a valid NXT filename (15.3)
    nxtFilename := MakeValidNXTFilename(dest);
    delname := nxtFilename;
    SCDeleteFile(delname, True);
    if filetype in [nftProgram, nftGraphics] then
      Result := SCOpenWriteLinear(nxtFilename, size, handle)
    else if filetype = nftData then
      Result := SCOpenWriteData(nxtFilename, size, handle)
    else
      Result := SCOpenWrite(nxtFilename, size, handle);
    if Result then
    begin
      GetMem(buf, size);
      try
        aStream.Position := 0; // start at the beginning
        aStream.Read(buf^, size);
        status := kStatusNoError;
        iFile_write(handle, buf, size, status);
        Result := status >= kStatusNoError;
      finally
        FreeMem(buf);
      end;
      Result := SCCloseFile(handle) and Result;
    end;
  end;
end;

function TFantomSpirit.SCPollCommandLen(const bufNum : byte; var count: byte): boolean;
var
  status : integer;
begin
  Result := IsOpen;
  if not Result then Exit;
  count := iNXT_pollAvailableLength(fNXTHandle, bufNum, status);
  Result := status < kStatusNoError;
  if not Result then
    count := 0;
end;

function TFantomSpirit.SCPollCommand(const bufNum: byte; var count: byte;
  var buffer: PBRDataBuffer): boolean;
var
  dataBuffer : PByte;
  status : Integer;
begin
  Result := IsOpen;
  if not Result then Exit;
  if count > 64 then
    count := 64;
  dataBuffer := @buffer.Data[0];
  count := iNXT_readBufferData(fNXTHandle, dataBuffer, bufNum, count, status);
  Result := status >= kStatusNoError;
  if not Result then
    count := 0;
end;

function TFantomSpirit.SCWriteIOMap(var ModID: Cardinal;
  const Offset: Word; var count: Word; const buffer: PBRDataBuffer;
  chkResponse : Boolean): boolean;
var
  status : integer;
  mh : Cardinal;
  modName : string;
begin
  Result := IsOpen;
  if not Result then Exit;
  status := kStatusNoError;
  modName := NXTModuleIDToName(ModID);
  mh := iNXT_createModule(fNXTHandle, PChar(modName), ModID, 0, 0, status);
  if status >= kStatusNoError then
  begin
    // found the correct module
    status := kStatusNoError;
    iModule_writeIOMap(mh, Offset, count, @(buffer.Data), status);
    // now destroy it
    status := kStatusNoError;
    iNXT_destroyModule(fNXTHandle, mh, status);
  end;
end;

function TFantomSpirit.SCReadIOMap(var ModID: Cardinal;
  const Offset: Word; var Count: Word; var buffer: PBRDataBuffer): boolean;
var
  status : integer;
  mh : Cardinal;
  modName : string;
begin
  Result := IsOpen;
  if not Result then Exit;
  status := kStatusNoError;
  modName := NXTModuleIDToName(ModID);
  mh := iNXT_createModule(fNXTHandle, PChar(modName), ModID, 0, 0, status);
  if status >= kStatusNoError then
  begin
    // found the correct module
    status := kStatusNoError;
    FillChar(buffer.Data[0], kNXT_MaxBytes, 0);
    iModule_readIOMap(mh, Offset, Count, @(buffer.Data), status);
    Result := status = kStatusNoError;
    // now destroy it
    status := kStatusNoError;
    iNXT_destroyModule(fNXTHandle, mh, status);
  end;
end;

function TFantomSpirit.SCFindNextModule(var Handle: cardinal;
  var ModName: string; var ModID, ModSize: Cardinal;
  var IOMapSize: Word): boolean;
var
  status : integer;
  Buf : array[0..19] of Char;
  mh : cardinal;
begin
  Result := IsOpen;
  if not Result then Exit;
  status := kStatusNoError;
  iModuleIterator_advance(Handle, status);
  Result := status >= kStatusNoError;
  if Result then
  begin
    mh := iModuleIterator_getModule(Handle, status);
    status := kStatusNoError;
    iModule_getName(mh, buf, status);
    ModName   := buf;
    status := kStatusNoError;
    ModSize   := iModule_getModuleSize(mh, status);
    status := kStatusNoError;
    ModID     := iModule_getModuleID(mh, status);
    status := kStatusNoError;
    IOMapSize := iModule_getIOMapSize(mh, status);
    status := kStatusNoError;
    iNXT_destroyModule(FNXTHandle, mh, status);
  end
  else
  begin
    // destroy the iterator
    status := kStatusNoError;
    iNXT_destroyModuleIterator(fNXTHandle, Handle, status);
    handle := 0;
    ModName := '';
  end;
end;

function TFantomSpirit.SCFindFirstModule(var ModName: string; var Handle: cardinal;
  var ModID, ModSize: Cardinal; var IOMapSize: Word): boolean;
var
  status : integer;
  buf : array[0..19] of Char;
  mh : cardinal;
begin
  Result := IsOpen;
  if not Result then Exit;
  status := kStatusNoError;
  Handle := iNXT_createModuleIterator(FNXTHandle, PChar(ModName), status);
  Result := status >= kStatusNoError;
  if Result then
  begin
    mh := iModuleIterator_getModule(Handle, status);
    status := kStatusNoError;
    iModule_getName(mh, buf, status);
    ModName   := buf;
    status := kStatusNoError;
    ModSize   := iModule_getModuleSize(mh, status);
    status := kStatusNoError;
    ModID     := iModule_getModuleID(mh, status);
    status := kStatusNoError;
    IOMapSize := iModule_getIOMapSize(mh, status);
    status := kStatusNoError;
    iNXT_destroyModule(FNXTHandle, mh, status);
  end;
end;

function TFantomSpirit.dcBuffer: PByte;
begin
  Result := @dcResponse[0];
end;

function BytesToCardinal(b1 : byte; b2 : byte = 0; b3 : byte = 0; b4 : Byte = 0) : Cardinal;
begin
  Result := Cardinal(b1) + (Cardinal(b2) shl 8) + (Cardinal(b3) shl 16) + (Cardinal(b4) shl 24);
end;

function TFantomSpirit.GetReplyByte(index: integer): Byte;
const
  DCReplyOffset = 2;
begin
  Result := dcResponse[index + DCReplyOffset];

end;

function TFantomSpirit.GetReplyCardinal(index: integer): Cardinal;
begin
  Result := BytesToCardinal(GetReplyByte(index),
                            GetReplyByte(index+1),
                            GetReplyByte(index+2),
                            GetReplyByte(index+3));
end;

function TFantomSpirit.GetReplyWord(index: integer): Word;
begin
  Result := Word(BytesToCardinal(GetReplyByte(index), GetReplyByte(index+1)));
end;

function TFantomSpirit.ListBricks(Bricks: TStrings): boolean;
var
  nih : Cardinal;
  status, status2 : integer;
  resNamePC : array[0..255] of Char;
  resName, alias, tmp : string;
begin
  Result := False;
  Bricks.Clear;
  if FantomAPILoaded then
  begin
    resName := '';
    status := kStatusNoError;
    // use Fantom API to obtain a handle to an NXT on either USB or bluetooth
    nih := createNXTIterator(1, BluetoothSearchTimeout, status);
    while status >= kStatusNoError do
    begin
      status2 := kStatusNoError;
      iNXTIterator_getName(nih, resNamePC, status2);
      resName := AnsiUpperCase(resNamePC);
      // if the resource name starts with BTH then grab the beginning of
      // the resource name and use it as the alias
      // if the resource name starts with USB then grab the end of the
      // resource name instead
      if Pos('BTH', resName) = 1 then
      begin
        tmp := Copy(resName, 6, MaxInt);
        alias := 'BTH::' + Copy(tmp, 1, Pos('::', tmp)-1);
      end
      else
      begin
        alias := Copy(resName, 23, MaxInt);
        System.Delete(alias, Length(alias)-4, 5);
      end;
//      alias := AnsiLowerCase(Copy(resName, 1, Pos('::', resName)-1));
      Bricks.Add(alias + '=' + resName);
      iNXTIterator_advance(nih, status);
    end;
    status := kStatusNoError;
    destroyNXTIterator(nih, status);
    // also look for bricks in firmware download mode
    status := kStatusNoError;
    iNXT_findDeviceInFirmwareDownloadMode(resNamePC, status);
    if status >= kStatusNoError then
    begin
      resName := AnsiUpperCase(resNamePC);
      alias := Copy(resName, 23, MaxInt);
      System.Delete(alias, Length(alias)-4, 5);
//      alias := AnsiLowerCase(Copy(resName, 1, Pos('::', resName)-1));
      Bricks.Add(alias + '=' + resName);
    end;
    Result := Bricks.Count > 0;
  end;
end;

function TFantomSpirit.GetDownloadWaitTime: Integer;
begin
  Result := 0;
end;

function TFantomSpirit.GetEEPROM(addr: Byte): Byte;
begin
  Result := 0;
end;

function TFantomSpirit.GetEEPROMBlock(idx: Integer): EEPROMBlock;
begin
// do nothing
end;

function TFantomSpirit.GetLinkLog: string;
begin
  Result := '';
end;

function TFantomSpirit.GetOmitHeader: Boolean;
begin
  Result := False;
end;

function TFantomSpirit.GetQuiet: Boolean;
begin
  Result := False;
end;

function TFantomSpirit.GetRCXFirmwareChunkSize: Integer;
begin
  Result := 200;
end;

function TFantomSpirit.GetRxTimeout: Word;
begin
  Result := 400;
end;

procedure TFantomSpirit.SetDownloadWaitTime(const Value: Integer);
begin
// do nothing
end;

procedure TFantomSpirit.SetEEPROM(addr: Byte; const Value: Byte);
begin
// do nothing
end;

procedure TFantomSpirit.SetOmitHeader(const Value: Boolean);
begin
// do nothing
end;

procedure TFantomSpirit.SetQuiet(const Value: Boolean);
begin
// do nothing
end;

procedure TFantomSpirit.SetRCXFirmwareChunkSize(const Value: Integer);
begin
// do nothing
end;

procedure TFantomSpirit.SetRxTimeout(const Value: Word);
begin
// do nothing
end;

function TFantomSpirit.AbsVar(aVar, aSrc, aNum: integer): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.AndVar(aVar, aSrc, aNum: integer): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.BrickAlive: boolean;
begin
  Result := Open;
end;

function TFantomSpirit.CalibrateEvent(enum, upper, lower,
  hysteresis: integer): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.CalibrateLightSensor: boolean;
begin
  Result := Open;
end;

function TFantomSpirit.ClearAllEvents: boolean;
begin
  Result := Open;
end;

function TFantomSpirit.ClearCounter(num: TCounterNumber): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.ClearSound: boolean;
begin
  Result := Open;
end;

function TFantomSpirit.ClearTachoCounter(aMotorList: Byte): boolean;
var
  i : integer;
begin
  Result := Open;
  if Result then
  begin
    for i := 0 to 2 do
    begin
      if (MotorBits[i] and aMotorList) = MotorBits[i] then
      begin
        Result := Result and ResetOutputPosition(i, False);
        if not Result then Break;
      end;
    end;
  end;
end;

function TFantomSpirit.ClearTimer(aNum: integer): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.DatalogNext(aSrc, aNum: integer): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.DecCounter(num: TCounterNumber): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.DeleteAllSubs: boolean;
begin
  Result := Open;
end;

function TFantomSpirit.DeleteAllTasks: boolean;
begin
  Result := Open;
end;

function TFantomSpirit.DeleteSub(aSub: integer): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.DeleteTask(aTask: integer): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.DivVar(aVar, aSrc, aNum: integer): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.DownloadMemoryMap: TStrings;
var
  SL : TStringList;
  i, p, id : integer;
  tmp : string;
begin
  fMemMap.Clear;
  SL := TStringList.Create;
  try
    fMemMap.Add('Files');
    fMemMap.Add('');
    if ListFiles('*.*', SL) then
    begin
      for i := 0 to SL.Count - 1 do
      begin
        fMemMap.Add(SL.Names[i]);
        fMemMap.Add(SL.ValueFromIndex[i]);
      end;
    end;
    SL.Clear;
    fMemMap.Add('');
    fMemMap.Add('');
    fMemMap.Add('Modules');
    fMemMap.Add('');
    if ListModules('*.*', SL) then
    begin
      for i := 0 to SL.Count - 1 do
      begin
        fMemMap.Add(SL.Names[i]);
        tmp := SL.ValueFromIndex[i];
        // tmp = moduleID, size, iosize
        p := Pos(',', tmp);
        id := StrToIntDef(Copy(tmp, 1, p-1), 0);
        Delete(tmp, 1, p);
        p := Pos(',', tmp);
        Delete(tmp, 1, p);
        fMemMap.Add(IntToStr(id)+'|'+tmp); // moduleID|iomap size
      end;
    end;
    fMemMap.Add('');
    fMemMap.Add('');
    i := SCFreeMemory;
    fMemMap.Add('Free Memory');
    fMemMap.Add(IntToStr(i));
  finally
    SL.Free;
  end;
  Result := fMemMap;
end;

function TFantomSpirit.Drive(aLeft, aRight: integer): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.GetCounterValue(aNum: integer): integer;
begin
  Result := Poll(kRCX_CounterType, aNum);
end;

function TFantomSpirit.GetMessageValue(aNum: integer): integer;
begin
  Result := Poll(kRCX_MessageType, aNum);
end;

function TFantomSpirit.GetOutputStatus(aOut: integer): integer;
var
  res : boolean;
  mode, regmode, runstate : byte;
  power, turnratio : integer;
  tacholimit : cardinal;
  tachocount, blocktachocount, rotationcount : integer;
  bBrake : boolean;
begin
  Result := 0;
  res := DCGetOutputState(aOut, power, mode, regmode, turnratio, runstate,
    tacholimit, tachocount, blocktachocount, rotationcount);
  if res then
  begin
    // what is the power?
    fMotorOn[aOut]      := ((mode and OUT_MODE_MOTORON) = OUT_MODE_MOTORON) and
                           ((runstate and OUT_RUNSTATE_RUNNING) = OUT_RUNSTATE_RUNNING) and
                           (power <> 0);
    bBrake              := (mode and OUT_MODE_BRAKE) = OUT_MODE_BRAKE;
    // if the power is 0 and fMotorOn[aOut] is false then do not change
    // the stored power level
    if fMotorOn[aOut] then
      fMotorPower[aOut] := abs(power div 14) mod 8;
    fMotorForward[aOut] := power >= 0;
    Result := fMotorPower[aOut]; // bits 0..2
    if fMotorForward[aOut] then
      Result := Result + (1 shl 3); // bit 3
    if bBrake then
      Result := Result + (1 shl 6); // bit 6
    if fMotorOn[aOut] then
      Result := Result + (1 shl 7); // bit 7
  end;
end;

function TFantomSpirit.GetTimerValue(aNum: integer): integer;
begin
  Result := Poll(kRCX_TimerType, aNum);
end;

function TFantomSpirit.GetVariableValue(aVar: integer): integer;
begin
  Result := Poll(kRCX_VariableType, aVar);
end;

function TFantomSpirit.IncCounter(num: TCounterNumber): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.MonitorIR(aSeconds: integer): TStrings;
begin
  Result := fMemData;
end;

function TFantomSpirit.MulVar(aVar, aSrc, aNum: integer): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.OnWait(aMotorList: Byte; aNum: integer; aTime: Byte): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.OnWaitDifferent(aMotorList: Byte; aNum0, aNum1,
  aNum2: integer; aTime: Byte): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.OrVar(aVar, aSrc, aNum: integer): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.PlaySystemSound(aSnd: byte): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.Poll(aSrc, aNum: integer): integer;
var
  valid, calibrated, res : boolean;
  stype, smode : byte;
  raw, normalized : word;
  scaled, calvalue : smallint;
  modID : Cardinal;
  count : Word;
  buffer : PBRDataBuffer;
  power, turnratio, tachocount, blocktachocount, rotationcount : integer;
  mode, regmode, runstate : byte;
  tacholimit : cardinal;
  protmin, protmaj, firmmin, firmmaj : byte;
begin
  Result := 0;
  case aSrc of
    kRCX_ConstantType : begin
      Result := aNum;
    end;
    kRCX_OutputStatusType : begin
      Result := GetOutputStatus(aNum);
    end;
    kRCX_RandomType : begin
      Result := Random(aNum);
    end;
    kRCX_TachCounterType : begin
      res := DCGetOutputState(aNum, power, mode, regmode, turnratio, runstate,
        tacholimit, tachocount, blocktachocount, rotationcount);
      if res then
        Result := rotationcount;
    end;
    kRCX_TimerType : begin
      // IOMapRead CommandOffsetTick
      modID := kNXT_ModuleCmd;
      count := 4;
      res := SCReadIOMap(modID, CommandOffsetTick, count, buffer);
      if res then
      begin
        Result := BytesToCardinal(buffer.Data[0], buffer.Data[1], buffer.Data[2], buffer.Data[3]);
      end;
    end;
    kRCX_BatteryLevelType : begin
      Result := BatteryLevel;
    end;
    kRCX_FirmwareVersionType : begin
      if SCGetVersions(protmin, protmaj, firmmin, firmmaj) then
      begin
        // 1.03 => 1030
        Result := (firmmaj * 100) + firmmin;
      end;
    end;
    kRCX_InputTypeType, kRCX_InputModeType,
    kRCX_InputValueType, kRCX_InputRawType,
    kRCX_InputBooleanType : begin
      // get input type or input mode
      res := DCGetInputValues(aNum, valid, calibrated, stype, smode,
        raw, normalized, scaled, calvalue);
      if res then
      begin
        if aSrc = kRCX_InputTypeType then
        begin
          fSensorType[aNum] := stype;
          Result := stype;
        end
        else if aSrc = kRCX_InputModeType then
        begin
          fSensorMode[aNum] := smode;
          Result := smode;
        end
        else if aSrc = kRCX_InputValueType then
        begin
          Result := scaled; // normalized?
        end
        else if aSrc = kRCX_InputRawType then
        begin
          Result := raw;
        end
        else if aSrc = kRCX_InputBooleanType then
        begin
          Result := scaled;
        end;
      end;
    end;
  end;
end;

function TFantomSpirit.PollEEPROM(block: Integer): TStrings;
var
  i, j, start, finish, status : Integer;
  mh, Offset, cnt : Cardinal;
  buf : PByte;
const
  MAX_BLOCK  = $803;
  BLOCK_SIZE = $10;
begin
  Open;
  Result := fMemData;
  fMemData.Clear;
  start := block;
  finish := block;
  if block < 0 then
  begin
    start := 0;
    finish := MAX_BLOCK;
  end
  else if block > MAX_BLOCK then
  begin
    start  := MAX_BLOCK;
    finish := MAX_BLOCK;
  end;
  mh := iNXT_createModule(fNXTHandle, PChar(kNXT_ModuleCmdName), kNXT_ModuleCmd, 0, 0, status);
  // are we in a position to poll memory?
  if status >= kStatusNoError then
  begin
    GetMem(buf, BLOCK_SIZE);
    try
      for j := start to finish do
      begin
        status := kStatusNoError;
        Offset := j*BLOCK_SIZE;
        cnt := iModule_readIOMap(mh, Offset, BLOCK_SIZE, buf, status);
        if status >= kStatusNoError then
        begin
          for i := 0 to cnt - 1 do
          begin
            fMemData.Add(Format('%d', [PByte(PChar(buf) + i)^]));
          end;
        end
        else
          Break;
      end;
    finally
      FreeMem(buf);
    end;
    // now destroy the module handle
    status := kStatusNoError;
    iNXT_destroyModule(fNXTHandle, mh, status);
  end;
end;

function TFantomSpirit.PollMemory(address, size: Integer): TStrings;
var
  status, cnt : integer;
  mh, Offset : Cardinal;
  amt, i : Integer;
  buf : PByte;
const
//  CHUNK = $FFFF;
  CHUNK = $36;
begin
  Open;
  fMemData.Clear;
  Result := fMemData;
  mh := iNXT_createModule(fNXTHandle, PChar(kNXT_ModuleCmdName), kNXT_ModuleCmd, 0, 0, status);
  // are we in a position to poll memory?
  if status >= kStatusNoError then
  begin
    // found the Command module now use it
    Offset := address;
    amt := 0;
    GetMem(buf, CHUNK);
    try
      while (amt < size) and (status >= kStatusNoError) do
      begin
        status := kStatusNoError;
        cnt := Min(CHUNK, size-amt);
        cnt := iModule_readIOMap(mh, Offset, cnt, buf, status);
        if status >= kStatusNoError then
        begin
          for i := 0 to cnt - 1 do
          begin
            fMemData.Add(Format('%d', [PByte(PChar(buf) + i)^]));
          end;
        end;
        inc(amt, CHUNK);
        inc(Offset, CHUNK);
      end;
    finally
      FreeMem(buf);
    end;
    // now destroy the module handle
    status := kStatusNoError;
    iNXT_destroyModule(fNXTHandle, mh, status);
  end;
end;

function TFantomSpirit.PowerDownTime(aTime: integer): boolean;
var
  modID : Cardinal;
  count : Word;
  buffer : PBRDataBuffer;
begin
  Result := Open;
  if not Result then Exit;
  modID := kNXT_ModuleUI;
  count := 1;
  buffer.Data[0] := Byte(abs(aTime) mod $FF);
  Result := SCWriteIOMap(modID, UIOffsetSleepTimeout, count, buffer);
end;

function TFantomSpirit.PrepareBrick: boolean;
begin
  Result := Open;
end;

function TFantomSpirit.Scout(bPower: boolean): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.Scout(aVal: integer): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.ScoutRules(motion: TScoutMotion; touch: TScoutTouch;
  light: TScoutLight; time: TScoutScale; fx: TScoutEffects): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.ScoutSound(bSoundEnable, bSoundOff: boolean;
  aNum: TSoundSetNumber): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.SelectDisplay(aSrc, aNumber: integer): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.SelectProgram(aProg: integer): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.SendMessage(aMsg: integer): boolean;
begin
  Result := MessageWrite(0, IntToStr(aMsg));
end;

function TFantomSpirit.SendRawCommand(aCmd: string; bRetry: boolean): string;
begin
  Result := '';
end;

function TFantomSpirit.SendRemote(aEvent: string; aRepeat: integer): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.SendRemote(aEvent: Word; aRepeat: integer): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.SendUARTData(start, size: integer): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.SendVLL(aSrc, aNum: integer): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.SetCounterLimit(num: TCounterNumber; src: TTCSource;
  val: integer): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.SetDatalog(aSize: integer): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.SetEvent(enum, snum, etype: integer): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.SetFeedback(src, val: integer): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.SetGlobalDirection(motors: TMotorsNum; action: TGlobalDirAction): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.SetGlobalOutput(motors: TMotorsNum; action: TGlobalOutAction): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.SetLight(bOn: boolean): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.SetLightSensorBlinkTime(src: TLSSource; val: TBlinkTimeValue): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.SetLightSensorHysteresis(src: TLSSource; val: TThresholdValue): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.SetLightSensorLowerThreshold(src: TLSSource; val: TThresholdValue): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.SetLightSensorUpperThreshold(src: TLSSource; val: TThresholdValue): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.SetMaxPower(motors: TMotorsNum; src, num: integer): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.SetSourceValue(aDestSrc, aDestVal, aOrigSrc: Byte; aOrigVal: Smallint): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.SetTimerLimit(num: TTimerNumber; src: TTCSource; val: integer): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.SetVar(aVar, aSrc, aNum: integer): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.SetWatch(aTime: string): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.SetWatch(aHrs, aMins: integer): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.SgnVar(aVar, aSrc, aNum: integer): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.StartTask(aTask: integer): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.StopAllTasks: boolean;
begin
  Result := Open;
end;

function TFantomSpirit.StopTask(aTask: integer): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.SubVar(aVar, aSrc, aNum: integer): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.SumVar(aVar, aSrc, aNum: integer): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.TowerExists: boolean;
begin
  Result := Open;
end;

function TFantomSpirit.TransmitPower(aLevel: TTransmitLevel): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.UnlockBrick: string;
begin
  Open;
  Result := '';
end;

function TFantomSpirit.UnlockFirmware: boolean;
begin
  Result := Open;
end;

function TFantomSpirit.UploadDatalog(bVerbose: boolean): TStrings;
begin
  Open;
  Result := fDataLog;
end;

function TFantomSpirit.UploadDatalog(aFrom, aSize: integer): TStrings;
begin
  Open;
  Result := fDataLog;
end;

function TFantomSpirit.Version(var rom, ram: Cardinal): boolean;
var
  protmin, protmaj, firmmin, firmmaj : byte;
begin
  Result := SCGetVersions(protmin, protmaj, firmmin, firmmaj);
  rom := (protmin shl 8) + (protmaj shl 16);
  ram := (firmmin shl 0) + (firmmaj shl 16);
end;

function TFantomSpirit.ViewSourceValue(prec, src, value: integer): boolean;
begin
  Result := Open;
end;

function TFantomSpirit.GetUseBT: Boolean;
begin
  Result := fUseBT or (Pos('BTH', fResPort) > 0);
  if Result then
    fUseBT := True;
end;

procedure TFantomSpirit.InitializeResourceNames;
var
  SL : TStringList;
  name : string;
begin
  SL := TStringList.Create;
  try
    ListBricks(SL);
    name := GetInitFilename;
    ForceDirectories(ExtractFilePath(name));
    SL.SaveToFile(name);
  finally
    SL.Free;
  end;
end;

function TFantomSpirit.SCFreeMemory: integer;
var
  BTAddr : PByte;
  memFree, BTSig : Cardinal;
  nxtName : string;
begin
  Result := 0;
  GetMem(BTAddr, 7);
  try
    if SCGetDeviceInfo(nxtName, BTAddr, BTSig, memFree) then
    begin
      Result := memFree;
    end;
  finally
    FreeMem(BTAddr);
  end;
end;

function TFantomSpirit.SCRenameFile(const old, new: string;
  const chkResponse: boolean): boolean;
var
  cmd : TNxtCmd;
  status : integer;
  b : byte;
  buf, readBuf : PByte;
  bufLen : Cardinal;
begin
  Result := Open;
  if not Result then Exit;
  cmd := TNxtCmd.Create;
  try
    if chkResponse then
      b := kNXT_SystemCmd
    else
      b := kNXT_SystemCmdNoReply;
    cmd.MakeCmdRenameFile(b, new, old);
//    cmd.MakeCmdRenameFile(b, old, new);
    buf := cmd.GetBody;
    bufLen := cmd.GetLength;
    iNXT_write(fNXTHandle, buf, bufLen, status);
    // now read the response
    if (status >= kStatusNoError) and chkResponse then
    begin
      GetMem(readBuf, 44);
      try
        iNXT_read(fNXTHandle, readBuf, 44, status);
      finally
        FreeMem(readBuf);
      end;
    end;
    Result := status >= kStatusNoError;
  finally
    cmd.Free;
  end;
end;

procedure TFantomSpirit.SetResourcePort(const name: string);
var
  sl : TStringList;
  i : integer;
  fname : string;
begin
  fResPort := name;
  sl := TStringList.Create;
  try
    fname := GetInitFilename;
    if FileExists(fname) then
    begin
      sl.LoadFromFile(fname);
      for i := 0 to sl.Count - 1 do
      begin
        if Pos(fResPort, sl[i]) > 0 then
          Exit;
      end;
      // if we get here then we need to add this resource string to
      // our nxt.dat file
      sl.Add('alias' + IntToStr(sl.Count) + '=' + fResPort);
      sl.SaveToFile(fname);
    end;
  finally
    sl.Free;
  end;
end;

procedure TFantomSpirit.LookupResourceName;
var
  name : string;
  i : integer;
begin
  // lookup a resource string given this port name
  if fResourceNames.Count = 0 then
  begin
    name := GetInitFilename;
    if FileExists(name) then
    begin
      fResourceNames.LoadFromFile(name);
    end;
  end;
  i := fResourceNames.IndexOfName(fPort);
  if i <> -1 then
    fResPort := fResourceNames.Values[fPort];
end;

end.