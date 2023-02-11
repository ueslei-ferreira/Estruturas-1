//arquivo de cabecalho
typedef struct{
	char nome[25];
	int jogos;
	int gols;
	int assistencias;
}Jogador;

void inicializa(Jogador **jogadores, int tamanho);
void atribui(Jogador **jogadores, int tamanho, int indice);
void imprime(Jogador **jogadores, int tamanho);
void soma(int tamanho, Jogador **jogadores);
void ehbom(Jogador **jogadores, int tamanho);