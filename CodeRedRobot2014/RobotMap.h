// RobotBuilder Version: 1.0
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
	static CANJaguar* driveleft1;
	static CANJaguar* driveleft2;
	static CANJaguar* driveleft3;
	static CANJaguar* driveright1;
	static CANJaguar* driveright2;
	static CANJaguar* driveright3;
	static Encoder* drivelEnc;
	static Encoder* driverEnc;
	static Ultrasonic* driverangeFinder;
	static Ultrasonic* drivegoalSensor;
	static Solenoid* driveshift;
	static Solenoid* shooterleft;
	static Solenoid* shooterright;
	static SpeedController* acquisitionroller;
	static Solenoid* acquisitionraise;
	static AnalogChannel* acquisitionproc1;
	static AnalogChannel* acquisitionproc2;
	static AnalogChannel* acquisitionproc3;
	static Solenoid* ejectionkicker;
	static DigitalInput* visiongoalHot;
	static Relay* visionLEDs;

	static void init();
	
	/* Naming scheme for ports:
	 * "Subsystem_Type_Function"
	 * 
	 * Subsystem:
	 * ACQ - Acquisition
	 * DRV - Drive
	 * RBT - No subsystem
	 * SHO - Shooter
	 * EJT - Ejection
	 * VIS - Vision
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
#define DRV_MTR_LEFT_ONE 2
#define DRV_MTR_LEFT_TWO 3
#define DRV_MTR_LEFT_THREE 4
#define DRV_MTR_RIGHT_ONE 5
#define DRV_MTR_RIGHT_TWO 6
#define DRV_MTR_RIGHT_THREE 7
#define DRV_ENC_LEFT 1,4,1,5
#define DRV_ENC_RIGHT 1,6,1,7
#define DRV_SOL_SHIFT 1,1
#define DRV_ULT_LONGDIST 1,8,1,9
#define DRV_ULT_SHORTDIST 1,10,1,11
#define DRV_ANA_PROC_1 1,1
#define DRV_ANA_PROC_2 1,2
#define DRV_ANA_PROC_3 1,3

//Shooter
#define SHO_SOL_LEFT 1,2
#define SHO_SOL_RIGHT 1,3

//Shooting default times
#define SHO_DEFAULT_TRUSS .5 	//TODO: Replace dummy value
#define SHO_DEFAULT_GOAL 1		

//Acquisition
#define ACQ_MTR_ROLLER 1,1
#define ACQ_SOL_RAISE 1,4
#define ACQ_DIN_GEAR 1,3,false 

#define ACQ_FOR_DEFAULT .9
#define ACQ_REV_DEFAULT -1

//Ejection
#define EJT_SOL_KICK 1,5

//Vision
#define VIS_DIN_HOT 1,2
#define VIS_REL_LED 1,2

};
#endif
