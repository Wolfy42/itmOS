////////////////////////////////////////////////////////
// Linker command file for BeagleBoard
// 
// Configuration of a Task for the BOSS-Kernel
//

-stack           0x00002000
-heap            0x00002000

MEMORY
{
   v_memory:     ORIGIN 0x00001000 LENGTH = 0x01000000
   stack_memory: ORIGIN 0x10000000 LENGTH = 0x00002000
}

SECTIONS
{
   ORDER
   .text	   > v_memory
   .bss        > v_memory
   .const      > v_memory
   .cinit      > v_memory
   .pinit      > v_memory
   .cio        > v_memory
   .switch     > v_memory
   .far        > v_memory
   .data       > v_memory
   .switch     > v_memory
   .sysmem     > v_memory
   
   .stack      > stack_memory
}
