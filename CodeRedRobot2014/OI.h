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
	
	JoystickButton* m_driveHighBtn;
	JoystickButton* m_driveLowBtn;
	
	JoystickButton* m_driveMotorsForce;
	JoystickButton* m_driveAutoStop;
	JoystickButton* m_shooterOverride;
	
	Button* m_shootTrussBtn;
	Button* m_shootGoalBtn;
	Button* m_shootManualBtn;
	
	Button* m_armPositionBtn;
	Button* m_ejectBtn;
	Button* m_acquisitionAutoBtn;
	Button* m_acquisitionManualBtn;
	Button* m_acquisitionDirectionBtn;
	Button* m_acquisitionToShooterBtn;
	
public:
	OI();
 
	double GetYLeft();
	double GetYRight();
	double GetRollerSpeed();
	double GetManualFire();
	
	bool IsReversed();
	bool IsAutoStop();
	bool AreMotorsForced();
	bool OverrideShooter();
};

#endif
