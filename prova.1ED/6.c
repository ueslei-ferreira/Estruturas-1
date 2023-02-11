#include <stdio.h>
void preenche(int *v, int tamanho)
{
    for(int i = 0; i < tamanho; i++)
    {
        scanf("%i", v);
        v++;
    }
}
void uniao(int *v1, int *v2, int *v3, int tamanho1, int tamanho2, int &tamanho3, int i, int j, int k )
{
    //não tem ninguem
    if(i == tamanho1 - 1 && j == tamanho2 - 1)
    {
        tamanho3=k;
        return ;
    }
    //so tem no segundo
    if(i == tamanho1 - 1)
    {
        if(k == 0 || v2[j] != v3[k - 1])
        {
            v3[k] = v2[j];
            uniao(v1, v2, v3, tamanho1, tamanho2, tamanho3, i, j + 1, k + 1);
        }
        else
        {
            uniao(v1, v2, v3, tamanho1, tamanho2, tamanho3, i, j + 1, k);
        }
        return ;
    }
    //so tem no primeiro
    else if(j == tamanho2 - 1)
    {
        if(k == 0 || v1[i] != v3[k - 1])
        {
            v3[k] = v1[i];
            uniao(v1, v2, v3, tamanho1, tamanho2, tamanho3, i + 1, j, k + 1);
        }
        else
        {
            uniao(v1, v2, v3, tamanho1, tamanho2, tamanho3, i + 1, j, k);
        }
        return ;
    }
    //tem nos dois mas o primeiro é maior
    else if(v1[i] > v2[j])
    {
        if(k == 0 || v2[j] != v3[k - 1])
        {
            v3[k] = v2[j];
            uniao(v1, v2, v3, tamanho1, tamanho2, tamanho3, i, j + 1, k + 1);
        }
        else
        {
            uniao(v1, v2, v3, tamanho1, tamanho2, tamanho3, i, j + 1, k);
        }
        return ;
    }
    //tem nos dois mas o segundo é maior
    else
    {
        if(k == 0 || v1[i] != v3[k - 1])
        {
            v3[k] = v1[i];
            uniao(v1, v2, v3, tamanho1, tamanho2, tamanho3, i + 1, j, k + 1);
        }
        else
        {
            uniao(v1, v2, v3, tamanho1, tamanho2, tamanho3, i + 1, j, k);
        }
    }
}
void quickSort(int *v, int esq, int dir)
{
    int i, j, posicao, troca;
    i = esq;
    j = dir;
    posicao = v[(esq + dir) / 2];

    while(i <= j)
    {
        while(v[i] < posicao && i < dir)
        {
            i++;
        }
        while(v[j] > posicao && j > esq)
        {
            j--;
        }
        if(i <= j)
        {
            troca = v[i];
            v[i] = v[j];
            v[j] = troca;
            i++;
            j--;
        }
    }
    if(j > esq)
    {
        quickSort(v, esq, j);
    }
    if(i < dir)
    {
        quickSort(v, i, dir);
    }
}
int main()
{
    int tamanho, tamanho2;
    printf("tamanho do primeiro vetor: ");
    scanf("%d", &tamanho);
    int vet[tamanho];
    preenche(vet, tamanho);

    printf("tamanho do segundo vetor: ");
    scanf("%d", &tamanho2);
    int vet2[tamanho2];
    preenche(vet2, tamanho2);

    quickSort(vet, 0, tamanho - 1);
    quickSort(vet2, 0, tamanho2 - 1);
    
    
    
    int tamanho3 = 0;

    int vet3[tamanho + tamanho2];
    uniao(vet, vet2, vet3 , tamanho, tamanho2, tamanho3, 0, 0, 0);
    for(int i = 0; i < tamanho3; i++)
    {
        printf("v3 = %d\n", vet3[i]);
    }
    return 0;
}
