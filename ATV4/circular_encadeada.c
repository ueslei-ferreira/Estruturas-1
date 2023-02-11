#include <stdio.h>
#include <stdlib.h>
typedef struct lista Lista;
struct lista{
	int valor;
	Lista * prox;
    Lista * anterior;
};

Lista * inicializa() {
	return NULL;
}
Lista *aloca_no(int valor){
    Lista *no = (Lista*)malloc(sizeof(Lista));
    no->valor = valor;
    no->prox = NULL;
    no->anterior = NULL;

    return no;
}
Lista *insere(Lista *l, int valor){
    Lista *novo = aloca_no(valor);
    if(l == NULL){ //se a lista estiver vazia

        novo->prox = novo; //aponta para ele mesmo
        novo->anterior = novo;
    }else{ //se não estiver vazia
        novo->anterior = l->anterior;
        novo->prox = l;
        l->anterior = novo;
        novo->anterior->prox = novo;
    } 
    return novo;
}

void imprime(Lista *l){
    Lista *aux;
    if(l==NULL){
        printf("lista vazia\n");
    }else{
        aux = l;
        do{
            printf("%d ",aux->valor);
            aux = aux->prox;
        }while(aux != l);
    }
}
Lista *busca(Lista *l, int valor){
    Lista *p = l;
    if(p == NULL){
        do{
            p = p->prox;
            if(p->valor == valor){
                return p;
            }
        }while(p != l);
    }
    return NULL;

}
Lista *retira(Lista *l, int valor){
    Lista *ant = NULL;
    Lista *p = l;
    int achou = 0;

    if(p == NULL){ //verifica se a lista está vazia
        return NULL;
    }
    if(p){
        do{
            ant = p;
            p = p->prox;
            if(p->valor == valor){
                achou = 1;
                break;
            }
        }while (p != l);
        
    }
    if(!achou){
        return l;
    }
    if(p->prox == p){
        free(p);
        return NULL;
    
    }if(p == l){
        ant->prox = l->prox;
        l = ant;
    }else{
        ant->prox = p->prox;
    }
    free(p);
    return l;
}
Lista *libera(Lista *l){
    Lista *p = l;
    Lista *t = NULL;
    if(p){
        do{
            t = p->prox;
            free(p);
            p = t;
        }while(p != l);
    }
    return NULL;
}
int main() {
    system("cls");
	Lista *lista;
	lista = inicializa();

    for(int i=0;i<5;i++){
        lista = insere(lista, i);
    }
    imprime(lista);
    Lista *aux = busca(lista, 6);
    if (aux){
        printf(" %d ", aux->valor);
    }else{
        printf("nao encontrado\n");
    }

    lista = retira(lista, 3);
    imprime(lista);
    lista = libera(lista);
	return 0;
}
