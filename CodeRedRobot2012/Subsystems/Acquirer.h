#ifndef ACQUIRER_H
#define ACQUIRER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Ian
 */
class Acquirer: public Subsystem {
private:
	Victor belt;
	
	AnalogChannel gateLeft;
	AnalogChannel gateRight;
	AnalogChannel ballHigh;
	AnalogChannel ballLow;
	
	int ballCount;
	
public:
	Acquirer();
	void InitDefaultCommand();
	
	void BeltRun();
	void BeltStop();
	void BeltReverse();
	
	void SetBallCount(int num);
	int GetBallCount();
	void AddBall();
	void RemoveBall();
};

#endif