////////////////////////////////////////////////////////
// Linker command file for BeagleBoard
// 
// Configuration of the BOSS-Project
//

-stack           0x00002000
-heap            0x00002000

MEMORY
{
   
   int_ram:  ORIGIN = 0x40200000  LENGTH = 0x0000FFC4
   int_vecs: ORIGIN = 0x4020FFC4  LENGTH = 0x00000020
   
   ext_ddr:  ORIGIN = 0x82000000  LENGTH = 0x00010000
   
}

SECTIONS
{
   .intvecs    > int_vecs
		
   .const      > int_ram
   .bss        > int_ram
   .far        > int_ram
   
   .stack      > int_ram
   .data       > int_ram
   .cinit      > int_ram
   .cio        > int_ram
   
   .text       > int_ram
   .sysmem     > int_ram
   .switch     > int_ram
   .pinit      > int_ram  {
   	   *(.pinit)
       kernelMasterTable = . ;
   }
}
