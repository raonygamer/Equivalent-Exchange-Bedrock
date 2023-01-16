#pragma once

class LogLevel {};
class LogArea {};

class ContentLog {
public:
	int log(LogLevel, LogArea, ...);
};