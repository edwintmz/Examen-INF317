#include "omp.h"
#include "stdio.h"
#include "string.h"

#define TAM 40
         
char palin[TAM];
int m, i = 0, f;
         
int main(){
    	printf("\nIngrese una palabra: ");
    	scanf("%s",palin);
    	m=strlen(palin);
    	
	#pragma omp parallel
	{
		int nh = omp_get_thread_num();
            	if(nh != 0){
            		printf("\nHilo %d : ", nh);
          	}
            	
		for(f = m - 1 ; f >= 0 ; f--)
		#pragma omp if private
		{
			if(palin[f] == palin[i])
				i++;
		}
		
		#pragma omp if private
		{
			if(nh == 0){
				if(i == m){
					printf("\nHilo %d : ", nh);
					printf("Verdadero");
				}else{
					printf("\nHilo %d : ", nh);
					printf ("Falso");
				}
			}
		}
	}
	printf("\n");
	return 0;
}
