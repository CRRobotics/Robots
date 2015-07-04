#ifndef _ROBOT_H
#define _ROBOT_H

#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
//#include "LiveWindow.h"

// The following variables are automatically assigned by
// robotbuilder and will be updated the next time you export to
// Java from robot builder. Do not put any code or make any change
// in the following block or it will be lost on an update. To
// prevent this subsystem from being automatically updated, delete
// the following line.
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "Commands/AutonomousCommand.h"
#include "Subsystems/Drive.h"

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "OI.h"

class Robot : public IterativeRobot {
public:
	Command *autonomousCommand;
	static OI *oi;
	LiveWindow *lw;
	// The following variables are automatically assigned by
	// robotbuilder and will be updated the next time you export to
	// Java from robot builder. Do not put any code or make any change
	// in the following block or it will be lost on an update. To
	// prevent this subsystem from being automatically updated, delete
	// the following line.
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static Drive* drive;
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	virtual void RobotInit();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
};
#endif
