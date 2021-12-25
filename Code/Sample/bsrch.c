
#define MAXSIZE 2000
#include "array"

_start()
{
	int  new, i,j, n, fd;
        int key, max,first,last,mid,pos,found;
	
        j=100; n=100;
        max = j - 1;
        key = a[max];

        found = 0;
        first = 0;
        last = max - 1;
        while ( first <= last )
	  {
             mid = (int)((first + last)>>1);
             if ( key == a[mid] )
	       {
                  found = 1;
                  pos = mid;
                  first = last + 1;
	       }
             else if ( key < a[mid] )
	       {
                  last = mid - 1;
	       }
             else 
	       {
                  first = mid + 1;
	       }
	  }

}
               
