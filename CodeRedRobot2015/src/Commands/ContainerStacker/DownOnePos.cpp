#include "DownOnePos.h"

#include "SetClawTargetPos.h"
#include "../../Subsystems/ClawPositions.h"
#include "ResetClaw.h"


DownOnePos::DownOnePos() {
	ClawPositions current = Robot::containerStacker->GetTargetEnum();
	if(current == ClawPositions::PICK_UP) {
		AddParallel(new ResetClaw);
	}
	else if(current == ClawPositions::LEVEL_1) {
		AddParallel(new SetClawTargetPos(ClawPositions::PICK_UP));
	}
	else if(current == ClawPositions::LEVEL_2) {
		AddParallel(new SetClawTargetPos(ClawPositions::LEVEL_1));
	}
	else if(current == ClawPositions::LEVEL_3) {
		AddParallel(new SetClawTargetPos(ClawPositions::LEVEL_2));
	}
	else if(current == ClawPositions::LEVEL_4) {
		AddParallel(new SetClawTargetPos(ClawPositions::LEVEL_3));
	}
	else if(current == ClawPositions::LEVEL_5) {
		AddParallel(new SetClawTargetPos(ClawPositions::LEVEL_4));
	}
	else if(current == ClawPositions::MAX) {
		AddParallel(new SetClawTargetPos(ClawPositions::LEVEL_5));
	}
}