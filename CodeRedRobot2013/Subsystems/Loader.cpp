// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "Loader.h"
#include "../Robotmap.h"
#include "../Commands/Loader/SendCamHome.h"

#define RUNTIME_THRESH 1.0f

Loader::Loader() : Subsystem("Loader") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	cam = RobotMap::loaderCam;
	camDetect = RobotMap::loaderCamDetect;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}
    
void Loader::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new SendCamHome());
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

bool Loader::IsCamHome()
{
	return camDetect->Get();
}


void Loader::CamRun()
{
	if(Robot::shooter->IsEnabled() && Robot::shooter->GetRunTime() > RUNTIME_THRESH)
	{
		cam->Set(.75);
	}
	else
	{
		cam->Set(0.0);
	}
}

void Loader::CamSlow()
{
	if(Robot::shooter->IsEnabled() && Robot::shooter->GetRunTime() > RUNTIME_THRESH)
	{
		cam->Set(.35);
	}
	else
	{
		cam->Set(0.0);
	}
}

void Loader::CamReverse()
{
	if(Robot::shooter->IsEnabled() && Robot::shooter->GetRunTime() > RUNTIME_THRESH)
	{
		cam->Set(-.35);
	}
	else
	{
		cam->Set(0.0);
	}
}


void Loader::CamStop()
{
	cam->Set(0.0);
}
