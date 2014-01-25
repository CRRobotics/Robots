// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "JoystickAutoDrive.h"

JoystickAutoDrive::JoystickAutoDrive(double lSpeed, double rSpeed) :
		m_lSpeed(lSpeed),
		m_rSpeed(rSpeed)
{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(Robot::drive);
}

// Called just before this Command runs the first time
void JoystickAutoDrive::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void JoystickAutoDrive::Execute() {
	Robot::drive->TankDrive(m_lSpeed, m_rSpeed);
}

// Make this return true when this Command no longer needs to run execute()
bool JoystickAutoDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void JoystickAutoDrive::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void JoystickAutoDrive::Interrupted() {

}
