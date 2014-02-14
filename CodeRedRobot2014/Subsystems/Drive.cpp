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

#define HAMMER_DRIVE_ENABLE 0

#define CURRENT_THRESH_1 100 	//TODO: Replace dummy value // Current at which we go from 1 motor to 2 motors  (1->2)
#define CURRENT_THRESH_1_END 45 //TODO: Replace dummy value // Current at which we go from 2 motors to 1 motor  (2->1)
#define CURRENT_THRESH_2 200 	//TODO: Replace dummy value // Current at which we go from 2 motors to 3 motors (2->3)
#define CURRENT_THRESH_2_END 95 //TODO: Replace dummy value // Current at which we go from 3 motors to 2 motors (3->2)

#define TIME_THRESH_1 .4 //TODO: Replace semi-dummy value // Time before we turn on the second motor
#define TIME_THRESH_2 .8 //TODO: Replace sem-dummy value // Time before we turn on the third motor


Drive::Drive() : Subsystem("Drive") {
	left1 = RobotMap::driveleft1;
	left2 = RobotMap::driveleft2;
	left3 = RobotMap::driveleft3;
	right1 = RobotMap::driveright1;
	right2 = RobotMap::driveright2;
	right3 = RobotMap::driveright3;
	shift = RobotMap::driveshift;
	rangeFinder = new Ultrasonic(DRV_ANA_DISTANCE);
	
	isFirstOn = false;
	isSecondOn = false;
	isThirdOn = false;
	
	mtrTime.Start();
	mtrTime.Reset();
}
    
void Drive::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new JoystickDrive());
}

void Drive::TankDrive(double lSpeed, double rSpeed) {
	// If the motor direction is reversing or going from 0, we need to reset the timer so we don't turn on all the motors at once
	if(left1->Get()*lSpeed <= 0 || right1->Get()*rSpeed <= 0) mtrTime.Reset(); 
#if HAMMER_DRIVE_ENABLE
	if (lSpeed == 0 && rSpeed == 0) // Run if the robot is being told to stop moving
	{
		isFirstOn = false;			// Register all motors as stationary
		isSecondOn = false;
		isThirdOn = false;
	}
	else if (!isFirstOn) 			// Run if the robot is currently considered stationary
	{
		isFirstOn = true; 			// Start only the first motor on each side
	}
	else if (!isSecondOn && 
				(left1->GetOutputCurrent() > CURRENT_THRESH_1 ||
				 right1->GetOutputCurrent() > CURRENT_THRESH_1))
	// Run if only one motor is running and one side is above the threshold
	{
		isSecondOn = true;			// Run the first two motors on each side 
	}
	else if (isSecondOn && !isThirdOn && 
				left1->GetOutputCurrent() < CURRENT_THRESH_1_END &&
				right1->GetOutputCurrent() < CURRENT_THRESH_1_END)
	// Run if two motors are running, but the current is small enough for only one
	{
		isSecondOn = false;			// Only run the first motor on each side
	}
	else if (!isThirdOn && 
				(left1->GetOutputCurrent() > CURRENT_THRESH_2 ||
				 right1->GetOutputCurrent() > CURRENT_THRESH_2))
	// Run if only two motors are running and one side is above the second threshold
	{
		isThirdOn = true;			// Run all three motors on each side
	} 
	else if (isThirdOn && 
				left1->GetOutputCurrent() < CURRENT_THRESH_2_END &&
				right1->GetOutputCurrent() < CURRENT_THRESH_2_END)
	// Run if all motors are running, but the current is enough for just two
	{
		isThirdOn = false;			// Run only the first two motors on each side
	}
	
	//Set the Jaguars to brake or coast mode
	if(!isFirstOn)	// Robot's not moving -- brake
	{
		left1->ConfigNeutralMode(CANJaguar::kNeutralMode_Brake);
		left2->ConfigNeutralMode(CANJaguar::kNeutralMode_Brake);
		left3->ConfigNeutralMode(CANJaguar::kNeutralMode_Brake);
		right1->ConfigNeutralMode(CANJaguar::kNeutralMode_Brake);
		right2->ConfigNeutralMode(CANJaguar::kNeutralMode_Brake);
		right3->ConfigNeutralMode(CANJaguar::kNeutralMode_Brake);
	}
	else  // Robot's moving, but not necessarily all the motors are running -- better not brake
	{
		left1->ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);
		left2->ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);
		left3->ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);
		right1->ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);
		right2->ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);
		right3->ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);
	}
	
	// Run each motor pair if they were set to run above
	if(isFirstOn) 
	{
		left1->Set(lSpeed);
		right1->Set(rSpeed);
	}
	if(isSecondOn && mtrTime.HasPeriodPassed(TIME_THRESH_1)) // Stagger the motor startup to prevent enormous current
	{
		left2->Set(lSpeed);
		right2->Set(rSpeed);
	}
	if(isThirdOn && mtrTime.HasPeriodPassed(TIME_THRESH_2)) // Stagger the motor startup to prevent enormous current
	{
		left3->Set(lSpeed);
		right3->Set(rSpeed);
	}
	
#else
			left1->Set(lSpeed);
			right1->Set(rSpeed);
		if(mtrTime.Get()> TIME_THRESH_1) // Stagger the motor startup to prevent enormous current
		{
			left2->Set(lSpeed);
			right2->Set(rSpeed);
		}
		else
		{
			left2->Set(0);
			right2->Set(0);
		}
		if(mtrTime.Get() > TIME_THRESH_2) // Stagger the motor startup to prevent enormous current
		{
			left3->Set(lSpeed);
			right3->Set(rSpeed);
		}
		else
		{
			left3->Set(0);
			right3->Set(0);
		}

#endif
}

void Drive::Shift(bool high) {
	shift->Set(high);
}

double Drive::GetDistance() {
	return rangeFinder->GetRangeInches()/12;
}

void Drive::ResetTime() {
	mtrTime.Reset();
}

