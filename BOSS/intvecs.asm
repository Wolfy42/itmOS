
	.asg _c_intSWI, C_INTSWI
	.asg _c_intIRQ, C_INTIRQ
	.asg _c_intPABT, C_INTPABT
	.asg _c_intDABT, C_INTDABT

	.global _c_int00
	.global C_INTSWI
	.global C_INTIRQ
	.global C_INTPABT
	.global C_INTDABT

	.sect ".intvecs"
	     B _c_int00    ; Reset Interrupt
	     .word 0       ; Undefined Instructions Interrupt
	     B C_INTSWI    ; Software Interrupt
	     B C_INTPABT   ; Prefetch Abort Interrupt
	     B C_INTDABT   ; Data Abort Interrupt
	     .word 0       ; Unused
	     B C_INTIRQ,   ; IRQ Interrupt
	     .word 0       ; FIQ Interrupt
