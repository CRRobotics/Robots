/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2011. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#ifndef __INVERTED_IO_BUTTON_H__
#define __INVERTED_IO_BUTTON_H__

#include "Buttons/Button.h"

class InvertedIOButton: public Button
{
public:
	static const bool kActiveState;

	InvertedIOButton(int port);
	virtual ~InvertedIOButton() {}

	virtual bool Get();

private:
	int m_port;
};

#endif
