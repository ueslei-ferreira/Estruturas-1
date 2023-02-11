#include <stdio.h>
int imprimir_ab(int a, int b){
	if(a>=b){
		return a;
	}
	else{
		return a+imprimir_ab(a+1,b);
	}
}
int main(){
	int a,b;
	printf("digite A ");
	scanf("%i",&a);
	printf("digite B ");
	scanf("%i",&b);
	int menor=a,maior=b;
	if(b<a){
		menor=b;
		maior=a;
	}
	printf("%d",imprimir_ab(menor+1,maior-1));
	return 0;
}