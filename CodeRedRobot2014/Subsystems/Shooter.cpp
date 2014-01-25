// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "Shooter.h"
#include "../Robotmap.h"
#include "../Commands/Shooter/Fire.h"

Shooter::Shooter() : Subsystem("Shooter") {
	left = RobotMap::shooterleft;
	right = RobotMap::shooterright;
}
    
void Shooter::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new Fire());
}

void Shooter::SetSolenoids(bool extended) {
	
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

