// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "math.h"
#include "JoystickHDriveField.h"

JoystickHDriveField::JoystickHDriveField() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::drive);
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void JoystickHDriveField::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void JoystickHDriveField::Execute() {
	double theta = Robot::drive->GetRobotHeading();//Dummy Value
	SmartDashboard::PutNumber("theta before",theta);
	if(theta > 90) {
		theta -= 360;
	}
	theta = abs(theta - 90);
//	theta += 180;
	double x = Robot::oi->GetSingleX();
	double y = Robot::oi->GetSingleY();
//	theta = 90;
	theta *= M_PI / 180;
	Robot::drive->HDrive(x*cos(theta) + y*sin(theta), -x*sin(theta) + y*cos(theta), Robot::oi->GetSingleTwist());
	SmartDashboard::PutNumber("theta after",theta);
}

// Make this return true when this Command no longer needs to run execute()
bool JoystickHDriveField::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void JoystickHDriveField::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void JoystickHDriveField::Interrupted() {

}
