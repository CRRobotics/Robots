// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#ifndef DRIVE_H
#define DRIVE_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../TripleMotorOutput.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class Drive: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	TripleMotorOutput* left;
	TripleMotorOutput* right;
	Solenoid* shift;
	AnalogChannel* rangeFinder;
	AnalogChannel* goalSensor;
	SpeedController* parallel1;
	SpeedController* parallel2;
public:
	
	Drive();
	void InitDefaultCommand();
	void TankDrive(double lSpeed, double rSpeed);
	void HDrive(double forwardSpeed, double sideSpeed, double rotationSpeed);
	void Shift(bool high);
	double GetDistanceLong();
	double GetDistanceShort();
	bool GetShifters();
};

#endif
