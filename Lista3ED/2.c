#include <stdio.h>
#include <stdlib.h>
int *impar(int tamanho){ //funcao de alocacao
	int *v;
	v = (int*)malloc(tamanho*sizeof(int));
	for(int i=0;i<tamanho;i++){ //preenche o vetor alocado dinamicamente
		v[i]=i+1;
	}
	return (v); // retorna o vetor
}
int main(){
	printf("digite um valor impar\n");
	int valor;
	scanf("%d",&valor);
	while(valor%2==0){ //obriga a ler um numero impar
		printf("valor digitado nao era impar, tente novamente\n");
		scanf("%d",&valor);
	}
	int *vet;
	vet = impar(valor); //o ponteiro recebe o vetor alocado pela funcao
	
	int meio=(valor-1)/2; //variavel que recebe a posicao central
	int esquerda=meio-1, direita=meio+1, cont=0; // a variavel esquerda percorre o vetor para a esquerda e a variavel direita percorre para a direita
	
	while(esquerda>=0&&direita<=valor){ //enquanto a esquerda nao chegar a posicao minima, e a direita nao chegar na posicao maxima
		if(cont==0){ //verifica se é a primeira impressao, se for, imprime o numero central
			printf(" %d\n",vet[meio]);
			cont++;
		}else{ // se nao for o central, imprime a esquerda e direita do vetor
			printf("%d %d\n", vet[esquerda], vet[direita]);
			esquerda-=1; //decrementa a posicao a ser impressa na proxima vez
			direita+=1; //incrementa a posicao a ser impressa na proxima vez
		}
	}
	free(vet); //libera a memoria
	return 0;
}