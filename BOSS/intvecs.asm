	.if __TI_EABI_ASSEMBLER
		.asg c_intSWI, C_INTSWI
		.asg c_intIRQ, C_INTIRQ
	.else
		.asg _c_intSWI, C_INTSWI
		.asg _c_intIRQ, C_INTIRQ
	.endif

	.global _c_int00
	.global C_INTSWI
	.global C_INTIRQ

	.sect ".intswi"
	B C_INTSWI ; software interrupt
	.sect ".intirq"
	B C_INTIRQ ; IRQ
