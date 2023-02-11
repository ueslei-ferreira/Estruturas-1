#include <stdio.h>
#include <string.h>
void mudarVogais(char *frase) {
	int i, tam;
 
	tam = strlen(frase);
	for (i=0; i < tam; i++) {
		if(*frase == 'a'){
			*frase = 'u';
		}else if(*frase == 'e'){
			*frase = 'o';
		}
		else if(*frase == 'i'){
			*frase = 'u';
		}
		else if(*frase == 'o'){
			*frase = 'a';
		}
		else if(*frase == 'u'){
			*frase = 'e';
		}
		frase++;
	}
}
int main(){
	char frase[100];
	printf("Entre com uma frase: ");
	gets(frase);
	
	mudarVogais(frase);
	printf("%s",frase);
}