#pragma once

#include <string>

#include "FileSplitter.h"
#include "FileSplitStrategyFactory.h"

class MainForm: public Form, public IProgress
{
public:
	void Button1_Click()
	{
		std::string filePath = txt_file_path_->getText();
		int number = atoi(txt_file_number_->getText().c_str());

		FileSplitter splitter(filePath, number, kTypeA);
		splitter.AddIProgress(this);
		splitter.Split();
		splitter.RemoveIProgress(this);
	}

	void DoProgress(double progress_value) {
		progress_bar_.setValue(progress_value);
	}

private:
	TextBox*  txt_file_path_;
	TextBox* txt_file_number_;
	ProgressBar* progress_bar_;
};