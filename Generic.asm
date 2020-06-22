_TEXT SEGMENT


EQUAL_ANY	    = 0000b
RANGES		    = 0100b
EQUAL_EACH	    = 1000b
EQUAL_ORDERED	    = 1100b
NEGATIVE_POLARITY	= 010000b
BYTE_MASK			= 1000000b

appstreq PROC
;rcx str1
;rdx str2

 ; Using __fastcall convention, ecx = string1, edx = string2
  mov rax, rcx
  sub rax, rdx ; rax = rcx - rdx
  sub rdx, 16

STRCMP_LOOP:
    add rdx, 16
    MovDqU    xmm0, xmmword ptr[rdx]
    ; find the first *different* bytes, hence negative polarity
    PcmpIstrI xmm0, xmmword ptr[rdx + rax], EQUAL_EACH + NEGATIVE_POLARITY
    ja STRCMP_LOOP
	jc STRCMP_DIFF

	; the strings are equal
	mov rax, 1
	ret
	;They're not
	STRCMP_DIFF:
	xor rax, rax
	ret
appstreq ENDP

appstrcmp PROC
;rcx str1
;rdx str2
mov rax, rcx
sub rax, rdx ; rax = rcx - rdx
sub rdx, 16	;Align?

STRCMP_LOOP:
    add rdx, 16
    MovDqU    xmm0, xmmword ptr[rdx]
    ; find the first *different* bytes, hence negative polarity
    PcmpIstrI xmm0, xmmword ptr[rdx + rax], EQUAL_EACH + NEGATIVE_POLARITY
    ja STRCMP_LOOP
	;else
	jc STRCMP_DIFF

; the strings are equal
xor rax, rax
ret
STRCMP_DIFF:
; subtract the first different bytes
add rax, rdx
movzx rax, byte ptr[rax + rcx]
movzx rdx, byte ptr[rdx + rcx]
sub rax, rdx
ret
appstrcmp ENDP

appstrlen PROC
 mov rax, -16
 mov rdx, rcx
 pxor xmm0, xmm0

STRLEN_LOOP:
    add rax, 16
    PcmpIstrI xmm0, xmmword ptr[rdx + rax], EQUAL_EACH
    jnz STRLEN_LOOP

  add rax, rcx
  ret
appstrlen ENDP

appstrstr PROC
; rcx = haystack, rdx = needle
  mov rbx, rcx	;Copy starting point
  push rsi
  push rdi
  MovDqU xmm2, xmmword ptr[rdx] ; load the first 16 bytes of needle
  Pxor xmm3, xmm3
  lea rax, [rcx - 16]

  ; find the first possible match of 16-byte fragment in haystack
STRSTR_MAIN_LOOP:
    add rax, 16
    PcmpIstrI xmm2, xmmword ptr[rax], EQUAL_ORDERED
    ja STRSTR_MAIN_LOOP

  jnc STRSTR_NOT_FOUND

  add rax, rcx ; save the possible match start
  mov rdi, rdx
  mov rsi, rax
  sub rdi, rsi
  sub rsi, 16

  ; compare the strings
@@:
    add rsi, 16
    MovDqU    xmm1, xmmword ptr[rsi + rdi]
    ; mask out invalid bytes in the haystack
    PcmpIstrM xmm3, xmm1, EQUAL_EACH + NEGATIVE_POLARITY + BYTE_MASK
    MovDqU xmm4, xmmword ptr[rsi]
    PAnd xmm4, xmm0
    PcmpIstrI xmm1, xmm4, EQUAL_EACH + NEGATIVE_POLARITY
    ja @B

  jnc STRSTR_FOUND

  ; continue searching from the next byte
  sub rax, 15
  jmp STRSTR_MAIN_LOOP

STRSTR_NOT_FOUND:
  mov rax, 0FFFFFFFFFFFFFFFFh

STRSTR_FOUND:
  sub rax, rbx
  pop rdi
  pop rsi
  ret

appstrstr ENDP


_TEXT ENDS

_DATA SEGMENT
_DATA ENDS

END