#pragma once

#include <assert.h>

#include "FileSplitStrategy.h"
#include "AFileSplitStrategy.h"
#include "BFileSplitStrategy.h"
#include "CFileSplitStrategy.h"

enum FileSplitStrategyType {
	kTypeA,
	kTypeB,
	kTypeC,
	// ...
};

class FileSplitStrategyFactory {
public:
	static FileSplitStrategy* NewStrategy(FileSplitStrategyType type) {
		switch (type) {
			case kTypeA:
				return new AFileSplitStrategy();
				break;
			case kTypeB:
				return new BFileSplitStrategy();
				break;
			case kTypeC:
				return new CFileSplitStrategy();
				break;
			default:
				assert(false);
				break;
		}
		return nullptr;
	}

};