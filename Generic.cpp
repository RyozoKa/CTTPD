#include "Main.h"

//#ifdef _WIN32
#define NAKED __declspec(naked)


#define EQUAL_ANY = 0000b
#define RANGES = 0100b
#define EQUAL_EACH = 1000b
#define EQUAL_ORDERED = 1100b
#define NEGATIVE_POLARITY = 010000b
#define BYTE_MASK = 1000000b
/*
NAKED bool appstreq(const char*, const char*)
{
	__asm
	{
		mov rax, rcx
		sub rax, rdx
		sub rdx, 16
		STRCMP_LOOP:
		add rdx, 16
		MovDqU    xmm0, xmmword ptr[rdx]
		PcmpIstrI xmm0, xmmword ptr[rdx + rax], 11000b
		ja STRCMP_LOOP
		jc STRCMP_DIFF
		mov rax, 1
		ret
		STRCMP_DIFF:
		xor rax, rax
		ret
	}
}

NAKED int appstrcmp(const char*, const char*)
{
	__asm
	{
		mov rax, rcx
		sub rax, rdx
		sub rdx, 16
		STRCMP_LOOP:
		add rdx, 16
		MovDqU    xmm0, xmmword ptr[rdx]
		PcmpIstrI xmm0, xmmword ptr[rdx + rax], 11000b
		ja STRCMP_LOOP
		jc STRCMP_DIFF
		xor rax, rax
		ret
		STRCMP_DIFF:
		add rax, rdx
		movzx rax, byte ptr[rax + rcx]
		movzx rdx, byte ptr[rdx + rcx]
		sub rax, rdx
		ret
	}
}

NAKED int appstrlen(const char*)
{
	__asm
	{
		mov rax, -16
		mov rdx, rcx
		pxor xmm0, xmm0
		STRLEN_LOOP :
		add rax, 16
		PcmpIstrI xmm0, xmmword ptr[rdx + rax], 1000b
		jnz STRLEN_LOOP
		add rax, rcx
		ret
	}
}

NAKED unsigned __int64 appstrstr(const char* str1, const char* str2)
{
	__asm
	{
		mov rbx, rcx; Copy starting point
		push rsi
		push rdi
		MovDqU xmm2, xmmword ptr[rdx]; load the first 16 bytes of needle
		Pxor xmm3, xmm3
		lea rax, [rcx - 16]
		STRSTR_MAIN_LOOP :
		add rax, 16
		PcmpIstrI xmm2, xmmword ptr[rax], 1100b
		ja STRSTR_MAIN_LOOP
		jnc STRSTR_NOT_FOUND
		add rax, rcx; save the possible match start
		mov rdi, rdx
		mov rsi, rax
		sub rdi, rsi
		sub rsi, 16
		AA:
		add rsi, 16
		MovDqU    xmm1, xmmword ptr[rsi + rdi]
		PcmpIstrM xmm3, xmm1, 1011000b
		MovDqU xmm4, xmmword ptr[rsi]
		PAnd xmm4, xmm0
		PcmpIstrI xmm1, xmm4, 11000b
		ja AA
		jnc STRSTR_FOUND
		sub rax, 15
		jmp STRSTR_MAIN_LOOP
		STRSTR_NOT_FOUND :
		mov rax, 0FFFFFFFFFFFFFFFFh
		STRSTR_FOUND :
		sub rax, rbx
		pop rdi
		pop rsi
		ret
	}
}
*/
//#endif