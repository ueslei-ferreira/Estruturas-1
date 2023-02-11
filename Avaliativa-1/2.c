#include <stdio.h>
void fatoraPotencia(int numero, int *base, int *expoente){
	int resto=0,cont=0,controle=0;
	while(controle==0){
		resto=*base%2;
		if(resto==0){
			cont++;
			*base=*base/2;
		}
		else{
			controle=1;   	
		}	
	}
	if(*base==1){
		*base=2;
	}
	if(*base^(*expoente*cont)==numero){
		printf("simplificado: %d ^(%d * %d)",*base,*expoente,cont);
	}	
}
int main(){
	int b,e,n;
	printf("digite o numero\n");
	scanf("%i",&n);
	printf("base-expoente\n");
	scanf("%i",&b);
	scanf("%i",&e);
	fatoraPotencia(n,&b,&e);
	return 0;
}
