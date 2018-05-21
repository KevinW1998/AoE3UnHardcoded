#pragma once
#include <unordered_map>


class BangNative
{
	std::unordered_map<std::string, std::uintptr_t> m_bangSymTable;
public:
	BangNative();

	std::uintptr_t GetSym(const char* name);
};



