/** \file NBCCommon.h
 * \brief Constants and macros common to both NBC and NXC
 *
 * NBCCommon.h contains declarations for the NBC and NXC NXT API functions.
 *
 * License:
 *
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
 * The Initial Developer of this code is John Hansen.
 * Portions created by John Hansen are Copyright (C) 2009-2010 John Hansen.
 * All Rights Reserved.
 *
 * ----------------------------------------------------------------------------
 *
 * \author John Hansen (bricxcc_at_comcast.net)
 * \date 2010-01-13
 * \version 42
 */

#ifndef NBCCOMMON_H
#define NBCCOMMON_H

/** @defgroup OutputPortConstants Output port constants.
 * Output port constants are used when calling motor control API functions.
 * @{
 */
#define OUT_A   0x00 /*!< Output port A */
#define OUT_B   0x01 /*!< Output port B */
#define OUT_C   0x02 /*!< Output port C */
#define OUT_AB  0x03 /*!< Output ports A and B */
#define OUT_AC  0x04 /*!< Output ports A and C */
#define OUT_BC  0x05 /*!< Output ports B and C */
#define OUT_ABC 0x06 /*!< Output ports A, B, and C */
/** @} */  // end of OutputPortConstants group

/** @defgroup InputPortConstants Input port constants.
 * Input port constants are used when calling sensor control API functions.
 * @{
 */
#define IN_1 0x00 /*!< Input port 1 */
#define IN_2 0x01 /*!< Input port 2 */
#define IN_3 0x02 /*!< Input port 3 */
#define IN_4 0x03 /*!< Input port 4 */
/** @} */  // end of InputPortConstants group

#define TRUE  1 /*!< A true value */
#define FALSE 0 /*!< A false value */

#define NA 0xFFFF /*!< The specified argument does not apply (aka unwired) */

/** @defgroup PIDConstants PID constants.
 * PID constants are for adjusting the Proportional, Integral, and Derivative
 * motor controller parameters.
 * \sa RotateMotorExPID(), RotateMotorPID(), OnFwdExPID(), OnRevExPID(),
 * \sa OnFwdRegExPID(), OnRevRegExPID(), OnFwdRegPID(), OnRevRegPID(),
 * \sa OnFwdSyncExPID(), OnRevSyncExPID(), OnFwdSyncPID(), OnRevSyncPID()
 * @{
 */
#define PID_0   0 /*!< PID zero */
#define PID_1  32 /*!< PID one */
#define PID_2  64 /*!< PID two */
#define PID_3  96 /*!< PID three */
#define PID_4 128 /*!< PID four */
#define PID_5 160 /*!< PID five */
#define PID_6 192 /*!< PID six */
#define PID_7 224 /*!< PID seven */
/** @} */  // end of PIDConstants group

#ifdef __ENHANCED_FIRMWARE
// array operation definitions
#define OPARR_SUM    0x00 /*!< */
#define OPARR_MEAN   0x01 /*!< */
#define OPARR_SUMSQR 0x02 /*!< */
#define OPARR_STD    0x03 /*!< */
#define OPARR_MIN    0x04 /*!< */
#define OPARR_MAX    0x05 /*!< */
#define OPARR_SORT   0x06 /*!< */
#endif

#if __FIRMWARE_VERSION > 107
#define PI 3.141593               /*!< A constant for PI */
#define RADIANS_PER_DEGREE PI/180 /*!< Converting from degrees to radians */
#define DEGREES_PER_RADIAN 180/PI /*!< Converting from radians to degrees */
#endif

/** @defgroup OutUFConstants Output port update flag constants.
 * Use these constants to specify which motor values need to be updated.
 * Update flag constants can be combined with bitwise OR.
 * \sa SetOutput()
 * @{
 */
#define UF_UPDATE_MODE                 0x01 /*!< Update the motor mode */
#define UF_UPDATE_SPEED                0x02 /*!< Update the motor speed */
#define UF_UPDATE_TACHO_LIMIT          0x04 /*!< Update the motor tachometer limit */
#define UF_UPDATE_RESET_COUNT          0x08 /*!< Reset the internal tachometer counter */
#define UF_UPDATE_PID_VALUES           0x10 /*!< Update the motor PID values */
#define UF_UPDATE_RESET_BLOCK_COUNT    0x20 /*!< Reset the NXT-G block tachometer counter */
#define UF_UPDATE_RESET_ROTATION_COUNT 0x40 /*!< Reset the rotation counter */
#define UF_PENDING_UPDATES             0x80 /*!< Are there any pending motor updates? */
/** @} */  // end of OutUFConstants group

/** @defgroup TachoResetConstants Tachometer counter reset flags.
 * Use these constants to specify which of the three tachometer counters
 * should be reset. Reset constants can be combined with bitwise OR.
 * \sa OnFwdEx(), OnRevEx(), etc...
 * @{
 */
#define RESET_NONE           0x00 /*!< No counters will be reset */
#define RESET_COUNT          0x08 /*!< Reset the internal tachometer counter */
#define RESET_BLOCK_COUNT    0x20 /*!< Reset the NXT-G block tachometer counter */
#define RESET_ROTATION_COUNT 0x40 /*!< Reset the rotation counter */
#define RESET_BLOCKANDTACHO  0x28 /*!< Reset both the internal counter and the NXT-G block counter */
#define RESET_ALL            0x68 /*!< Reset all three tachometer counters */
/** @} */  // end of TachoResetConstants group

/** @defgroup OutModeConstants Output port mode constants.
 * Use these constants to configure the desired mode for the
 * specified motor(s): coast, motoron, brake, or regulated. Mode constants
 * can be combined with bitwise OR.
 * \sa SetOutput()
 * @{
 */
#define OUT_MODE_COAST     0x00 /*!< Set motor mode to coast */
#define OUT_MODE_MOTORON   0x01 /*!< Set motor mode to motoron */
#define OUT_MODE_BRAKE     0x02 /*!< Set motor mode to brake */
#define OUT_MODE_REGULATED 0x04 /*!< Set motor mode to regulated */
#define OUT_MODE_REGMETHOD 0xF0 /*!< Mask for unimplemented regulation mode */
/** @} */  // end of OutModeConstants group

/** @defgroup OutOptionConstants Output port option constants.
 * Use these constants to configure the desired options for the
 * specified motor(s): hold at limit and ramp down to limit. Option constants
 * can be combined with bitwise OR.
 * \sa SetOutput()
 * @{
 */
#if defined(__ENHANCED_FIRMWARE) && (__FIRMWARE_VERSION > 107)
#define OUT_OPTION_HOLDATLIMIT     0x10 /*!< */
#define OUT_OPTION_RAMPDOWNTOLIMIT 0x20 /*!< */
#endif
/** @} */  // end of OutOptionConstants group

/** @defgroup OutRunStateConstants Output port run state constants.
 * Use these constants to configure the desired run state for the
 * specified motor(s): idle, rampup, running, rampdown, or hold.
 * \sa SetOutput()
 * @{
 */
#define OUT_RUNSTATE_IDLE     0x00 /*!< Set motor run state to idle */
#define OUT_RUNSTATE_RAMPUP   0x10 /*!< Set motor run state to rampup */
#define OUT_RUNSTATE_RUNNING  0x20 /*!< Set motor run state to running */
#define OUT_RUNSTATE_RAMPDOWN 0x40 /*!< Set motor run state to rampdown */
#define OUT_RUNSTATE_HOLD     0x60 /*!< Set motor run state to hold */
/** @} */  // end of OutRunStateConstants group

/** @defgroup OutRegModeConstants Output port regulation mode constants.
 * Use these constants to configure the desired regulation mode for the
 * specified motor(s): none, speed regulation, or multi-motor synchronization.
 * \sa SetOutput()
 * @{
 */
#define OUT_REGMODE_IDLE  0 /*!< Set motor regulation mode to idle */
#define OUT_REGMODE_SPEED 1 /*!< Set motor regulation mode to speed */
#define OUT_REGMODE_SYNC  2 /*!< Set motor regulation mode to sync */
/** @} */  // end of OutRegModeConstants group

/** @defgroup NBCSensorTypeConstants NBC sensor type constants.
 * Use sensor type constants to configure an input port for a specific type
 * of sensor.
 * \sa SetSensorType()
 * @{
 */
#define IN_TYPE_NO_SENSOR      0x00 /*!< No sensor configured */
#define IN_TYPE_SWITCH         0x01 /*!< NXT or RCX touch sensor */
#define IN_TYPE_TEMPERATURE    0x02 /*!< RCX temperature sensor */
#define IN_TYPE_REFLECTION     0x03 /*!< RCX light sensor */
#define IN_TYPE_ANGLE          0x04 /*!< RCX rotation sensor */
#define IN_TYPE_LIGHT_ACTIVE   0x05 /*!< NXT light sensor with light */
#define IN_TYPE_LIGHT_INACTIVE 0x06 /*!< NXT light sensor without light */
#define IN_TYPE_SOUND_DB       0x07 /*!< NXT sound sensor with dB scaling */
#define IN_TYPE_SOUND_DBA      0x08 /*!< NXT sound sensor with dBA scaling */
#define IN_TYPE_CUSTOM         0x09 /*!< NXT custom sensor */
#define IN_TYPE_LOWSPEED       0x0A /*!< NXT I2C digital sensor */
#define IN_TYPE_LOWSPEED_9V    0x0B /*!< NXT I2C digital sensor with 9V power */
#define IN_TYPE_HISPEED        0x0C /*!< NXT Hi-speed port (only S4) */
#if __FIRMWARE_VERSION > 107
#define IN_TYPE_COLORFULL      0x0D /*!< NXT 2.0 color sensor in full color mode */
#define IN_TYPE_COLORRED       0x0E /*!< NXT 2.0 color sensor with red light */
#define IN_TYPE_COLORGREEN     0x0F /*!< NXT 2.0 color sensor with green light */
#define IN_TYPE_COLORBLUE      0x10 /*!< NXT 2.0 color sensor with blue light */
#define IN_TYPE_COLORNONE      0x11 /*!< NXT 2.0 color sensor with no light */
#define IN_TYPE_COLOREXIT      0x12
#endif
/** @} */  // end of NBCSensorTypeConstants group

/** @defgroup NBCSensorModeConstants NBC sensor mode constants.
 * Use sensor mode constants to configure an input port for the desired
 * sensor mode.
 * \sa SetSensorMode()
 * @{
 */
#define IN_MODE_RAW           0x00 /*!< Raw value from 0 to 1023 */
#define IN_MODE_BOOLEAN       0x20 /*!< Boolean value (0 or 1) */
#define IN_MODE_TRANSITIONCNT 0x40 /*!< Counts the number of boolean transitions */
#define IN_MODE_PERIODCOUNTER 0x60 /*!< Counts the number of boolean periods */
#define IN_MODE_PCTFULLSCALE  0x80 /*!< Scaled value from 0 to 100 */
#define IN_MODE_CELSIUS       0xA0 /*!< RCX temperature sensor value in degrees celcius */
#define IN_MODE_FAHRENHEIT    0xC0 /*!< RCX temperature sensor value in degrees fahrenheit */
#define IN_MODE_ANGLESTEP     0xE0 /*!< RCX rotation sensor (16 ticks per revolution) */
#define IN_MODE_SLOPEMASK     0x1F /*!< Mask for slope parameter added to mode */
#define IN_MODE_MODEMASK      0xE0 /*!< Mask for the mode without any slope value */
/** @} */  // end of NBCSensorModeConstants group


/** @defgroup OutputFieldConstants Output field constants.
 * Constants for use with SetOutput() and GetOutput().
 * @{
 */
#define UpdateFlags     0  /*!< Update flags field. Contains a combination of the update flag constants.  Read/write. */
#define OutputMode      1  /*!< Mode field. Contains a combination of the output mode constants. Read/write. */
#define Power           2  /*!< Power field. Contains the desired power level (-100 to 100). Read/write. */
#define ActualSpeed     3  /*!< Actual speed field. Contains the actual power level (-100 to 100). Read only. */
#define TachoCount      4  /*!< Internal tachometer count field. Contains the current internal tachometer count. Read only. */
#define TachoLimit      5  /*!< Tachometer limit field. Contains the current tachometer limit. Read/write. */
#define RunState        6  /*!< Run state field. Contains one of the run state constants. Read/write. */
#define TurnRatio       7  /*!< Turn ratio field. Contains the current turn ratio. Only applicable when synchronizing multiple motors. Read/write. */
#define RegMode         8  /*!< Regulation mode field. Contains one of the regulation mode constants. Read/write. */
#define Overload        9  /*!< Overload field. Contains a boolean value which is TRUE if the motor is overloaded. Read only. */
#define RegPValue       10 /*!< Proportional field. Contains the proportional constant for the PID motor controller. Read/write. */
#define RegIValue       11 /*!< Integral field. Contains the integral constant for the PID motor controller. Read/write. */
#define RegDValue       12 /*!< Derivative field. Contains the derivative constant for the PID motor controller. Read/write. */
#define BlockTachoCount 13 /*!< NXT-G block tachometer count field. Contains the current NXT-G block tachometer count. Read only. */
#define RotationCount   14 /*!< Rotation counter field. Contains the current rotation count. Read only. */
#if defined(__ENHANCED_FIRMWARE) && (__FIRMWARE_VERSION > 107)
#define OutputOptions   15 /*!< Options field. Contains a combination of the output options constants. Read/write. */
#endif
/** @} */  // end of OutputFieldConstants group

/** @defgroup InputFieldConstants Input field constants.
 * Constants for use with SetInput() and GetInput().
 * @{
 */
#define Type            0 /*!< Type field. Contains one of the sensor type constants. Read/write. */
#define InputMode       1 /*!< Input mode field. Contains one of the sensor mode constants. Read/write. */
#define RawValue        2 /*!< Raw value field. Contains the current raw analog sensor value. Read only. */
#define NormalizedValue 3 /*!< Normalized value field. Contains the current normalized analog sensor value. Read only. */
#define ScaledValue     4 /*!< Scaled value field. Contains the current scaled analog sensor value. Read/write. */
#define InvalidData     5 /*!< Invalid data field. Contains a boolean value indicating whether the sensor data is valid or not. Read/write. */
/** @} */  // end of InputFieldConstants group

/** @defgroup IOMapAddressConstants Direct IOMap data addresses.
 * Constants for use in direct IOMap addressing (1.0x only).
 * @{
 */
#if __FIRMWARE_VERSION <= 107

#define IO_BASE    0xC000
#define MOD_INPUT  0x0000
#define MOD_OUTPUT 0x0200
#define IO_IN_FPP  6
#define IO_OUT_FPP 15

#define InputIOType(p)            (IO_BASE+MOD_INPUT+Type+((p)*IO_IN_FPP))
#define InputIOInputMode(p)       (IO_BASE+MOD_INPUT+InputMode+((p)*IO_IN_FPP))
#define InputIORawValue(p)        (IO_BASE+MOD_INPUT+RawValue+((p)*IO_IN_FPP))
#define InputIONormalizedValue(p) (IO_BASE+MOD_INPUT+NormalizedValue+((p)*IO_IN_FPP))
#define InputIOScaledValue(p)     (IO_BASE+MOD_INPUT+ScaledValue+((p)*IO_IN_FPP))
#define InputIOInvalidData(p)     (IO_BASE+MOD_INPUT+InvalidData+((p)*IO_IN_FPP))

#define OutputIOUpdateFlags(p)     (IO_BASE+MOD_OUTPUT+UpdateFlags+((p)*IO_OUT_FPP))
#define OutputIOOutputMode(p)      (IO_BASE+MOD_OUTPUT+OutputMode+((p)*IO_OUT_FPP))
#define OutputIOPower(p)           (IO_BASE+MOD_OUTPUT+Power+((p)*IO_OUT_FPP))
#define OutputIOActualSpeed(p)     (IO_BASE+MOD_OUTPUT+ActualSpeed+((p)*IO_OUT_FPP))
#define OutputIOTachoCount(p)      (IO_BASE+MOD_OUTPUT+TachoCount+((p)*IO_OUT_FPP))
#define OutputIOTachoLimit(p)      (IO_BASE+MOD_OUTPUT+TachoLimit+((p)*IO_OUT_FPP))
#define OutputIORunState(p)        (IO_BASE+MOD_OUTPUT+RunState+((p)*IO_OUT_FPP))
#define OutputIOTurnRatio(p)       (IO_BASE+MOD_OUTPUT+TurnRatio+((p)*IO_OUT_FPP))
#define OutputIORegMode(p)         (IO_BASE+MOD_OUTPUT+RegMode+((p)*IO_OUT_FPP))
#define OutputIOOverload(p)        (IO_BASE+MOD_OUTPUT+Overload+((p)*IO_OUT_FPP))
#define OutputIORegPValue(p)       (IO_BASE+MOD_OUTPUT+RegPValue+((p)*IO_OUT_FPP))
#define OutputIORegIValue(p)       (IO_BASE+MOD_OUTPUT+RegIValue+((p)*IO_OUT_FPP))
#define OutputIORegDValue(p)       (IO_BASE+MOD_OUTPUT+RegDValue+((p)*IO_OUT_FPP))
#define OutputIOBlockTachoCount(p) (IO_BASE+MOD_OUTPUT+BlockTachoCount+((p)*IO_OUT_FPP))
#define OutputIORotationCount(p)   (IO_BASE+MOD_OUTPUT+RotationCount+((p)*IO_OUT_FPP))

#define InputIOType0             0xc000
#define InputIOInputMode0        0xc001
#define InputIORawValue0         0xc002
#define InputIONormalizedValue0  0xc003
#define InputIOScaledValue0      0xc004
#define InputIOInvalidData0      0xc005
#define InputIOType1             0xc006
#define InputIOInputMode1        0xc007
#define InputIORawValue1         0xc008
#define InputIONormalizedValue1  0xc009
#define InputIOScaledValue1      0xc00a
#define InputIOInvalidData1      0xc00b
#define InputIOType2             0xc00c
#define InputIOInputMode2        0xc00d
#define InputIORawValue2         0xc00e
#define InputIONormalizedValue2  0xc00f
#define InputIOScaledValue2      0xc010
#define InputIOInvalidData2      0xc011
#define InputIOType3             0xc012
#define InputIOInputMode3        0xc013
#define InputIORawValue3         0xc014
#define InputIONormalizedValue3  0xc015
#define InputIOScaledValue3      0xc016
#define InputIOInvalidData3      0xc017
// output IO Map addresses
#define OutputIOUpdateFlags0     0xc200
#define OutputIOOutputMode0      0xc201
#define OutputIOPower0           0xc202
#define OutputIOActualSpeed0     0xc203
#define OutputIOTachoCount0      0xc204
#define OutputIOTachoLimit0      0xc205
#define OutputIORunState0        0xc206
#define OutputIOTurnRatio0       0xc207
#define OutputIORegMode0         0xc208
#define OutputIOOverload0        0xc209
#define OutputIORegPValue0       0xc20a
#define OutputIORegIValue0       0xc20b
#define OutputIORegDValue0       0xc20c
#define OutputIOBlockTachoCount0 0xc20d
#define OutputIORotationCount0   0xc20e
#define OutputIOUpdateFlags1     0xc20f
#define OutputIOOutputMode1      0xc210
#define OutputIOPower1           0xc211
#define OutputIOActualSpeed1     0xc212
#define OutputIOTachoCount1      0xc213
#define OutputIOTachoLimit1      0xc214
#define OutputIORunState1        0xc215
#define OutputIOTurnRatio1       0xc216
#define OutputIORegMode1         0xc217
#define OutputIOOverload1        0xc218
#define OutputIORegPValue1       0xc219
#define OutputIORegIValue1       0xc21a
#define OutputIORegDValue1       0xc21b
#define OutputIOBlockTachoCount1 0xc21c
#define OutputIORotationCount1   0xc21d
#define OutputIOUpdateFlags2     0xc21e
#define OutputIOOutputMode2      0xc21f
#define OutputIOPower2           0xc220
#define OutputIOActualSpeed2     0xc221
#define OutputIOTachoCount2      0xc222
#define OutputIOTachoLimit2      0xc223
#define OutputIORunState2        0xc224
#define OutputIOTurnRatio2       0xc225
#define OutputIORegMode2         0xc226
#define OutputIOOverload2        0xc227
#define OutputIORegPValue2       0xc228
#define OutputIORegIValue2       0xc229
#define OutputIORegDValue2       0xc22a
#define OutputIOBlockTachoCount2 0xc22b
#define OutputIORotationCount2   0xc22c

#endif
/** @} */  // end of IOMapAddressConstants group

/** @defgroup SysCallConstants System Call function constants.
 * Constants for use in the SysCall() function.
 * @{
 */
#define FileOpenRead       0 /*!< */
#define FileOpenWrite      1 /*!< */
#define FileOpenAppend     2 /*!< */
#define FileRead           3 /*!< */
#define FileWrite          4 /*!< */
#define FileClose          5 /*!< */
#define FileResolveHandle  6 /*!< */
#define FileRename         7 /*!< */
#define FileDelete         8 /*!< */
#define SoundPlayFile      9 /*!< */
#define SoundPlayTone     10 /*!< */
#define SoundGetState     11 /*!< */
#define SoundSetState     12 /*!< */
#define DrawText          13 /*!< */
#define DrawPoint         14 /*!< */
#define DrawLine          15 /*!< */
#define DrawCircle        16 /*!< */
#define DrawRect          17 /*!< */
#define DrawGraphic       18 /*!< */
#define SetScreenMode     19 /*!< */
#define ReadButton        20 /*!< */
#define CommLSWrite       21 /*!< */
#define CommLSRead        22 /*!< */
#define CommLSCheckStatus 23 /*!< */
#define RandomNumber      24 /*!< */
#define GetStartTick      25 /*!< */
#define MessageWrite      26 /*!< */
#define MessageRead       27 /*!< */
#define CommBTCheckStatus 28 /*!< */
#define CommBTWrite       29 /*!< */
#define CommBTRead        30 /*!< */
#define KeepAlive         31 /*!< */
#define IOMapRead         32 /*!< */
#define IOMapWrite        33 /*!< */

#if __FIRMWARE_VERSION <= 107
#ifdef __ENHANCED_FIRMWARE
#define IOMapReadByID          34 /*!< */
#define IOMapWriteByID         35 /*!< */
#define DisplayExecuteFunction 36 /*!< */
#define CommExecuteFunction    37 /*!< */
#define LoaderExecuteFunction  38 /*!< */
#define FileFindFirst          39 /*!< */
#define FileFindNext           40 /*!< */
#define FileOpenWriteLinear    41 /*!< */
#define FileOpenWriteNonLinear 42 /*!< */
#define FileOpenReadLinear     43 /*!< */
#define CommHSControl          44 /*!< */
#define CommHSCheckStatus      45 /*!< */
#define CommHSWrite            46 /*!< */
#define CommHSRead             47 /*!< */
#endif
#else
// NXT 2.0 firmwares
#define ColorSensorRead        34 /*!< */
#define CommBTOnOff            35 /*!< */
#define CommBTConnection       36 /*!< */
#define CommHSWrite            37 /*!< */
#define CommHSRead             38 /*!< */
#define CommHSCheckStatus      39 /*!< */
#define ReadSemData            40 /*!< */
#define WriteSemData           41 /*!< */
#define ComputeCalibValue      42 /*!< */
#define UpdateCalibCacheInfo   43 /*!< */
#define DatalogWrite           44 /*!< */
#define DatalogGetTimes        45 /*!< */
#define SetSleepTimeoutVal     46 /*!< */
#define ListFiles              47 /*!< */

#ifdef __ENHANCED_FIRMWARE
#define IOMapReadByID          78 /*!< */
#define IOMapWriteByID         79 /*!< */
#define DisplayExecuteFunction 80 /*!< */
#define CommExecuteFunction    81 /*!< */
#define LoaderExecuteFunction  82 /*!< */
#define FileFindFirst          83 /*!< */
#define FileFindNext           84 /*!< */
#define FileOpenWriteLinear    85 /*!< */
#define FileOpenWriteNonLinear 86 /*!< */
#define FileOpenReadLinear     87 /*!< */
#define CommHSControl          88 /*!< */
#define CommLSWriteEx          89 /*!< */
#define FileSeek               90 /*!< */
#define FileResize             91 /*!< */
#define DrawGraphicArray       92 /*!< */
#define DrawPolygon            93 /*!< */
#define DrawEllipse            94 /*!< */
#define DrawFont               95 /*!< */
#endif
#endif
/** @} */  // end of SysCallConstants group

/** @defgroup LineConstants Line number constants.
 * Line numbers for use with DrawText system function.
 * @{
 */
#define LCD_LINE8  0 /*!< */
#define LCD_LINE7  8 /*!< */
#define LCD_LINE6 16 /*!< */
#define LCD_LINE5 24 /*!< */
#define LCD_LINE4 32 /*!< */
#define LCD_LINE3 40 /*!< */
#define LCD_LINE2 48 /*!< */
#define LCD_LINE1 56 /*!< */
/** @} */  // end of LineConstants group

/** @defgroup TimeConstants Time constants.
 * Command use:  Wait()
 * @{
 */
#define MS_1        1 /*!< 1 millisecond */
#define MS_2        2 /*!< 2 milliseconds */
#define MS_3        3 /*!< 3 milliseconds */
#define MS_4        4 /*!< 4 milliseconds */
#define MS_5        5 /*!< 5 milliseconds */
#define MS_6        6 /*!< 6 milliseconds */
#define MS_7        7 /*!< 7 milliseconds */
#define MS_8        8 /*!< 8 milliseconds */
#define MS_9        9 /*!< 9 milliseconds */
#define MS_10      10 /*!< 10 milliseconds */
#define MS_20      20 /*!< 20 milliseconds */
#define MS_30      30 /*!< 30 milliseconds */
#define MS_40      40 /*!< 40 milliseconds */
#define MS_50      50 /*!< 50 milliseconds */
#define MS_60      60 /*!< 60 milliseconds */
#define MS_70      70 /*!< 70 milliseconds */
#define MS_80      80 /*!< 80 milliseconds */
#define MS_90      90 /*!< 90 milliseconds */
#define MS_100    100 /*!< 100 milliseconds */
#define MS_150    150 /*!< 150 milliseconds */
#define MS_200    200 /*!< 200 milliseconds */
#define MS_250    250 /*!< 250 milliseconds */
#define MS_300    300 /*!< 300 milliseconds */
#define MS_350    350 /*!< 350 milliseconds */
#define MS_400    400 /*!< 400 milliseconds */
#define MS_450    450 /*!< 450 milliseconds */
#define MS_500    500 /*!< 500 milliseconds */
#define MS_600    600 /*!< 600 milliseconds */
#define MS_700    700 /*!< 700 milliseconds */
#define MS_800    800 /*!< 800 milliseconds */
#define MS_900    900 /*!< 900 milliseconds */
#define SEC_1    1000 /*!< 1 second */
#define SEC_2    2000 /*!< 2 seconds */
#define SEC_3    3000 /*!< 3 seconds */
#define SEC_4    4000 /*!< 4 seconds */
#define SEC_5    5000 /*!< 5 seconds */
#define SEC_6    6000 /*!< 6 seconds */
#define SEC_7    7000 /*!< 7 seconds */
#define SEC_8    8000 /*!< 8 seconds */
#define SEC_9    9000 /*!< 9 seconds */
#define SEC_10  10000 /*!< 10 seconds */
#define SEC_15  15000 /*!< 15 seconds */
#define SEC_20  20000 /*!< 20 seconds */
#define SEC_30  30000 /*!< 30 seconds */
#define MIN_1   60000 /*!< 1 minute */
/** @} */  // end of TimeConstants group

/** @defgroup ToneConstants Tone constants.
 * Command use:  SoundPlayTone()
 * @{
 */
#define TONE_A3               220 /*!< */
#define TONE_AS3              233 /*!< */
#define TONE_B3               247 /*!< */
#define TONE_C4               262 /*!< */
#define TONE_CS4              277 /*!< */
#define TONE_D4               294 /*!< */
#define TONE_DS4              311 /*!< */
#define TONE_E4               330 /*!< */
#define TONE_F4               349 /*!< */
#define TONE_FS4              370 /*!< */
#define TONE_G4               392 /*!< */
#define TONE_GS4              415 /*!< */
#define TONE_A4               440 /*!< */
#define TONE_AS4              466 /*!< */
#define TONE_B4               494 /*!< */
#define TONE_C5               523 /*!< */
#define TONE_CS5              554 /*!< */
#define TONE_D5               587 /*!< */
#define TONE_DS5              622 /*!< */
#define TONE_E5               659 /*!< */
#define TONE_F5               698 /*!< */
#define TONE_FS5              740 /*!< */
#define TONE_G5               784 /*!< */
#define TONE_GS5              831 /*!< */
#define TONE_A5               880 /*!< */
#define TONE_AS5              932 /*!< */
#define TONE_B5               988 /*!< */
#define TONE_C6               1047 /*!< */
#define TONE_CS6              1109 /*!< */
#define TONE_D6               1175 /*!< */
#define TONE_DS6              1245 /*!< */
#define TONE_E6               1319 /*!< */
#define TONE_F6               1397 /*!< */
#define TONE_FS6              1480 /*!< */
#define TONE_G6               1568 /*!< */
#define TONE_GS6              1661 /*!< */
#define TONE_A6               1760 /*!< */
#define TONE_AS6              1865 /*!< */
#define TONE_B6               1976 /*!< */
#define TONE_C7               2093 /*!< */
#define TONE_CS7              2217 /*!< */
#define TONE_D7               2349 /*!< */
#define TONE_DS7              2489 /*!< */
#define TONE_E7               2637 /*!< */
#define TONE_F7               2794 /*!< */
#define TONE_FS7              2960 /*!< */
#define TONE_G7               3136 /*!< */
#define TONE_GS7              3322 /*!< */
#define TONE_A7               3520 /*!< */
#define TONE_AS7              3729 /*!< */
#define TONE_B7               3951 /*!< */
/** @} */  // end of ToneConstants group

/** @defgroup MailboxConstants Mailbox constants.
 * Mailbox number constants should be used to avoid confusing NXT-G users.
 * @{
 */
#define MAILBOX1  0 /*!< Mailbox number 1 */
#define MAILBOX2  1 /*!< Mailbox number 2 */
#define MAILBOX3  2 /*!< Mailbox number 3 */
#define MAILBOX4  3 /*!< Mailbox number 4 */
#define MAILBOX5  4 /*!< Mailbox number 5 */
#define MAILBOX6  5 /*!< Mailbox number 6 */
#define MAILBOX7  6 /*!< Mailbox number 7 */
#define MAILBOX8  7 /*!< Mailbox number 8 */
#define MAILBOX9  8 /*!< Mailbox number 9 */
#define MAILBOX10 9 /*!< Mailbox number 10 */
/** @} */  // end of MailboxConstants group


/** @addtogroup CommandModule
 * @{
 */
/** @defgroup CommandModuleConstants Command module constants.
 * Constants that are part of the NXT firmware's Command module.
 * @{
 */
#define CommandModuleName "Command.mod" /*!< The command module name */
#define CommandModuleID   0x00010001 /*!< The command module ID */

//Status/error codes for the VM internal code and bytecodes
#define STAT_MSG_EMPTY_MAILBOX 64 /*!< Specified mailbox contains no new messages */
#define STAT_COMM_PENDING 32      /*!< Pending setup operation in progress */

/** @defgroup CommandVMState VM state constants.
 * Constants defining possible VM states.
 * @{
 */
#define TIMES_UP      6
#define ROTATE_QUEUE  5
#define STOP_REQ      4
#define BREAKOUT_REQ  3
#define CLUMP_SUSPEND 2
#define CLUMP_DONE    1
/** @} */  // end of CommandVMState group

#define NO_ERR        0 /*!< Successful execution of the specified command */

/** @defgroup CommandFatalErrors Fatal errors.
 * Constants defining various fatal error conditions.
 * @{
 */
#define ERR_ARG             -1 /*!< 0xFF Bad arguments */
#define ERR_INSTR           -2 /*!< 0xFE Illegal bytecode instruction */
#define ERR_FILE            -3 /*!< 0xFD Malformed file contents */
#define ERR_VER             -4 /*!< 0xFC Version mismatch between firmware and compiler */
#define ERR_MEM             -5 /*!< 0xFB Insufficient memory available */
#define ERR_BAD_PTR         -6 /*!< 0xFA Someone passed us a bad pointer! */
#define ERR_CLUMP_COUNT     -7 /*!< 0xF9 (FileClumpCount == 0 || FileClumpCount >= NOT_A_CLUMP) */
#define ERR_NO_CODE         -8 /*!< 0xF8 VarsCmd.CodespaceCount == 0 */
#define ERR_INSANE_OFFSET   -9 /*!< 0xF7 CurrOffset != (DataSize - VarsCmd.CodespaceCount * 2) */
#define ERR_BAD_POOL_SIZE   -10 /*!< 0xF6 VarsCmd.PoolSize > POOL_MAX_SIZE */
#define ERR_LOADER_ERR      -11 /*!< 0xF5 LOADER_ERR(LStatus) != SUCCESS || pData == NULL || DataSize == 0 */
#define ERR_SPOTCHECK_FAIL  -12 /*!< 0xF4 ((UBYTE*)(VarsCmd.pCodespace) < pData) (c_cmd.c 1893) */
#define ERR_NO_ACTIVE_CLUMP -13 /*!< 0xF3 VarsCmd.RunQ.Head == NOT_A_CLUMP */
#define ERR_DEFAULT_OFFSETS -14 /*!< 0xF2 (DefaultsOffset != FileOffsets.DynamicDefaults) || (DefaultsOffset + FileOffsets.DynamicDefaultsSize != FileOffsets.DSDefaultsSize) */
#define ERR_MEMMGR_FAIL     -15 /*!< 0xF1 (UBYTE *)VarsCmd.MemMgr.pDopeVectorArray != VarsCmd.pDataspace + DV_ARRAY[0].Offset */

#define ERR_NON_FATAL -16 /*!< Fatal errors are greater than this value */
/** @} */  // end of CommandFatalErrors group

/** @defgroup CommandGenErrors General errors.
 * Constants defining general error conditions.
 * @{
 */
#define ERR_INVALID_PORT   -16 /*!< 0xF0 Bad input or output port specified */
#define ERR_INVALID_FIELD  -17 /*!< 0xEF Attempted to access invalid field of a structure */
#define ERR_INVALID_QUEUE  -18 /*!< 0xEE Illegal queue ID specified */
#define ERR_INVALID_SIZE   -19 /*!< 0xED Illegal size specified */
#define ERR_NO_PROG        -20 /*!< 0xEC No active program */
/** @} */  // end of CommandGenErrors group

/** @defgroup CommandCommErrors Communications specific errors.
 * Constants defining communication error conditions.
 * @{
 */
#define ERR_COMM_CHAN_NOT_READY -32 /*!< 0xE0 Specified channel/connection not configured or busy */
#define ERR_COMM_CHAN_INVALID   -33 /*!< 0xDF Specified channel/connection is not valid */
#define ERR_COMM_BUFFER_FULL    -34 /*!< 0xDE No room in comm buffer */
#define ERR_COMM_BUS_ERR        -35 /*!< 0xDD Something went wrong on the communications bus */
/** @} */  // end of CommandCommErrors group

/** @defgroup CommandRCErrors Remote control (direct commands) errors.
 * Detailed description.
 * @{
 */
#define ERR_RC_ILLEGAL_VAL -64 /*!< 0xC0 Data contains out-of-range values */
#define ERR_RC_BAD_PACKET  -65 /*!< 0xBF Clearly insane packet */
#define ERR_RC_UNKNOWN_CMD -66 /*!< 0xBE Unknown command opcode */
#define ERR_RC_FAILED      -67 /*!< 0xBD Request failed (i.e. specified file not found) */
/** @} */  // end of CommandRCErrors group

/** @defgroup CommandProgStatus Program status constants.
 * Detailed description.
 * @{
 */
#define PROG_IDLE     0 /*!< Program state is idle */
#define PROG_OK       1 /*!< Program state is okay */
#define PROG_RUNNING  2 /*!< Program is running */
#define PROG_ERROR    3 /*!< A program error has occurred */
#define PROG_ABORT    4 /*!< Program has been aborted */
#define PROG_RESET    5 /*!< Program has been reset */
/** @} */  // end of CommandProgStatus group

/** @defgroup CommandIOMAP Command module IOMAP offsets.
 * Constant offsets into the Command module IOMAP structure.
 * @{
 */
#define CommandOffsetFormatString   0 /*!< Offset to the format string */
#define CommandOffsetPRCHandler     16 /*!< Offset to the RC Handler function pointer */
#define CommandOffsetTick           20 /*!< Offset to the VM's current tick */
#define CommandOffsetOffsetDS       24 /*!< Offset to the running program's data space (DS) */
#define CommandOffsetOffsetDVA      26 /*!< Offset to the running program's DOPE vector address (DVA) */
#define CommandOffsetProgStatus     28 /*!< Offset to the running program's status */
#define CommandOffsetAwake          29 /*!< Offset to the VM's awake state */
#define CommandOffsetActivateFlag   30 /*!< Offset to the activate flag */
#define CommandOffsetDeactivateFlag 31 /*!< Offset to the deactivate flag */
#define CommandOffsetFileName       32 /*!< Offset to the running program's filename */
#define CommandOffsetMemoryPool     52 /*!< Offset to the VM's memory pool */
#if __FIRMWARE_VERSION > 107
#define CommandOffsetSyncTime       32820 /*!< Offset to the VM sync time */
#define CommandOffsetSyncTick       32824 /*!< Offset to the VM sync tick */
#endif
/** @} */  // end of CommandIOMAP group

/** @} */  // end of CommandModuleConstants group
/** @} */  // end of CommandModule group


/** @addtogroup IOCtrlModule
 * @{
 */
/** @defgroup IOCtrlModuleConstants IOCtrl module constants.
 * Constants that are part of the NXT firmware's IOCtrl module.
 * @{
 */
#define IOCtrlModuleName "IOCtrl.mod" /*!< The IOCtrl module name */
#define IOCtrlModuleID   0x00060001 /*!< The IOCtrl module ID */

/** @defgroup IOCtrlPO PowerOn constants.
 * Use these constants to power down the NXT or boot it into SAMBA
 * (aka firmware download) mode.
 * @{
 */
#define IOCTRL_POWERDOWN  0x5A00 /*!< Power down the NXT */
#define IOCTRL_BOOT       0xA55A /*!< Reboot the NXT into SAMBA mode */
/** @} */  // end of IOCtrlPO group

/** @defgroup IOCtrlIOMAP IOCtrl module IOMAP offsets.
 * Constant offsets into the IOCtrl module IOMAP structure.
 * @{
 */
#define IOCtrlOffsetPowerOn 0 /*!< Offset to power on field */
/** @} */  // end of IOCtrlIOMAP group

/** @} */  // end of IOCtrlModuleConstants group
/** @} */  // end of IOCtrlModule group


/** @addtogroup LoaderModule
 * @{
 */
/** @defgroup LoaderModuleConstants Loader module constants.
 * Constants that are part of the NXT firmware's Loader module.
 * @{
 */
#define LoaderModuleName "Loader.mod" /*!< The Loader module name */
#define LoaderModuleID   0x00090001 /*!< The Loader module ID */

/** @defgroup LoaderIOMAP Loader module IOMAP offsets.
 * Constant offsets into the Loader module IOMAP structure.
 * @{
 */
#define LoaderOffsetPFunc         0 /*!< Offset to the Loader module function pointer */
#define LoaderOffsetFreeUserFlash 4 /*!< Offset to the amount of free user flash */
/** @} */  // end of LoaderIOMAP group

#define EOF -1 /*!< A constant representing end of file */
#define NULL 0 /*!< A constant representing NULL */

/** @defgroup LoaderErrors Loader module error codes.
 * Error codes returned by functions in the Loader module (file access).
 * @{
 */
#define LDR_SUCCESS             0x0000 /*!< */
#define LDR_INPROGRESS          0x0001 /*!< */
#define LDR_REQPIN              0x0002 /*!< */
#define LDR_NOMOREHANDLES       0x8100 /*!< */
#define LDR_NOSPACE             0x8200 /*!< */
#define LDR_NOMOREFILES         0x8300 /*!< */
#define LDR_EOFEXPECTED         0x8400 /*!< */
#define LDR_ENDOFFILE           0x8500 /*!< */
#define LDR_NOTLINEARFILE       0x8600 /*!< */
#define LDR_FILENOTFOUND        0x8700 /*!< */
#define LDR_HANDLEALREADYCLOSED 0x8800 /*!< */
#define LDR_NOLINEARSPACE       0x8900 /*!< */
#define LDR_UNDEFINEDERROR      0x8A00 /*!< */
#define LDR_FILEISBUSY          0x8B00 /*!< */
#define LDR_NOWRITEBUFFERS      0x8C00 /*!< */
#define LDR_APPENDNOTPOSSIBLE   0x8D00 /*!< */
#define LDR_FILEISFULL          0x8E00 /*!< */
#define LDR_FILEEXISTS          0x8F00 /*!< */
#define LDR_MODULENOTFOUND      0x9000 /*!< */
#define LDR_OUTOFBOUNDARY       0x9100 /*!< */
#define LDR_ILLEGALFILENAME     0x9200 /*!< */
#define LDR_ILLEGALHANDLE       0x9300 /*!< */
#define LDR_BTBUSY              0x9400 /*!< */
#define LDR_BTCONNECTFAIL       0x9500 /*!< */
#define LDR_BTTIMEOUT           0x9600 /*!< */
#define LDR_FILETX_TIMEOUT      0x9700 /*!< */
#define LDR_FILETX_DSTEXISTS    0x9800 /*!< */
#define LDR_FILETX_SRCMISSING   0x9900 /*!< */
#define LDR_FILETX_STREAMERROR  0x9A00 /*!< */
#define LDR_FILETX_CLOSEERROR   0x9B00 /*!< */

#if defined(__ENHANCED_FIRMWARE) && (__FIRMWARE_VERSION > 107)
#define LDR_INVALIDSEEK         0x9C00 /*!< Invalid file seek operation */
#endif
/** @} */  // end of LoaderErrors group

/** @defgroup LoaderFunctionConstants Loader module function constants.
 * Constants defining the functions provided by the Loader module.
 * @{
 */
#define LDR_CMD_OPENREAD        0x80 /*!< Open a file for reading */
#define LDR_CMD_OPENWRITE       0x81 /*!< Open a file for writing */
#define LDR_CMD_READ            0x82 /*!< Read from a file */
#define LDR_CMD_WRITE           0x83 /*!< Write to a file */
#define LDR_CMD_CLOSE           0x84 /*!< Close a file handle */
#define LDR_CMD_DELETE          0x85 /*!< Delete a file */
#define LDR_CMD_FINDFIRST       0x86 /*!< Find the first file matching the specified pattern */
#define LDR_CMD_FINDNEXT        0x87 /*!< Find the next file matching the specified pattern */
#define LDR_CMD_VERSIONS        0x88 /*!< Read firmware version information */
#define LDR_CMD_OPENWRITELINEAR 0x89 /*!< Open a linear file for writing */
#define LDR_CMD_OPENREADLINEAR  0x8A /*!< Open a linear file for reading */
#define LDR_CMD_OPENWRITEDATA   0x8B /*!< Open a data file for writing */
#define LDR_CMD_OPENAPPENDDATA  0x8C /*!< Open a data file for appending */
#if __FIRMWARE_VERSION > 107
#define LDR_CMD_CROPDATAFILE    0x8D /*!< Crop a data file to its used space */
#endif
#define LDR_CMD_FINDFIRSTMODULE 0x90 /*!< Find the first module matching the specified pattern */
#define LDR_CMD_FINDNEXTMODULE  0x91 /*!< Find the next module matching the specified pattern */
#define LDR_CMD_CLOSEMODHANDLE  0x92 /*!< Close a module handle */
#define LDR_CMD_IOMAPREAD       0x94 /*!< Read data from a module IOMAP */
#define LDR_CMD_IOMAPWRITE      0x95 /*!< Write data to a module IOMAP */
#define LDR_CMD_BOOTCMD         0x97 /*!< Reboot the NXT into SAMBA mode */
#define LDR_CMD_SETBRICKNAME    0x98 /*!< Set the NXT's brick name */
#define LDR_CMD_BTGETADR        0x9A /*!< Get the NXT's bluetooth brick address */
#define LDR_CMD_DEVICEINFO      0x9B /*!< Read device information */
#define LDR_CMD_DELETEUSERFLASH 0xA0 /*!< Delete all files from user flash memory */
#define LDR_CMD_POLLCMDLEN      0xA1 /*!< Read poll command length */
#define LDR_CMD_POLLCMD         0xA2 /*!< Poll command */
#define LDR_CMD_RENAMEFILE      0xA3 /*!< Rename a file */
#define LDR_CMD_BTFACTORYRESET  0xA4 /*!< Reset bluetooth configuration to factory defaults */
#if defined(__ENHANCED_FIRMWARE) && (__FIRMWARE_VERSION > 107)
#define LDR_CMD_RESIZEDATAFILE  0xD0 /*!< Resize a data file */
#define LDR_CMD_SEEKFROMSTART   0xD1 /*!< Seek from the start of the file */
#define LDR_CMD_SEEKFROMCURRENT 0xD2 /*!< Seek from the current position */
#define LDR_CMD_SEEKFROMEND     0xD3 /*!< Seek from the end of the file */
#endif
/** @} */  // end of LoaderFunctionConstants group

/** @} */  // end of LoaderModuleConstants group
/** @} */  // end of LoaderModule group


/** @addtogroup SoundModule
 * @{
 */
/** @defgroup SoundModuleConstants Sound module constants.
 * Constants that are part of the NXT firmware's Sound module.
 * @{
 */
#define SoundModuleName "Sound.mod" /*!< The Sound module name */
#define SoundModuleID   0x00080001 /*!< The Sound module ID */

// Constants related to Flags
#define SOUND_FLAGS_IDLE    0x00 // R  - Idle
#define SOUND_FLAGS_UPDATE  0x01 // W  - Make changes take effect
#define SOUND_FLAGS_RUNNING 0x02 // R  - Processing tone or file

// Constants related to State
#define SOUND_STATE_IDLE 0x00 // R  - Idle, ready for start sound (SOUND_UPDATE)
#define SOUND_STATE_FILE 0x02 // R  - Processing file of sound/melody data
#define SOUND_STATE_TONE 0x03 // R  - Processing play tone request
#define SOUND_STATE_STOP 0x04 // W  - Stop sound immediately and close hardware

// Constants related to Mode
#define SOUND_MODE_ONCE 0x00 // W  - Only play file once
#define SOUND_MODE_LOOP 0x01 // W  - Play file until writing "SOUND_STOP" into "State" or new "update"
#define SOUND_MODE_TONE 0x02 // W  - Play tone specified in Freq for Duration ms

// offsets
#define SoundOffsetFreq           0 // RW - Tone frequency [Hz] (2 bytes)
#define SoundOffsetDuration       2 // RW - Tone duration  [mS] (2 bytes)
#define SoundOffsetSampleRate     4 // RW - Sound file sample rate [2000..16000] (2 bytes)
#define SoundOffsetSoundFilename  6 // RW - Sound/melody filename (20 bytes)
#define SoundOffsetFlags         26 // RW - Play flag  - described above (1 byte)
#define SoundOffsetState         27 // RW - Play state - described above (1 byte)
#define SoundOffsetMode          28 // RW - Play mode  - described above (1 byte)
#define SoundOffsetVolume        29 // RW - Sound/melody volume [0..4] 0 = off (1 byte)

#define FREQUENCY_MIN       220       // [Hz]
#define FREQUENCY_MAX       14080     // [Hz]

#define SAMPLERATE_MIN      2000      // Min sample rate [sps]
#define SAMPLERATE_DEFAULT  8000      // Default sample rate [sps]
#define SAMPLERATE_MAX      16000     // Max sample rate [sps]
/** @} */  // end of SoundModuleConstants group
/** @} */  // end of SoundModule group


/** @addtogroup ButtonModule
 * @{
 */
/** @defgroup ButtonModuleConstants Button module constants.
 * Constants that are part of the NXT firmware's Button module.
 * @{
 */
#define ButtonModuleName "Button.mod" /*!< */
#define ButtonModuleID   0x00040001 /*!< */

// constants related to buttons
#define BTN1 0 /*!< */
#define BTN2 1 /*!< */
#define BTN3 2 /*!< */
#define BTN4 3 /*!< */

#define BTNEXIT   BTN1 /*!< */
#define BTNRIGHT  BTN2 /*!< */
#define BTNLEFT   BTN3 /*!< */
#define BTNCENTER BTN4 /*!< */

#define NO_OF_BTNS 4 /*!< */

// Constants related to State
#define BTNSTATE_PRESSED_EV         0x01 /*!< */
#define BTNSTATE_SHORT_RELEASED_EV  0x02 /*!< */
#define BTNSTATE_LONG_PRESSED_EV    0x04 /*!< */
#define BTNSTATE_LONG_RELEASED_EV   0x08 /*!< */
#define BTNSTATE_PRESSED_STATE      0x80 /*!< */
#define BTNSTATE_NONE               0x10 /*!< */

// offsets
#define ButtonOffsetPressedCnt(b)   (((b)*8)+0) /*!< */
#define ButtonOffsetLongPressCnt(b) (((b)*8)+1) /*!< */
#define ButtonOffsetShortRelCnt(b)  (((b)*8)+2) /*!< */
#define ButtonOffsetLongRelCnt(b)   (((b)*8)+3) /*!< */
#define ButtonOffsetRelCnt(b)       (((b)*8)+4) /*!< */
#define ButtonOffsetState(b)        ((b)+32) /*!< */
/** @} */  // end of ButtonModuleConstants group
/** @} */  // end of ButtonModule group


/** @addtogroup UiModule
 * @{
 */
/** @defgroup UiModuleConstants Ui module constants.
 * Constants that are part of the NXT firmware's Ui module.
 * @{
 */
#define UIModuleName "Ui.mod" /*!< */
#define UIModuleID   0x000C0001 /*!< */

// Constants related to Flags
#define UI_FLAGS_UPDATE                   0x01 // W  - Make changes take effect
#define UI_FLAGS_DISABLE_LEFT_RIGHT_ENTER 0x02 // RW - Disable left, right and enter button
#define UI_FLAGS_DISABLE_EXIT             0x04 // RW - Disable exit button
#define UI_FLAGS_REDRAW_STATUS            0x08 // W  - Redraw entire status line
#define UI_FLAGS_RESET_SLEEP_TIMER        0x10 // W  - Reset sleep timeout timer
#define UI_FLAGS_EXECUTE_LMS_FILE         0x20 // W  - Execute LMS file in "LMSfilename" (Try It)
#define UI_FLAGS_BUSY                     0x40 // R  - UI busy running or datalogging (popup disabled)
#define UI_FLAGS_ENABLE_STATUS_UPDATE     0x80 // W  - Enable status line to be updated

// Constants related to State
#define UI_STATE_INIT_DISPLAY       0 // RW - Init display and load font, menu etc.
#define UI_STATE_INIT_LOW_BATTERY   1 // R  - Low battery voltage at power on
#define UI_STATE_INIT_INTRO         2 // R  - Display intro
#define UI_STATE_INIT_WAIT          3 // RW - Wait for initialization end
#define UI_STATE_INIT_MENU          4 // RW - Init menu system
#define UI_STATE_NEXT_MENU          5 // RW - Next menu icons ready for drawing
#define UI_STATE_DRAW_MENU          6 // RW - Execute function and draw menu icons
#define UI_STATE_TEST_BUTTONS       7 // RW - Wait for buttons to be pressed
#define UI_STATE_LEFT_PRESSED       8 // RW - Load selected function and next menu id
#define UI_STATE_RIGHT_PRESSED      9 // RW - Load selected function and next menu id
#define UI_STATE_ENTER_PRESSED     10 // RW - Load selected function and next menu id
#define UI_STATE_EXIT_PRESSED      11 // RW - Load selected function and next menu id
#define UI_STATE_CONNECT_REQUEST   12 // RW - Request for connection accept
#define UI_STATE_EXECUTE_FILE      13 // RW - Execute file in "LMSfilename"
#define UI_STATE_EXECUTING_FILE    14 // R  - Executing file in "LMSfilename"
#define UI_STATE_LOW_BATTERY       15 // R  - Low battery at runtime
#define UI_STATE_BT_ERROR          16 // R  - BT error

// Constants related to Button
#define UI_BUTTON_NONE             0 // R  - Button inserted are executed
#define UI_BUTTON_LEFT             1 // W  - Insert left arrow button
#define UI_BUTTON_ENTER            2 // W  - Insert enter button
#define UI_BUTTON_RIGHT            3 // W  - Insert right arrow button
#define UI_BUTTON_EXIT             4 // W  - Insert exit button

// Constants related to BlueToothState
#define UI_BT_STATE_VISIBLE        0x01 // RW - BT visible
#define UI_BT_STATE_CONNECTED      0x02 // RW - BT connected to something
#define UI_BT_STATE_OFF            0x04 // RW - BT power off
#define UI_BT_ERROR_ATTENTION      0x08 // W  - BT error attention
#define UI_BT_CONNECT_REQUEST      0x40 // RW - BT get connect accept in progress
#define UI_BT_PIN_REQUEST          0x80 // RW - BT get pin code

// offsets
#define UIOffsetPMenu            0 // W  - Pointer to menu file (4 bytes)
#define UIOffsetBatteryVoltage   4 // R  - Battery voltage in millivolts (2 bytes)
#define UIOffsetLMSfilename      6 // W  - LMS filename to execute (Try It) (20 bytes)
#define UIOffsetFlags           26 // RW - Update command flags  (flags enumerated above) (1 byte)
#define UIOffsetState           27 // RW - UI state              (states enumerated above) (1 byte)
#define UIOffsetButton          28 // RW - Insert button         (buttons enumerated above) (1 byte)
#define UIOffsetRunState        29 // W  - VM Run state          (0 = stopped, 1 = running) (1 byte)
#define UIOffsetBatteryState    30 // W  - Battery state         (0..4 capacity) (1 byte)
#define UIOffsetBluetoothState  31 // W  - Bluetooth state       (0=on, 1=visible, 2=conn, 3=conn.visible, 4=off, 5=dfu) (1 byte)
#define UIOffsetUsbState        32 // W  - Usb state             (0=disconnected, 1=connected, 2=working) (1 byte)
#define UIOffsetSleepTimeout    33 // RW - Sleep timeout time    (min) (1 byte)
#define UIOffsetSleepTimer      34 // RW - Sleep timer           (min) (1 byte)
#define UIOffsetRechargeable    35 // R  - Rechargeable battery  (0 = no, 1 = yes) (1 byte)
#define UIOffsetVolume          36 // RW - Volume used in UI     (0 - 4) (1 byte)
#define UIOffsetError           37 // W  - Error code (1 byte)
#define UIOffsetOBPPointer      38 // W  - Actual OBP step       (0 - 4) (1 byte)
#define UIOffsetForceOff        39 // W  - Force off             (> 0 = off) (1 byte)
#define UIOffsetAbortFlag       40 // RW - Long Abort            (true == use long press to abort) (1 byte)

/** @} */  // end of UiModuleConstants group
/** @} */  // end of UiModule group


/** @addtogroup InputModule
 * @{
 */
/** @defgroup InputModuleConstants Input module constants.
 * Constants that are part of the NXT firmware's Input module.
 * @{
 */
#define InputModuleName "Input.mod" /*!< */
#define InputModuleID   0x00030001 /*!< */

// Constants related to Digital I/O
#define INPUT_DIGI0 1 /*!< */
#define INPUT_DIGI1 2 /*!< */

#define INPUT_CUSTOMINACTIVE 0x00 /*!< */
#define INPUT_CUSTOM9V       0x01 /*!< */
#define INPUT_CUSTOMACTIVE   0x02 /*!< */

#define INPUT_INVALID_DATA   0x01 /*!< */

#if __FIRMWARE_VERSION > 107

// constants related to Colorstruct
#define INPUT_RED          0 /*!< */
#define INPUT_GREEN        1 /*!< */
#define INPUT_BLUE         2 /*!< */
#define INPUT_BLANK        3 /*!< */
#define INPUT_NO_OF_COLORS 4 /*!< */

// color sensor value when used as color detector
#define INPUT_BLACKCOLOR  1 /*!< */
#define INPUT_BLUECOLOR   2 /*!< */
#define INPUT_GREENCOLOR  3 /*!< */
#define INPUT_YELLOWCOLOR 4 /*!< */
#define INPUT_REDCOLOR    5 /*!< */
#define INPUT_WHITECOLOR  6 /*!< */

// color calibration state
#define INPUT_SENSORCAL  0x01 /*!< */
#define INPUT_SENSOROFF  0x02 /*!< */
#define INPUT_RUNNINGCAL 0x20 /*!< */
#define INPUT_STARTCAL   0x40 /*!< */
#define INPUT_RESETCAL   0x80 /*!< */

#define INPUT_CAL_POINT_0  0 /*!< */
#define INPUT_CAL_POINT_1  1 /*!< */
#define INPUT_CAL_POINT_2  2 /*!< */
#define INPUT_NO_OF_POINTS 3 /*!< */

#endif


// offsets
#define InputOffsetCustomZeroOffset(p)   (((p)*20)+0) // Set the offset of the custom sensor (2 bytes) uword
#define InputOffsetADRaw(p)              (((p)*20)+2) // (2 bytes) uword
#define InputOffsetSensorRaw(p)          (((p)*20)+4) // (2 bytes) uword
#define InputOffsetSensorValue(p)        (((p)*20)+6) // (2 bytes) sword
#define InputOffsetSensorType(p)         (((p)*20)+8)
#define InputOffsetSensorMode(p)         (((p)*20)+9)
#define InputOffsetSensorBoolean(p)      (((p)*20)+10)
#define InputOffsetDigiPinsDir(p)        (((p)*20)+11) // Direction of the Digital pins 1 is output 0 is input
#define InputOffsetDigiPinsIn(p)         (((p)*20)+12) // Contains the status of the digital pins
#define InputOffsetDigiPinsOut(p)        (((p)*20)+13) // Sets the output level of the digital pins
#define InputOffsetCustomPctFullScale(p) (((p)*20)+14) // Sets the Pct full scale of the custom sensor
#define InputOffsetCustomActiveStatus(p) (((p)*20)+15) // Sets the active or inactive state of the custom sensor
#define InputOffsetInvalidData(p)        (((p)*20)+16) // Indicates whether data is invalid (1) or valid (0)

#if __FIRMWARE_VERSION > 107
// color structure offsets
#define InputOffsetColorCalibration(p, np, nc) (80+((p)*84)+0+((np)*16)+((nc)*4)) /*!< */
#define InputOffsetColorCalLimits(p, np)       (80+((p)*84)+48+((np)*2)) /*!< */
#define InputOffsetColorADRaw(p, nc)           (80+((p)*84)+52+((nc)*2)) /*!< */
#define InputOffsetColorSensorRaw(p, nc)       (80+((p)*84)+60+((nc)*2)) /*!< */
#define InputOffsetColorSensorValue(p, nc)     (80+((p)*84)+68+((nc)*2)) /*!< */
#define InputOffsetColorSensorBoolean(p, nc)   (80+((p)*84)+76+((nc)*2)) /*!< */
#define InputOffsetColorCalibrationState(p)    (80+((p)*84)+80) /*!< */
#endif
/** @} */  // end of InputModuleConstants group
/** @} */  // end of InputModule group


/** @addtogroup OutputModule
 * @{
 */
/** @defgroup OutputModuleConstants Output module constants.
 * Constants that are part of the NXT firmware's Output module.
 * @{
 */
#define OutputModuleName "Output.mod"
#define OutputModuleID   0x00020001

// offsets
#define OutputOffsetTachoCount(p)        (((p)*32)+0)  // R  - Holds current number of counts, since last reset, updated every 1 mS (4 bytes) slong
#define OutputOffsetBlockTachoCount(p)   (((p)*32)+4)  // R  - Holds current number of counts for the current output block (4 bytes) slong
#define OutputOffsetRotationCount(p)     (((p)*32)+8)  // R  - Holds current number of counts for the rotation counter to the output (4 bytes) slong
#define OutputOffsetTachoLimit(p)        (((p)*32)+12) // RW - Holds number of counts to travel, 0 => Run forever (4 bytes) ulong
#define OutputOffsetMotorRPM(p)          (((p)*32)+16) // !! Is not updated, will be removed later !! (2 bytes) sword
#define OutputOffsetFlags(p)             (((p)*32)+18) // RW - Holds flags for which data should be updated (1 byte) ubyte
#define OutputOffsetMode(p)              (((p)*32)+19) // RW - Holds motor mode: Run, Break, regulated, ... (1 byte) ubyte
#define OutputOffsetSpeed(p)             (((p)*32)+20) // RW - Holds the wanted speed (1 byte) sbyte
#define OutputOffsetActualSpeed(p)       (((p)*32)+21) // R  - Holds the current motor speed (1 byte) sbyte
#define OutputOffsetRegPParameter(p)     (((p)*32)+22) // RW - Holds the P-constant used in the regulation (1 byte) ubyte
#define OutputOffsetRegIParameter(p)     (((p)*32)+23) // RW - Holds the I-constant used in the regulation (1 byte) ubyte
#define OutputOffsetRegDParameter(p)     (((p)*32)+24) // RW - Holds the D-constant used in the regulation (1 byte) ubyte
#define OutputOffsetRunState(p)          (((p)*32)+25) // RW - Holds the current RunState in the output module (1 byte) ubyte
#define OutputOffsetRegMode(p)           (((p)*32)+26) // RW - Tells which regulation mode should be used (1 byte) ubyte
#define OutputOffsetOverloaded(p)        (((p)*32)+27) // R  - True if the motor has been overloaded within speed control regulation (1 byte) ubyte
#define OutputOffsetSyncTurnParameter(p) (((p)*32)+28) // RW - Holds the turning parameter need within MoveBlock (1 byte) sbyte
#if defined(__ENHANCED_FIRMWARE) && (__FIRMWARE_VERSION > 107)
#define OutputOffsetOptions(p)           (((p)*32)+29) /*!< */
#endif
#define OutputOffsetPwnFreq              96 /*!< */
/** @} */  // end of OutputModuleConstants group
/** @} */  // end of OutputModule group


/** @addtogroup LowSpeedModule
 * @{
 */
/** @defgroup LowSpeedModuleConstants LowSpeed module constants.
 * Constants that are part of the NXT firmware's LowSpeed module.
 * @{
 */
#define LowSpeedModuleName "Low Speed.mod" /*!< */
#define LowSpeedModuleID   0x000B0001 /*!< */

//Constants referring to LowSpeedDeviceType
#define LS_DEVTYPE_ULTRA_SONIC       2 /*!< */
#define LS_DEVTYPE_CUSTOM_LS_DEVICE  3 /*!< */

// Constants referring to State
#define COM_CHANNEL_NONE_ACTIVE  0x00 /*!< */
#define COM_CHANNEL_ONE_ACTIVE   0x01 /*!< */
#define COM_CHANNEL_TWO_ACTIVE   0x02 /*!< */
#define COM_CHANNEL_THREE_ACTIVE 0x04 /*!< */
#define COM_CHANNEL_FOUR_ACTIVE  0x08 /*!< */

// Constants referring to ChannelState
#define LOWSPEED_IDLE          0 /*!< */
#define LOWSPEED_INIT          1 /*!< */
#define LOWSPEED_LOAD_BUFFER   2 /*!< */
#define LOWSPEED_COMMUNICATING 3 /*!< */
#define LOWSPEED_ERROR         4 /*!< */
#define LOWSPEED_DONE          5 /*!< */

// Constants referring to Mode
#define LOWSPEED_TRANSMITTING   1 /*!< */
#define LOWSPEED_RECEIVING      2 /*!< */
#define LOWSPEED_DATA_RECEIVED  3 /*!< */

// Constants referring to ErrorType
#define LOWSPEED_NO_ERROR     0 /*!< */
#define LOWSPEED_CH_NOT_READY 1 /*!< */
#define LOWSPEED_TX_ERROR     2 /*!< */
#define LOWSPEED_RX_ERROR     3 /*!< */

// offsets
#define LowSpeedOffsetInBufBuf(p)       (((p)*19)+0) /*!< */
#define LowSpeedOffsetInBufInPtr(p)     (((p)*19)+16) /*!< */
#define LowSpeedOffsetInBufOutPtr(p)    (((p)*19)+17) /*!< */
#define LowSpeedOffsetInBufBytesToRx(p) (((p)*19)+18) /*!< */

#define LowSpeedOffsetOutBufBuf(p)       (((p)*19)+76) /*!< */
#define LowSpeedOffsetOutBufInPtr(p)     (((p)*19)+92) /*!< */
#define LowSpeedOffsetOutBufOutPtr(p)    (((p)*19)+93) /*!< */
#define LowSpeedOffsetOutBufBytesToRx(p) (((p)*19)+94) /*!< */

#define LowSpeedOffsetMode(p)            ((p)+152) /*!< */
#define LowSpeedOffsetChannelState(p)    ((p)+156) /*!< */
#define LowSpeedOffsetErrorType(p)       ((p)+160) /*!< */

#define LowSpeedOffsetState            164 /*!< */
#define LowSpeedOffsetSpeed            165 /*!< */

#ifdef __ENHANCED_FIRMWARE
#define LowSpeedOffsetNoRestartOnRead  166 /*!< */

#define LSREAD_RESTART_ALL     0x00 /*!< */
#define LSREAD_NO_RESTART_1    0x01 /*!< */
#define LSREAD_NO_RESTART_2    0x02 /*!< */
#define LSREAD_NO_RESTART_3    0x04 /*!< */
#define LSREAD_NO_RESTART_4    0x08 /*!< */
#define LSREAD_RESTART_NONE    0x0F /*!< */
#define LSREAD_NO_RESTART_MASK 0x10 /*!< */

#endif

// generic I2C device constants
#define I2C_REG_VERSION   0x00 /*!< */
#define I2C_REG_VENDOR_ID 0x08 /*!< */
#define I2C_REG_DEVICE_ID 0x10 /*!< */
#define I2C_REG_CMD       0x41 /*!< */

//Ultrasonic sensor constants
#define US_CMD_OFF           0x00 /*!< */
#define US_CMD_SINGLESHOT    0x01 /*!< */
#define US_CMD_CONTINUOUS    0x02 /*!< */
#define US_CMD_EVENTCAPTURE  0x03 /*!< */
#define US_CMD_WARMRESET     0x04 /*!< */

#define US_REG_CM_INTERVAL   0x40 /*!< */
#define US_REG_ACTUAL_ZERO   0x50 /*!< */
#define US_REG_SCALE_FACTOR  0x51 /*!< */
#define US_REG_SCALE_DIVISOR 0x52 /*!< */

#define US_REG_FACTORY_ACTUAL_ZERO   0x11 /*!< */
#define US_REG_FACTORY_SCALE_FACTOR  0x12 /*!< */
#define US_REG_FACTORY_SCALE_DIVISOR 0x13 /*!< */
#define US_REG_MEASUREMENT_UNITS     0x14 /*!< */


// LEGO temperature configuration constants (OR together as needed)
// R1/R0
#define TEMP_RES_12BIT     0x60 /*!< */
#define TEMP_RES_11BIT     0x40 /*!< */
#define TEMP_RES_10BIT     0x20 /*!< */
#define TEMP_RES_9BIT      0x00 /*!< */
// SD (shutdown mode)
#define TEMP_SD_CONTINUOUS 0x00 /*!< */
#define TEMP_SD_SHUTDOWN   0x01 /*!< */
// TM (thermostat mode)
#define TEMP_TM_COMPARATOR 0x00 /*!< */
#define TEMP_TM_INTERRUPT  0x02 /*!< */
// OS (one shot)
#define TEMP_OS_ONESHOT    0x80 /*!< */
// F1/F0 (fault queue)
#define TEMP_FQ_1          0x00 /*!< */
#define TEMP_FQ_2          0x08 /*!< */
#define TEMP_FQ_4          0x10 /*!< */
#define TEMP_FQ_6          0x18 /*!< */
// POL (polarity)
#define TEMP_POL_LOW       0x00 /*!< */
#define TEMP_POL_HIGH      0x04 /*!< */

#define TEMP_I2C_ADDRESS   0x98 /*!< */
#define TEMP_REG_TEMP      0x00 /*!< */
#define TEMP_REG_CONFIG    0x01 /*!< */
#define TEMP_REG_TLOW      0x02 /*!< */
#define TEMP_REG_THIGH     0x03 /*!< */

/** @} */  // end of LowSpeedModuleConstants group
/** @} */  // end of LowSpeedModule group


/** @addtogroup DisplayModule
 * @{
 */
/** @defgroup DisplayModuleConstants Display module constants.
 * Constants that are part of the NXT firmware's Display module.
 * @{
 */
#define DisplayModuleName "Display.mod" /*!< */
#define DisplayModuleID   0x000A0001 /*!< */

// Constants related to simple draw entry (x = dont care)
#define DISPLAY_ERASE_ALL       0x00     // W - erase entire screen     (CMD,x,x,x,x,x)
#define DISPLAY_PIXEL           0x01     // W - set pixel (on/off)      (CMD,TRUE/FALSE,X,Y,x,x)
#define DISPLAY_HORIZONTAL_LINE 0x02     // W - draw horizontal line    (CMD,TRUE/FALSE,X1,Y1,X2,x)
#define DISPLAY_VERTICAL_LINE   0x03     // W - draw vertical line      (CMD,TRUE/FALSE,X1,Y1,x,Y2)
#define DISPLAY_CHAR            0x04     // W - draw char (actual font) (CMD,TRUE,X1,Y1,Char,x)
#define DISPLAY_ERASE_LINE      0x05     // W - erase a single line     (CMD,x,LINE,x,x,x)
#define DISPLAY_FILL_REGION     0x06     // W - fill screen region      (CMD,TRUE/FALSE,X1,Y1,X2,Y2)
#define DISPLAY_FRAME           0x07     // W - draw a frame (on/off)   (CMD,TRUE/FALSE,X1,Y1,X2,Y2)

#define DRAW_OPT_NORMAL                     (0x0000) /*!< */
#define DRAW_OPT_LOGICAL_COPY               (0x0000) /*!< */

#define DRAW_OPT_CLEAR_WHOLE_SCREEN         (0x0001) /*!< */
#define DRAW_OPT_CLEAR_EXCEPT_STATUS_SCREEN (0x0002) /*!< */
#define DRAW_OPT_CLEAR_PIXELS               (0x0004) /*!< */
#define DRAW_OPT_CLEAR                      (0x0004) /*!< */
#define DRAW_OPT_INVERT                     (0x0004) /*!< */
#define DRAW_OPT_LOGICAL_AND                (0x0008) /*!< */
#define DRAW_OPT_LOGICAL_OR                 (0x0010) /*!< */
#define DRAW_OPT_LOGICAL_XOR                (0x0018) /*!< */
#define DRAW_OPT_FILL_SHAPE                 (0x0020) /*!< */

// Combined parameter masks:
#define DRAW_OPT_CLEAR_SCREEN_MODES         (0x0003) /*!< */
#define DRAW_OPT_LOGICAL_OPERATIONS         (0x0018) /*!< */
#define DRAW_OPT_FONT_DIRECTIONS            (0x01C0) /*!< */

#define DRAW_OPT_FONT_WRAP       (0x0200) /*!< */

#define DRAW_OPT_FONT_DIR_L2RB   (0x0000)           // Font left to right bottom align
#define DRAW_OPT_FONT_DIR_L2RT   (0x0040)           // Font left to right top align
#define DRAW_OPT_FONT_DIR_R2LB   (0x0080)           // Font right to left bottom align
#define DRAW_OPT_FONT_DIR_R2LT   (0x00C0)           // Font right to left top align
#define DRAW_OPT_FONT_DIR_B2TL   (0x0100)           // Font bottom to top left align
#define DRAW_OPT_FONT_DIR_B2TR   (0x0140)           // Font bottom to top right align
#define DRAW_OPT_FONT_DIR_T2BL   (0x0180)           // Font top to bottom left align
#define DRAW_OPT_FONT_DIR_T2BR   (0x01C0)           // Font top to bottom right align

// Constants related to Flags
#define DISPLAY_ON               0x01     // W  - Display on
#define DISPLAY_REFRESH          0x02     // W  - Enable refresh
#define DISPLAY_POPUP            0x08     // W  - Use popup display memory
#define DISPLAY_REFRESH_DISABLED 0x40     // R  - Refresh disabled
#define DISPLAY_BUSY             0x80     // R  - Refresh in progress

#if defined(__ENHANCED_FIRMWARE) && (__FIRMWARE_VERSION > 107)
// Constants related to Contrast
#define DISPLAY_CONTRAST_DEFAULT 0x5A /*!< */
#define DISPLAY_CONTRAST_MAX     0x7F /*!< */
#endif

#define SCREEN_MODE_RESTORE 0x00 /*!< */
#define SCREEN_MODE_CLEAR   0x01 /*!< */

#define DISPLAY_HEIGHT 64 /*!< */
#define DISPLAY_WIDTH  100 /*!< */

#define DISPLAY_MENUICONS_Y       40 /*!< */
#define DISPLAY_MENUICONS_X_OFFS  7 /*!< */
#define DISPLAY_MENUICONS_X_DIFF  31 /*!< */

// Used in macro "TEXTLINE_BIT"
#define TEXTLINE_1 0 /*!< */
#define TEXTLINE_2 1 /*!< */
#define TEXTLINE_3 2 /*!< */
#define TEXTLINE_4 3 /*!< */
#define TEXTLINE_5 4 /*!< */
#define TEXTLINE_6 5 /*!< */
#define TEXTLINE_7 6 /*!< */
#define TEXTLINE_8 7 /*!< */
#define TEXTLINES  8 /*!< */

// Used in macro "MENUICON_BIT"
#define MENUICON_LEFT   0 // Left icon /*!< */
#define MENUICON_CENTER 1 // Center icon /*!< */
#define MENUICON_RIGHT  2 // Right icon /*!< */
#define MENUICONS       3 /*!< */

// Used in macro "SPECIAL_BIT"
#define FRAME_SELECT 0   // Center icon select frame /*!< */
#define STATUSTEXT   1   // Status text (BT name) /*!< */
#define MENUTEXT     2   // Center icon text /*!< */
#define STEPLINE     3   // Step collection lines /*!< */
#define TOPLINE      4   // Top status underline /*!< */
#define SPECIALS     5 /*!< */

// Used in macro "STATUSICON_BIT"
#define STATUSICON_BLUETOOTH 0 // BlueTooth status icon collection /*!< */
#define STATUSICON_USB       1 // USB status icon collection /*!< */
#define STATUSICON_VM        2 // VM status icon collection /*!< */
#define STATUSICON_BATTERY   3 // Battery status icon collection /*!< */
#define STATUSICONS          4 /*!< */

// Used in macro "SCREEN_BIT"
#define SCREEN_BACKGROUND 0 // Entire screen /*!< */
#define SCREEN_LARGE      1 // Entire screen except status line /*!< */
#define SCREEN_SMALL      2 // Screen between menu icons and status line /*!< */
#define SCREENS           3 /*!< */

// Used in macro "BITMAP_BIT"
#define BITMAP_1 0 // Bitmap 1 /*!< */
#define BITMAP_2 1 // Bitmap 2 /*!< */
#define BITMAP_3 2 // Bitmap 3 /*!< */
#define BITMAP_4 3 // Bitmap 4 /*!< */
#define BITMAPS  4 /*!< */

// Used in macro "STEPICON_BIT"
#define STEPICON_1 0 // Left most step icon /*!< */
#define STEPICON_2 1 // /*!< */
#define STEPICON_3 2 // /*!< */
#define STEPICON_4 3 // /*!< */
#define STEPICON_5 4 // Right most step icon /*!< */
#define STEPICONS  5 /*!< */

#define SCREEN_BITS     (0xE0000000)  // Executed as 1. /*!< */
#define STEPICON_BITS   (0x1F000000)  // Executed as 2. /*!< */
#define BITMAP_BITS     (0x00F00000)  // Executed as 3. /*!< */
#define MENUICON_BITS   (0x000E0000)  // Executed as 4. /*!< */
#define STATUSICON_BITS (0x0001E000)  // Executed as 5. /*!< */
#define SPECIAL_BITS    (0x00001F00)  // Executed as 6. /*!< */
#define TEXTLINE_BITS   (0x000000FF)  // Executed as 7. /*!< */

#define SCREEN_BIT(No)     (0x20000000<<(No)) /*!< */
#define STEPICON_BIT(No)   (0x01000000<<(No)) /*!< */
#define BITMAP_BIT(No)     (0x00100000<<(No)) /*!< */
#define MENUICON_BIT(No)   (0x00020000<<(No)) /*!< */
#define STATUSICON_BIT(No) (0x00002000<<(No)) /*!< */
#define SPECIAL_BIT(No)    (0x00000100<<(No)) /*!< */
#define TEXTLINE_BIT(No)   (0x00000001<<(No)) /*!< */

// offsets
#define DisplayOffsetPFunc          0 // Simple draw entry
#define DisplayOffsetEraseMask      4 // Section erase mask   (executed first)
#define DisplayOffsetUpdateMask     8 // Section update mask  (executed next)
#define DisplayOffsetPFont          12 // Pointer to font file
#define DisplayOffsetPTextLines(p)  (((p)*4)+16)  // Pointer to text strings
#define DisplayOffsetPStatusText    48 // Pointer to status text string
#define DisplayOffsetPStatusIcons   52 // Pointer to status icon collection file
#define DisplayOffsetPScreens(p)    (((p)*4)+56) // Pointer to screen bitmap file
#define DisplayOffsetPBitmaps(p)    (((p)*4)+68) // Pointer to free bitmap files
#define DisplayOffsetPMenuText      84 // Pointer to menu icon text (NULL == none)
#define DisplayOffsetPMenuIcons(p)  (((p)*4)+88) // Pointer to menu icon images (NULL == none)
#define DisplayOffsetPStepIcons     100 // Pointer to step icon collection file
#define DisplayOffsetDisplay        104 // Display content copied to physical display every 17 mS
#define DisplayOffsetStatusIcons(p) ((p)+108) // Index in status icon collection file (index = 0 -> none)
#define DisplayOffsetStepIcons(p)   ((p)+112) // Index in step icon collection file (index = 0 -> none)
#define DisplayOffsetFlags          117 // Update flags enumerated above
#define DisplayOffsetTextLinesCenterFlags 118 // Mask to center TextLines
#define DisplayOffsetNormal(l,w)    (((l)*100)+(w)+119) // Raw display memory for normal screen
#define DisplayOffsetPopup(l,w)     (((l)*100)+(w)+919) // Raw display memory for popup screen

#if defined(__ENHANCED_FIRMWARE) && (__FIRMWARE_VERSION > 107)
#define DisplayOffsetContrast       1719 /*!< */
#endif
/** @} */  // end of DisplayModuleConstants group
/** @} */  // end of DisplayModule group


/** @addtogroup CommModule
 * @{
 */
/** @defgroup CommModuleConstants Comm module constants.
 * Constants that are part of the NXT firmware's Comm module.
 * @{
 */
#define CommModuleName "Comm.mod" /*!< The Comm module name */
#define CommModuleID   0x00050001 /*!< The Comm module ID */

#define SIZE_OF_USBBUF                64 /*!< Size of USB Buffer in bytes */
#define USB_PROTOCOL_OVERHEAD         2  /*!< Size of USB Overhead in bytes -- Command type byte + Command*/
#define SIZE_OF_USBDATA               62 /*!< Size of USB Buffer available for data */
#define SIZE_OF_HSBUF                 128 /*!< Size of High Speed Port 4 buffer */
#define SIZE_OF_BTBUF                 128 /*!< Size of Bluetooth buffer*/

#define BT_CMD_BYTE                   1 /*!< Size of Bluetooth command*/
#define SIZE_OF_BT_DEVICE_TABLE       30 /*!< Size of Bluetooth device table */
#define SIZE_OF_BT_CONNECT_TABLE      4 /*!< Size of Bluetooth connection table -- Index 0 is always incoming connection */
#define SIZE_OF_BT_NAME               16 /*!< Size of Bluetooth name */
#define SIZE_OF_BRICK_NAME            8 /*!< Size of NXT Brick name */
#define SIZE_OF_CLASS_OF_DEVICE       4 /*!< Size of class of device */
#define SIZE_OF_BT_PINCODE            16 /*!< Size of Bluetooth PIN */
#define SIZE_OF_BDADDR                7 /*!< Size of Bluetooth Address*/
#define MAX_BT_MSG_SIZE               60000 /*!< Max Bluetooth Message Size */

#define BT_DEFAULT_INQUIRY_MAX        0   /*!< Bluetooth default inquiry Max (0 == unlimited)*/
#define BT_DEFAULT_INQUIRY_TIMEOUT_LO 15  /*!< Bluetooth inquiry timeout (15*1.28 sec = 19.2 sec) */

#define BT_ARM_OFF              0 /*!< BtState constant bluetooth off */
#define BT_ARM_CMD_MODE         1 /*!< BtState constant bluetooth command mode */
#define BT_ARM_DATA_MODE        2 /*!< BtState constant bluetooth data mode */

#define BT_BRICK_VISIBILITY     0x01 /*!< BtStateStatus brick visibility bit */
#define BT_BRICK_PORT_OPEN      0x02 /*!< BtStateStatus port open bit */
#define BT_CONNECTION_0_ENABLE  0x10 /*!< BtStateStatus connection 0 enable/disable bit */
#define BT_CONNECTION_1_ENABLE  0x20 /*!< BtStateStatus connection 1 enable/disable bit */
#define BT_CONNECTION_2_ENABLE  0x40 /*!< BtStateStatus connection 2 enable/disable bit */
#define BT_CONNECTION_3_ENABLE  0x80 /*!< BtStateStatus connection 3 enable/disable bit */

#define BT_ENABLE               0x00 /*!< BtHwStatus bluetooth enable */
#define BT_DISABLE              0x01 /*!< BtHwStatus bluetooth disable */

#define HS_UPDATE 1 /*!< HsFlags high speed update required */

#define HS_INITIALISE    1 /*!< HsState initialize */
#define HS_INIT_RECEIVER 2 /*!< HsState initialize receiver */
#define HS_SEND_DATA     3 /*!< HsState send data */
#define HS_DISABLE       4 /*!< HsState disable */
#define HS_ENABLE        5 /*!< HsState enable */

#ifdef __ENHANCED_FIRMWARE

#define HS_CTRL_INIT 0 /*!< CommHSControl enable high speed port */
#define HS_CTRL_UART 1 /*!< CommHSControl setup high speed port */
#define HS_CTRL_EXIT 2 /*!< CommHSControl disable high speed port */

#if __FIRMWARE_VERSION > 107

#define HS_BAUD_1200     0 /*!< HsMode 1200 Baud */
#define HS_BAUD_2400     1 /*!< HsMode 2400 Baud */
#define HS_BAUD_3600     2 /*!< HsMode 3600 Baud */
#define HS_BAUD_4800     3 /*!< HsMode 4800 Baud */
#define HS_BAUD_7200     4 /*!< HsMode 7200 Baud */
#define HS_BAUD_9600     5 /*!< HsMode 9600 Baud */
#define HS_BAUD_14400    6 /*!< HsMode 14400 Baud */
#define HS_BAUD_19200    7 /*!< HsMode 19200 Baud */
#define HS_BAUD_28800    8 /*!< HsMode 28800 Baud */
#define HS_BAUD_38400    9 /*!< HsMode 38400 Baud */
#define HS_BAUD_57600   10 /*!< HsMode 57600 Baud */
#define HS_BAUD_76800   11 /*!< HsMode 76800 Baud */
#define HS_BAUD_115200  12 /*!< HsMode 115200 Baud */
#define HS_BAUD_230400  13 /*!< HsMode 230400 Baud */
#define HS_BAUD_460800  14 /*!< HsMode 460800 Baud */
#define HS_BAUD_921600  15 /*!< HsMode 921600 Baud */

// constants referring to HsMode (number of bits)
#define HS_MODE_5_DATA 0x0000 /*!< HsMode 5 data bits */
#define HS_MODE_6_DATA 0x0040 /*!< HsMode 6 data bits */
#define HS_MODE_7_DATA 0x0080 /*!< HsMode 7 data bits */
#define HS_MODE_8_DATA 0x00C0 /*!< HsMode 8 data bits */

// constants referring to HsMode (number of stop bits)
#define HS_MODE_10_STOP 0x0000 /*!< HsMode 1 stop bit */
#define HS_MODE_15_STOP 0x1000 /*!< HsMode 1.5 stop bits */
#define HS_MODE_20_STOP 0x2000 /*!< HsMode 2 stop bits */

// constants referring to HsMode (parity)
#define HS_MODE_E_PARITY 0x0000 /*!< HsMode Even parity */
#define HS_MODE_O_PARITY 0x0200 /*!< HsMode Odd parity */
#define HS_MODE_S_PARITY 0x0400 /*!< HsMode Space parity */
#define HS_MODE_M_PARITY 0x0600 /*!< HsMode Mark parity */
#define HS_MODE_N_PARITY 0x0800 /*!< HsMode No parity */

// constants referring to HsMode (D|P|S)
#define HS_MODE_8N1 (HS_MODE_8_DATA|HS_MODE_N_PARITY|HS_MODE_10_STOP) /*!< HsMode 8 data bits, no parity, 1 stop bit */
#define HS_MODE_7E1 (HS_MODE_7_DATA|HS_MODE_E_PARITY|HS_MODE_10_STOP) /*!< HsMode 7 data bits, even parity, 1 stop bit */

#endif

#endif

//Constants refering to DeviceStatus within DeviceTable
#define BT_DEVICE_EMPTY   0x00 /*!< Bluetooth device table empty */
#define BT_DEVICE_UNKNOWN 0x01 /*!< Bluetooth device unknown */
#define BT_DEVICE_KNOWN   0x02 /*!< Bluetooth device known */
#define BT_DEVICE_NAME    0x40 /*!< Bluetooth device name */
#define BT_DEVICE_AWAY    0x80 /*!< Bluetooth device away */

/* Interface between command other modules */
#define INTF_SENDFILE      0 /*!< ActiveUpdate send file */
#define INTF_SEARCH        1 /*!< ActiveUpdate search for connections */
#define INTF_STOPSEARCH    2 /*!< ActiveUpdate stop connection search */
#define INTF_CONNECT       3 /*!< ActiveUpdate connect */
#define INTF_DISCONNECT    4 /*!< ActiveUpdate disconnect */
#define INTF_DISCONNECTALL 5 /*!< ActiveUpdate disconnect all */
#define INTF_REMOVEDEVICE  6 /*!< ActiveUpdate remove device */
#define INTF_VISIBILITY    7 /*!< ActiveUpdate set visibility */
#define INTF_SETCMDMODE    8 /*!< ActiveUpdate set command mode */
#define INTF_OPENSTREAM    9 /*!< ActiveUpdate open stream */
#define INTF_SENDDATA      10 /*!< ActiveUpdate send data */
#define INTF_FACTORYRESET  11 /*!< ActiveUpdate factory reset */
#define INTF_BTON          12 /*!< ActiveUpdate turn on bluetooth */
#define INTF_BTOFF         13 /*!< ActiveUpdate turn off bluetooth */
#define INTF_SETBTNAME     14 /*!< ActiveUpdate set bluetooth name */
#define INTF_EXTREAD       15 /*!< ActiveUpdate external read */
#define INTF_PINREQ        16 /*!< ActiveUpdate pin request */
#define INTF_CONNECTREQ    17 /*!< ActiveUpdate connect request */

#if __FIRMWARE_VERSION > 107
#define INTF_CONNECTBYNAME 18 /*!< */
#endif

#define LR_SUCCESS        0x50 /*!< Bluetooth list result success */
#define LR_COULD_NOT_SAVE 0x51 /*!< Bluetooth list result could not save */
#define LR_STORE_IS_FULL  0x52 /*!< Bluetooth list result store is full */
#define LR_ENTRY_REMOVED  0x53 /*!< Bluetooth list result entry removed */
#define LR_UNKNOWN_ADDR   0x54 /*!< Bluetooth list result unknown address */

#define USB_CMD_READY     0x01 /*!< A constant representing usb direct command */
#define BT_CMD_READY      0x02 /*!< A constant representing bluetooth direct command */
#define HS_CMD_READY      0x04 /*!< A constant representing high speed direct command */


/** Comm module IOMAP offsets.
 * Constant offsets into the Comm module IOMAP structure.
 */
#define CommOffsetPFunc    0 /*!< Offset to the Comm module first function pointer */
#define CommOffsetPFuncTwo 4 /*!< Offset to the Comm module second function pointer */
// BtDeviceTable[30] (930 bytes)
#define CommOffsetBtDeviceTableName(p)           (((p)*31)+8) /*!< Offset to BT device table name */
#define CommOffsetBtDeviceTableClassOfDevice(p)  (((p)*31)+24) /*!< Offset to Bluetooth device table device class */
#define CommOffsetBtDeviceTableBdAddr(p)         (((p)*31)+28) /*!< Offset to Bluetooth device table address */
#define CommOffsetBtDeviceTableDeviceStatus(p)   (((p)*31)+35) /*!< Offset to Bluetooth device table status */
//  BDCONNECTTABLE BtConnectTable[4]; (188 bytes)
#define CommOffsetBtConnectTableName(p)          (((p)*47)+938) /*!< Offset to Bluetooth connect table name */
#define CommOffsetBtConnectTableClassOfDevice(p) (((p)*47)+954) /*!< Offset to Bluetooth connect table device class */
#define CommOffsetBtConnectTablePinCode(p)       (((p)*47)+958) /*!< Offset to Bluetooth connect table pin code */
#define CommOffsetBtConnectTableBdAddr(p)        (((p)*47)+974) /*!< Offset to Bluetooth connect table address */
#define CommOffsetBtConnectTableHandleNr(p)      (((p)*47)+981) /*!< Offset to Bluetooth connect table handle */
#define CommOffsetBtConnectTableStreamStatus(p)  (((p)*47)+982) /*!< Offset to Bluetooth connect table stream status */
#define CommOffsetBtConnectTableLinkQuality(p)   (((p)*47)+983) /*!< Offset to Bluetooth connect table link quality */
//General brick data
//  BRICKDATA      BrickData; (31 bytes)

#define CommOffsetBrickDataName            1126 /*!< Offset to brick name */
#define CommOffsetBrickDataBluecoreVersion 1142 /*!< Offset to Bluecore version */
#define CommOffsetBrickDataBdAddr          1144 /*!< Offset to Bluetooth address */
#define CommOffsetBrickDataBtStateStatus   1151 /*!< Offset to BtStateStatus */
#define CommOffsetBrickDataBtHwStatus      1152 /*!< Offset to BtHwStatus */
#define CommOffsetBrickDataTimeOutValue    1153 /*!< Offset to data timeout value */
//  BTBUF          BtInBuf; (132 bytes)
#define CommOffsetBtInBufBuf       1157 /*!< Offset to Bluetooth input buffer data */
#define CommOffsetBtInBufInPtr     1285 /*!< Offset to Bluetooth input buffer front pointer */
#define CommOffsetBtInBufOutPtr    1286 /*!< Offset to Bluetooth output buffer back pointer */
//  BTBUF          BtOutBuf; (132 bytes)
#define CommOffsetBtOutBufBuf      1289 /*!< Offset to Bluetooth output buffer offset data */
#define CommOffsetBtOutBufInPtr    1417 /*!< Offset to Bluetooth output buffer front pointer */
#define CommOffsetBtOutBufOutPtr   1418 /*!< Offset to Bluetooth output buffer back pointer */
// HI Speed related entries
//  HSBUF          HsInBuf; (132 bytes)
#define CommOffsetHsInBufBuf       1421 /*!< Offset to High Speed input buffer data */
#define CommOffsetHsInBufInPtr     1549 /*!< Offset to High Speed input buffer front pointer */
#define CommOffsetHsInBufOutPtr    1550 /*!< Offset to High Speed input buffer back pointer */
//  HSBUF          HsOutBuf; (132 bytes)
#define CommOffsetHsOutBufBuf      1553 /*!< Offset to High Speed output buffer data */
#define CommOffsetHsOutBufInPtr    1681 /*!< Offset to High Speed output buffer front pointer */
#define CommOffsetHsOutBufOutPtr   1682 /*!< Offset to High Speed output buffer back pointer */
// USB related entries
//  USBBUF         UsbInBuf; (68 bytes)
#define CommOffsetUsbInBufBuf        1685 /*!< Offset to Usb input buffer data */
#define CommOffsetUsbInBufInPtr      1749 /*!< Offset to Usb input buffer front pointer */
#define CommOffsetUsbInBufOutPtr     1750 /*!< Offset to Usb input buffer back pointer */
//  USBBUF         UsbOutBuf;
#define CommOffsetUsbOutBufBuf       1753 /*!< Offset to Usb output buffer data */
#define CommOffsetUsbOutBufInPtr     1817 /*!< Offset to Usb output buffer front pointer */
#define CommOffsetUsbOutBufOutPtr    1818 /*!< Offset to Usb output buffer back pointer */
//  USBBUF         UsbPollBuf;
#define CommOffsetUsbPollBufBuf      1821 /*!< Offset to Usb Poll buffer data */
#define CommOffsetUsbPollBufInPtr    1885 /*!< Offset to Usb Poll buffer front pointer */
#define CommOffsetUsbPollBufOutPtr   1886 /*!< Offset to Usb Poll buffer back pointer */

#define CommOffsetBtDeviceCnt      1889 /*!< Offset to Bluetooth device count */
#define CommOffsetBtDeviceNameCnt  1890 /*!< Offset to Bluetooth device name count */
#define CommOffsetHsFlags          1891 /*!< Offset to High Speed flags */
#define CommOffsetHsSpeed          1892 /*!< Offset to High Speed speed */
#define CommOffsetHsState          1893 /*!< Offset to High Spped state */
#define CommOffsetUsbState         1894 /*!< Offset to Usb State */
#define CommOffsetHsMode           1895 /*!< Offset to High Speed mode */
/** @} */  // end of DisplayModuleConstants group
/** @} */  // end of DisplayModule group


/** @defgroup RCXAPIConstants RCX constants.
 * Constants that are for use with devices that communicate with the RCX or
 * Scout programmable bricks via IR such as the HiTechnic IRLink or the
 * MindSensors nRLink.
 * @{
 */
#define RCX_OUT_A   0x01 /*!< */
#define RCX_OUT_B   0x02 /*!< */
#define RCX_OUT_C   0x04 /*!< */
#define RCX_OUT_AB  0x03 /*!< */
#define RCX_OUT_AC  0x05 /*!< */
#define RCX_OUT_BC  0x06 /*!< */
#define RCX_OUT_ABC 0x07 /*!< */

#define RCX_OUT_FLOAT 0 /*!< */
#define RCX_OUT_OFF   0x40 /*!< */
#define RCX_OUT_ON    0x80 /*!< */

#define RCX_OUT_REV    0 /*!< */
#define RCX_OUT_TOGGLE 0x40 /*!< */
#define RCX_OUT_FWD    0x80 /*!< */

#define RCX_OUT_LOW  0 /*!< */
#define RCX_OUT_HALF 3 /*!< */
#define RCX_OUT_FULL 7 /*!< */

#define RCX_RemoteKeysReleased 0x0000 /*!< */
#define RCX_RemotePBMessage1   0x0100 /*!< */
#define RCX_RemotePBMessage2   0x0200 /*!< */
#define RCX_RemotePBMessage3   0x0400 /*!< */
#define RCX_RemoteOutAForward  0x0800 /*!< */
#define RCX_RemoteOutBForward  0x1000 /*!< */
#define RCX_RemoteOutCForward  0x2000 /*!< */
#define RCX_RemoteOutABackward 0x4000 /*!< */
#define RCX_RemoteOutBBackward 0x8000 /*!< */
#define RCX_RemoteOutCBackward 0x0001 /*!< */
#define RCX_RemoteSelProgram1  0x0002 /*!< */
#define RCX_RemoteSelProgram2  0x0004 /*!< */
#define RCX_RemoteSelProgram3  0x0008 /*!< */
#define RCX_RemoteSelProgram4  0x0010 /*!< */
#define RCX_RemoteSelProgram5  0x0020 /*!< */
#define RCX_RemoteStopOutOff   0x0040 /*!< */
#define RCX_RemotePlayASound   0x0080 /*!< */

#define RCX_SOUND_CLICK       0 /*!< */
#define RCX_SOUND_DOUBLE_BEEP 1 /*!< */
#define RCX_SOUND_DOWN        2 /*!< */
#define RCX_SOUND_UP          3 /*!< */
#define RCX_SOUND_LOW_BEEP    4 /*!< */
#define RCX_SOUND_FAST_UP     5 /*!< */

#define SCOUT_LIGHT_ON        0x80 /*!< */
#define SCOUT_LIGHT_OFF       0 /*!< */

#define SCOUT_SOUND_REMOTE    6 /*!< */
#define SCOUT_SOUND_ENTERSA   7 /*!< */
#define SCOUT_SOUND_KEYERROR  8 /*!< */
#define SCOUT_SOUND_NONE      9 /*!< */

#define SCOUT_SOUND_TOUCH1_PRES     10 /*!< */
#define SCOUT_SOUND_TOUCH1_REL      11 /*!< */
#define SCOUT_SOUND_TOUCH2_PRES     12 /*!< */
#define SCOUT_SOUND_TOUCH2_REL      13 /*!< */
#define SCOUT_SOUND_ENTER_BRIGHT    14 /*!< */
#define SCOUT_SOUND_ENTER_NORMAL    15 /*!< */
#define SCOUT_SOUND_ENTER_DARK      16 /*!< */
#define SCOUT_SOUND_1_BLINK         17 /*!< */
#define SCOUT_SOUND_2_BLINK         18 /*!< */
#define SCOUT_SOUND_COUNTER1        19 /*!< */
#define SCOUT_SOUND_COUNTER2        20 /*!< */
#define SCOUT_SOUND_TIMER1          21 /*!< */
#define SCOUT_SOUND_TIMER2          22 /*!< */
#define SCOUT_SOUND_TIMER3          23 /*!< */
#define SCOUT_SOUND_MAIL_RECEIVED   24 /*!< */
#define SCOUT_SOUND_SPECIAL1        25 /*!< */
#define SCOUT_SOUND_SPECIAL2        26 /*!< */
#define SCOUT_SOUND_SPECIAL3        27 /*!< */

#define SCOUT_SNDSET_NONE           0 /*!< */
#define SCOUT_SNDSET_BASIC          1 /*!< */
#define SCOUT_SNDSET_BUG            2 /*!< */
#define SCOUT_SNDSET_ALARM          3 /*!< */
#define SCOUT_SNDSET_RANDOM         4 /*!< */
#define SCOUT_SNDSET_SCIENCE        5 /*!< */

#define SCOUT_MODE_STANDALONE       0 /*!< */
#define SCOUT_MODE_POWER            1 /*!< */

#define SCOUT_MR_NO_MOTION          0 /*!< */
#define SCOUT_MR_FORWARD            1 /*!< */
#define SCOUT_MR_ZIGZAG             2 /*!< */
#define SCOUT_MR_CIRCLE_RIGHT       3 /*!< */
#define SCOUT_MR_CIRCLE_LEFT        4 /*!< */
#define SCOUT_MR_LOOP_A             5 /*!< */
#define SCOUT_MR_LOOP_B             6 /*!< */
#define SCOUT_MR_LOOP_AB            7 /*!< */

#define SCOUT_TR_IGNORE             0 /*!< */
#define SCOUT_TR_REVERSE            1 /*!< */
#define SCOUT_TR_AVOID              2 /*!< */
#define SCOUT_TR_WAIT_FOR           3 /*!< */
#define SCOUT_TR_OFF_WHEN           4 /*!< */

#define SCOUT_LR_IGNORE             0 /*!< */
#define SCOUT_LR_SEEK_LIGHT         1 /*!< */
#define SCOUT_LR_SEEK_DARK          2 /*!< */
#define SCOUT_LR_AVOID              3 /*!< */
#define SCOUT_LR_WAIT_FOR           4 /*!< */
#define SCOUT_LR_OFF_WHEN           5 /*!< */

#define SCOUT_TGS_SHORT             0 /*!< */
#define SCOUT_TGS_MEDIUM            1 /*!< */
#define SCOUT_TGS_LONG              2 /*!< */

#define SCOUT_FXR_NONE              0 /*!< */
#define SCOUT_FXR_BUG               1 /*!< */
#define SCOUT_FXR_ALARM             2 /*!< */
#define SCOUT_FXR_RANDOM            3 /*!< */
#define SCOUT_FXR_SCIENCE           4 /*!< */

#define RCX_VariableSrc             0 /*!< */
#define RCX_TimerSrc                1 /*!< */
#define RCX_ConstantSrc             2 /*!< */
#define RCX_OutputStatusSrc         3 /*!< */
#define RCX_RandomSrc               4 /*!< */
#define RCX_ProgramSlotSrc          8 /*!< */
#define RCX_InputValueSrc           9 /*!< */
#define RCX_InputTypeSrc            10 /*!< */
#define RCX_InputModeSrc            11 /*!< */
#define RCX_InputRawSrc             12 /*!< */
#define RCX_InputBooleanSrc         13 /*!< */
#define RCX_WatchSrc                14 /*!< */
#define RCX_MessageSrc              15 /*!< */
#define RCX_GlobalMotorStatusSrc    17 /*!< */
#define RCX_ScoutRulesSrc           18 /*!< */
#define RCX_ScoutLightParamsSrc     19 /*!< */
#define RCX_ScoutTimerLimitSrc      20 /*!< */
#define RCX_CounterSrc              21 /*!< */
#define RCX_ScoutCounterLimitSrc    22 /*!< */
#define RCX_TaskEventsSrc           23 /*!< */
#define RCX_ScoutEventFBSrc         24 /*!< */
#define RCX_EventStateSrc           25 /*!< */
#define RCX_TenMSTimerSrc           26 /*!< */
#define RCX_ClickCounterSrc         27 /*!< */
#define RCX_UpperThresholdSrc       28 /*!< */
#define RCX_LowerThresholdSrc       29 /*!< */
#define RCX_HysteresisSrc           30 /*!< */
#define RCX_DurationSrc             31 /*!< */
#define RCX_UARTSetupSrc            33 /*!< */
#define RCX_BatteryLevelSrc         34 /*!< */
#define RCX_FirmwareVersionSrc      35 /*!< */
#define RCX_IndirectVarSrc          36 /*!< */
#define RCX_DatalogSrcIndirectSrc   37 /*!< */
#define RCX_DatalogSrcDirectSrc     38 /*!< */
#define RCX_DatalogValueIndirectSrc 39 /*!< */
#define RCX_DatalogValueDirectSrc   40 /*!< */
#define RCX_DatalogRawIndirectSrc   41 /*!< */
#define RCX_DatalogRawDirectSrc     42 /*!< */

#define RCX_PingOp           0x10 /*!< */
#define RCX_BatteryLevelOp   0x30 /*!< */
#define RCX_DeleteTasksOp    0x40 /*!< */
#define RCX_StopAllTasksOp   0x50 /*!< */
#define RCX_PBTurnOffOp      0x60 /*!< */
#define RCX_DeleteSubsOp     0x70 /*!< */
#define RCX_ClearSoundOp     0x80 /*!< */
#define RCX_ClearMsgOp       0x90 /*!< */
#define RCX_LSCalibrateOp    0xc0 /*!< */
#define RCX_MuteSoundOp      0xd0 /*!< */
#define RCX_UnmuteSoundOp    0xe0 /*!< */
#define RCX_ClearAllEventsOp 0x06 /*!< */
#define RCX_OnOffFloatOp     0x21 /*!< */
#define RCX_IRModeOp         0x31 /*!< */
#define RCX_PlaySoundOp      0x51 /*!< */
#define RCX_DeleteTaskOp     0x61 /*!< */
#define RCX_StartTaskOp      0x71 /*!< */
#define RCX_StopTaskOp       0x81 /*!< */
#define RCX_SelectProgramOp  0x91 /*!< */
#define RCX_ClearTimerOp     0xa1 /*!< */
#define RCX_AutoOffOp        0xb1 /*!< */
#define RCX_DeleteSubOp      0xc1 /*!< */
#define RCX_ClearSensorOp    0xd1 /*!< */
#define RCX_OutputDirOp      0xe1 /*!< */
#define RCX_PlayToneVarOp    0x02 /*!< */
#define RCX_PollOp           0x12 /*!< */
#define RCX_SetWatchOp       0x22 /*!< */
#define RCX_InputTypeOp      0x32 /*!< */
#define RCX_InputModeOp      0x42 /*!< */
#define RCX_SetDatalogOp     0x52 /*!< */
#define RCX_DatalogOp        0x62 /*!< */
#define RCX_SendUARTDataOp   0xc2 /*!< */
#define RCX_RemoteOp         0xd2 /*!< */
#define RCX_VLLOp            0xe2 /*!< */
#define RCX_DirectEventOp    0x03 /*!< */
#define RCX_OutputPowerOp    0x13 /*!< */
#define RCX_PlayToneOp       0x23 /*!< */
#define RCX_DisplayOp        0x33 /*!< */
#define RCX_PollMemoryOp     0x63 /*!< */
#define RCX_SetFeedbackOp    0x83 /*!< */
#define RCX_SetEventOp       0x93 /*!< */
#define RCX_GOutputPowerOp   0xa3 /*!< */
#define RCX_LSUpperThreshOp  0xb3 /*!< */
#define RCX_LSLowerThreshOp  0xc3 /*!< */
#define RCX_LSHysteresisOp   0xd3 /*!< */
#define RCX_LSBlinkTimeOp    0xe3 /*!< */
#define RCX_CalibrateEventOp 0x04 /*!< */
#define RCX_SetVarOp         0x14 /*!< */
#define RCX_SumVarOp         0x24 /*!< */
#define RCX_SubVarOp         0x34 /*!< */
#define RCX_DivVarOp         0x44 /*!< */
#define RCX_MulVarOp         0x54 /*!< */
#define RCX_SgnVarOp         0x64 /*!< */
#define RCX_AbsVarOp         0x74 /*!< */
#define RCX_AndVarOp         0x84 /*!< */
#define RCX_OrVarOp          0x94 /*!< */
#define RCX_UploadDatalogOp  0xa4 /*!< */
#define RCX_SetTimerLimitOp  0xc4 /*!< */
#define RCX_SetCounterOp     0xd4 /*!< */
#define RCX_SetSourceValueOp 0x05 /*!< */
#define RCX_UnlockOp         0x15 /*!< */
#define RCX_BootModeOp       0x65 /*!< */
#define RCX_UnlockFirmOp     0xa5 /*!< */
#define RCX_ScoutRulesOp     0xd5 /*!< */
#define RCX_ViewSourceValOp  0xe5 /*!< */
#define RCX_ScoutOp          0x47 /*!< */
#define RCX_SoundOp          0x57 /*!< */
#define RCX_GOutputModeOp    0x67 /*!< */
#define RCX_GOutputDirOp     0x77 /*!< */
#define RCX_LightOp          0x87 /*!< */
#define RCX_IncCounterOp     0x97 /*!< */
#define RCX_DecCounterOp     0xa7 /*!< */
#define RCX_ClearCounterOp   0xb7 /*!< */
#define RCX_SetPriorityOp    0xd7 /*!< */
#define RCX_MessageOp        0xf7 /*!< */
/** @} */  // end of RCXConstants group


/** @addtogroup HiTechnicAPI
 * @{
 */
/** @defgroup HiTechnicConstants HiTechnic device constants.
 * Constants that are for use with HiTechnic devices.
 * @{
 */
/** @defgroup HTIRLinkPFConstants HiTechnic Power Function/IR Train constants.
 * Constants that are for use with the HiTechnic IRLink in Power Function or IR Train mode.
 * @{
 */
#define PF_CMD_STOP  0 /*!< */
#define PF_CMD_FWD   1 /*!< */
#define PF_CMD_REV   2 /*!< */
#define PF_CMD_BRAKE 3 /*!< */

#define PF_CHANNEL_1 0 /*!< */
#define PF_CHANNEL_2 1 /*!< */
#define PF_CHANNEL_3 2 /*!< */
#define PF_CHANNEL_4 3 /*!< */

#define HTPF_CMD_STOP  0 /*!< */
#define HTPF_CMD_FWD   1 /*!< */
#define HTPF_CMD_REV   2 /*!< */
#define HTPF_CMD_BRAKE 3 /*!< */

#define HTPF_CHANNEL_1 0 /*!< */
#define HTPF_CHANNEL_2 1 /*!< */
#define HTPF_CHANNEL_3 2 /*!< */
#define HTPF_CHANNEL_4 3 /*!< */

#define PF_MODE_TRAIN             0 /*!< */
#define PF_MODE_COMBO_DIRECT      1 /*!< */
#define PF_MODE_SINGLE_PIN_CONT   2 /*!< */
#define PF_MODE_SINGLE_PIN_TIME   3 /*!< */
#define PF_MODE_COMBO_PWM         4 /*!< */
#define PF_MODE_SINGLE_OUTPUT_PWM 4 /*!< */
#define PF_MODE_SINGLE_OUTPUT_CST 6 /*!< */

#define TRAIN_FUNC_STOP         0 /*!< */
#define TRAIN_FUNC_INCR_SPEED   1 /*!< */
#define TRAIN_FUNC_DECR_SPEED   2 /*!< */
#define TRAIN_FUNC_TOGGLE_LIGHT 4 /*!< */

#define TRAIN_CHANNEL_1   0 /*!< */
#define TRAIN_CHANNEL_2   1 /*!< */
#define TRAIN_CHANNEL_3   2 /*!< */
#define TRAIN_CHANNEL_ALL 3 /*!< */

#define PF_OUT_A 0 /*!< */
#define PF_OUT_B 1 /*!< */

#define PF_PIN_C1 0 /*!< */
#define PF_PIN_C2 1 /*!< */

#define PF_FUNC_NOCHANGE 0 /*!< */
#define PF_FUNC_CLEAR    1 /*!< */
#define PF_FUNC_SET      2 /*!< */
#define PF_FUNC_TOGGLE   3 /*!< */

#define PF_CST_CLEAR1_CLEAR2 0 /*!< */
#define PF_CST_SET1_CLEAR2   1 /*!< */
#define PF_CST_CLEAR1_SET2   2 /*!< */
#define PF_CST_SET1_SET2     3 /*!< */
#define PF_CST_INCREMENT_PWM 4 /*!< */
#define PF_CST_DECREMENT_PWM 5 /*!< */
#define PF_CST_FULL_FWD      6 /*!< */
#define PF_CST_FULL_REV      7 /*!< */
#define PF_CST_TOGGLE_DIR    8 /*!< */

#define PF_PWM_FLOAT 0 /*!< */
#define PF_PWM_FWD1  1 /*!< */
#define PF_PWM_FWD2  2 /*!< */
#define PF_PWM_FWD3  3 /*!< */
#define PF_PWM_FWD4  4 /*!< */
#define PF_PWM_FWD5  5 /*!< */
#define PF_PWM_FWD6  6 /*!< */
#define PF_PWM_FWD7  7 /*!< */
#define PF_PWM_BRAKE 8 /*!< */
#define PF_PWM_REV7  9 /*!< */
#define PF_PWM_REV6  10 /*!< */
#define PF_PWM_REV5  11 /*!< */
#define PF_PWM_REV4  12 /*!< */
#define PF_PWM_REV3  13 /*!< */
#define PF_PWM_REV2  14 /*!< */
#define PF_PWM_REV1  15 /*!< */
/** @} */  // end of HTIRLinkPFConstants group

/** @defgroup HTIRSeeker2Constants HiTechnic IRSeeker2 constants.
 * Constants that are for use with the HiTechnic IRSeeker2 device.
 * @{
 */
#define HTIR2_MODE_1200 0 /*!< */
#define HTIR2_MODE_600  1 /*!< */

#define HTIR2_ADDR_MODE  0x41 /*!< */
#define HTIR2_ADDR_DCDIR 0x42 /*!< */
#define HTIR2_ADDR_DC01  0x43 /*!< */
#define HTIR2_ADDR_DC02  0x44 /*!< */
#define HTIR2_ADDR_DC03  0x45 /*!< */
#define HTIR2_ADDR_DC04  0x46 /*!< */
#define HTIR2_ADDR_DC05  0x47 /*!< */
#define HTIR2_ADDR_DCAVG 0x48 /*!< */
#define HTIR2_ADDR_ACDIR 0x49 /*!< */
#define HTIR2_ADDR_AC01  0x4A /*!< */
#define HTIR2_ADDR_AC02  0x4B /*!< */
#define HTIR2_ADDR_AC03  0x4C /*!< */
#define HTIR2_ADDR_AC04  0x4D /*!< */
#define HTIR2_ADDR_AC05  0x4E /*!< */
/** @} */  // end of HTIRSeeker2Constants group

/** @defgroup HTIRReceiverConstants HiTechnic IRReceiver constants.
 * Constants that are for use with the HiTechnic IRReceiver device.
 * @{
 */
#define HT_CH1_A 0 /*!< */
#define HT_CH1_B 1 /*!< */
#define HT_CH2_A 2 /*!< */
#define HT_CH2_B 3 /*!< */
#define HT_CH3_A 4 /*!< */
#define HT_CH3_B 5 /*!< */
#define HT_CH4_A 6 /*!< */
#define HT_CH4_B 7 /*!< */
/** @} */  // end of HTIRSeeker2Constants group

/** @defgroup HTColor2Constants HiTechnic Color2 constants.
 * Constants that are for use with the HiTechnic Color2 device.
 * @{
 */
#define HT_CMD_COLOR2_ACTIVE  0x00 /*!< */
#define HT_CMD_COLOR2_PASSIVE 0x01 /*!< */
#define HT_CMD_COLOR2_RAW     0x03 /*!< */
#define HT_CMD_COLOR2_50HZ    0x35 /*!< */
#define HT_CMD_COLOR2_60HZ    0x36 /*!< */
#define HT_CMD_COLOR2_BLCAL   0x42 /*!< */
#define HT_CMD_COLOR2_WBCAL   0x43 /*!< */
#define HT_CMD_COLOR2_FAR     0x46 /*!< */
#define HT_CMD_COLOR2_LED_HI  0x48 /*!< */
#define HT_CMD_COLOR2_LED_LOW 0x4C /*!< */
#define HT_CMD_COLOR2_NEAR    0x4E /*!< */
/** @} */  // end of HTColor2Constants group

/** @} */  // end of HiTechnicConstants group
/** @} */  // end of HiTechnicAPI group


/** @addtogroup MindSensorsAPI
 * @{
 */
/** @defgroup MindSensorsConstants MindSensors device constants.
 * Constants that are for use with MindSensors devices.
 * @{
 */
// MindSensors constants
#define MS_CMD_ENERGIZED   0x45 /*!< */
#define MS_CMD_DEENERGIZED 0x44 /*!< */
#define MS_CMD_ADPA_ON     0x4E /*!< */
#define MS_CMD_ADPA_OFF    0x4F /*!< */

/** @defgroup MSDistNX MindSensors DIST-Nx constants.
 * Constants that are for use with the MindSensors DIST-Nx device.
 * @{
 */
// DIST-Nx Commands
#define DIST_CMD_GP2D12      0x31 /*!< */
#define DIST_CMD_GP2D120     0x32 /*!< */
#define DIST_CMD_GP2YA21     0x33 /*!< */
#define DIST_CMD_GP2YA02     0x34 /*!< */
#define DIST_CMD_CUSTOM      0x35 /*!< */

// DIST-Nx Registers
#define DIST_REG_DIST          0x42 /*!< */
#define DIST_REG_VOLT          0x44 /*!< */
#define DIST_REG_MODULE_TYPE   0x50 /*!< */
#define DIST_REG_NUM_POINTS    0x51 /*!< */
#define DIST_REG_DIST_MIN      0x52 /*!< */
#define DIST_REG_DIST_MAX      0x54 /*!< */
#define DIST_REG_VOLT1         0x56 /*!< */
#define DIST_REG_DIST1         0x58 /*!< */
/** @} */  // end of MSDistNX group

/** @defgroup MSPSPNX MindSensors PSP-Nx constants.
 * Constants that are for use with the MindSensors PSP-Nx device.
 * @{
 */
// PSP-Nx commands
#define PSP_CMD_DIGITAL 0x41 /*!< */
#define PSP_CMD_ANALOG  0x73 /*!< */

// PSP-Nx registers
#define PSP_REG_BTN1   0x42 /*!< */
#define PSP_REG_BTN2   0x43 /*!< */
#define PSP_REG_XLEFT  0x44 /*!< */
#define PSP_REG_YLEFT  0x45 /*!< */
#define PSP_REG_XRIGHT 0x46 /*!< */
#define PSP_REG_YRIGHT 0x47 /*!< */
/** @} */  // end of MSPSPNX group

/** @defgroup MSNRLink MindSensors nRLink constants.
 * Constants that are for use with the MindSensors nRLink device.
 * @{
 */
// NRLink commands
#define NRLINK_CMD_2400      0x44 /*!< */
#define NRLINK_CMD_FLUSH     0x46 /*!< */
#define NRLINK_CMD_4800      0x48 /*!< */
#define NRLINK_CMD_IR_LONG   0x4C /*!< */
#define NRLINK_CMD_IR_SHORT  0x53 /*!< */
#define NRLINK_CMD_RUN_MACRO 0x52 /*!< */
#define NRLINK_CMD_TX_RAW    0x55 /*!< */
#define NRLINK_CMD_SET_RCX   0x58 /*!< */
#define NRLINK_CMD_SET_TRAIN 0x54 /*!< */
#define NRLINK_CMD_SET_PF    0x50 /*!< */

// NRLink registers
#define NRLINK_REG_BYTES  0x40 /*!< */
#define NRLINK_REG_DATA   0x42 /*!< */
#define NRLINK_REG_EEPROM 0x50 /*!< */
/** @} */  // end of MSNRLink group

/** @} */  // end of MindSensorsConstants group
/** @} */  // end of MindSensorsAPI group


//==============================================================================
/** @addtogroup RICMacros
 * @{
 */
//==============================================================================
#define RICImgPoint(_X, _Y) (_X)&0xFF, (_X)>>8, (_Y)&0xFF, (_Y)>>8 /*!< */
#define RICImgRect(_Pt, _W, _H) _Pt, (_W)&0xFF, (_W)>>8, (_H)&0xFF, (_H)>>8 /*!< */
#define RICOpDescription(_Options, _Width, _Height) 8, 0, 0, 0, (_Options)&0xFF, (_Options)>>8, (_Width)&0xFF, (_Width)>>8, (_Height)&0xFF, (_Height)>>8 /*!< */
#define RICOpCopyBits(_CopyOptions, _DataAddr, _SrcRect, _DstPoint) 18, 0, 3, 0, (_CopyOptions)&0xFF, (_CopyOptions)>>8, (_DataAddr)&0xFF, (_DataAddr)>>8, _SrcRect, _DstPoint /*!< */
#define RICOpPixel(_CopyOptions, _Point, _Value) 10, 0, 4, 0, (_CopyOptions)&0xFF, (_CopyOptions)>>8, _Point, (_Value)&0xFF, (_Value)>>8 /*!< */
#define RICOpLine(_CopyOptions, _Point1, _Point2) 12, 0, 5, 0, (_CopyOptions)&0xFF, (_CopyOptions)>>8, _Point1, _Point2 /*!< */
#define RICOpRect(_CopyOptions, _Point, _Width, _Height) 12, 0, 6, 0, (_CopyOptions)&0xFF, (_CopyOptions)>>8, _Point, (_Width)&0xFF, (_Width)>>8, (_Height)&0xFF, (_Height)>>8 /*!< */
#define RICOpCircle(_CopyOptions, _Point, _Radius) 10, 0, 7, 0, (_CopyOptions)&0xFF, (_CopyOptions)>>8, _Point, (_Radius)&0xFF, (_Radius)>>8 /*!< */
#define RICOpNumBox(_CopyOptions, _Point, _Value) 10, 0, 8, 0, (_CopyOptions)&0xFF, (_CopyOptions)>>8, _Point, (_Value)&0xFF, (_Value)>>8 /*!< */
#define RICOpSprite(_DataAddr, _Rows, _BytesPerRow, _SpriteData) ((_Rows*_BytesPerRow)+((_Rows*_BytesPerRow)%2)+8)&0xFF, ((_Rows*_BytesPerRow)+((_Rows*_BytesPerRow)%2)+8)>>8, 1, 0, (_DataAddr)&0xFF, (_DataAddr)>>8, (_Rows)&0xFF, (_Rows)>>8, (_BytesPerRow)&0xFF, (_BytesPerRow)>>8, _SpriteData /*!< */
#define RICSpriteData(...) __VA_ARGS__ /*!< */
#define RICOpVarMap(_DataAddr, _MapCount, _MapFunction) ((_MapCount*4)+6)&0xFF, ((_MapCount*4)+6)>>8, 2, 0, (_DataAddr)&0xFF, (_DataAddr)>>8, (_MapCount)&0xFF, (_MapCount)>>8, _MapFunction /*!< */
#define RICMapElement(_Domain, _Range) (_Domain)&0xFF, (_Domain)>>8, (_Range)&0xFF, (_Range)>>8 /*!< */
#define RICMapFunction(_MapElement, ...) _MapElement, __VA_ARGS__ /*!< */
#define RICArg(_arg) ((_arg)|0x1000) /*!< */
#define RICMapArg(_mapidx, _arg) ((_arg)|0x1000|(((_mapidx)&0xF)<<8)) /*!< */
#define RICOpPolygon(_CopyOptions, _Count, _ThePoints)  ((_Count*4)+6)&0xFF, ((_Count*4)+6)>>8, 10, 0, (_CopyOptions)&0xFF, (_CopyOptions)>>8, (_Count)&0xFF, (_Count)>>8, _ThePoints /*!< */
#define RICPolygonPoints(_pPoint1, _pPoint2, ...) _pPoint1, _pPoint2, __VA_ARGS__ /*!< */
#define RICOpEllipse(_CopyOptions, _Point, _Radius1, _Radius1) 12, 0, 9, 0, (_CopyOptions)&0xFF, (_CopyOptions)>>8, _Point, (_Radius1)&0xFF, (_Radius1)>>8, (_Radius2)&0xFF, (_Radius2)>>8 /*!< */
/** @} */  // end of RICMacros group

/** @defgroup NXTLimits Data type limits.
 * Constants that define various data type limits.
 * @{
 */
#define CHAR_BIT   8 /*!< */
#define SCHAR_MIN  -127 /*!< */
#define SCHAR_MAX  127 /*!< */
#define UCHAR_MAX  255 /*!< */
#define CHAR_MIN   -127 /*!< */
#define CHAR_MAX   127 /*!< */
#define SHRT_MIN   -32767 /*!< */
#define SHRT_MAX   32767 /*!< */
#define USHRT_MAX  65535 /*!< */
#define INT_MIN    -32767 /*!< */
#define INT_MAX    32767 /*!< */
#define UINT_MAX   65535 /*!< */
#define LONG_MIN   -2147483647 /*!< */
#define LONG_MAX   2147483647 /*!< */
#define ULONG_MAX  4294967295 /*!< */
/** @} */  // end of NXTLimits group

#endif // NBCCOMMON_H
