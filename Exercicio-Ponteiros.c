/*

	Ponteiros

*/

#include <stdio.h>

void positions(int n, int d[], int * first_zero, int * first_five, int * last_five);

int main(){
	
	int n, f_zero, f_five, l_five, aux;
	
	printf("Digite qual o tamanho do numero: ");
    scanf("%i", &n);
    
	while(n < 2 || n > 1000){
		printf("\nERRO! Informe um numero entre 2 e 1000\n");
		printf("Digite qual o tamanho do numero: ");
    	scanf("%i", &n);
	}
    
    int d[n];

    printf("Digite os digitos decimais do numero: ");

    for (int c = 0; c < n; c++)
    {
        scanf("%i", &d[c]);
    }
    
    positions(n, d, &f_zero, &f_five, &l_five);
	
	if((f_zero != -1) || (f_five != -1) || l_five != -1){
		if(f_zero != -1){
			aux = d[f_zero];
			d[f_zero] = d[n - 1];
			d[n - 1] = aux;
		}
		else if(l_five != -1){
			aux = d[l_five];
			d[l_five] = d[n - 1];
			d[n - 1] = aux;
		} 
		else{
			aux = d[f_five];
			d[f_five] = d[n - 1];
			d[n - 1] = aux;
		}

		for(int i = 0; i < n; i++){
			printf("%d ", d[i]);
		}
	} 
	else{
		printf("-1\n");
	}
	
	printf("\n");
	
	return 0;
}
void positions(int n, int d[], int * first_zero, int * first_five, int * last_five){
	*first_zero = -1;
	*first_five = -1;
	*last_five = -1;
	
	for(int i = 0; i < n; i++){
		if(d[i] == 0 && (*first_zero) == -1){
			*first_zero = i;
		}
		if(d[i] == 5){
			if((*first_five) == -1){
				*first_five = i;
			}
			else{
				*last_five = i;
			}
		}
	}
}