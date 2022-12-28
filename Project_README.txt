Project_Sequential.c :

1)	How to compile your program?
	gcc Project_Sequential.c  -o pro1

2)	How to run your program?
	./pro1


Progrm_MPI.c :

1)	How to compile your program?
	mpicc  Program_MPI.c  -o Prog2

2)	How to run your program?
	mpirun  -np 1 ./Prog2
	mpirun  -np 2 ./Prog2
	mpirun  -np 3 ./Prog2
	mpirun  -np 4 ./Prog2



Project_omp.c :

1)	How to compile your program?
	export OMP_NUM_THREADS=1
	gcc Project_omp.c -fopenmp -o pro3

2)	How to run your program?
	./pro3

