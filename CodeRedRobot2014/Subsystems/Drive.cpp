// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "Drive.h"
#include "../Robotmap.h"
#include "../Commands/Drive/JoystickDrive.h"
#include "Math.h"

#define MIN_DIST_LONG 3.55
#define MAX_DIST_LONG 3.75

Drive::Drive() : Subsystem("Drive") {
	left = new TripleMotorOutput(RobotMap::driveleft1, RobotMap::driveleft2, 
								RobotMap::driveleft3, RobotMap::drivelEnc);
	right = new TripleMotorOutput(RobotMap::driveright1, RobotMap::driveright2, 
								RobotMap::driveright3, RobotMap::driverEnc);
	shift = RobotMap::driveshift;
	rangeFinder = RobotMap::driverangeFinder;
	goalSensor = RobotMap::drivegoalSensor;
}

void Drive::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new JoystickDrive());
}

void Drive::TankDrive(double lSpeed, double rSpeed) {
	lSpeed = lSpeed * fabs(lSpeed); // Square values (preserving sign) for better driving
	rSpeed = rSpeed * fabs(rSpeed);
//	int leftNum = left->GetNumMotors(lSpeed); // Only useful for Hammer Drive
//	int rightNum = right->GetNumMotors(rSpeed);
//	if(leftNum > rightNum)
//	{
//		left->SetSpeed(lSpeed, leftNum);
//		right->SetSpeed(rSpeed, leftNum);
//	}
//	else
//	{
//		left->SetSpeed(lSpeed, rightNum);
//		right->SetSpeed(rSpeed, rightNum);
//	}
	left->SetSpeed(lSpeed, 3);
	right->SetSpeed(rSpeed, 3);
//	SmartDashboard::PutNumber("Short Dist", GetDistanceShort());
//	SmartDashboard::PutNumber("Long Dist", GetDistanceLong());
//	SmartDashboard::PutBoolean("Shoot Now!", GetDistanceLong() > MIN_DIST_LONG && 
//											GetDistanceLong() < MAX_DIST_LONG);
	SmartDashboard::PutBoolean("Goal Hot!", Robot::vision->IsGoalHot());
}

void Drive::Shift(bool high) {
	shift->Set(high);
}

double Drive::GetDistanceLong() {
	return rangeFinder->GetAverageVoltage();
}

double Drive::GetDistanceShort() {
	return goalSensor->GetAverageVoltage();
}

bool Drive::GetShifters() {
	return shift->Get();
}
