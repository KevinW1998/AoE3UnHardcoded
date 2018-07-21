#pragma once

#include "helper/generator.h"
#include "BString.h"
#include <remod.h>

#define _BYTE void
#define BWorld void
#define BCameraManager void
#define BColor void

class BCore
{
public:
	BANG_NATIVE_BINDING(0xab498f) virtual ~BCore();
	BANG_NATIVE_BINDING(0x602966) virtual void * vfunc4(_BYTE * a2);
	BANG_NATIVE_BINDING(0xa3383c) virtual int vfunc8();
	BANG_NATIVE_BINDING(0x452442) virtual void vfunc12();
	BANG_NATIVE_BINDING(0x452442) virtual void * vfunc16();
	BANG_NATIVE_BINDING(0x452442) virtual int vfunc20();
	BANG_NATIVE_BINDING(0x452442) virtual int vfunc24();
	BANG_NATIVE_BINDING(0xab497d) virtual long double vfunc28();
	BANG_NATIVE_BINDING(0xab4984) virtual int vfunc32(char a2);
	BANG_NATIVE_BINDING(0x4e2926) virtual void vfunc36();
	BANG_NATIVE_BINDING(0x4e2926) virtual void vfunc40();
	BANG_NATIVE_BINDING(0x8e3926) virtual int ShowMessageBox(const BString& text, int unk, const wchar_t* commandAfterClose);
	BANG_NATIVE_BINDING(0x5fde49) virtual signed int vfunc48(BString * a1);
	BANG_NATIVE_BINDING(0x401f71) virtual BWorld * vfunc52(int a2);
	BANG_NATIVE_BINDING(0x882556) virtual signed int vfunc56();
	BANG_NATIVE_BINDING(0x452442) virtual int vfunc60();
	BANG_NATIVE_BINDING(0x452442) virtual int vfunc64();
	BANG_NATIVE_BINDING(0x452442) virtual BCameraManager * vfunc68();
	BANG_NATIVE_BINDING(0x401f71) virtual int vfunc72(unsigned __int8 a2);
	BANG_NATIVE_BINDING(0x4474c9) virtual bool vfunc76();
	BANG_NATIVE_BINDING(0x4011e6) virtual int vfunc80();
	BANG_NATIVE_BINDING(0x4011e6) virtual int vfunc84();
	BANG_NATIVE_BINDING(0x4011e6) virtual int vfunc88();
	BANG_NATIVE_BINDING(0x58ea6b) virtual bool createGadgetManager();
	BANG_NATIVE_BINDING(0x784a8e) virtual BWorld * vfunc96(int a2, int a3, BColor * a4, int a5);
	BANG_NATIVE_BINDING(0x401000) virtual BWorld * vfunc100(int a2, int a3, BColor * a4, BColor * a5, int a6);
	BANG_NATIVE_BINDING(0x94e09f) virtual int vfunc104(int a2, int a3, int a4, int a5, BColor * a6, BColor * a7, int a8);
	BANG_NATIVE_BINDING(0xab498a) virtual int vfunc108(int a2, int a3, char a4, unsigned __int8 a5);
	BANG_NATIVE_BINDING(0x44e511) virtual char vfunc112(int a2, char a3);
	BANG_NATIVE_BINDING(0x58ea6b) virtual bool vfunc116();
	BANG_NATIVE_BINDING(0x58ea6b) virtual int vfunc120();
	BANG_NATIVE_BINDING(0x58ea6b) virtual bool vfunc124();
	BANG_NATIVE_BINDING(0x401f71) virtual void vfunc128(const char * a2);
	BANG_NATIVE_BINDING(0x602966) virtual int vfunc132(int a2);
	BANG_NATIVE_BINDING(0x44e511) virtual int vfunc136(char a2, char a3);
	BANG_NATIVE_BINDING(0x44e511) virtual void vfunc140(BString * a2, BString * a3);

	BANG_NATIVE_ALLOC_OVERRIDE
private:
	unsigned int dword4;
	unsigned int dword8;
	unsigned int dwordC;
	unsigned int dword10;
	unsigned int dword14;
	unsigned int dword18;
	unsigned int dword1C;
	unsigned int dword20;
	unsigned int dword24;
	unsigned int dword28;
	unsigned int dword2C;
	unsigned int dword30;
	unsigned int dword34;
	unsigned int dword38;
	unsigned int dword3C;
	unsigned int dword40;
	unsigned int dword44;
	unsigned char gap48[24];
	unsigned int dword60;
	unsigned int dword64;
	unsigned int dword68;
	unsigned int dword6C;
	unsigned int dword70;
	unsigned int dword74;
	unsigned int dword78;
	unsigned int dword7C;
	unsigned char byte80;
	unsigned char gap81[255];
	unsigned char byte180;
	unsigned char gap181[255];
	unsigned char byte280;
	unsigned char gap281[255];
	unsigned char byte380;
	unsigned char gap381[255];
	unsigned char byte480;
	unsigned char gap481[255];
	unsigned char byte580;
	unsigned char gap581[255];
	unsigned char byte680;
	unsigned char gap681[255];
	unsigned char byte780;
	unsigned char gap781[255];
	unsigned int dword880;
	unsigned int dword884;
	unsigned char byte888;
	unsigned char byte889;
	unsigned int dword88C;
	unsigned char byte890[152];
};

static_assert(sizeof(BCore) == 0x928u, "BCore must me 0x928 bytes");

inline remod::global_data_pointer_no_resolve<BCore> BCoreInstance { 0x00C66244 };


#undef _BYTE
#undef BWorld void
#undef BCameraManager void
#undef BColor void
