// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#ifndef ACQUISITION_H
#define ACQUISITION_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class Acquisition: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	DigitalInput* ballSensor;
	Counter* gearSpeed;
	SpeedController* roller;
	Solenoid* raise;
public:
	
	Acquisition();
	void InitDefaultCommand();
	void RollerRun();
	void RollerSetTargetSpeed(double speed);
	void SetArm(bool raised);
	bool HasBall();
	
	double m_speed;
};

#endif
