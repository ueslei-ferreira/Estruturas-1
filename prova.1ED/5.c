#include <stdio.h>
void verifica_f(char *frase){
	char tirar[20], tirar2[20];
	for(int i=0;*frase!='\0';i++){
		tirar[i]=*frase;
		frase++;
	}
	int cont=0, cont2=0;
	tirar2[0]=tirar[0];
	for(int i=0;tirar[i]!='\0';i++){
		for(int j=0;tirar2[j]!='\0';j++){
			if(tirar2[j]==tirar[i]){
				cont++;
			}
		}
		if(cont==0||i==0||cont2==0){
			tirar2[cont2]=tirar[i];
			cont2++;
		}
		cont=0;
	}
	for(int i=0;tirar2[i]!='\0';i++){
		for(int j=0;tirar[j]!='\0';j++){
			if(tirar2[i]==tirar[j]){
				cont++;
			}
		}
		printf("'%c' = %d\n",tirar2[i],cont);
		cont=0;
	}
}
int main(){
	char frase[20];
	printf("frase: ");
	scanf("%[^\n]s",frase);
	verifica_f(frase);
	return 0;
}