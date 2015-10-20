#pragma once

#include <set>
#include <string>
#include <vector>

#include "IProgress.h"
#include "FileSplitStrategy.h"
#include "FileSplitStrategyFactory.h"

class FileSplitter
{
public:
	FileSplitter(
		const std::string& file_path, 
		int file_number, 
		FileSplitStrategyType type): 
		file_path_(file_path), 
		file_number_(file_number),
		strategy_(FileSplitStrategyFactory::NewStrategy(type)) { }

	~FileSplitter() {
		delete strategy_;
	}

	void Split()
	{
		std::vector<std::string> split_result;
		strategy_->split(file_path_, file_number_, split_result);
		for (int i = 0; i < file_number_; ++i) {
			// Write split_result[i] to *ith* file
			double progress_value = (i + 1.0) / file_number_;
			onProgress(progress_value);
		}
	}

	void AddIProgress(IProgress* iprogress) {
		iprogress_list_.insert(iprogress);
	}

	void RemoveIProgress(IProgress* iprogress) {
		iprogress_list_.erase(iprogress);
	}

private:
	std::string file_path_;
	int file_number_;
	std::set<IProgress*> iprogress_list_;
	FileSplitStrategy* strategy_;
	void onProgress(double value) {
		for (std::set<IProgress*>::iterator it = iprogress_list_.begin();
			 it != iprogress_list_.end();
			 ++it) {
			(*it)->DoProgress(value);
		}
	}

};