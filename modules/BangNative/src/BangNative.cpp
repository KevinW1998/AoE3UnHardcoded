#include "BangNative.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

BangNative::BangNative()
{
	const auto bangModuleBaseAddr = reinterpret_cast<std::uintptr_t>(GetModuleHandle(nullptr));
	
	// Inline lambdas
	const auto tf = [bangModuleBaseAddr](std::uintptr_t ptr)
	{
		return ptr + bangModuleBaseAddr;
	};

	/*
	m_bangSymTable = {
		BANG_NATIVE_SYM_ELEMENTS(tf, tf)
	};
	*/
}

std::uintptr_t BangNative::GetSym(const char* name)
{
	const auto possibleSym = m_bangSymTable.find(name);
	if (possibleSym != m_bangSymTable.end())
	{
		const auto value = possibleSym->second;
		if (value != 0)
			return value;
	}

	return 0;
}