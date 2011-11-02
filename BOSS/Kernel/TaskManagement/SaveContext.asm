		.global _save_reg
		.bss _reg_state, 4, 4
		.bss temp, 4, 4
		.global _reg_state
_save_reg:
;		LDR r1, var
;		STR r3, [r1, #0]
;		STR r4, [r1, #4]
		
		;LDR R0, temp
		
		push {r3}
		pop {r0}
		LDR r1, var
		STR r3, [r1, #0]
		STR r4, [r1, #4]		
		
		
		MOV pc, lr
var	.field _reg_state, 32

