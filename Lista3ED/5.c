#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *repete(char *s, int n){
	char *nova;
	nova = (char*)malloc((n)*sizeof(char));
	for(int i=0;i<n;i++){
		strcat(nova,s);
		if(i!=n-1){
			strcat(nova," ");
		}
	}
	return nova;
}
int main(){
	int tamanho;
	printf("digite a quantidade de repeticoes: ");
	scanf("%d",&tamanho);
	
	printf("agora digite a o texto que deseja repetir");
	char texto[20];
	scanf("%s",texto);
	
	char *sr;
	sr = repete(texto, tamanho);
	printf("%s'", sr);
	free(sr);
	return 0;
}