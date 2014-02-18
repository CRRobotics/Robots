#include "SimpleAuton.h"
#include "Acquisition/ArmLower.h"
#include "Acquisition/RollerSpin.h"
#include "Acquisition/RollerStop.h"
#include "Drive/DriveToDistance.h"
#include "Drive/JoystickAutoDrive.h"
#include "Shooter/Fire.h"
#include "BallToShooter.h"

#define TIME_TO_DRIVE 1.5 //TODO: Test dummy value
#define DIST_TO_WALL 3.25 //TODO: REPLACE SEMI-DUMMY VALUE!

SimpleAuton::SimpleAuton() {
	AddSequential(new ArmLower());
	AddParallel(new RollerSpin(false, false, true));
	AddSequential(new JoystickAutoDrive(1, -1), TIME_TO_DRIVE);
	AddParallel(new JoystickAutoDrive(0, 0));
	AddSequential(new WaitCommand(1));
//	AddSequential(new DriveToDistance(DIST_TO_WALL));
	if(Robot::acquisition->HasBall() && !Robot::acquisition->BallReady())
		AddSequential(new BallToShooter(), .7);
	AddSequential(new Fire(1, false, true));
	AddParallel(new RollerStop());
}
