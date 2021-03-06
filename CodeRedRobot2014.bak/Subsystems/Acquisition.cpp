// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "Acquisition.h"
#include "../Robotmap.h"
#include "../Commands/Acquisition/RollerStop.h"

#define GEAR_TEETH 20 // May be 18 or 20 -- ensure you know which arm is in use
#define PROC_1_THRESH 1
#define PROC_2_THRESH 1.5
#define PROC_3_THRESH 1

Acquisition::Acquisition() : Subsystem("Acquisition") {
	roller = RobotMap::acquisitionroller;
	raise = RobotMap::acquisitionraise;
	rollSpeed = new GearTooth(ACQ_DIN_GEAR);
	rollSpeed->Start();

	proc1 = RobotMap::acquisitionproc1;
	proc2 = RobotMap::acquisitionproc2;
	proc3 = RobotMap::acquisitionproc3;
	
	m_speed = 0;
	
	acqPID = new PIDController(0, 0, 0, this, roller);
}

void Acquisition::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new RollerStop());
}

void Acquisition::RollerRun() {
	if(raise->Get()) // Acquisition is up
		roller->Set(m_speed);
	else // Acquisition is down
		roller->Set(0);
}

void Acquisition::RollerSetTargetSpeed(double speed) { // Speed in [-1, 1]
	m_speed = speed;
}

void Acquisition::SetArm(bool raised) {
	raise->Set(raised);
}

bool Acquisition::HasBall() {
	return proc2->GetAverageVoltage() > PROC_2_THRESH;
}

bool Acquisition::BallReady() {
	return proc3->GetAverageVoltage() > PROC_3_THRESH;
}

double Acquisition::GetSpeed(){
	double speed = 1/rollSpeed->GetPeriod();
	if(m_speed < 0) speed *= -1;
	return speed;
}

double Acquisition::PIDGet() {
	return GetSpeed();
}
