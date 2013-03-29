// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.
#include "AutonomousCommand.h"
AutonomousCommand::AutonomousCommand() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::shooter);
	Requires(Robot::arm);
	Requires(Robot::loader);
}
// Called just before this Command runs the first time
void AutonomousCommand::Initialize() {
	Robot::shooter->Start();
	Robot::oi->SetElbowSetpoint(Robot::arm->GetElbowPosition(Arm::kHigh));
	Robot::oi->SetWristSetpoint(Robot::arm->GetWristPosition(Arm::kHigh));
}
// Called repeatedly when this Command is scheduled to run
void AutonomousCommand::Execute() {
	Robot::shooter->SetSpeed(Robot::shooter->GetDefaultSpeed());
	Robot::loader->CamRun();
	Robot::arm->SetState(Arm::kHigh);
	Robot::shooter->SetArmState(Arm::kHigh);
}
// Make this return true when this Command no longer needs to run execute()
bool AutonomousCommand::IsFinished() {
	return false;
}
// Called once after isFinished returns true
void AutonomousCommand::End() {
	
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonomousCommand::Interrupted() {
	
}
