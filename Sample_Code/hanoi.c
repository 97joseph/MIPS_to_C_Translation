/************************************************/
/*                                                */
/* Example compilation:                           */
/*  cc -DUNIX hanoi.c -o hanoi, or                */
/* gcc -DUNIX -O hanoi.c -o hanoi, or             */
/*  cc -dAmiga hanoi.c -o hanoi, ..., etc         */
/*************************************************/

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

