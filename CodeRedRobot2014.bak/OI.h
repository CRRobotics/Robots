// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "OIMap.h"

class OI {
private:
	Joystick* m_lStick;
	Joystick* m_rStick;
	Joystick* m_cStick;
	
	Joystick* m_sStick;

	JoystickButton* m_driveHighBtn;
	JoystickButton* m_driveMotorsForce;
	JoystickButton* m_driveAutoRangeFor;

	JoystickButton* m_driveLowBtn;
	JoystickButton* m_driveAutoRangeBack;
	
	Button* m_shootGoalBtn;
	Button* m_ejectBtn;
	Button* m_acquisitionToShooterBtn;
	Button* m_acquisitionInBtn;
	Button* m_acquisitionOutBtn;
	
	Button* m_armUpBtn;
	Button* m_armDownBtn;
	Button* m_shootTrussBtn;
	Button* m_shootShortBtn;
	Button* m_shooterOverride;
	Button* m_LEDBtn;
	
public:
	OI();
 
	double GetYLeft();
	double GetYRight();
	double GetXLeft();
	double GetXRight();
	double GetYSingle();
	double GetXSingle();
	double GetTurnSingle();
	
	bool IsReversed();
	bool IsAutoRangeForwards();
	bool IsAutoRangeBackwards();
	bool AreMotorsForced();
	bool OverrideShooter();
};

#endif
