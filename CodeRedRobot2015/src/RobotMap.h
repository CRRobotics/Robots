// RobotBuilder Version: 1.5 ♥♥♥♥♥
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
class RobotMap {
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static CANTalon* drivelDrive;
	static CANTalon* driverDrive;
	static CANTalon* drivecDrive;
	static Solenoid* drivelowerWheel;
	static Ultrasonic* drivelSonic;
	static Ultrasonic* driverSonic;
	static AnalogInput* drivelIR;
	static AnalogInput* driverIR;
	static Talon* acquisitionlAcquisition;
	static Talon* acquisitionrAcquisition;
	static Solenoid* acquisitionacqArm;
	static CANTalon* toteStackertoteLift;
	static Solenoid* toteStackerbrake;
	static DigitalInput* toteStackertoteHome;
	static CANTalon* containerStackercontainerLift;
	static Solenoid* containerStackerclaw;
	static DigitalInput* containerStackercontainerHome;
	static AnalogInput* containerStackerclawIR;
	static Victor* wingswingRetracter;
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	static void init();

	/* Naming scheme for ports:
	 * "Subsystem_Type_Function"
	 *
	 * Subsystem:
	 * ACQ - Acquisition
	 * DRV - Drive
	 * RBT - No subsystem
	 * TST - Tote stacker
	 * CST - Container stacker
	 * WNG - Wings
	 *
	 * Type:
	 * ANA - Analog Channel
	 * MTR - Motor
	 * SOL - Solenoid
	 * ENC - Encoder
	 * POT - Potentiometer
	 * CNT - Counter
	 * PRS - Pressure switch
	 * CMP - Compressor
	 * DIN - Digital input
	 * ULT - Ultrasonic
	 */

//Drive
#define DRV_MTR_LEFT 1 //beware: dummy values ahead
#define DRV_MTR_RIGHT 2
#define DRV_MTR_CENTER 3
#define DRV_SOL_CNTRSUSP 4
#define DRV_ULT_LEFTD 5
#define DRV_ULT_RIGHTD 6
#define DRV_ANA_LEFT 7
#define DRV_ANA_RIGHT 8

//Acquisition
#define ACQ_MTR_LEFT 1
#define ACQ_MTR_RIGHT 2
#define ACQ_SOL_EXTEND 3

//Tote stacker
#define TST_MTR_LIFT 1
#define TST_SOL_BRAKE 2
#define TST_ENC_HOME 3

//Container stacker
#define CST_MTR_LIFT 1
#define CST_SOL_CLAW 2
#define CST_ENC_HOME 3
#define CST_ANA_IR 4

//Wing
#define WNG_MTR_RET 5
};
#endif
