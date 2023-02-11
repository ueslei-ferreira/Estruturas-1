#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	int codigo_disc;
	int codigo_curso;
	char nome_disc[20];
	int periodo;
	float carga_horaria;
}Disciplinas;
typedef struct{
	int codigo;
	char nome_curso[20];
	int disc;
	int qt_periodo;
}Cursos;
void inicializaD(Disciplinas **d, int tamanho){
	for(int i=0;i<tamanho;i++){//inicializa a struct para indicar que pode ser usada
		d[i]=NULL;
	}
}
void inicializaC(Cursos **c, int tamanho){
	for(int i=0;i<tamanho;i++){//inicializa a struct para indicar que pode ser usada
		c[i]=NULL;
	}
}
void cadastra_curso(int i, Cursos **curso){ //funcao que cadastra uma struct de Cursos 
		if(curso[i]==NULL){ //se a struct estiver vazia
			curso[i] = (Cursos*)malloc(sizeof(Cursos)); //aloca os atributos da struct
			printf("nome do curso que deseja cadastrar: "); //solicita a insercao dos atributos
			fflush(stdin);
			scanf("%s",curso[i]->nome_curso);
			
			printf("codigo do curso: ");
			scanf("%d",&curso[i]->codigo);
			
			printf("digite a quantidade de periodos do curso: ");
			scanf("%d",&curso[i]->qt_periodo);
			
			curso[i]->disc=0; //o numero de disciplinas comeca sempre zero, pois nao ha disciplinas cadastradas ainda
		}
}
void cadastra_disciplina(int i, Disciplinas **disciplina, Cursos **curso, int tamanho2){//funcao que cadastra as disciplinas
	int codigoT, j,quantidade; //codigoT sera lido para procurar um codigo de curso existente, quantidade foi cria para receber a quantidade de periodos, pois quando eu chamava pela struct de cursos acontecia um bug que eu nao soube resolver
	if(disciplina[i]==NULL){ //se a struct estiver disponivel
		printf("digite o codigo do curso que voce deseja inserir a disciplina: ");
		scanf("%d",&codigoT); //codigo de procura
		
		for( j=0;j<tamanho2;j++){
			if(codigoT==curso[j]->codigo){//se a disciplina existir
				quantidade=curso[i]->qt_periodo; //pega a quantidade de periodos da disciplina
				curso[j]->disc+=1;//adiciona a disciplina ao curso
				disciplina[i] = (Disciplinas*)malloc(sizeof(Disciplinas)); //aloca os atributos da struct
				printf("curso encontrado\n");
				disciplina[i]->codigo_curso=codigoT; //o codigo de curso é armazenado na disciplina
				codigoT=0; //a variavel é zerada para a confirmacao a seguir
 			}
		}
		if(codigoT==0){ //confirma que foi encontrado um curso pelo codigo
			printf("codigo da disciplina"); //pede a insercao dos atributos da disciplina
			scanf("%d",&disciplina[i]->codigo_disc);
			
			printf("nome da disciplina: ");
			scanf("%s",disciplina[i]->nome_disc);
			
			printf("periodo: ");
			scanf("%d",&disciplina[i]->periodo);
			while(disciplina[i]->periodo<=0||disciplina[i]->periodo>quantidade){ //verifica se o periodo existe no curso
				printf("periodo nao encontrado, digite novamente\n");
				scanf("%d",&disciplina[i]->periodo);
			}
			
			printf("carga horaria: ");
			scanf("%f",&disciplina[i]->carga_horaria);
			
		}else{
			printf("curso nao encontrado"); //se o codigo nao foi encontrado
		}
	}
}
void maior_qt_periodo(int tamanho, Cursos **curso, char *nome){ //funcao que verifica o curso com mais periodos
	int maior = 0, ri; //ri pega a posicao do curso com mais periodos
	for(int i=0;i<tamanho;i++){
		if(curso[i]->qt_periodo>maior){
			maior = curso[i]->qt_periodo;
			ri = i;
		}
	}
	strcpy(nome, curso[ri]->nome_curso); //"nome" copia o nome do curso com mais periodos e retorna por parametro
}
void qt_disc(Cursos **curso, char *nome, int tamanho){//funcao que verifica a quantidade de disciplinas no curso
	int recebe; //variavel usada para receber o retorno da strcmp
	for(int i=0;i<tamanho;i++){
		recebe = strcmp(curso[i]->nome_curso, nome); //verifica se o curso inserido é existente
		if(recebe==0){
			printf("numero de disciplinas no curso: %d\n",curso[i]->disc); //imprime o numero de disciplinas
		}
	}
} 
int disc_periodo(Disciplinas **disciplina, int tamanhoD, int per){ // funcao que verifica a quantidade de disciplinas por periodo
	int cont=0; //conta quantas vezes a disciplina aparece no periodo
	for(int i=0;i<tamanhoD;i++){
		if(per==disciplina[i]->periodo){
			cont++;
		}
	}
	return cont; // retorna a quantidade de vezes
}
int main(){
	printf("quantos cursos deseja cadastrar?");
	int tamanhoC;//tamanho que sera usado para os cursos
	scanf("%d",&tamanhoC);
	while(tamanhoC<=0){
		printf("digite um tamanho valido\n");
		scanf("%d",&tamanhoC);
	}
	
	Cursos **curso;
	curso= (Cursos**)malloc(tamanhoC*sizeof(Cursos)); //aloca o ponteiro de ponteiros que sera usado para alocar cada struct
	
	inicializaC(curso, tamanhoC); //inicializa com NULL
	
	for(int i=0;i<tamanhoC;i++){
		cadastra_curso(i, curso); //cadastra a quantidade de cursos desejada
		printf("\n");
	}
	
	printf("quantas disciplinas deseja cadastrar?");
	int tamanhoD;
	scanf("%d",&tamanhoD); //tamanho que sera usado para as disciplinas
	while(tamanhoD<=0){
		printf("digite um tamanho valido\n");
		scanf("%d",&tamanhoD);
	}
	
	Disciplinas **disciplina;
	disciplina = (Disciplinas**)malloc(tamanhoD*sizeof(Disciplinas));//aloca o ponteiro de ponteiros que sera usado para alocar cada struct
	
	inicializaD(disciplina, tamanhoD); //inicializa com NULL
	
	
	for(int i=0;i<tamanhoD;i++){
		cadastra_disciplina(i, disciplina, curso, tamanhoC); //cadastra o numero de disciplinas desejado
		printf("\n");
	}
	char nome[20]; //nome que sera usado para receber o nome do curso com mais periodos 
	maior_qt_periodo(tamanhoC, curso, nome); //chama a funcao que verifica qual o curso com mais periodos
	
	printf("curso com maior quantidade de periodos '%s'\n",nome);
	
	printf("pesquise o curso para saber quantas disciplinas existem nele: ");
	char nomeC[20];
	scanf("%s",nomeC);
	qt_disc(curso, nomeC, tamanhoC);//funcao que verifica quantas disciplinas existem em determinado curso
	
	printf("codigo do curso para pesuisa de periodos: ");
	int codigoC, per;
	scanf("%d",&codigoC); //codigo que sera usado na pesquisa
	int recebe;
	for(int i=0;i<tamanhoC;i++){
		if(codigoC==curso[i]->codigo){//pesquisa por codigo 
			printf("curso foi encontrado, agora digite o periodo desejado: ");
			scanf("%d",&per); //variavel que recebe o periodo a ser pequisado
			if(per>0&&per<=curso[i]->qt_periodo){ //verifica se a variavel é valida dentro do escopo de periodos do curso desejado
				recebe = disc_periodo(disciplina, tamanhoD, per); // variavel que recebe o retorno de quantas disciplinas foram encontradas no periodo desejado
				break;
            }		
		}
	}
	
	printf("foram encontradas %d disciplinas no periodo %d\n", recebe, per);
	
	for(int i=0;i<tamanhoC;i++){ //parte que libera a memoria alocada
		free(curso[i]);
	}for(int i=0;i<tamanhoD;i++){
		free(disciplina[i]);
	}
	free(curso);
	free(disciplina);
	return 0;
}