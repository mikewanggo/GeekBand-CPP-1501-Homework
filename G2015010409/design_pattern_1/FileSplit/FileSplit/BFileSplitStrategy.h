#pragma once

#include <string>

class BFileSplitStrategy : public FileSplitStrategy {
public:
	BFileSplitStrategy() { }
	~BFileSplitStrategy() { }
	// result - out, ...
	void split(const std::string& file_path, int file_number_, std::vector<std::string>& result) {
		// split the file to the result
	}
};
