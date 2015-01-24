// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "RetractArms.h"

RetractArms::RetractArms() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::acquisition);
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void RetractArms::Initialize() {
	Robot::acquisition->SetLeft(0);
	Robot::acquisition->SetRight(0);
}

// Called repeatedly when this Command is scheduled to run
void RetractArms::Execute() {
	if(Robot::acquisition->GetArmState()) Robot::acquisition->SetArm(false);
}

// Make this return true when this Command no longer needs to run execute()
bool RetractArms::IsFinished() {
	return Robot::acquisition->GetArmState();
}

// Called once after isFinished returns true
void RetractArms::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RetractArms::Interrupted() {

}
