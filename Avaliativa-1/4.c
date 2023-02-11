#include <stdio.h>
void minutosHoras(int totalMinutos, int *horas, int *minutos){
	*horas=totalMinutos/60;
	*minutos=totalMinutos%60;
}
int main(){
	printf("digite os minutos a serem convertidos\n");
	int minutos, h, m;
	scanf("%d",&minutos);
	minutosHoras(minutos,&h,&m);
	printf("%dhoras e %d minutos",h,m);
	return 0;
}