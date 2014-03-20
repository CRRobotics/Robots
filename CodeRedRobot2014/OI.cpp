// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "OI.h"
#include "InvertedIOButton.h"
#include "SmartDashboard/SmartDashboard.h"

#include "Commands/Acquisition/ArmLower.h"
#include "Commands/Acquisition/ArmRaise.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/Shooter/Fire.h"
#include "Commands/Drive/JoystickAutoDrive.h"
#include "Commands/Drive/JoystickDrive.h"
#include "Commands/Acquisition/RollerSpin.h"
#include "Commands/Acquisition/RollerStop.h"
#include "Commands/Drive/ShiftHigh.h"
#include "Commands/Drive/ShiftLow.h"
#include "Commands/Ejection/ExtendKicker.h"
#include "Commands/Ejection/RetractKicker.h"
#include "Commands/EjectBall.h"
#include "Commands/BallToShooter.h"
#include "Commands/Vision/TurnLEDsOn.h"

OI::OI() {
	// Process operator interface input here.

	m_lStick = new Joystick(DRV_JOY_LEFT);
	m_rStick = new Joystick(DRV_JOY_RIGHT);
	
	m_driveHighBtn = new JoystickButton(m_rStick, 1); // Trigger on the right stick
	m_driveLowBtn = new JoystickButton(m_lStick, 1);
	
	m_LEDBtn = new JoystickButton(m_rStick, 11); //Just for testing
	
	m_driveMotorsForce = new JoystickButton(m_rStick, 2); // Button 2 on the right stick
	m_driveAutoRangeFor = new JoystickButton(m_rStick, 3);
	m_driveAutoRangeFor = new JoystickButton(m_lStick, 3);
	m_shooterOverride = new JoystickButton(m_lStick, 8);
	
	m_shootTrussBtn = new InvertedIOButton(SHO_DIN_TRUSS);
	m_shootGoalBtn = new InvertedIOButton(SHO_DIN_GOAL);
	m_shootManualBtn = new InvertedIOButton(SHO_DIN_MAN);
	
	m_ejectBtn = new InvertedIOButton(EJT_DIN_EJECT);
	m_armPositionBtn = new DigitalIOButton(ACQ_DIN_ARM);
	m_acquisitionAutoBtn = new DigitalIOButton(ACQ_DIN_AUTO);
	m_acquisitionManualBtn = new DigitalIOButton(ACQ_DIN_MAN);
	m_acquisitionDirectionBtn = new DigitalIOButton(ACQ_DIN_DIR);
	
	m_acquisitionToShooterBtn = new JoystickButton(m_lStick, 6);
	
	//Separation comment to make it easier to read
	
	m_driveHighBtn->WhenPressed(new ShiftHigh());
	m_driveLowBtn->WhenPressed(new ShiftLow());
	
	m_LEDBtn->ToggleWhenPressed(new TurnLEDsOn());
	
    m_shootTrussBtn->WhenPressed(new Fire(SHO_DEFAULT_TRUSS, false, false));
    m_shootGoalBtn->WhenPressed(new Fire(SHO_DEFAULT_GOAL, false, false));
    m_shootManualBtn->WhenPressed(new Fire(0, true, true));
    
    m_ejectBtn->WhileHeld(new EjectBall());
    m_acquisitionAutoBtn->WhileHeld(new RollerSpin(false, false, false));
    m_acquisitionManualBtn->WhileHeld(new RollerSpin(true, false, false));
    m_acquisitionToShooterBtn->WhenPressed(new BallToShooter());
    m_armPositionBtn->WhenInactive(new ArmLower());
    m_armPositionBtn->WhenActive(new ArmRaise());
}

double OI::GetYLeft() {
	if(m_lStick->GetY() > -.03 && m_lStick->GetY() < .03) return 0; // Add a deadzone to the joystick
	else return m_lStick->GetY();
}

double OI::GetYRight() {
	if(m_rStick->GetY() > -.03 && m_rStick->GetY() < .03) return 0; // Add a deadzone to the joystick
	else return m_rStick->GetY();}

double OI::GetRollerSpeed() {
	return DriverStation::GetInstance()->GetEnhancedIO().GetAnalogInRatio(1); 
}

double OI::GetManualFire() {
	return (1-DriverStation::GetInstance()->GetEnhancedIO().GetAnalogInRatio(2)) * .25;
}

bool OI::IsReversed() {
	return !m_acquisitionDirectionBtn->Get();
}

bool OI::IsAutoRangeForwards() {
	return m_driveAutoRangeFor->Get();
}

bool OI::IsAutoRangeBackwards() {
	return m_driveAutoRangeBack->Get();
}

bool OI::AreMotorsForced() {
//	return true;
	return m_driveMotorsForce->Get();
}

bool OI::OverrideShooter() {
	return m_shooterOverride->Get();
}
