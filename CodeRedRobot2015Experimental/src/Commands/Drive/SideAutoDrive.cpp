// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "SideAutoDrive.h"

SideAutoDrive::SideAutoDrive(double inches, double speed) :
			m_inches(inches),
			m_speed(speed)
{
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::drive);
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	m_ticks = m_inches * INCH;
}

// Called just before this Command runs the first time
void SideAutoDrive::Initialize() {
	m_startTicks = Robot::drive->GetSideEnc();
	if(m_ticks > 0) {
		m_speed *= -1;
	}
	Robot::drive->SetCenterWheel(true);
}

// Called repeatedly when this Command is scheduled to run
void SideAutoDrive::Execute() {
	Robot::drive->HDrive(0,m_speed,0);
}

// Make this return true when this Command no longer needs to run execute()
bool SideAutoDrive::IsFinished() {
	return (fabs(Robot::drive->GetSideEnc() - m_startTicks) > fabs(m_ticks));
}

// Called once after isFinished returns true
void SideAutoDrive::End() {
	Robot::drive->HDrive(0,0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SideAutoDrive::Interrupted() {
	Robot::drive->HDrive(0,0,0);
}