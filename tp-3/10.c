#include <stdio.h>

int bisiesto(int);
void parsear_fechas(void);
int leer_nro(void);
int dias_del_mes(int, int);
int calcular_diferencia(int, int, int, int, int, int);

int hasta_dia = 0, hasta_mes = 0, hasta_anno = 0;
int desde_dia = 0, desde_mes = 0, desde_anno = 0;


int main(void){
	
	parsear_fechas();
	printf("Fecha de inicio: %d\t%d\t%d\n", desde_dia, desde_mes, desde_anno);
	printf("Fecha de fin   : %d\t%d\t%d\n", hasta_dia, hasta_mes, hasta_anno);
	int resultado = calcular_diferencia(desde_anno, desde_mes, desde_dia, 
										hasta_anno, hasta_mes, hasta_dia);
	printf("\nLa diferencia entre fechas es %d\n", resultado);

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

void parsear_fechas(void) { // dd,mm,aaaa
	// 5/1/6
	// 05/01/0006
	int fecha_erronea = 1;

	while(fecha_erronea == 1) {
		printf("Ingrese una fecha de inicio valida (dd/mm/aaaa): ");
		desde_dia = leer_nro();
		desde_mes = leer_nro();
		desde_anno = leer_nro();
		if(desde_dia == 0 || desde_dia > dias_del_mes(desde_mes, desde_anno) || desde_mes == 0 || desde_mes > 12){
			fecha_erronea = 1;
		} else {
			fecha_erronea = 0;
		}
	}
	fecha_erronea = 1;
	while(fecha_erronea == 1) {
		printf("Ingrese una fecha de fin valida (dd/mm/aaaa): ");
		hasta_dia = leer_nro();
		hasta_mes = leer_nro();
		hasta_anno = leer_nro();
		if(hasta_dia == 0 || hasta_dia > dias_del_mes(hasta_mes, hasta_anno) || hasta_mes == 0 || hasta_mes > 12){
			fecha_erronea = 1;
		} else {
			fecha_erronea = 0;
		}
	}
}

int calcular_diferencia(int desde_anno, int desde_mes, int desde_dia, int hasta_anno, int hasta_mes, int hasta_dia) {
	int dias_de_diferencia = 0;		// analizo del 5.10.1970 al 8.11.1975

	// analizo del 5.10.1970 al 8.11.1975

	for(int anno_analizado = desde_anno + 1; anno_analizado < hasta_anno; anno_analizado++) {
		for(int mes_analizado = 1; mes_analizado <= 12; mes_analizado++) {
			dias_de_diferencia += dias_del_mes(mes_analizado, anno_analizado);
		}
	}
	
	if(hasta_anno != desde_anno) {
		//Cuántos días pasaron para el 8.11.1975 NO
		// Contar cuantos días pasaron para el 30.10.1975
		for(int mes_analizado = 1; mes_analizado < hasta_mes; mes_analizado++) {
			dias_de_diferencia += dias_del_mes(mes_analizado, hasta_anno);
		}
		dias_de_diferencia += hasta_dia;

		//Cuántos días pasaron entre el 5.10.1970 y 31.12.1970
		// Primero: Cuántos días pasaron entre el 1.11.1970 y 31.12.1970
		for(int mes_analizado = 12; mes_analizado > desde_mes; mes_analizado--) {
			dias_de_diferencia += dias_del_mes(mes_analizado, desde_anno);
		}
		// Segundo: cuántos días pasaron entre el 5.10.1970 y 31.10.1970
		dias_de_diferencia += dias_del_mes(desde_mes, desde_anno) - desde_dia;
	} else if (desde_mes != hasta_mes) {
		// quiero analizar entre 10.09.2020 y 15.11.2020

		// cuento entre 1.10.2020 a 31.11.2020
		for(int mes_analizado = desde_mes + 1; mes_analizado < hasta_mes; mes_analizado++) {
			dias_de_diferencia += dias_del_mes(mes_analizado, desde_anno);
		}
		
		// cuántos días pasaron entre el 1.11.2020 y 15.11.2020
		dias_de_diferencia += hasta_dia;

		// cuántos días pasaron entre el 10.09.2020 y 30.09.2020
		dias_de_diferencia += dias_del_mes(desde_mes, desde_anno) - desde_dia;
	} else {
		dias_de_diferencia = hasta_dia - desde_dia;
	}
	return dias_de_diferencia;
}

int dias_del_mes(int mes, int anno){
	if(mes == 2){
		return bisiesto(anno) ? 29 : 28;
	} else if(mes <= 7) {
		return (mes % 2) == 1 ? 31 : 30;
	} else {
		return (mes % 2) == 1 ? 30 : 31;
	}
}

int leer_nro(void) {
	char c;
	int numero = 0;
	while((c = getchar()) >= '0' && c <= '9') {
        numero *= 10.0;
		numero += c - '0';
	}
	return numero;
}