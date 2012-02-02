#ifndef ROBOTMAP_H
#define ROBOTMAP_H

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

/* Naming scheme for ports:
 * "Subsystem_Type_Function"
 * 
 * Subsystem:
 * AQS - Acquisition
 * BRG - Bridge
 * DRV - Drive
 * LDR - Loader
 * RBT - No subsystem
 * SHO - Shooter
 * 
 * Type:
 * MTR - Motor
 * SOL - Solenoid
 * ENC - Encoder
 * POT - Potentiometer
 * CNT - Counter
 * PRS - Pressure switch
 * CMP - Compressor
 * 
 */

// Acquisition
#define AQS_MTR_BELT 1
#define AQS_SOL_GATE 5

// Bridge
#define BRD_SOL_DEPLOY 6

// Drive
#define DRV_MTR_LEFT_A 6
#define DRV_MTR_LEFT_B 7
#define DRV_MTR_RIGHT_A 8
#define DRV_MTR_RIGHT_B 9

#define DRV_SOL_SHIFT 1

#define DRV_ENC_LEFT 2,3 // A,B
#define DRV_ENC_RIGHT 4,5

// Loader
#define LDR_SOL_GATE_TOP 3
#define LDR_SOL_GATE_BOT 4

#define LDR_SOL_COMP_TEST 2
#define LDR_POT_COMP_TEST 5

// Shooter
#define SHO_MTR_A 2
#define SHO_MTR_B 3
#define SHO_MTR_C 4
#define SHO_MTR_D 5

#define SHO_CNT_SPEED 6

#endif // ROBOTMAP_H
