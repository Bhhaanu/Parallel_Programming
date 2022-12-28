
// quickSort.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>

void interchange(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partitioning(int a[], int l, int h) {
  int pivot = a[h];
  int i = (l - 1);
  int j;
  for (j = l; j < h; j++) {
    if (a[j] <= pivot) {
      i++;
      interchange(&a[i], &a[j]);
    }
  }
  interchange(&a[i + 1], &a[h]);
  return (i + 1);
}

void quickSort(int a[], int l, int h) {
  if (l< h) {
    int pi = partitioning(a, l, h);
    quickSort(a, l, pi - 1);
    quickSort(a, pi + 1, h);
  }
}

int *generateRandomNumbers(int *randArray, int size){

   int sz = size;
   int i;
   for(i=0;i<sz;i++)
     randArray[i]=rand()%100000;     //Generate number between 0 to 999

	return randArray;	
}

int *ele_list(int *n, int size){

   int i;
    for(i=0;i<size;++i)  
        printf("%d ",n[i]);
    printf("\n");
    return n;	
}

int largestPrime(int* n, int size)
{
int i,j,count=0;
int ele=n[size-1];
for (i=ele;size>0;size--){
	count = 0;
	int k;
	j=n[size-1];
	for(k=1;k<=j;k++){
		if(j%k==0){
			count++;
			if(count>2)
				break;
		}
	}	
	if(count==2)
	    return j;
	}
return 0; 
} 

void main()
{
	
    time_t t1;
    
	int sz,prime ;
    printf("Enter the size of array::");
    scanf("%d",&sz);
	int *n;	
	int randArray[sz];	
	srand (time (&t1));
	double start = clock();
	n=generateRandomNumbers(randArray,sz);
	
	printf("Elements before sorting:\n");
    n=ele_list(n,sz);
quickSort(n, 0, sz-1);

printf("Elements after sorting:\n");
n=ele_list(n,sz);
prime=largestPrime(n,sz);

if(prime)
printf("Largest prime is: %d\n",prime);
else 
printf("No prime in the random list\n");
double end = clock();
printf("The running time is: %f\n",(double)(end-start)/CLOCKS_PER_SEC);
}




