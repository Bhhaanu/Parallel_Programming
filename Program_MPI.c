#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000000

#define BLOCK_LOW(id,p,n)  ((id)*(n)/(p))
#define BLOCK_HIGH(id,p,n) (BLOCK_LOW(((id)+1),p,n))
#define BLOCK_SIZE(id,p,n) ((BLOCK_LOW(((id)+1),p,n))-(BLOCK_LOW(id,p,n)))

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
   srand(time(NULL));
   int i;
   for(i=0;i<size;i++)
     randArray[i]=rand()%100000;     //Generate number between 0 to 999
	return randArray;	
}

int *ele_list(int *n,int low_value, int high_value, int size){

   int i;
    for(i=low_value;i<high_value;++i)  
        printf("%d ",n[i]);
    printf("\n");
    return n;	
}

int main(int argc, char *argv[]) {
  int id,p,global_n;
  int *n;
  int randArray[SIZE];
  double e_time;
  time_t t1;
  int c,prime;
  int low_value, high_value;

  MPI_Init(&argc, &argv);
  e_time=-MPI_Wtime();
  MPI_Comm_size(MPI_COMM_WORLD, &p);
  MPI_Comm_rank(MPI_COMM_WORLD, &id);
  
  n=generateRandomNumbers(randArray,SIZE);
  low_value = BLOCK_LOW(id,p,SIZE);
  high_value = BLOCK_HIGH(id,p,SIZE);
  c=SIZE/p; 

  if (SIZE%p) c++;
  srand(time(&t1));
  
  printf("Elements before sorted:\n");
  n=ele_list(n,low_value,high_value,c);
  quickSort(n, low_value, high_value);
  printf("Elements after sorting:\n");
  n=ele_list(n,low_value,high_value,c);
  //MPI_Send(&n, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
  prime=largestPrime(n,c);
  MPI_Reduce (&prime, &global_n, 1, MPI_INT, MPI_MAX,0, MPI_COMM_WORLD);
  
  e_time+=MPI_Wtime();
  printf("process %d is done \n",id);
  
  if(id==0){
  
  printf("Number of processors: %d\n, time : %f\n",p,e_time);
  if(prime)
  printf("Largest prime is: %d",prime);
  else 
  printf("No prime in the random list");
  }  
  MPI_Finalize();
  return 0;
}

