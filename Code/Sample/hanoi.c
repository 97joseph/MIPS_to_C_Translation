/************************************************/
/*  hanoi.c, Version 1.0, 18 Sep 1992  --- AAA  */
/*           Version 1.1, 06 Jul 1993  --- AAA  */
/*           Added print out for all disks      */
/*           Version 1.2, 28 May 1994  --- AAA  */
/*           Calculate average Moves/25usec     */
/*           Version 1.2, 27 Oct 1994  --- AAA  */
/*           Only avg for RunTime > 0.1 sec     */
/************************************************/

/**************************************************/
/* Adapted from the MUSBUS test suite.            */
/* hanoi.c, V3.5 87/08/06 08:11:14 kenj           */
/*                                                */
/* Various timer routines are included. Please    */
/* select the appropriate timer routine for your  */
/* system from the options below. If no option is */
/* available then you will need to create your    */
/* own similar 'dtime()' timer routine.           */
/*                                                */
/* You can uncomment one of the timer options     */
/* below to use it, or you can compile with the   */
/* option name. For example you can compile with  */
/* '-DUNIX', or '-DVMS', '-DMSC',..., etc.        */
/*                                                */
/* Example compilation:                           */
/*  cc -DUNIX hanoi.c -o hanoi, or                */
/* gcc -DUNIX -O hanoi.c -o hanoi, or             */
/*  cc -dAmiga hanoi.c -o hanoi, ..., etc         */
/**************************************************/

/* #include <stdio.h> */

/***************************************************************/
/* Timer options. You MUST uncomment one of the options below  */
/* or compile, for example, with the '-DUNIX' option.          */
/***************************************************************/
/* #define Amiga       */
/* #define UNIX        */
/* #define UNIX_Old    */
/* #define VMS         */
/* #define BORLAND_C   */
/* #define MSC         */
/* #define MAC         */
/* #define IPSC        */
/* #define FORTRAN_SEC */
/* #define GTODay      */
/* #define CTimer      */
/* #define UXPM        */
/* #define MAC_TMgr    */
/* #define PARIX       */
/* #define POSIX       */

#define other(i,j) (6-(i+j))

int num[4];
long count;

void _start()
{
	
	register disk, Loops = 0;
       
	disk    = 1;
 
      	while ( 1 )
        { 
	 disk++;
	 num[0] = 0;
	 num[1] = disk;
	 num[2] = 0;
	 num[3] = 0;
	 count  = 0;

	 
	 mov(disk,1,3);
	 
	 Loops = Loops + 1;
	 	 
	 if ( disk == 10 ) break;
	 } 
	
}

mov(n,f,t)
{
   register o;
   if(n == 1) 
   {
	num[f]--;
	num[t]++;
	count++;
	return;
   }
   o = other(f,t);
   mov(n-1,f,o);
   mov(1,f,t);
   mov(n-1,o,t);
   return;
}

