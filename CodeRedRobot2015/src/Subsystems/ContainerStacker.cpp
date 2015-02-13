// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "ContainerStacker.h"
#include "../RobotMap.h"
#include "../Commands/ContainerStacker/SetClawPos.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

ContainerStacker::ContainerStacker() : Subsystem("ContainerStacker") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	containerLift = RobotMap::containerStackercontainerLift;
	claw = RobotMap::containerStackerclaw;
	containerHome = RobotMap::containerStackercontainerHome;
	clawIR = RobotMap::containerStackerclawIR;
	m_targetPos = 0; //TODO: Dummy Value Replace(Maybe)
	m_targetPosEnum = ClawPositions::PICK_STANDING; //TODO: Dummy Value replace
	m_standingMode = true;
	m_platform = false;
	m_manualControl = false;
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}
    
void ContainerStacker::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new SetClawPos());
}

void ContainerStacker::SetClaw(bool closed) {
	claw->Set(closed);
}

void ContainerStacker::ZeroClaw() {
	containerLift->SetPosition(0);
}

bool ContainerStacker::IsAtHome() {
	return !containerLift->GetReverseLimitOK();
}

void ContainerStacker::SetPos(int position) {
	containerLift->Set(position);
}

int ContainerStacker::GetTargetPos() {
	return m_targetPos;
}

void ContainerStacker::SetTargetPos(int position) {
	m_targetPos = position;
}

void ContainerStacker::SetMode(bool standing) {
	m_standingMode = standing;
}

bool ContainerStacker::GetStanding() {
	return m_standingMode;
}

void ContainerStacker::TogglePlatform() {
	m_platform = !m_platform;
}

bool ContainerStacker::GetPlatform() {
	return m_platform;
}

ClawPositions ContainerStacker::GetTargetEnum() {
	return m_targetPosEnum;
}

void ContainerStacker::SetTargetEnum(ClawPositions target) {
	m_targetPosEnum = target;
}

bool ContainerStacker::GetManual() {
	return m_manualControl;
}

void ContainerStacker::SetControlMode(bool manual) {
	m_manualControl = manual;
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

