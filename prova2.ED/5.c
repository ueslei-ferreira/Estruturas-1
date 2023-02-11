#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void ler_aposta(int *aposta, int tamanho){
	int i;
	for( i=0;i<tamanho;i++){
		printf("valor %d\n", i+1);
		scanf("%d",&aposta[i]);
		while(aposta[i]<=0 && aposta[i]>100){ //verifica se o tamanho eh valido
			printf("valor invalido (1 - 100), digite novamente\n");
			scanf("%d",&aposta[i]);
		}
	}
}
void sorteia_valores(int *sorteio, int tamanho){ //funcao que preenche o vetor de sorteio
	for(int i=0;i<tamanho;i++){
		sorteio[i] = 1+rand() %100; //numeros aleatorios
	}
}

int *compara_aposta(int *aposta, int *sorteio,int *qtd_acertos, int na, int ns){
	int *acertos;
	acertos = (int*)malloc(sizeof(int)); //aloca o vetor que recebe os numeros acertados, com uma posicao 
	
	for(int i=0;i<ns;i++){
		for(int j=0;j<na;j++){
			if(aposta[j] == sorteio[i]){ //verifica se cada numero no cartao de aposta se encontra no sorteio
				acertos[*qtd_acertos] = aposta[j]; //armazena no vetor de retorno o numero acertado 
				*qtd_acertos+=1; //a quantidade de acertos eh aumentada em 1
				acertos = (int*)realloc(acertos,sizeof(int)); //realoca uma posicao do vetor de retorno
			}
		}
	}
	return acertos;
}
int main(){
	srand(time(NULL));
	printf("Bingo de ED I\ndigite a quantidade de numeros que deseja apostar (entre 1 e 20)");
	int tamanho, tamanhoS = 20, acertos=0; //"tamanhoS" eh o tamanho estatico do vetor de sorteio, "acertos" eh a variavel que recebe o ponteiro da funcao compara_aposta
	
	scanf("%d", &tamanho);
	while(tamanho<=0 && tamanho>20){ //obriga a inserir um valor entre 1 e 20
		printf("tamanho invalido\n");
		scanf("%d", &tamanho);
	}
	
	int *aposta, *sorteio;
	aposta = (int*)malloc(tamanho * sizeof(int)); //aloca o vetor que recebe os numeros inseridos pelo apostador
	sorteio = (int*)malloc(tamanhoS * sizeof(int));
	
	sorteia_valores(sorteio, tamanhoS); //preenche o vetor gabarito
	ler_aposta(aposta, tamanho); //insere os numeros aleatorios
	
	for(int i=0;i<tamanhoS;i++){
		printf(" %d ",sorteio[i]);
	}
	
	int *vet = compara_aposta(aposta, sorteio, &acertos, tamanho, tamanhoS); //o vetor 'vet' recebe o vetor alocado dinamicamente 
	printf("quantidade de acertos: %d\n", acertos);
	if(acertos>0){
		printf("numeros acertados: ");
		for(int i=0;i<acertos;i++){
			printf(" %d ", vet[i]);
		}
	}
	free(vet);
	free(aposta);
	free(sorteio);
	return 0;
}