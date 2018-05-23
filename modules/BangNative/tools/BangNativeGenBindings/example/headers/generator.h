#pragma once

// Macro Utils
// Found from http://stackoverflow.com/a/1872506/5082374
#define BANG_NATIVE_STRINGIZE(arg)  BANG_NATIVE_STRINGIZE1(arg)
#define BANG_NATIVE_STRINGIZE1(arg) BANG_NATIVE_STRINGIZE2(arg)
#define BANG_NATIVE_STRINGIZE2(arg) #arg

#define BANG_NATIVE_CONCATENATE(arg1, arg2)   BANG_NATIVE_CONCATENATE1(arg1, arg2)
#define BANG_NATIVE_CONCATENATE1(arg1, arg2)  BANG_NATIVE_CONCATENATE2(arg1, arg2)
#define BANG_NATIVE_CONCATENATE2(arg1, arg2)  arg1##arg2

#define BANG_NATIVE_FOR_EACH_1(what, x, ...) what(x)
#define BANG_NATIVE_FOR_EACH_2(what, x, ...)\
  what(x),\
  BANG_NATIVE_FOR_EACH_1(what,  __VA_ARGS__)
#define BANG_NATIVE_FOR_EACH_3(what, x, ...)\
  what(x),\
  BANG_NATIVE_FOR_EACH_2(what,  __VA_ARGS__)
#define BANG_NATIVE_FOR_EACH_4(what, x, ...)\
  what(x),\
  BANG_NATIVE_FOR_EACH_3(what,  __VA_ARGS__)
#define BANG_NATIVE_FOR_EACH_5(what, x, ...)\
  what(x),\
  BANG_NATIVE_FOR_EACH_4(what,  __VA_ARGS__)
#define BANG_NATIVE_FOR_EACH_6(what, x, ...)\
  what(x),\
  BANG_NATIVE_FOR_EACH_5(what,  __VA_ARGS__)
#define BANG_NATIVE_FOR_EACH_7(what, x, ...)\
  what(x),\
  BANG_NATIVE_FOR_EACH_6(what,  __VA_ARGS__)
#define BANG_NATIVE_FOR_EACH_8(what, x, ...)\
  what(x),\
  BANG_NATIVE_FOR_EACH_7(what,  __VA_ARGS__)

#define BANG_NATIVE_FOR_EACH_NARG(...) BANG_NATIVE_FOR_EACH_NARG_(__VA_ARGS__, BANG_NATIVE_FOR_EACH_RSEQ_N())
#define BANG_NATIVE_FOR_EACH_NARG_(...) BANG_NATIVE_FOR_EACH_ARG_N(__VA_ARGS__) 
#define BANG_NATIVE_FOR_EACH_ARG_N(_1, _2, _3, _4, _5, _6, _7, _8, N, ...) N 
#define BANG_NATIVE_FOR_EACH_RSEQ_N() 8, 7, 6, 5, 4, 3, 2, 1, 0

#define BANG_NATIVE_FOR_EACH_(N, what, x, ...) BANG_NATIVE_CONCATENATE(BANG_NATIVE_FOR_EACH_, N)(what, x, __VA_ARGS__)
#define BANG_NATIVE_FOR_EACH(what, x, ...) BANG_NATIVE_FOR_EACH_(BANG_NATIVE_FOR_EACH_NARG(x, __VA_ARGS__), what, x, __VA_ARGS__)



#ifdef __BANG_NATIVE_CODE_GENERATOR__
#define BANG_NATIVE_ANNOTATE(elem) annotate(elem)
#define BANG_NATIVE_ANNOTATE_ELEMS(...) BANG_NATIVE_FOR_EACH(BANG_NATIVE_ANNOTATE, __VA_ARGS__)
#define BANG_NATIVE_ATTR_ANNOTATE(...) __attribute__((BANG_NATIVE_ANNOTATE_ELEMS(__VA_ARGS__)))

// 1. BANG_NATIVE Option --> BANG_NATIVE_BINDING
//    Attributes
#define BANG_NATIVE_BINDING_ELEM(elem) "bang_native_arg$$" ## #elem
#define BANG_NATIVE_BINDING_ELEMS(...) BANG_NATIVE_FOR_EACH(BANG_NATIVE_BINDING_ELEM, __VA_ARGS__)
#define BANG_NATIVE_BINDING(...) BANG_NATIVE_ATTR_ANNOTATE(BANG_NATIVE_BINDING_ELEMS(__VA_ARGS__))

#else
#define BANG_NATIVE_BINDING(...)
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





