#pragma once

// Macro Utils
// Found from http://stackoverflow.com/a/1872506/5082374
#define BANG_NATIVE_STRINGIZE(arg)  BANG_NATIVE_STRINGIZE1(arg)
#define BANG_NATIVE_STRINGIZE1(arg) BANG_NATIVE_STRINGIZE2(arg)
#define BANG_NATIVE_STRINGIZE2(arg) #arg

#define BANG_NATIVE_CONCATENATE(arg1, arg2)   BANG_NATIVE_CONCATENATE1(arg1, arg2)
#define BANG_NATIVE_CONCATENATE1(arg1, arg2)  BANG_NATIVE_CONCATENATE2(arg1, arg2)
#define BANG_NATIVE_CONCATENATE2(arg1, arg2)  arg1##arg2

#define BANG_NATIVE_FOR_EACH_1(what, x, ...) what(x, 1)
#define BANG_NATIVE_FOR_EACH_2(what, x, ...)\
  what(x, 2),\
  BANG_NATIVE_FOR_EACH_1(what,  __VA_ARGS__)
#define BANG_NATIVE_FOR_EACH_3(what, x, ...)\
  what(x, 3),\
  BANG_NATIVE_FOR_EACH_2(what,  __VA_ARGS__)
#define BANG_NATIVE_FOR_EACH_4(what, x, ...)\
  what(x, 4),\
  BANG_NATIVE_FOR_EACH_3(what,  __VA_ARGS__)
#define BANG_NATIVE_FOR_EACH_5(what, x, ...)\
  what(x, 5),\
  BANG_NATIVE_FOR_EACH_4(what,  __VA_ARGS__)
#define BANG_NATIVE_FOR_EACH_6(what, x, ...)\
  what(x, 6),\
  BANG_NATIVE_FOR_EACH_5(what,  __VA_ARGS__)
#define BANG_NATIVE_FOR_EACH_7(what, x, ...)\
  what(x, 7),\
  BANG_NATIVE_FOR_EACH_6(what,  __VA_ARGS__)
#define BANG_NATIVE_FOR_EACH_8(what, x, ...)\
  what(x, 8),\
  BANG_NATIVE_FOR_EACH_7(what,  __VA_ARGS__)

#define BANG_NATIVE_FOR_EACH_NARG(...) BANG_NATIVE_FOR_EACH_NARG_(__VA_ARGS__, BANG_NATIVE_FOR_EACH_RSEQ_N())
#define BANG_NATIVE_FOR_EACH_NARG_(...) BANG_NATIVE_FOR_EACH_ARG_N(__VA_ARGS__) 
#define BANG_NATIVE_FOR_EACH_ARG_N(_1, _2, _3, _4, _5, _6, _7, _8, N, ...) N 
#define BANG_NATIVE_FOR_EACH_RSEQ_N() 8, 7, 6, 5, 4, 3, 2, 1, 0

#define BANG_NATIVE_FOR_EACH_(N, what, x, ...) BANG_NATIVE_CONCATENATE(BANG_NATIVE_FOR_EACH_, N)(what, x, __VA_ARGS__)
#define BANG_NATIVE_FOR_EACH(what, x, ...) BANG_NATIVE_FOR_EACH_(BANG_NATIVE_FOR_EACH_NARG(x, __VA_ARGS__), what, x, __VA_ARGS__)



#ifdef __BANG_NATIVE_CODE_GENERATOR__
#define BANG_NATIVE_ANNOTATE(elem, index) annotate(elem)
#define BANG_NATIVE_ANNOTATE_ELEMS(...) BANG_NATIVE_FOR_EACH(BANG_NATIVE_ANNOTATE, __VA_ARGS__)
#define BANG_NATIVE_ATTR_ANNOTATE(...) __attribute__((BANG_NATIVE_ANNOTATE_ELEMS(__VA_ARGS__)))

// 1. BANG_NATIVE Option --> BANG_NATIVE_BINDING
//    Attributes
#define BANG_NATIVE_BINDING_ELEM(elem, index) "bang_native_arg$$" ## #index ## "$$" ## #elem
#define BANG_NATIVE_BINDING_ELEMS(...) BANG_NATIVE_FOR_EACH(BANG_NATIVE_BINDING_ELEM, __VA_ARGS__)
#define BANG_NATIVE_BINDING(...) __declspec(dllimport) BANG_NATIVE_ATTR_ANNOTATE(BANG_NATIVE_BINDING_ELEMS(__VA_ARGS__))

// 2. BN_RET Return with calling convention
#define BN_RET(ret, callconv) __attribute__((callconv)) ret

#else
#define BANG_NATIVE_BINDING(...) __declspec(dllimport)
#define BN_RET(ret, callconv) ret __ ## callconv
#endif

enum class RegGen {
	EAX,
	ECX,
	EDX,
	EBX,
	ESI,
	EDI,

	AX,
	CX,
	DX,
	BX,
	SI,
	DI,

	AH,
	AL,
	CH,
	CL,
	DH,
	DL,
	BH,
	BL
};

#define BANG_NATIVE_ALLOC_OVERRIDE \
	__declspec(dllimport) static void* operator new(unsigned int size); \
	__declspec(dllimport) static void* operator new[](unsigned int size); \
	__declspec(dllimport) static void operator delete(void* ptr); \
	__declspec(dllimport) static void operator delete[](void* ptr); 



