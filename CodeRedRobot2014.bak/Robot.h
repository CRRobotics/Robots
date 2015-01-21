// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#ifndef _ROBOT_H
#define _ROBOT_H

#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"

#include "Subsystems/Acquisition.h"
#include "Subsystems/Drive.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/Ejection.h"
#include "Subsystems/Vision.h"

#include "OI.h"

class Robot : public IterativeRobot {
public:
	Command *autonomousCommand;
	static OI *oi;
	LiveWindow *lw;
	SendableChooser* autoChooser;
	
	static Drive* drive;
	static Shooter* shooter;
	static Acquisition* acquisition;
	static Ejection* ejection;
	static Vision* vision;
	
	Compressor* comp;
	
	virtual void RobotInit();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
	
	bool m_firstRun;
};
#endif
