#pragma once

class FileSplitStrategy {
public:
	virtual ~FileSplitStrategy() {}
	// result - out, ...
	virtual void split(const std::string& file_path, int file_number, std::vector<std::string>& result) = 0;
};