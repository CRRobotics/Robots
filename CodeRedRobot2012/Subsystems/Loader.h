#ifndef LOADER_H
#define LOADER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author devon.loehr
 */
class Loader: public Subsystem {
private:
	Solenoid *lockH;
	Solenoid *lockL;
	Solenoid *compTest;
	
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Loader();
	void InitDefaultCommand();
	void Lock();
	void Load();
	void Launch();
	void Rapidfire();
	
};

#endif
 
