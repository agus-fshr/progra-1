#include <stdio.h>

int bisiesto(int);
void linter(void);
int leer_nro(void);

int dia, mes, anno;
char c;

int main(void){

	linter();
	printf("%d\t%d\t%d\n", dia, mes, anno);

	return 0;	
}


// anno bisiesto-->1       anno no bisiesto-->0
int bisiesto(int anno) {
	if(anno%4 == 0){
		if(anno%100 == 0 && anno%400 != 0){
			return 0; //no es bisiesto
		}
		return 1;
	}
	return 0;
}

void linter(void) { // dd/mm/aaaa
	int componente;
	
	while(((c = getchar()) >= '0' && c <= '9') || (c == '/')){
		switch(componente){
			case 0:{
				dia = leer_nro();
			}
			case 1:{
				mes = leer_nro();
			}
			case 2:{
				anno = leer_nro();
			}
		}
	}
	
}

int leer_nro(void){
	int numero;
	if(c >= '0' && c <= '9') {
        numero *= 10.0;
		numero += c - '0';
	}
	return numero;
}