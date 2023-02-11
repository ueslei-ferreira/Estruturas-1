#include <stdio.h>
#include <stdlib.h>
typedef struct lista Lista;
struct lista{
	int valor;
	Lista * prox; //recebe a proxima estrutura
    Lista * anterior; //recebe a estrutura anterior
};

Lista * inicializa() { //inicializa a estrutura
	return NULL;
}
Lista *aloca_no(int valor){
    Lista *no = (Lista*)malloc(sizeof(Lista)); //aloca a estrutura
    no->valor = valor; //insere a informacao

    no->prox = NULL; //inicializa as duas estruturas internas
    no->anterior = NULL; //''
    
    return no;
}
Lista *insere(Lista *l, int valor){
    Lista *novo = aloca_no(valor);
    if(novo){
        novo->prox = l; //insere a nova estrutura no comeco
        if(l){
            l->anterior = novo;
        }
    }else{
        printf("erro");
        exit(1);
    }
    return novo;
}
Lista *insere_no_final(Lista *l, int valor){
    Lista *aux, *novo = aloca_no(valor);

    if(novo){ //se nao for nulo
        
        aux = l;
        while(aux->prox){
            aux = aux->prox; //percorre a lista até o final
        }
        aux->prox = novo; //a ultima posicao recebe o novo registro
        novo->anterior = aux; //o anterior do ultimo vai receber o penultimo registro
    }else{
        printf("erro");
        exit(1);
    }
    return novo;
}
void insere_meio(Lista *l, int valor, int ant){ //insere um valor no meio da lista
    Lista *aux, *novo = aloca_no(valor); //aloca um nova estrutura, e cria uma estrutura auxiliar 
    if(novo){
        aux = l; //auxiliar recebe a primeira estrutura
        while(aux->valor !=  ant && aux->prox){ //procura pela posicao do anterior inserida enquanto for diferente de nulo
            aux = aux->prox; //percorre as proximas estruturas enquanto nao encontrar a posicao desejada
        }
        novo->prox = aux->prox; //a nova estrutura recebe a posicao anterior a que sera inserido o novo valor
        if(aux->prox){ //ate o fim da lista
            aux->prox->anterior = novo; //insere o valor no intem anterior ao valor passado por referencia
        }
        novo->anterior = aux; 
        aux->prox = novo;

    }else{
        printf("erro");
        exit(1);
    }
}
void imprime(Lista *raiz){
    Lista *p = NULL;
    for(p = raiz; p != NULL; p = p->prox){ //enquanto nao for o fim da lista
        printf(" %d ", p->valor); //imprime o valor contido em cada estrutura
    }
}
Lista *ultimo(Lista *l){ //funcao que retorna o ultimo elemento da lista, que sera usado para imprimir ao contrario
    Lista *aux = l;
    while(aux->prox){
        aux = aux->prox;
    }
    return aux;
}
void imprime_contrario(Lista *ultimo){ //funcao vai receber o endereco do ultimo elemtento da lista
    printf("imprime ao contrario\n");
    while(ultimo){ //enquanto nao chegar ao final de dos elementos anteriores
        printf("%d ", ultimo->valor); //imprime o conteudo da lista
        ultimo = ultimo->anterior; //pega o valor anterior
    }
    printf("\n");
}

Lista *busca(Lista *l, int valor){
    Lista *p;
    for(p=l; p != NULL; p = p->prox){ //verifica em toda a lista
        if(p->valor==valor){ //se encontrar, ele retorna o endereco da estrutura
            return p;
        }
    }
    return NULL; //se n encontrar, retorna nullo

}
Lista *retira(Lista *l, int valor){
    Lista *ant = NULL;
    Lista *p = l;

    for(p=l; p!=NULL;p = p->prox){ //verifica se o valor existe na lista
        if(p->valor==valor){ //se existir, para a repeticao
            break;
        }
        ant = p; //a lista auxiliar recebe a posicao anterior a quando for encontrado
    }
    if(p == NULL){ //se a lista chegar ao fim
        return l; //retorna ela sem alteracoes
    }
    if(ant == NULL){ //se nao existir nenhum valor antes de p
        l = p->prox; //l agora aponta para a proxima posicao que era de p
    }else{
        ant->prox = p->prox;
    }
    free(p); //libera a estrutura
    return l; //retorna a estrutura principal
}
Lista *libera(Lista *l){
    Lista *p = l;
    Lista *t = NULL;
    while(p != NULL){
        t = p->prox;
        free(p);
        p = t;
    }
    return NULL;
}
int main() {
    system("cls");
	Lista *lista;
	lista = inicializa(); //inicializa uma lista com nulo

    for(int i=0;i<5;i++){
        lista = insere(lista, i); //insere automaticamente para teste
    }
    printf("\n");

    insere_no_final(lista, 99); //insere um item ao final da lista
    imprime(lista);

    int new_valor = 100, anterior = 0;
    insere_meio(lista, new_valor, anterior); 

    Lista *aux = busca(lista, 2); //busca um determinado valor na lista
    if (aux!=NULL){
        printf("valor encontrado! %d\n", aux->valor); //imprime o valor se foi encontrado
    }else{
        printf("\nnao encontrado\n");
    }

    imprime_contrario(ultimo(lista)); //imprime ao contrario

    lista = retira(lista, 3); //retira um item 
    
    imprime(lista); //imprime normalmente

    lista = libera(lista); //libera toda a memoria alocada
	return 0;
}
