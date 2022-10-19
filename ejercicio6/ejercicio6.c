#include "stdio.h"
#include "mpi.h"

int main()
{
	MPI_Status status;
  	int num, nejec, nproc, tag, next, from, a, b, c;
  	a = 1;
  	b = 1;
  	c = 0;

  	MPI_Init(NULL, NULL);
 	MPI_Comm_rank(MPI_COMM_WORLD, &nejec);
	MPI_Comm_size(MPI_COMM_WORLD, &nproc);
 
  	tag = 201;
	next = (nejec + 1) % nproc;
  	from = (nejec + nproc - 1) % nproc;

  	if (nejec == 0) {
		printf("Introduce el numero: ");
    		scanf("%d", &num);

    		MPI_Send(&c, 1, MPI_INT, next, tag, MPI_COMM_WORLD); //encia c al siguiente proceso inicio
  	}

  	do{    		//los procesos pasan el numero de vueltas y s calcula l siguiente fibonacci
		MPI_Recv(&c, 1, MPI_INT, from, tag, MPI_COMM_WORLD, &status);
    		printf("Proceso %d --> %d\n", nejec, c);

    		if(nejec == 0) {
      			num = num - 1;
      			a = b;
      			b = c;
      			c = a + b;
    		}

    		MPI_Send(&c, 1, MPI_INT, next, tag, MPI_COMM_WORLD); //en via c al siguiente proceso
  	} while(num > 0);
  
  	if (nejec == 0)
    		MPI_Recv(&c, 1, MPI_INT, from, tag, MPI_COMM_WORLD, &status);

  	MPI_Finalize;
  	return 0;
}

