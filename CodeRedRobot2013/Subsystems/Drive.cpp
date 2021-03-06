// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.
#include "Drive.h"
#include "../Robotmap.h"
#include "../Commands/Drive/JoystickDrive.h"
Drive::Drive() : Subsystem("Drive") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	left = RobotMap::driveLeft;
	right = RobotMap::driveRight;
	lEnc = RobotMap::drivelEnc;
	rEnc = RobotMap::driverEnc;
	shift = RobotMap::driveShift;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}
    
void Drive::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new JoystickDrive());
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
void Drive::TankDrive(double lSpeed, double rSpeed) {
	left->Set(lSpeed);
	right->Set(-rSpeed);
}
void Drive::Shift(bool high)
{
	shift->Set(high);
}
