// RobotBuilder Version: 1.5
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
#include "InvertedIOButton.h"

class OI {
private:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	Joystick* sStick;
	Joystick* cStick;
	JoystickButton* m_halfSpeed;
	JoystickButton* m_raiseWheel;
	JoystickButton* m_lowerWheel;
	JoystickButton* m_NOS;
	JoystickButton* m_resetDirection;
	JoystickButton* m_zero;
	JoystickButton* m_brake;
	InvertedIOButton* m_holdTest;
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
public:
	OI();
	double GetSingleY();
	double GetSingleX();
	double GetSingleTwist();
	double GetDial();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES

	Joystick* getsStick();
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES
};

#endif
