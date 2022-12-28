# parallel_programming

Finding the largest prime using Quick Sort with parallel programming.
Description:
This project is about implementing a sequential and two parallel programs to find the largest prime number in each set of data using sorting techniques. Although we have the sorting technique implemented programs in different languages, our goal is to combine those with prime number check and use them for parallel programming such that these larger tasks can be carried out simultaneously.
Initially a list of elements is provided which are unsorted. Using our algorithm, the list of sorted elements is processed to find the largest prime from the list.
For sorting: Here, we are going to use quick sort which works on divide and conquer technique by selecting a 'pivot' element from the array and partitioning the other elements into two sub-arrays, according to whether they are less than or greater than the pivot.
Using sorting that is explained above to find the largest prime in the data will be the final task of this project using prime number check logic.
Tasks:
1. Writing a working sequential program for the problem statement and note the execution time for it.
2. Using the sequential program, implementing the parallel programs using parallel programming frameworks i.e., MPI and openmp.
3. Compare and analyze the performances of all the three programs.
