#pragma once

#include "helper/generator.h"

class BGadget
{
public:
	BANG_NATIVE_BINDING( 0x504758 ) virtual ~BGadget( );
	BANG_NATIVE_BINDING( 0x6008f4 ) virtual void show( );
	BANG_NATIVE_BINDING( 0x504238 ) virtual void vfunc8( char a2 );
	BANG_NATIVE_BINDING( 0x4066a8 ) virtual void vfunc12( );
	BANG_NATIVE_BINDING( 0x41dc3d ) virtual void vfunc16( );
	BANG_NATIVE_BINDING( 0x41dce3 ) virtual void vfunc20( );
	BANG_NATIVE_BINDING( 0x436a7c ) virtual bool vfunc24( signed int a2, int a3 );
	BANG_NATIVE_BINDING( 0x437b89 ) virtual bool vfunc28( );
	BANG_NATIVE_BINDING( 0x4540d4 ) virtual void vfunc32( );
	BANG_NATIVE_BINDING( 0xab75fe ) virtual bool vfunc36( int a2 );
	BANG_NATIVE_BINDING( 0x4374b7 ) virtual signed int vfunc40( int a2, unsigned __int8 a3 );
	BANG_NATIVE_BINDING( 0x44b967 ) virtual void vfunc44( const BCoord * coord );
	BANG_NATIVE_BINDING( 0xab5a72 ) virtual void vfunc48( int a2, int a3 );
	BANG_NATIVE_BINDING( 0x5c7a3b ) virtual void vfunc52( const BCoord * coord );
	BANG_NATIVE_BINDING( 0xab6a13 ) virtual void vfunc56( const BCoord * coord, int a3 );
	BANG_NATIVE_BINDING( 0x44b7d0 ) virtual void vfunc60( const BCoord * bCoord );
	BANG_NATIVE_BINDING( 0x4481bc ) virtual void vfunc64( BCoordRect * rect );
	BANG_NATIVE_BINDING( 0xab5b72 ) virtual void vfunc68( int a2 );
	BANG_NATIVE_BINDING( 0x402d23 ) virtual void setHandle( BGadgetHandle handle );
	BANG_NATIVE_BINDING( 0x6008d2 ) virtual void vfunc76( const BGadgetHandle handle );
	BANG_NATIVE_BINDING( 0x518598 ) virtual void removeChildHandle( BGadgetHandle value );
	BANG_NATIVE_BINDING( 0x447bbc ) virtual void makeReal( );
	BANG_NATIVE_BINDING( 0x447cea ) virtual void makeUnreal( char arg4 );
	BANG_NATIVE_BINDING( 0x4066f7 ) virtual bool vfunc92( BPoint * point );
	BANG_NATIVE_BINDING( 0x44797c ) virtual bool vfunc96( int a2, const BGadgetHandle gadgetHandle, int a4 );
	BANG_NATIVE_BINDING( 0x4042ce ) virtual void setFlag( BGadgetFlag flag );
	BANG_NATIVE_BINDING( 0x4433b5 ) virtual void resetFlag( BGadgetFlag flag );
	BANG_NATIVE_BINDING( 0xab6c63 ) virtual void vfunc108( float a2 );
	BANG_NATIVE_BINDING( 0xab5d70 ) virtual long double vfunc112( );
	BANG_NATIVE_BINDING( 0x41df4a ) virtual unsigned int vfunc116( );
	BANG_NATIVE_BINDING( 0x4011e6 ) virtual void vfunc120( );
	BANG_NATIVE_BINDING( 0x4011e6 ) virtual void vfunc124( );
	BANG_NATIVE_BINDING( 0x62af05 ) virtual void vfunc128( BString * text );
	BANG_NATIVE_BINDING( 0x5938dc ) virtual void setTextColor;
	BANG_NATIVE_BINDING( 0x59386a ) virtual int vfunc136( int a2 );
	BANG_NATIVE_BINDING( 0x59391d ) virtual void setFont( const BString * fontName, int fontSize );
	BANG_NATIVE_BINDING( 0x593882 ) virtual void vfunc144( );
	BANG_NATIVE_BINDING( 0x565ca0 ) virtual int vfunc148( unsigned __int8 a2 );
	BANG_NATIVE_BINDING( 0x63880b ) virtual int vfunc152( int a2 );
	BANG_NATIVE_BINDING( 0x5e0075 ) virtual int vfunc156( );
	BANG_NATIVE_BINDING( 0x6389b2 ) virtual int vfunc160( int a2 );
	BANG_NATIVE_BINDING( 0x5e006c ) virtual int vfunc164( );
	BANG_NATIVE_BINDING( 0x6293d3 ) virtual void vfunc168( BGadXMLWalker * arg4 );
	BANG_NATIVE_BINDING( 0x629a7a ) virtual void vfunc172( BGadXMLWalker * arg4 );
	BANG_NATIVE_BINDING( 0x401f71 ) virtual void vfunc176( );
	BANG_NATIVE_BINDING( 0x447c97 ) virtual void vfunc180( );
	BANG_NATIVE_BINDING( 0x455719 ) virtual void vfunc184( float a2 );
	BANG_NATIVE_BINDING( 0x437c2e ) virtual unsigned int vfunc188( int a2, int a3 );
	BANG_NATIVE_BINDING( 0x4325ee ) virtual bool vfunc192( int index );
	BANG_NATIVE_BINDING( 0x401f71 ) virtual void vfunc196( );
	BANG_NATIVE_BINDING( 0xab7c55 ) virtual int vfunc200( char a2, char a3 );
	BANG_NATIVE_BINDING( 0x404310 ) virtual bool isOfType( BGadgetType gadgetType );
	BANG_NATIVE_BINDING( 0xab7990 ) virtual BGadget * vfunc208( );
	BANG_NATIVE_BINDING( 0x46fb85 ) virtual int vfunc212( float * color, unsigned __int8 flashLimit, unsigned __int8 a4, int a5 );
	BANG_NATIVE_BINDING( 0x44a1e9 ) virtual BGadget * vfunc216( );
	BANG_NATIVE_BINDING( 0x466003 ) virtual int vfunc220( _DWORD * a2, _DWORD * a3, _DWORD * a4, _DWORD * a5 );
	BANG_NATIVE_BINDING( 0xab5cb0 ) virtual bool vfunc224( int a2 );
	BANG_NATIVE_BINDING( 0xab7b2d ) virtual void vfunc228( float a2, char a3 );
	BANG_NATIVE_BINDING( 0x41dd17 ) virtual void vfunc232( BColor * color );

	BANG_NATIVE_ALLOC_OVERRIDE
};