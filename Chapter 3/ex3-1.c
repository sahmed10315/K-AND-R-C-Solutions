#include <stdio.h>

int binsearch(int x, int v[], int n);
int binsearch2(int x, int v[], int n);

main()
{
	int v [] = {13, 54, 55, 233, 563, 1432, 6542, 9432, 23453};

	printf("%d\n", binsearch2(233, v, 9));

}

int binsearch(int x, int v[], int n)
{
	
	int low = 0;
	int high = n - 1;
	int mid = 0;

	while(low <= high)
	{
		mid = (low + high) / 2;

		if(x < v[mid])
			high = mid -1;
		else if(x > v[mid])
			low = mid + 1;
		else 
			return mid;
	}

	return -1;

}
/* Not mine */
int binsearch2(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n-1;
  
  	while(low < high) 
	{
   		mid = (low+high)/2;
    
		if(x <= v[mid]) 
      			high=mid;
    	       else 
      			low = mid+1;
  	}
     
	return (x == v[low]) ? low : -1;
}
