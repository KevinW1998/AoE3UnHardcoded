#pragma once

#include "helper/generator.h"

#include "BString.h"


#include <remod.h>

class BCore
{
public:
	BANG_NATIVE_BINDING(0x6B498F) virtual ~BCore();
	BANG_NATIVE_BINDING(0x202966) virtual int BCoreUnkFunc8( );
	BANG_NATIVE_BINDING(0x63383C) virtual int BCoreUnkFunc12( );
	BANG_NATIVE_BINDING(0x52442) virtual int BCoreUnkFunc16( );
	BANG_NATIVE_BINDING(0x52442) virtual int BCoreUnkFunc20( );
	BANG_NATIVE_BINDING(0x52442) virtual int BCoreUnkFunc24( );
	BANG_NATIVE_BINDING(0x52442) virtual int BCoreUnkFunc28( );
	BANG_NATIVE_BINDING(0x6B497D) virtual long double BCoreUnkFunc32( );
	BANG_NATIVE_BINDING(0x6B4984) virtual int BCoreUnkFunc36( int a2 );
	BANG_NATIVE_BINDING(0xE2926) virtual int BCoreUnkFunc40( int a2, int a3, int a4 );
	BANG_NATIVE_BINDING(0xE2926) virtual int BCoreUnkFunc44( int a2, int a3, int a4 );
	BANG_NATIVE_BINDING(0xE2926) virtual int ShowMessageBox( const BString& text, int unk, const wchar_t* commandAfterClose );
	BANG_NATIVE_BINDING(0x1FDE49) virtual signed int BCoreUnkFunc52( int a2 );
	BANG_NATIVE_BINDING(0x1F71) virtual int * BCoreUnkFunc56( int a2 );
	BANG_NATIVE_BINDING(0x482556) virtual signed int BCoreUnkFunc60( );
	BANG_NATIVE_BINDING(0x52442) virtual int BCoreUnkFunc64( );
	BANG_NATIVE_BINDING(0x52442) virtual int BCoreUnkFunc68( );
	BANG_NATIVE_BINDING(0x52442) virtual int BCoreUnkFunc72( );
	BANG_NATIVE_BINDING(0x1F71) virtual int BCoreUnkFunc76( unsigned __int8 a2 );
	BANG_NATIVE_BINDING(0x474C9) virtual int BCoreUnkFunc80( );
	BANG_NATIVE_BINDING(0x11E6) virtual int BCoreUnkFunc84( );
	BANG_NATIVE_BINDING(0x11E6) virtual int BCoreUnkFunc88( );
	BANG_NATIVE_BINDING(0x11E6) virtual int BCoreUnkFunc92( );
	BANG_NATIVE_BINDING(0x18EA6B) virtual signed int BCoreUnkFunc96( );
	BANG_NATIVE_BINDING(0x384A8E) virtual int BCoreUnkFunc100( int a2, int a3, int a4, int a5 );
	BANG_NATIVE_BINDING(0x1000) virtual int BCoreUnkFunc104( int a2, int a3, int a4, int a5, int a6 );
	BANG_NATIVE_BINDING(0x54E09F) virtual int BCoreUnkFunc108( int a2, int a3, int a4, int a5, int a6, int a7, int a8 );
	BANG_NATIVE_BINDING(0x6B498A) virtual int BCoreUnkFunc112( int a2, int a3, char a4, unsigned __int8 a5 );
	BANG_NATIVE_BINDING(0x4E511) virtual int BCoreUnkFunc116( int a2, unsigned __int8 a3 );
	BANG_NATIVE_BINDING(0x18EA6B) virtual bool BCoreUnkFunc120( );
	BANG_NATIVE_BINDING(0x18EA6B) virtual int BCoreUnkFunc124( );
	BANG_NATIVE_BINDING(0x18EA6B) virtual bool BCoreUnkFunc128( );
	BANG_NATIVE_BINDING(0x1F71) virtual int BCoreUnkFunc132( int a2 );
	BANG_NATIVE_BINDING(0x202966) virtual int BCoreUnkFunc136( int a2 );
	BANG_NATIVE_BINDING(0x4E511) virtual int BCoreUnkFunc140( int a2, int a3 );
	BANG_NATIVE_BINDING(0x4E511) virtual int BCoreUnkFunc144( int a2, int a3 );

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


