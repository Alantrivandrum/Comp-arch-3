add r0, #4, r9  ; global parameter inp_int=4

max:                        ; int max(int a, int b, int c)

    add r0, r26, r1         ; r1=a=v
    sub r27, r1, r0, {C}    ; if(b>v) {
    jle continue            ;
    xor r0, r0, r0          ; nop
    add r0, r27, r1         ; v=b

continue:
    sub r28, r1, r0, {C}    ; if(c>v)
    jle minEnd              ;
    xor r0, r0, r0          ;
    add r0, r28, r1         ; v = c

maxEnd:
    ret r31, 0
    xor r0, r0, r0

max5:                          ; int max5(int i, int j, int k, int l)

    add r0, r9, r10         ; g as param 1 for inner min
    add r0, r26, r11        ; i = param2
    add r0, r27, r12        ; j = param3
    callr r15, max          ; max(g, i, j) 
    xor r0, r0, r0

    add r0, r1, r10         ; max(inp_int, i, j) = param1
    add r0, r28, r11        ; k = param2
    add r0, r29, r12        ; l = param3
    callr r15, max          ; max((inp_int, i, j), k, l) 
    xor r0, r0, r0

    ret r31, 0 
    xor r0, r0, r0




fun:
    sub r27, r0, r0, {C}  ; if (b == 0)
    jne fun2
    xor r0, r0, r0
    ret r31, 0
    xor r0, r0, r0

fun2:
    add r27, r0, r10      ; b as parameter for modulus function
    add 2, r0, r11       ; 2 as parameter for modulus function
    callr r15, modulus
    xor r0, r0, r0
    sub r1, r0, r0, {C}  ; if (b % 2 = 0)
    jne fun3
    add r27, r0, r10      ; b as parameter for modulus function
    add #2, r0, r11        ; 2 as parameter for modulus function
    callr r15, divide
    xor r0, r0, r0
    add r26, r26, r10	  ; new a = a+a
    add r1, r0, r11	  ; r1 = new b = b/2
    callr r15, fun        ; call fun(a + a, b/2)
    xor r0, r0, r0
    ret	r31, 0	          ; ret r31
    xor r0, r0, r0
    
	

fun3:
    add r27, r0, r10      ; b as parameter for modulus function
    add #2, r0, r11        ; 2 as parameter for modulus function
    callr r15, divide
    xor r0, r0, r0
    add r26, r26, r10	  ; new a = a+a
    add r1, r0, r11	  ; new b = b/2
    callr r15, fun        ; call fun(a + a, b/2)
    xor r0, r0, r0
    add	r1, r26, r31	  ; r31 = call fun(a + a, b/2) + a
    ret	r31, 0		  ; ret r31
    xor	r0, r0, r0


   



