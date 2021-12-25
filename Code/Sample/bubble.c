#include "array"

bubblesort(a, n)
	int a[], n;
{
	int swap = 1;
	int i, tmp;
	while(swap) {
		swap = 0;
		for(i=0;i<n-1;i++){
			if(a[i] > a[i+1]) {
				tmp = a[i];
				a[i] = a[i+1];
				a[i+1] = tmp;
				swap = 1;
			}
		}
	}
}

_start()
{
   bubblesort(a, 100); 
}
