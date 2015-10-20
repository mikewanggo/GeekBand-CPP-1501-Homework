#pragma once

#include <string>

class AFileSplitStrategy: public FileSplitStrategy {
public:
	AFileSplitStrategy() { }
	~AFileSplitStrategy() { }
	// result - out, ...
	void split(const std::string& file_path, int file_number_, std::vector<std::string>& result) {
		// split the file to the result
	}
};