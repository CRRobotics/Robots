// RobotBuilder Version: 0.0.2
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
#include "OIMap.h"
/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
class RobotMap {
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static CANJaguar* shooterSpinner;
	static CANJaguar* armWrist;
	static CANJaguar* armElbow;
	static SpeedController* driveLeft;
	static SpeedController* driveRight;
	static Encoder* drivelEnc;
	static Encoder* driverEnc;
	static Solenoid* driveShift;
	static Victor* loaderCam;
	static DigitalInput* loaderCamDetect;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static void init();
};

/* Naming scheme for ports:
 * "Subsystem_Type_Function"
 * 
 * Subsystem:
 * ARM - Arm
 * DRV - Drive
 * RBT - No subsystem
 * SHO - Shooter
 * LDR - Loader
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
 */
//Arm Positions

//Arm
#define ARM_MTR_WRIST 8
#define ARM_MTR_ELBOW 7
//Drive
#define DRV_MTR_LEFT 1,2
#define DRV_MTR_RIGHT 1,1
#define DRV_SOL_SHIFT 1,1
#define DRV_ENC_LEFT 1,3,1,4 // 1 = Sidecar, 3 = port. Reads: Ports 3 and 4 on the the sidecar.
#define DRV_ENC_RIGHT 1,5,1,6
//Shooter
#define SHO_MTR_SPIN 6
//Loader
#define LDR_MTR_CAM 1,3
#define LDR_DIN_CAM 13
//PID
#define ELBOW_LOW .20
#define ELBOW_HIGH .52

#define WRIST_LOW .595 //TODO: Re-define wrist low and high
#define WRIST_HIGH .365

#define ELBOW_PID -2000,-5,10
#define WRIST_PID -2000,0.0,0.0

#endif
