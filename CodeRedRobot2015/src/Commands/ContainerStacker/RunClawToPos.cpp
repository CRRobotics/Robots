// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "RunClawToPos.h"

RunClawToPos::RunClawToPos() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::containerStacker);
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void RunClawToPos::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void RunClawToPos::Execute() {
	SmartDashboard::PutNumber("CONTAINER ENCODER", Robot::containerStacker->GetCurrentPos());
	SmartDashboard::PutBoolean("Hall container", Robot::containerStacker->GetHall());
	Robot::containerStacker->SetClaw(Robot::oi->GetClaw());
	Robot::containerStacker->SetControlMode(Robot::oi->GetAutoMan());
	if(Robot::containerStacker->GetManual()) {
		Robot::containerStacker->SetJustMan(true);
		Robot::containerStacker->DriveToPoint(Robot::oi->GetDial());
	}
	else if(!Robot::containerStacker->GetJustMan()){
		Robot::containerStacker->DriveToPoint();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool RunClawToPos::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void RunClawToPos::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunClawToPos::Interrupted() {

}
