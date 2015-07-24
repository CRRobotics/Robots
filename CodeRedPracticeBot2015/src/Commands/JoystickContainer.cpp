// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "JoystickContainer.h"

JoystickContainer::JoystickContainer() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::drive);
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void JoystickContainer::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void JoystickContainer::Execute() {
	SmartDashboard::PutNumber("Encoder container current", Robot::drive->GetContainerEnc());
	SmartDashboard::PutNumber("Do Nothing", Robot::oi->GetSingleY());
	Robot::drive->SetClawSpeed(Robot::oi->GetSingleY());
	Robot::drive->HDrive(0,0,0);
	SmartDashboard::PutNumber("Dial Value", Robot::oi->GetDial());
}

// Make this return true when this Command no longer needs to run execute()
bool JoystickContainer::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void JoystickContainer::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void JoystickContainer::Interrupted() {

}
