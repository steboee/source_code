#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

function_v() {
	FILE* file = fopen("pacienti.txt", "r");
	char buff[100];
	int pocet_riadkov =0, pacienti=0;
	
	for (int i = 1; fgets(buff, sizeof(buff), file) != NULL; i++) { // zistovanie poctu riadkov v zaznamoch
		pocet_riadkov++;
	}
	fseek(file, 1,SEEK_SET);
	int x;
	x = pocet_riadkov; //x = lokalna premenna pre nasledujuci for aby nemenula premennu pocet_riadkov
	for (x; x > 0; x = x - 7) { // zistenie poctu pacientov
		pacienti++;
	}
	
	char **pole_meno = calloc(pacienti, sizeof(char*));
	char **pole_rodnecislo = calloc(pacienti, sizeof(char*));
	char **pole_diagnoza = calloc(pacienti, sizeof(char*));
	char **pole_vysetrenie = calloc(pacienti, sizeof(char*));
	char **pole_vysledok = calloc(pacienti, sizeof(char*));
	char **pole_datum = calloc(pacienti, sizeof(char*));
	
	
	for (int i = 0; i < pacienti; i++) {
		
		pole_meno[i] = calloc(50,sizeof(char));
		fgets(pole_meno[i], 50 - 1, file);
		printf("Meno priiezvisko: %s", pole_meno[i]);
		pole_rodnecislo[i] =calloc(50,sizeof(char*));
		fgets(pole_rodnecislo[i], 50 - 1, file);
		printf("Rodne cislo: %s", pole_rodnecislo[i]);
		pole_diagnoza[i] = calloc(50,sizeof(char*));
		fgets(pole_diagnoza[i], 50 - 1, file);
		printf("Diagnoza: %s", pole_diagnoza[i]);
		pole_vysetrenie[i] = calloc(50,sizeof(char*));
		fgets(pole_vysetrenie[i], 50 - 1, file);
		printf("Vysetrenie: %s", pole_vysetrenie[i]);
		pole_vysledok[i] = calloc(50, sizeof(char*));
		fgets(pole_vysledok[i], 50 - 1, file);
		printf("Vysledok: %s", pole_vysledok[i]);
		pole_datum[i] = calloc(50,sizeof(char*));
		fgets(pole_datum[i], 50 - 1, file);
		printf("Datum: %s", pole_datum[i]);
		puts("");
		fgets(buff, 50, file);
	
	}
	printf("POELEEEE %s", pole_meno[2]);
	/*int pocitadlo = 0;
	for (int i = 0; i < pocet_riadkov;i++) {
		if (i == 7 * pocitadlo + 1) {
			fgets(pole_meno[i], 50 - 1, file);
			printf("Meno priiezvisko: %s", pole_meno[i]);
		}
		if (i == 7 * pocitadlo + 2) {
			fgets(pole_rodnecislo[i], 50 - 1, file);
			printf("Rodne cislo: %s", pole_rodnecislo[i]);
		}
		if (i == 7 * pocitadlo + 3) {
			fgets(pole_diagnoza[i], 50 - 1, file);
			printf("Diagnoza: %s", pole_diagnoza[i]);
		}
		if (i == 7 * pocitadlo + 4) {
			fgets(pole_vysetrenie[i], 50 - 1, file);
			printf("Vysetrenie: %s", pole_vysetrenie[i]);
		}
		if (i == 7 * pocitadlo + 5) {
			fgets(pole_vysledok[i], 50-1, file);
			printf("Vysledok: %s", pole_vysledok[i]);
		}
		if (i == 7 * pocitadlo + 6) {
			fgets(pole_datum[i], 50-1, file);
			printf("Datum: %s", pole_datum[i]);
		}
		if (i == 7 + 7*pocitadlo) {
			printf("\n");
			fgets(buff, sizeof(buff), file);
			pocitadlo++;
		}
		

	}
	*/
	

}

function_o() {

}

function_n() {

}

function_s() {

}

function_h() {

}

function_p() {

}

function_z() {

}

int main() {
	char input;
	while (scanf("%c", &input)) {
		switch (input){

			case 'v':
				function_v();
				break;

			case 'o':
				function_o();
				break;

			case 'n':
				function_n();
				break;

			case 's':
				function_s();
				break;

			case 'h':
				function_h();
				break;

			case 'p':
				function_p();
				break;

			case 'z':
				function_z();
				break;

			case 'k':
				exit(1);

			default:
				continue;
		}
	}
	return 0;
}


