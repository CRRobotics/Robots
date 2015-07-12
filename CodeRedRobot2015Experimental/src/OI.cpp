// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "OI.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/Autonomous/AutonomousCommand.h"
#include "Commands/ContainerStacker/CloseClaw.h"
#include "Commands/Acquisition/ExtendArms.h"
#include "Commands/Drive/JoystickAutoDrive.h"
#include "Commands/Drive/JoystickHDrive.h"
#include "Commands/Drive/LowerHWheel.h"
#include "Commands/ContainerStacker/OpenClaw.h"
#include "Commands/Drive/RaiseHWheel.h"
#include "Commands/ContainerStacker/ResetClaw.h"
#include "Commands/ToteStacker/ResetTote.h"
#include "Commands/Acquisition/RetractArms.h"
#include "Commands/Wings/RetractWings.h"
#include "Commands/Acquisition/StopWheels.h"
#include "Commands/Acquisition/ToteIntake.h"
#include "Commands/Acquisition/ToteOutput.h"
#include "Commands/ToteStacker/ToteSetPos.h"
#include "Commands/ToteStacker/SetRelativePos.h"
#include "Commands/ContainerStacker/TogglePlatformMode.h"
#include "Commands/ContainerStacker/SetManual.h"
#include "Commands/ContainerStacker/SetAuto.h"
#include "Commands/ToteStacker/DropTotes.h"
#include "Commands/ToteStacker/JoystickTote.h"
#include "Commands/ContainerStacker/JoystickContainer.h"
#include "Commands/ContainerStacker/RunClawToPos.h"
#include "Commands/ToteStacker/ChangeTotePosition.h"
#include "Commands/ContainerStacker/ContainerPositionChange.h"
#include "Commands/ContainerStacker/ZeroClaw.h"
#include "Commands/Wings/ExtendWings.h"
#include "Commands/Wings/StopWings.h"
#include "Commands/ToteStacker/ZeroTote.h"
#include "Subsystems/StackerRelative.h"
#include "Commands/ToteStackerNew/DropTotesNew.h"
#include "Commands/ToteStackerNew/Lift.h"
#include "Commands/ToteStackerNew/ResetToteNew.h"
#include "Commands/ToteStackerNew/SetRelativePosNew.h"
#include "Commands/ToteStackerNew/JoystickToteNew.h"
#include "Commands/ToteStackerNew/ZeroToteNew.h"
#include "Commands/Drive/ZeroDrive.h"

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
	// Process operator interface input here.
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

     	 m_sStick = new Joystick(1);
     	 m_cStick = new Joystick(0);

     	 //Conatiner Stacker
     	 m_contControlMode = new JoystickButton(m_cStick, CST_DIN_MAN_AUTO);
     	 m_contPlatform = new InvertedIOButton(m_cStick, CST_DIN_PLAT_TOG);
     	 m_contClaw = new JoystickButton(m_cStick, CST_DIN_CLAW);
     	 m_contUp = new InvertedIOButton(m_cStick, CST_DIN_UP);
     	 m_contDown = new InvertedIOButton(m_cStick, CST_DIN_DOWN);

     	 //Tote Stacker
     	 m_toteUp = new InvertedIOButton(m_cStick, TST_DIN_UP);
     	 m_toteDown = new InvertedIOButton(m_cStick, TST_DIN_DOWN);
     	 m_toteStep = new InvertedIOButton(m_cStick, TST_DIN_STEP);
     	 m_totePlatform = new InvertedIOButton(m_cStick, TST_DIN_PLAT);
     	 m_totePickup = new InvertedIOButton(m_cStick, TST_DIN_PCKUP);
     	 m_toteControlMode = new JoystickButton(m_cStick, TST_DIN_MAN_AUTO);

     	 //Acquisition
     	 m_acqOut = new InvertedIOButton(m_cStick, ACQ_DIN_OUT);
     	 m_acqIn = new InvertedIOButton(m_cStick, ACQ_DIN_IN);
     	 m_acqPosition = new JoystickButton(m_cStick, ACQ_DIN_POS);

     	 //Drive
     	 m_driveCenterUp = new JoystickButton(m_sStick, DRV_DIN_CNTR_UP);
     	 m_driveCenterDown = new JoystickButton(m_sStick, DRV_DIN_CNTR_DOWN);


     	 m_contPlatform->WhenPressed(new TogglePlatformMode());
     	 m_contUp->WhenPressed(new ContainerPositionChange(1));
     	 m_contDown->WhenPressed(new ContainerPositionChange(-1));

     	 /*
     	 m_toteUp->WhenReleased(new ChangeTotePosition(1));
     	 m_toteDown->WhenReleased(new ChangeTotePosition(-1));
     	 m_toteDown->WhileHeld(new DropTotes());
     	 m_toteStep->WhenPressed(new SetRelativePos(StackerRelative::STEP));
     	 m_totePlatform->WhenPressed(new SetRelativePos(StackerRelative::SCORING_PLAT));
     	 m_totePickup->WhenPressed(new SetRelativePos(StackerRelative::GROUND));
     	 */

     	m_toteUp->WhenPressed(new Lift());
     	m_toteDown->WhileHeld(new DropTotesNew());
     	m_toteStep->WhenPressed(new SetRelativePosNew(StackerRelative::STEP));
     	m_totePlatform->WhenPressed(new SetRelativePosNew(StackerRelative::SCORING_PLAT));
     	m_totePickup->WhenPressed(new SetRelativePosNew(StackerRelative::GROUND));

     	 m_acqOut->WhileHeld(new ToteOutput());
     	 m_acqIn->WhileHeld(new ToteIntake());

     	 m_driveCenterUp->WhenPressed(new RaiseHWheel());
     	 m_driveCenterDown->WhenPressed(new LowerHWheel());

        // SmartDashboard Buttons
//	SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());
//
//	SmartDashboard::PutData("ToteIntake", new ToteIntake());
//
//	SmartDashboard::PutData("ToteOutput", new ToteOutput());
//
//	SmartDashboard::PutData("ExtendArms", new ExtendArms());
//
//	SmartDashboard::PutData("RetractArms", new RetractArms());
//
//	SmartDashboard::PutData("StopWheels", new StopWheels());
//
//	SmartDashboard::PutData("JoystickHDrive", new JoystickHDrive());
//
//	SmartDashboard::PutData("JoystickAutoDrive", new JoystickAutoDrive(0,0,0,0,0,0));
//
	SmartDashboard::PutData("RetractWings", new RetractWings());

	SmartDashboard::PutData("ExtendWings", new ExtendWings());

	SmartDashboard::PutData("StopWings", new StopWings());
//
//	SmartDashboard::PutData("LowerHWheel", new LowerHWheel());
//
//	SmartDashboard::PutData("RaiseHWheel", new RaiseHWheel());
//
	SmartDashboard::PutData("ResetClaw", new ResetClaw());
//
//	SmartDashboard::PutData("CloseClaw", new CloseClaw());
//
//	SmartDashboard::PutData("OpenClaw", new OpenClaw());
//
//	SmartDashboard::PutData("SetClawPos", new SetClawPos());
//
	SmartDashboard::PutData("ResetTote", new ResetToteNew());
	//SmartDashboard::PutData("ZeroContainer", new ZeroClaw());
//
//	SmartDashboard::PutData("SetRelativePos", new SetRelativePos(StackerRelative::GROUND));
//
//	SmartDashboard::PutData("ToteSetPos", new ToteSetPos(StackerActions::SET_POS));

        // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

	SmartDashboard::PutData("Tote Joystick", new JoystickToteNew());
	SmartDashboard::PutData("Container Joystick", new JoystickContainer());
	SmartDashboard::PutData("Drive Zero", new ZeroDrive());
//	SmartDashboard::PutData("Zero Tote", new ZeroToteNew());
}

double OI::GetSingleTurn() {
	return m_sStick->GetThrottle();
}

double OI::GetSingleX() {
	return m_sStick->GetX();
}

double OI::GetSingleY() {
	if(fabs(m_sStick->GetY()) < .05) {
		return 0;
	}
	else {
		return m_sStick->GetY();
	}

}

int OI::GetDial() {
	int value = (int)(12250 * (m_cStick->GetRawAxis(7) + 1));
	//SmartDashboard::PutNumber("New Dial", value);
	return value;
}

int OI::GetDialTote() {
	int value = (int)(12500 * (m_cStick->GetRawAxis(7) + 1));
	//SmartDashboard::PutNumber("New Dial", value);
	return value;
}

bool OI::GetAcqArms() {
	return m_acqPosition->Get();
}

bool OI::GetClaw() {
	return m_contClaw->Get();
}

bool OI::GetAutoMan() {
	return m_contControlMode->Get();
}

bool OI::GetAutoManTote() {
	return m_toteControlMode->Get();
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
