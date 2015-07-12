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
#include "StackerRelative.h"

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
	DigitalInput* toteHall;
	StackerRelative m_relativePosition;
	int m_toteCount;
	int m_setPoint;
	bool m_dropMode;
	int ComputeSetPoint();
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	ToteStacker();
	void InitDefaultCommand();
	void SetTotes(int totesHigh);
	int GetPos();
	bool IsAtHome();
	void SetRelative(StackerRelative position);
	StackerRelative GetRelative();
	int GetTotes();
	bool GetHall();
	void SetSpeed(double speed);
	void DriveToHome();
	int GetSetPoint();
	void SetDrop(bool drop);
	void DriveToPoint();
	bool IsAtSetPoint();
	void ZeroTote();

};

#endif
