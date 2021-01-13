#include <stdlib.h>
#include <stdio.h>
#include <sched.h>

int main(){
	
	int planificacion = sched_getscheduler(0);
	//Imprimir planificacion
	switch(planificacion){
		case SCHED_OTHER:
			printf("SCHEDULER: OTHER\n");
		break;
		case SCHED_FIFO: 
			printf("SCHEDULER: FIFO\n");
		break;
		case SCHED_RR:
			printf("SCHEDULER: ROUND ROBIN\n");
		break;
	}
	//Imprimir prioridad
	struct sched_param param;
	sched_getparam(0,&param);
	printf("Prioridad proceso actual: %d\n",param.sched_priority);	
	//Para la planificacion, valores max-min
	int max = sched_get_priority_max(planificacion);
	int min = sched_get_priority_min(planificacion);

	printf("Prioridad maxima: %d\n",max);
	printf("Prioridad minima: %d\n",min);

	return 1;
}

