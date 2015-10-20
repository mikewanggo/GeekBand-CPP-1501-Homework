#pragma once

#include <string>
#include <vector>

#include "FileSplitStrategy.h"

class CFileSplitStrategy: public FileSplitStrategy {
public:
	CFileSplitStrategy() { }
	~CFileSplitStrategy() { }
	// result - out, ...
	void split(const std::string& file_path, int file_number_, std::vector<std::string>& result) {
		// split the file to the result
	}

};