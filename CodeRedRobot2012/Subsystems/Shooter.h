#ifndef SHOOTER_H
#define SHOOTER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author geoffrey.twardokus
 */
class Shooter: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	
	CANJaguar *JagA;
	CANJaguar *JagB;
	CANJaguar *JagC;
	CANJaguar *JagD;
	
	
public:
	Shooter();
	void InitDefaultCommand();
	void Shoot(double);
	void Spin(double speed);
	void Stop();
	
};

#endif
