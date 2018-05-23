#pragma once

#include "BCoreAnimationMessageHandler.h"
#include "BAnimationObjectMessageHandler.h"
#include "BLayoutObject.h"

#include "generator.h"

class __declspec(dllimport) BGadget : public BLayoutObject, public BAnimationObjectMessageHandler, public BCoreAnimationMessageHandler
{
public:
	BANG_NATIVE_BINDING(0x00D26180, RegGen::EDI) BGadget();
	virtual ~BGadget();
	
	// BLayoutObject
	BANG_NATIVE_BINDING(0x00D45460, RegGen::EAX) virtual void bLayoutObjUnkFunc4() override;
	BANG_NATIVE_BINDING(0x00D45460, RegGen::EAX, RegGen::EDI) virtual void bLayoutObjUnkFunc8(void*) override;
	BANG_NATIVE_BINDING(0x00DEADBE) virtual void bLayoutObjUnkFuncC(int, int) override;
	virtual void bLayoutObjUnkFunc10(int) override;
	virtual void bLayoutObjUnkFunc14(int, int) override;
	virtual void bLayoutObjUnkFunc18(int) override;
	virtual void bLayoutObjUnkFunc1C(int) override;
	virtual void blaMyFunc(int, ...);
	
	virtual void init();																		// +0x20
	virtual void bGadgetUnkFunc24(bool);														// +0x24
	virtual void bGadgetUnkFunc28();															// +0x28
	virtual void bGadgetUnkFunc2C();															// +0x2C
	virtual void bGadgetUnkFunc30();															// +0x30
	virtual void bGadgetUnkFunc34(int, int);													// +0x34
	virtual void bGadgetUnkFunc38();															// +0x38
	virtual void bGadgetUnkFunc3C();															// +0x3C
	virtual void bGadgetUnkFunc40(int);															// +0x40
	virtual void bGadgetUnkFunc44(int, int);													// +0x44
	virtual void setGadgetHash(int);															// +0x48
	virtual void bGadgetUnkFunc4C(bool);														// +0x4C [Bool not Confirmed]
	virtual void bGadgetUnkFunc50(bool);														// +0x50 [Bool not Confirmed]
	virtual void bGadgetUnkFunc54();															// +0x54
	virtual void bGadgetUnkFunc58(bool);														// +0x58
	virtual void bGadgetUnkFunc5C(int);															// +0x5C
	virtual void bGadgetUnkFunc60(int, int, int);												// +0x60
	virtual void bGadgetUnkFunc64(int);															// +0x64
	virtual void bGadgetUnkFunc68(int);															// +0x68
	virtual void bGadgetUnkFunc6C(bool);														// +0x6C
	virtual void bGadgetUnkFunc70(int);															// +0x70
	virtual void bGadgetUnkFunc74(int);															// +0x74
	virtual void bGadgetUnkFunc78();															// +0x78
	virtual void bGadgetUnkFunc7C();															// +0x7C
	virtual void bGadgetUnkFunc80(float);														// +0x80
	virtual void bGadgetUnkFunc84();															// +0x84
	virtual void bGadgetUnkFunc88();															// +0x88
	virtual void bGadgetUnkFunc8C();															// +0x8C
	virtual void bGadgetUnkFunc90();															// +0x90
	virtual void showGadgetText(void* gadgetText);												// +0x94 [TODO: gadgetText to BString]
	virtual void bGadgetUnkFunc98(float*);														// +0x98
	virtual void bGadgetUnkFunc9C(int);															// +0x9C
	virtual void bGadgetUnkFuncA0(void* text, int);												// +0xA0
	virtual void bGadgetUnkFuncA4(void* text, int);												// +0xA4
	virtual void bGadgetUnkFuncA8(int);															// +0xA8
	virtual void bGadgetUnkFuncAC();															// +0xAC
	virtual void bGadgetUnkFuncB0(int);															// +0xB0
	virtual void bGadgetUnkFuncB4(int);															// +0xB4
	virtual void bGadgetUnkFuncB8();															// +0xB8
	virtual void bGadgetUnkFuncBC(int);															// +0xBC
	virtual void bGadgetUnkFuncC0();															// +0xC0
	virtual void bGadgetUnkFuncC4(void* unkXMLReader);											// +0xC4
	virtual void bGadgetUnkFuncC8(int);															// +0xC8
	virtual void bGadgetUnkFuncCC(int);															// +0xC8
	virtual void bGadgetUnkFuncD0();															// +0xC8
	virtual void bGadgetUnkFuncD4(float);														// +0xC8
	virtual void bGadgetUnkFuncD8();															// +0xC8
	virtual void bGadgetUnkFuncDC(int, int);													// +0xC8
	virtual void bGadgetUnkFuncE0(int);															// +0xC8
	virtual void bGadgetUnkFuncE4(int);															// +0xC8
	virtual void bGadgetUnkFuncE8(int, int);													// +0xC8
	virtual void isZero(int);																	// +0xC8
	virtual void bGadgetUnkFuncF0();															// +0xC8
	virtual void bGadgetUnkFuncF4(int, char, bool, int);										// +0xC8
	virtual void bGadgetUnkFuncF8(float, float, float, float);									// +0xC8
	virtual void bGadgetUnkFuncFC(float*, float*, float*, float*);								// +0xC8
	virtual void bGadgetUnkFunc100(int);														// +0xC8
	virtual void bGadgetUnkFunc104(float, bool);												// +0xC8
	virtual void bGadgetUnkFunc108(float, bool);												// +0xC8
	virtual void bGadgetUnkFunc10C(float, float, float, bool);									// +0xC8 [TODO: 3x float = COLOR] setColor function?
	virtual void bGadgetUnkFunc110(int);														// +0xC8
	virtual void bGadgetUnkFunc114(int, int);													// +0xC8
	virtual void bGadgetUnkFunc118(unsigned int, int, int);										// +0xC8
	virtual void bGadgetUnkFunc11C(unsigned int, bool);											// +0xC8
	virtual void bGadgetUnkFunc120(int);														// +0xC8
	virtual void bGadgetUnkFunc124(float*);														// +0xC8
	virtual void bGadgetUnkFunc128(float*);														// +0xC8
	virtual void bGadgetUnkFunc12C(unsigned short*, void* text, unsigned int, unsigned int);	// +0xC8
	virtual void bGadgetUnkFunc130(void *text1, int a3, int *a4, unsigned int *a5, int a6, int a7, float *a8, int a9, float *a10, unsigned int *a11, void *text2, void *text3, void *text4, bool *a15);					// +0xC8
	virtual void bGadgetUnkFunc134(const wchar_t*, int, int, int, int);							// +0xC8 [Texture id?]
	virtual void bGadgetUnkFunc138(int);														// +0xC8
	virtual void bGadgetUnkFunc13C();															// +0xC8
	virtual void bGadgetUnkFunc140();															// +0xC8
	
	// BAnimationObjectMessageHandler
	virtual void bAnimObjUnkFunc0(int, int) override;
	virtual void bAnimObjUnkFunc4(int, int) override;
	virtual void bAnimObjUnkFunc8(int, int, int, int, int) override;
	virtual void bAnimObjUnkFuncC(int, int) override;

	// BCoreAnimationMessageHandler
	virtual void bCoreAnimUnkFunc0(int) override;

	// TODO: Fields
};

// static_assert(sizeof(BGadget) == 0x220, "Size of BGadget must be 0x220 bytes")
