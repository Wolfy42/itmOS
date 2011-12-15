
;***************************************************************
;* this is an arm-function
;***************************************************************

    .armfunc _c_int00
    .global  _c_int00

;***************************************************************
;* TI includes
;***************************************************************

    .asg    __args_main,   ARGS_MAIN_RTN
    .global ARGS_MAIN_RTN
    .global __TI_auto_init

;***************************************************************
;* Included addresses from the linker
;***************************************************************

    .global systemStack

;***************************************************************
;* CONSTANTS USED BY THIS MODULE
;***************************************************************

c_r13_system    .long    systemStack

;***************************************************************
;* FUNCTION DEF: _c_int00
;***************************************************************

_c_int00: .asmfunc

    ; SET System-Stack / User-Stack
    CPS   0x1F
    LDR   sp, c_r13_system

    ; Back to User-Mode
    CPS   0x10

    ; Perform all the required initilizations:
    ;  - Process BINIT Table
    ;  - Perform C auto initialization
    ;  - Call global constructors)
    BL    __TI_auto_init

    ; CALL APPLICATION
    BL    ARGS_MAIN_RTN

.end
