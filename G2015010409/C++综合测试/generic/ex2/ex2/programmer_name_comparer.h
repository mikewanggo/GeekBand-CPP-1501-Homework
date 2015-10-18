#pragma once

#include <functional>

#include "programmer.h"

struct ProgrammerNameComparer : public std::binary_function<Programmer, Programmer, bool>
{
	bool operator()(const Programmer& lhs, const Programmer& rhs) const {
		return (lhs.GetName() < rhs.GetName()) ? true : false;
	}
};
