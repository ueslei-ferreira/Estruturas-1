#include <stdio.h>
float media(double vet[], int n, int *i){
	double soma=0;
	for(int j=0;j<n;j++){
		soma=soma+vet[j];
	}
	double media = soma/n;
	double proximo=vet[0];
	int t;
	for(int j=0;j<n;j++){
		t=media-vet[j];
		if(proximo-media<t){
			proximo=vet[j];
		}
	}
	*i=proximo;
	return media;
}
int main(){
	printf("quantos valores vc deseja inserir?");
	int n;
	scanf("%d",&n);
	double vet[n];
	int *indice;
	for(int i=0;i<n;i++){
		scanf("%lf",&vet[i]);
	}
	printf("media: %.2lf\n",media(vet,n,indice));
	printf("mais proximo: %d",*indice);
	return 0;
}