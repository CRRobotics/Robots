// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "DropTotesNew.h"

#define DROP 700

DropTotesNew::DropTotesNew() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::toteStackerNew);
	Requires(Robot::acquisition);
}

// Called just before this Command runs the first time
void DropTotesNew::Initialize() {
	Robot::acquisition->SetArmsOpen(true);
	Robot::toteStackerNew->SetResting(false);
	Robot::toteStackerNew->SetOffset(DROP);
}

// Called repeatedly when this Command is scheduled to run
void DropTotesNew::Execute() {
	SmartDashboard::PutNumber("TOTE ENCODER", Robot::toteStackerNew->GetPos());
	Robot::toteStackerNew->DriveToPoint();
}

// Make this return true when this Command no longer needs to run execute()
bool DropTotesNew::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DropTotesNew::End() {
	Robot::toteStackerNew->SetResting(true);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DropTotesNew::Interrupted() {
	Robot::toteStackerNew->SetResting(true);
}