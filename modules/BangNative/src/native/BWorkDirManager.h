#pragma once

#include <remod/remod_definitions.h>

class BWorkDirManager
{
	// Delete for now, might add later
	BWorkDirManager() = delete;

public:
	static inline remod::global_data_pointer_no_resolve<const wchar_t*> StartUpSubPath{ 0xbeaf98 };
};
