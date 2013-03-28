// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.
#include "Arm.h"
#include "../Robotmap.h"
#include "../Commands/Arm/ArmPosition.h"
#include <math.h>

#define ELBOW_SHUTOFF_ENABLE 0
#define WRIST_SHUTOFF_ENABLE 0
#define WRIST_CLAMP_ENABLE 1

#define ELBOW_EPSILON 0.01f
#define WRIST_EPSILON 0.01f
#define ELBOW_SHUTOFF_THRESH 0.22f
#define ELBOW_SHUTOFF_DELTA  0.05f
#define WRIST_SHUTOFF_THRESH 0.83f
#define WRIST_SHUTOFF_DELTA  0.05f

// Wrist clamp thresholds
#define CLAMP_LOW_ELBOW 0.22f
#define CLAMP_LOW_WRIST 0.32f
#define CLAMP_MID_ELBOW_MIN 0.22f
#define CLAMP_MID_ELBOW_MAX 0.4f
#define CLAMP_MID_ELBOW_DOWN 0.44f
#define CLAMP_MID_WRIST 0.302f
#define CLAMP_HIGH_ELBOW 0.44f
#define CLAMP_HIGH_WRIST_MIN 0.35f

static const double kWristPositions[] = {.595,	.595,	.425,	.440,	.425};
static const double kElbowPositions[] = {.2,	.21,	.48,	.48,	.48};

#define ARM_NUM_POSITIONS 5

Arm::Arm() : Subsystem("Arm"),
			 m_bWristActive(false),
			 m_bElbowActive(false)
{
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	wrist = RobotMap::armWrist;
	elbow = RobotMap::armElbow;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	wrist->EnableControl();
	elbow->EnableControl();
}
    
void Arm::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new ArmPosition(kStow));
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
void Arm::SetWrist(double pos)
{
#if WRIST_SHUTOFF_ENABLE
	if (pos < WRIST_SHUTOFF_THRESH && wrist->GetPosition() < WRIST_SHUTOFF_THRESH + WRIST_SHUTOFF_DELTA && !m_bElbowActive)
	{
		wrist->DisableControl();
		m_bWristActive = false;
	}
	else if (!m_bWristActive)
	{
		wrist->EnableControl();
		m_bWristActive = true;
	}
#endif // WRIST_SHUTOFF_ENABLE

	pos = ClampWrist(pos, elbow->GetPosition());
	wrist->Set(pos);
	
	SmartDashboard::PutNumber("Wrist pos", wrist->GetPosition());
}
void Arm::SetElbow(double pos)
{
	double currentPos = elbow->GetPosition();
#if ELBOW_SHUTOFF_ENABLE
	if (pos < ELBOW_SHUTOFF_THRESH && elbow->GetPosition() < ELBOW_SHUTOFF_THRESH + ELBOW_SHUTOFF_DELTA)
	{
		elbow->DisableControl();
		m_bElbowActive = false;
	}
	else 
#endif // ELBOW_SHUTOFF_ENABLE
	if (currentPos < CLAMP_MID_ELBOW_DOWN
			&& currentPos > CLAMP_MID_ELBOW_MIN
			&& pos < CLAMP_MID_ELBOW_MIN
			&& wrist->GetPosition() > CLAMP_MID_WRIST + .01f)
	{
		elbow->DisableControl();
		m_bElbowActive = false;
	}
	else if (!m_bElbowActive)
	{
		elbow->EnableControl();
		m_bElbowActive = true;
	}	
	
	elbow->Set(pos);
}

bool Arm::IsElbowAtSetpoint()
{
	return fabs(elbow->GetPosition() - elbow->Get()) < ELBOW_EPSILON;
}
bool Arm::IsWristAtSetpoint()
{
	return fabs(wrist->GetPosition() - wrist->Get()) < WRIST_EPSILON;
}

void Arm::SetState(State state)
{
	SetWrist(GetWristPosition(state));
	SetElbow(GetElbowPosition(state));
}

double Arm::GetWristPosition(State state)
{
	if (state > 0 && state < ARM_NUM_POSITIONS)
		return kWristPositions[state];
	else
		return kWristPositions[0];
}

double Arm::GetElbowPosition(State state)
{
	if (state > 0 && state < ARM_NUM_POSITIONS)
		return kElbowPositions[state];
	else
		return kElbowPositions[0];
}

double Arm::ClampWrist(double wrist, double elbow)
{
#if WRIST_CLAMP_ENABLE
	if (elbow < CLAMP_LOW_ELBOW && wrist > CLAMP_LOW_WRIST)
	{
		return CLAMP_LOW_WRIST;
	}
	else if (elbow > CLAMP_MID_ELBOW_MIN && elbow < CLAMP_MID_ELBOW_MAX)
	{
		return CLAMP_MID_WRIST;
	}
	else if (elbow > CLAMP_HIGH_ELBOW)
	{
		if (wrist < CLAMP_HIGH_WRIST_MIN)
			return CLAMP_HIGH_WRIST_MIN;
	}
#endif // WRIST_CLAMP_ENABLE
	
	return wrist;
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
