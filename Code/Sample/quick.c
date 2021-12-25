/*#include <stdio.h>
  #include <fcntl.h> */

#include "array"

swap(a, i, j)
	int a[], i, j;
{
	int tmp;
	tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

int
partition(a,l,r)
	int a[], l, r;
{
	int x, i, t;
	swap(a,l,(l+r)>>1);
	t=l;
	for(i=l+1;i<=r;i++)
		if(a[i] < a[l]) swap(a, ++t, i);
	swap(a, l, t);
	return(t);
}

quicksort(a, l, r)
	int a[], l, r;
{
	int t;

	if(l < r) {
		t = partition(a,l,r);
		quicksort(a, l, t-1);
		quicksort(a, t+1, r);
	}
}


_start()
{
       quicksort(a, 0, 99); 
}
