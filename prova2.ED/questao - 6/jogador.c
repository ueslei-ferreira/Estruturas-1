#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogador.h"

void inicializa(Jogador **jogadores, int tamanho){
	int i;
	for(i=0;i<tamanho;i++){
		jogadores[i]=NULL; //inicializa todas as posicoes com NULL
	}
}

void atribui(Jogador **jogadores, int tamanho, int indice){
	
	if(jogadores[indice]==NULL){ //se a posicao estiver vazia, pede a insercao dos dados dos jogadores
		jogadores[indice] = (Jogador*)malloc(sizeof(Jogador)); //aloca cada posicao de uma nova estrutura no ponteiro para ponteiros
		printf("digite o nome: ");
		
		scanf("%s", jogadores[indice]->nome);
		
		printf("digite a quantidade de jogos: ");
		scanf("%d", &jogadores[indice]->jogos);

		printf("digite a quantidade de gols: ");
		scanf("%d", &jogadores[indice]->gols);

		printf("Digite a quantidade de assistencias: ");
		scanf("%d", &jogadores[indice]->assistencias);


		printf("\n");
	}
}

void imprime(Jogador **jogadores, int tamanho){
	int i;
		
	for(i=0;i<tamanho;i++){ //imprime todos os jogadores cadastrados
		
		printf("Jogador %s \n", jogadores[i]->nome);
		printf("numero de jogos: %d\n", jogadores[i]->jogos);
		printf("numero de gols: %d\n", jogadores[i]->gols);
		printf("numero de assistencias: %d\n", jogadores[i]->assistencias);
		printf("\n");	
		
	}
}

void soma(int tamanho, Jogador **jogadores){
	int i;
	int gols=0, assistencias=0, jogos=0; //variaveis usadas nas somas das estatisticas dos dois jogadores
	char jogador1[30], jogador2[30];
	
	printf("Digite o nome dos dois jogadores que voce quer somar as estatisticas: \n");
	printf("Jogador 1: ");
	scanf("%s", jogador1);
	
	printf("Jogador 2: ");
	scanf("%s", jogador2);
		
	for(i=0;i<tamanho;i++){
		if(strcmp(jogador1, jogadores[i]->nome) == 0 ) { //verifica se o nome do primeiro jogador esta cadastrado
			gols += jogadores[i]->gols; //soma as estatisticas se for encontrado
			assistencias += jogadores[i]->assistencias;
			jogos += jogadores[i]->jogos;	
		}
		if(strcmp(jogador2, jogadores[i]->nome) == 0) { //verifica se o nome do segundo jogador esta cadastrado
			gols += jogadores[i]->gols; //soma as estatisticas se for encontrado
			assistencias += jogadores[i]->assistencias;
			jogos += jogadores[i]->jogos;	
		}
	}

	printf("=============SOMA DAS ESTATISTICAS=============\n\n"); //imprime a soma das estatisticas
	printf("GOLS: %d\n", gols);
	printf("ASSISTENCIAS: %d\n", assistencias);
	printf("JOGOS: %d\n", jogos);
	printf("\n");
}

void ehbom(Jogador **jogadores, int tamanho){
	int i;
	
	printf("O criterio para dizer se o jogador eh bom: ter mais de 20 gols e ter mais de 15 assistencias\n");
	
	for(i=0;i<tamanho;i++){	//imprime os dados do jogador se ele for bom
		if(jogadores[i]->gols > 20 && jogadores[i]->assistencias >15) {
			printf("-------------EH BOM--------------");
			printf("Jogador %s\n", jogadores[i]->nome);
			printf("numero de gols: %d\n", jogadores[i]->gols);
			printf("numero de assistencias: %d\n", jogadores[i]->assistencias);
			printf("---------------------------------");
			printf("\n");	
		}
		
	}
}
void libera(Jogador **jogadores, int tamanho){ //funcao que libera a memoria alocada dinamicamente
	int i;
	for(i=0;i<tamanho;i++){
		free(jogadores[i]);
	}
	free(jogadores);
}