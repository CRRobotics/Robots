// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef TOTESTACKER_H
#define TOTESTACKER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class ToteStacker: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	CANTalon* toteLift;
	Solenoid* brake;
	DigitalInput* toteHome;
	int m_relativePosition;
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	ToteStacker();
	void InitDefaultCommand();
	void SetBrake(bool braked);
	int GetCurrentError();
	void SetPos(int position);
	int GetPos();
	bool IsAtHome();
	void ZeroToteStacker();
	void StopLift();
	void SetRelative(int position);
	int getRelative();
};

#endif
