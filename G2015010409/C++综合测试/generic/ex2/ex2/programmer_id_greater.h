#pragma once

#include "programmer.h"

struct ProgrammerIdGreater: public std::binary_function<Programmer, Programmer, bool>
{
public:
	bool operator()(const Programmer& lhs, const Programmer& rhs) const {
		return (lhs.GetId() > rhs.GetId()) ? true : false;
	}
};