// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "Drive.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "../Commands/Drive/JoystickHDrive.h"
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

Drive::Drive() : Subsystem("Drive") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	lDrive = RobotMap::drivelDrive;
	rDrive = RobotMap::driverDrive;
	cDrive = RobotMap::drivecDrive;
	lowerWheel = RobotMap::drivelowerWheel;
	lSonic = RobotMap::drivelSonic;
	rSonic = RobotMap::driverSonic;
	lIR = RobotMap::drivelIR;
	rIR = RobotMap::driverIR;
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	m_fullSpeed = true;
}
    
void Drive::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new JoystickHDrive());
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void Drive::HDrive(double forwardSpeed, double sideSpeed, double turnSpeed) {
	if(!m_fullSpeed) {
		forwardSpeed /= 2;
		sideSpeed /= 2;
		turnSpeed /= 2;
	}
	double leftSpeed = forwardSpeed + turnSpeed;
	double rightSpeed = forwardSpeed - turnSpeed;
	if(leftSpeed > 1) leftSpeed = 1;
	else if(leftSpeed < -1) leftSpeed = -1;
	if(rightSpeed > 1) rightSpeed = 1;
	else if(rightSpeed < -1) rightSpeed = -1;
	if(m_fullSpeed) {
		leftSpeed *= fabs(leftSpeed);
		rightSpeed *= fabs(rightSpeed);
		sideSpeed *= fabs(sideSpeed);
	}
	lDrive->Set(-leftSpeed);
	rDrive->Set(rightSpeed);
	cDrive->Set(-sideSpeed);
}

void Drive::HDriveField(double forwardSpeed, double sideSpeed, double turnSpeed) {
	//Add Code Later
}

void Drive::SetCenterWheel(bool down) {
	lowerWheel->Set(down);
}

void Drive::ToggleHalfSpeed() {
	m_fullSpeed = !m_fullSpeed;
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

