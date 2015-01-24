// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "Acquisition.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "../Commands/Acquisition/StopWheels.h"
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

Acquisition::Acquisition() : Subsystem("Acquisition") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	lAcquisition = RobotMap::acquisitionlAcquisition;
	rAcquisition = RobotMap::acquisitionrAcquisition;
	acqArm = RobotMap::acquisitionacqArm;
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}
    
void Acquisition::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new StopWheels());
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
void Acquisition::SetArms(bool state)
{
	acqArm.Set(state);
}

bool Acquisition::GetArmState()
{
	return acqArm.Get();
}

void Acquisition::SetLeft(double value){
	if(Acquisition->GetArmState()) lAcquisition.Set(value);
}

void Acquisition::SetRight(double value){
	if(Acquisition->GetArmState()) lAcquisition.Set(value);
}

double Acquisition::GetLeft(){
	return lAcquisition.Get();
}

double Acquisition::GetRight(){
	return lAcquisition.Get();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

