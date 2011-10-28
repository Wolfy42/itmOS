	.if __TI_EABI_ASSEMBLER
		.asg c_intSWI, C_INTSWI
	.else
		.asg _c_intSWI, C_INTSWI
	.endif

	.global _c_int00
	.global C_INTSWI

	.sect ".intswi"

	B C_INTSWI ; software interrupt

