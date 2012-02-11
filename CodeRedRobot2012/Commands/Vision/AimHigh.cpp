#include "AimHigh.h"

AimHigh::AimHigh() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(vision);
}

// Called just before this Command runs the first time
void AimHigh::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void AimHigh::Execute() {
	vision->SelectTarget(0);
}

// Make this return true when this Command no longer needs to run execute()
bool AimHigh::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void AimHigh::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AimHigh::Interrupted() {
}