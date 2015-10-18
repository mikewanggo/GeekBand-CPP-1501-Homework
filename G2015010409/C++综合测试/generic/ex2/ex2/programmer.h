#pragma once

#include <string>
#include <iostream>

struct Programmer 
{
	Programmer(const int id, const std::wstring name)
		: Id(id), Name(name)
	{
	}

	void Print() const
	{
		std::wcout << L"[" << Id << L"]:" << Name << std::endl;
	}

	int GetId() const { return Id; }
	std::wstring GetName() const { return Name; }
	void SetName(const std::wstring& name) { Name = name; }

	int Id;
	std::wstring Name;
};