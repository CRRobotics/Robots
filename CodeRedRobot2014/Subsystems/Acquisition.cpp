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

Acquisition::Acquisition() : Subsystem("Acquisition") {
	ballSensor = RobotMap::acquisitionballSensor;
	roller = RobotMap::acquisitionroller;
	raise = RobotMap::acquisitionraise;
	rollSpeed = new GearTooth(ACQ_DIN_GEAR);
	rollSpeed->Start();
	
	proc1 = new AnalogChannel(DRV_ANA_PROC_1);
	proc2 = new AnalogChannel(DRV_ANA_PROC_2);
	proc3 = new AnalogChannel(DRV_ANA_PROC_3);
	
	m_speed = 0;
	
	acqPID = new PIDController(0, 0, 0, this, roller);
}

void Acquisition::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new RollerStop());
}

void Acquisition::RollerRun() {
	if(raise->Get()) 	// Acquisition is down
		roller->Set(m_speed);
	else				// Acquisition is up
		roller->Set(0);
	SmartDashboard::PutNumber("GearSpeed", 1/rollSpeed->GetPeriod());
	SmartDashboard::PutNumber("proc1", proc1->GetAverageVoltage());
	SmartDashboard::PutNumber("proc2", proc2->GetAverageVoltage());
	SmartDashboard::PutNumber("proc3", proc3->GetAverageVoltage());
	
	SmartDashboard::PutNumber("P", 0);
	SmartDashboard::PutNumber("I", 0);
	SmartDashboard::PutNumber("D", 0);
	
	acqPID->SetPID(SmartDashboard::GetNumber("P"), 
				SmartDashboard::GetNumber("I"), 
				SmartDashboard::GetNumber("D"));
}

void Acquisition::RollerSetTargetSpeed(double speed) {
	m_speed = speed;
}

void Acquisition::SetArm(bool raised) {
	raise->Set(raised);
}

bool Acquisition::HasBall() {
	return ballSensor->Get();
}

double Acquisition::GetSpeed(){
	double speed = 1/rollSpeed->GetPeriod();
	if(m_speed < 0) speed *= -1;
	return speed;
}

double Acquisition::PIDGet() {
	return GetSpeed();
}
