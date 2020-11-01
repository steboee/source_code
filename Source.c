#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
function_v() {
	FILE* file = fopen("pacienti.txt", "r");
	char buff[100];
	int pocet_riadkov = 0, pacienti = 0;
	
	for (int i = 1; fgets(buff, sizeof(buff), file) != NULL; i++) { // zistovanie poctu riadkov v zaznamoch
		pocet_riadkov++;
	}
	fseek(file, 1,SEEK_SET);						 // nastavenie sa v subore na zaciatok.
	
	int x;
	x = pocet_riadkov;								//x = lokalna premenna pre nasledujuci for aby nsa zachovala premenná "pocet_riadkov"
	
	for (x; x > 0; x = x - 7) {						// zistenie poctu pacientov
		pacienti++;
	}
	
	char **pole_meno = calloc(pacienti, sizeof(char*));
	char **pole_rodnecislo = calloc(pacienti, sizeof(char*));
	char **pole_diagnoza = calloc(pacienti, sizeof(char*));
	char **pole_vysetrenie = calloc(pacienti, sizeof(char*));
	char **pole_vysledok = calloc(pacienti, sizeof(char*));
	char **pole_datum = calloc(pacienti, sizeof(char*));
	
	
	for (int i = 0; i < pacienti; i++) {
		
		pole_meno[i] = calloc(100,sizeof(char));			// 1. vytvorenie pola v poli na pozicii i 
		fgets(pole_meno[i], 100, file);				// 2. Priradenie stringu
		if (strlen(pole_meno[i]) > 50) {
			printf("ERROR : meno nesplna poziadavky\n");
		}
		else {
			printf("Meno priezvisko: %s", pole_meno[i]);	// 3. vypisanie stringu     
		}
		  

		pole_rodnecislo[i] =calloc(10,sizeof(char));
		fgets(pole_rodnecislo[i], 50 - 1, file);
		//mlady narodený od roku 2000
		if ((pole_rodnecislo[i])[0] == '0'){				// 1. ak rodne cislo nejakeho pacienta zacina 0
			(pole_rodnecislo[i])[0] = '1';					// 2. prevediem 0 na 1 aby som mohol previest tento string na int
			int rod = atoi(pole_rodnecislo[i]);
			(pole_rodnecislo[i])[0] = '0';												// 3. string ---> int
			rod = rod - 1000000000;							// 4. rodne cislo je 10 miestne , v (2.) som akokeby pripocital  1 000 000 000
			if (rod % 11 != 0) {								// tak teraz odcitam 1 000 000 000 
				printf("ERROR: neplatne rodne cislo mlady!\n");
			}
			else {
				printf("Rodne cislo: %s", pole_rodnecislo[i]);
			}
		}
		// narodeny pred rokom 2000
		else {
			int rod = atoi(pole_rodnecislo[i]);
			printf("%d\n", rod);
			if (rod % 11 != 0) {
				printf("ERROR: nespravne rodne cislo stary \n!");
			}
			else {
				printf("Rodne cislo: %s", pole_rodnecislo[i]);
			}
		}
		
		

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


