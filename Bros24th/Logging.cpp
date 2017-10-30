#include "stdafx.h"
#include "Logging.h"

bool LoggingDisabled = false;

void LoggingEnable()
{
	LoggingDisabled = false;
}

void LoggingDisable()
{
	LoggingDisabled = true;
}