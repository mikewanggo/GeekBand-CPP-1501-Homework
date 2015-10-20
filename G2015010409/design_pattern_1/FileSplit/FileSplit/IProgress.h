#pragma once

class IProgress {
public:
	virtual ~IProgress() {}
	virtual void DoProgress(double value) = 0;

};