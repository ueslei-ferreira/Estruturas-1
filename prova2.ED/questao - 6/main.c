#include <stdio.h>
#include <stdlib.h>
#include "jogador.c" //referencia o TAD

void inicializa(Jogador **jogadores,int tamanho);

int main(){
	int tamanho;
	printf("Quantos jogadores deseja inserir: ");
	scanf("%d", &tamanho); //pede a quantidade de jogadores
	
	while(tamanho<=0){
		printf("tamanho invalido, insira corretamente\n");
		scanf("%d", &tamanho); //obriga a inserir corretamente
	}
	
	Jogador **jogadores; 
	jogadores = (Jogador**)malloc(tamanho * sizeof(Jogador)); //aloca o ponteiro para ponteiros
	
	inicializa(jogadores, tamanho); //inicializa com NULL
	
	int i;
	for(i = 0; i < tamanho; ++i){
		atribui(jogadores, tamanho, i); //insere os dados
	}
	int opcao=0;
	while(opcao>=0){ //menu de opcoes
		printf("1 - para imprimir jogadores cadastrados\n");
		printf("2 - para somar e imprimir as estatisticas de dois jogadores\n");
		printf("3 - para saber quais jogadores sao bons de verdade XD \n");
		
		scanf("%d", &opcao);
		if(opcao==1){
			system("cls");
			imprime(jogadores, tamanho);
		}else if(opcao==2){
			system("cls");
			soma(tamanho, jogadores);
		}else if(opcao==3){
			system("cls");
			ehbom(jogadores, tamanho); 
		}
	}
	libera(jogadores, tamanho); //libera a memoria alocada
	return 0;
}
