#include "ShooterSpin.h"

ShooterSpin::ShooterSpin(bool user) :
							m_isUser(user)
{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(Robot::shooter);
}

// Called just before this Command runs the first time
void ShooterSpin::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void ShooterSpin::Execute() {
	if (m_isUser)
	{
		Robot::shooter->SetSpeed(Robot::oi->GetShooterSpeed());
	}
	else
	{
		Robot::shooter->SetSpeed(SHO_DEFAULT);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ShooterSpin::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ShooterSpin::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterSpin::Interrupted() {
	
}
