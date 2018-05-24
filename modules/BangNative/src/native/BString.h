#pragma once

#include <cstdint>
#include "helper/generator.h"

class BString 
{
	void* m_ptr;
public:
	BANG_NATIVE_BINDING(0x0033F) BString();
	BANG_NATIVE_BINDING(0x42AA0) BString(const BString& other);
	BANG_NATIVE_BINDING(0x00A12) BString(const wchar_t* str);
	BANG_NATIVE_BINDING(0x000CA) ~BString();

	// Classes to port:
	/*
	BANG_NATIVE_BINDING(0x0063CB10) BString(const char* str);
	BANG_NATIVE_BINDING(0x0063CBC0, RegGen::EAX, RegGen::ESI, RegGen::EAX) explicit BString(int locStr);
	

	BANG_NATIVE_BINDING(0x0063CC00) void replace(const BString& value, std::size_t srcmax, int index);
	BANG_NATIVE_BINDING(0x0063CC20) void replace(const wchar_t* value, std::size_t srcmax, int index);
	BANG_NATIVE_BINDING(0x0063CD70) void replace(const char* value, std::size_t srcmax, int index);
	BANG_NATIVE_BINDING(0x0063CEB0) void assign(const char *src, int len);
	BANG_NATIVE_BINDING(0x0063CFD0) void overwriteByLs(int strNum);
	// BANG_NATIVE_BINDING(0x0063D0E0) int toGameString();
	BANG_NATIVE_BINDING(0x0063D260) void clear();
	BANG_NATIVE_BINDING(0x0063D290) int getSubstring(BString &out, int index, wchar_t *delimiter);
	BANG_NATIVE_BINDING(0x0063D380) void append(const BString& src, int len, int startIndex);
	// BANG_NATIVE_BINDING(0x0063D3C0) void append(BString *this, const wchar_t *src, size_t srcmax@<eax> , int startIndex);

	BANG_NATIVE_BINDING(0x0063D970) int getSubstrLen(int startIndex, int preLastIndex);
	BANG_NATIVE_BINDING(0x0063D9A0) void format(const wchar_t *src, ...);

	BANG_NATIVE_BINDING(0x0063DBC0) void tolower();
	BANG_NATIVE_BINDING(0x0063DBE0) void toupper();
	// BANG_NATIVE_BINDING(0x0063DC00) void getSubstrLenFromDot(); // --> is __stdcall
	BANG_NATIVE_BINDING(0x0063DED0) int strpos(const BString& src, int startIndex) const;
	BANG_NATIVE_BINDING(0x0063DF50, RegGen::EAX, RegGen::EAX, RegGen::EDX) int find(int pos, wchar_t needle) const;
	BANG_NATIVE_BINDING(0x0063E0C0) bool empty() const;
	BANG_NATIVE_BINDING(0x0063E0C0) bool empty();
	BANG_NATIVE_BINDING(0x0063E0E0) int length() const;
	BANG_NATIVE_BINDING(0x0063E100) int compare(const wchar_t *src, bool caseSensitive, int count) const;
	BANG_NATIVE_BINDING(0x0063E170) int compare(const BString& other, bool caseSensitive, int count)  const;
	BANG_NATIVE_BINDING(0x0063E200) const wchar_t* c_str() const;
	BANG_NATIVE_BINDING(0x0063E200) const wchar_t* c_str();
	BANG_NATIVE_BINDING(0x0063E210) const char* createMbString() const;
	BANG_NATIVE_BINDING(0x0063E210) const char* createMbString();

	BANG_NATIVE_BINDING(0x0063E3D0) int strToInt32() const;
	BANG_NATIVE_BINDING(0x0063E3F0) float strToFloat() const;

	BANG_NATIVE_BINDING(0x0063E4D0) void fromInt(int value);
	
	BANG_NATIVE_BINDING(0x0063EA70) BString& operator=(const BString&);
	BANG_NATIVE_BINDING(0x0063EBE0) bool operator==(const BString&);
	BANG_NATIVE_BINDING(0x0063EB70, RegGen::EAX, RegGen::ESI, RegGen::EAX) BString& operator+=(BString const&);
	*/

	// Define as bang class
	BANG_NATIVE_ALLOC_OVERRIDE

	inline explicit operator bool() const { 
		std::uintptr_t* ptr = reinterpret_cast<std::uintptr_t*>(m_ptr);
		if (ptr && *ptr)
			return true;
		return false;
	}
};



static_assert(sizeof(BString) == 0x4, "Size of BString must be 0x4");
