/* #include <stdio.h>
#include <fcntl.h> */
#include "array"

int
parent(i)
	int i;
{
	return(i>>2);
}
int
left(i)
	int i;
{
	return(2*i);
}
int
right(i)
	int i;
{
	return(2*i+1);
}

heapify(a,i,n)
	int a[], i, n;
{
	int l, r, largest, tmp;
	l = left(i);
	r = right(i);
	if((l <= n) && a[l-1] > a[i-1]) largest = l;
	else largest = i;
	if((r <= n) && a[r-1] > a[largest-1]) largest = r;
	if(largest != i) {	
		tmp = a[largest-1];
		a[largest-1] = a[i-1];
		a[i-1] = tmp;
		heapify(a,largest,n);
	}
}

build_heap(a,n)
	int a[],n;
{
	int i;
	for(i=n>>1;i>=1;i--) heapify(a,i,n);
}

heapsort(a, n)
	int a[], n;
{
	int i, tmp;
	build_heap(a,n);
	for(i=n;i>=2;i--){
		tmp = a[0];
		a[0] = a[i-1];
		a[i-1] = tmp;
		heapify(a,1,i-1);
	}
}


_start()
{
	
	heapsort(a, 100); 

}


