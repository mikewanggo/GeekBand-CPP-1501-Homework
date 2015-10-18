#include <algorithm>
#include <functional>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "programmer.h"
#include "programmer_id_greater.h"
#include "programmer_name_comparer.h"

using namespace std;

int main() {
	const vector<Programmer> kProgrammer = {
		{ 1, L"Scott Meyers" },
		{ 2, L"Martin Fowler" },
		{ 3, L"Bill Gates" },
		{ 4, L"P.J. Plaught" },
		{ 5, L"Stanley B. Lippman" },
		{ 6, L"Andrei Alexandrescu" },
	};
	set<Programmer, ProgrammerIdGreater> programmer_set(
		kProgrammer.cbegin(), kProgrammer.cend());
	const Programmer search(3, L"BillGates");
	for_each(programmer_set.begin(), programmer_set.end(), mem_fun_ref(&Programmer::Print));

	// Modify
	set<Programmer, ProgrammerIdGreater>::iterator it = programmer_set.find(search);
	const_cast<Programmer&>(*it).SetName(L"David Vandevoorde");

	// Print after modify
	for_each(programmer_set.begin(), programmer_set.end(), mem_fun_ref(&Programmer::Print));

	set<Programmer, ProgrammerNameComparer> set2(programmer_set.begin(), programmer_set.end());
	for_each(set2.begin(), set2.end(), mem_fun_ref(&Programmer::Print));
	return 0;
}
