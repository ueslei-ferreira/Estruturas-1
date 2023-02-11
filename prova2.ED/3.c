#include <stdio.h>
#include <stdlib.h>
int *caracteres(char *frase, char letra, int *tamanho){
	int *vet;
	vet = (int*)malloc(sizeof(int)); //o vetor primeiramente eh alocado para uma posicao
	
	for(int i=0 ;frase[i] != '\0' ; i++){ //enquanto nao for o fim da frase
		 if(frase[i] == letra){ //compara a letra com cada caractere da frase
			 vet[*tamanho] = i; //o vetor recebe a posicao da letra encontrada na frase 
			 vet = (int*)realloc(vet, sizeof(int)); //realoca uma posicao a mais cada vez que eh econtrada uma letra na frase
			 *tamanho+=1; //soma 1 ao tamanho necessario
		 }
	}
	return vet; //retorna o vetor alocado
}
int main(){
	char *frase = (char*)malloc(100*sizeof(char)); //fiquei em duvida se colocava pra pedir quantos caracteres seriam lidos, mas ficaria estranho, entao coloquei o limite de 100
	char letra;
	int tamanho = 0;
	
	printf("digite a frase (limite de 100 caracteres): ");
	scanf(" %[^\n]s", frase);
	fflush(stdin); //limpa buffer do teclado
	
	printf("digite a letra a ser verificada: ");
	scanf("%c", &letra); //letra que sera compara a frase

	int *vet;
	vet = caracteres(frase, letra, &tamanho); //ponteiro que recebera o vetor alocado
	
	if(tamanho>0){
		printf("letra ' %c ' encontrada: %d vezes\n", letra, tamanho);
	}else{
		printf("letra nao encontrada na frase\n");
	}
	for(int i=0; i<tamanho; i++){
		printf("posicao[ %d ]\n", vet[i]); //imprime as posicoes com a letra procurada
	}
	free(frase);
	return 0;
}