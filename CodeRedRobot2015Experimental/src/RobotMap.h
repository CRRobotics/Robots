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
#include "IMU.h"

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
	static Talon* acquisitionlAcquisition;
	static Talon* acquisitionrAcquisition;
	static Solenoid* acquisitionacqArm;
	static DigitalInput* acquisitiontoteSensor;
	static CANTalon* toteStackertoteLift;
	static Solenoid* toteStackerbrake;
	static DigitalInput* toteStackertoteHome;
	static CANTalon* containerStackercontainerLift;
	static Solenoid* containerStackerclaw;
	static DigitalInput* containerStackercontainerHome;
	static AnalogInput* containerStackerclawIR;
	static Victor* wingswingRetracter;
	static DigitalInput* wingsleftLimit;
	static DigitalInput* wingsrightLimit;
	static AnalogInput* sensorstote1;
	static AnalogInput* sensorstote2;
	static AnalogInput* sensorstote3;
	static AnalogInput* sensorstote4;
	static AnalogInput* sensorstote5;
	static AnalogInput* sensorscontainerSensor;
	static DigitalInput* toteStackerhall;
	static DigitalInput* containerStackerhall;
	static IMU* m_imu;
	static SerialPort* serialPort;
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
#define DRV_MTR_LEFT 8 //beware: dummy(~ish~) values ahead
#define DRV_MTR_RIGHT 5
#define DRV_MTR_CENTER 4
#define DRV_SOL_CNTR_SUSP 0, 2

//Acquisition
#define ACQ_MTR_LEFT 1
#define ACQ_MTR_RIGHT 0
#define ACQ_SOL_EXTEND 0, 3

//Tote stacker
#define TST_MTR_LIFT 6
#define TST_SOL_BRAKE 0, 1
#define TST_DIN_HALL 3


//Container stacker
#define CST_MTR_LIFT 7
#define CST_SOL_CLAW 0, 0
#define CST_DIN_HALL 2

//Wing
#define WNG_MTR_RET 2
#define WNG_DIN_LEFT 0
#define WNG_DIN_RIGHT 1

//Sensors
#define SNS_ANA_TOTE1 0
#define SNS_ANA_TOTE2 1
#define SNS_ANA_TOTE3 2
#define SNS_ANA_TOTE4 3
#define SNS_ANA_TOTE5 4
#define SNS_ANA_CONT 5
};
#endif