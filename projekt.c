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
	fseek(file, 1, SEEK_SET);						 // nastavenie sa v subore na zaciatok.

	int x;
	x = pocet_riadkov;								//x = lokalna premenna pre nasledujuci for aby nsa zachovala premenná "pocet_riadkov"

	for (x; x > 0; x = x - 7) {						// zistenie poctu pacientov
		pacienti++;
	}

	char** pole_meno = calloc(pacienti, sizeof(char*));
	char** pole_rodnecislo = calloc(pacienti, sizeof(char*));
	char** pole_diagnoza = calloc(pacienti, sizeof(char*));
	char** pole_vysetrenie = calloc(pacienti, sizeof(char*));
	char** pole_vysledok = calloc(pacienti, sizeof(char*));
	char** pole_datum = calloc(pacienti, sizeof(char*));
	int korektnost = 0;

	for (int i = 0; i < pacienti; i++) {

		

		//MENO PRIEZVISKO KONTROLA
		pole_meno[i] = calloc(100, sizeof(char));
		fgets(pole_meno[i], 100, file);
		if (strlen(pole_meno[i]) > 50) {							// Meno priezvisko moze byt najviac 50 znakovy retazec	
			printf("Meno priezvisko: ERROR: Neplatne meno\n");
			korektnost++;
		}
		else {
			int p = 0;
			for (int j = 0; j < strlen(pole_meno[i]); j++) {
				if ((pole_meno[i])[j] == ' ') {
					continue;

				}
				else if ('A' <= ((pole_meno[i])[j]) && (pole_meno[i])[j] <= 'Z') {
					continue;

				}
				else if ('a' <= (pole_meno[i])[j] && (pole_meno[i])[j] <= 'z') {
					continue;

				}
				else if ((pole_meno[i])[j] == '\n') {
					continue;
				}
				else {
					p++;
					printf("Meno priezvisko: ERROR: Neplatne meno\n");
					korektnost++;
					break;
				}
			}
			if (p == 0) {
				printf("Meno priezvisko: %s", pole_meno[i]);
			}


		}



		// RODNE CISLA KONTROLA
		pole_rodnecislo[i] = calloc(10, sizeof(char));
		fgets(pole_rodnecislo[i], 50 - 1, file);
		long long cislo = atoll(pole_rodnecislo[i]);				// Vytvorenie long long zo stringu
		if (strlen(pole_rodnecislo[i]) != 11) {						// Rodne cislo musi byt 10-miestne 
			printf("Rodne cislo: ERROR: neplatne rodne cislo\n");
			korektnost++;
		}
		else if ((cislo % 11) != 0) {									// Rodne cislo musi byt delitelne 11
			printf("Rodne cislo: ERROR: neplatne rodne cislo\n");
			korektnost++;
		}
		else {
			printf("Rodne cislo: %s", pole_rodnecislo[i]);
		}

		// DIAGNOZY KONTROLA
		pole_diagnoza[i] = calloc(50, sizeof(char*));
		fgets(pole_diagnoza[i], 50 - 1, file);
		int dia = atoi(pole_diagnoza[i]);
		if (strlen(pole_diagnoza[i]) != 4) {
			printf("Diagnoza: ERROR: nespravna diagnoza!\n");
			korektnost++;
		}
		else if ((pole_diagnoza[i])[0] <= 'A' || (pole_diagnoza[i])[0] >= 'Z') {
			printf("Diagnoza: ERROR: nespravna diagnoza!\n");
			korektnost++;
		}
		else if (dia > 99) {
			printf("Diagnoza: ERROR: nespravna diagnoza!\n");
			korektnost++;
		}
		else {
			printf("Diagnoza: %s", pole_diagnoza[i]);
		}

		//VYSETRENIE KONTROLA
		pole_vysetrenie[i] = calloc(50, sizeof(char*));
		fgets(pole_vysetrenie[i], 50 - 1, file);
		if (strlen(pole_vysetrenie[i]) > 51) {
			printf("Vysetrenie: ERROR: nespravne vysetrenie");
			korektnost++;
		}
		else {
			printf("Vysetrenie: %s", pole_vysetrenie[i]);
		}

		//VYSLEDOK KONTROLA
		pole_vysledok[i] = calloc(50, sizeof(char*));
		fgets(pole_vysledok[i], 50 - 1, file);
		int dlzkadigits = strlen(pole_vysledok[i]) - 1;			// pocet cifier v stringu -- bez "."
		int intcislo = atoi(pole_vysledok[i]);					//vytvorenie int zo stringu
		int j = 0;
		int new = intcislo;
		while (new != 0) {		// pocitanie cifier INT-egru
			new = new / 10;
			j++;
		}
		int decimal = dlzkadigits - j;			//pocet cifier za desatinnou ciarkou
		if (decimal > 4) {
			printf("Vysledok: ERROR:nekorektny vysledok\n");
			korektnost++;
		}
		else if (intcislo > 0 && intcislo < 1000) {
			printf("Vysledok: %s", pole_vysledok[i]);
			
		}
		else {
			printf("Vyledok: ERROR:nekorektny vysledok\n");
			korektnost++;
		}



		//DATUM KONTROLA
		pole_datum[i] = calloc(50, sizeof(char*));
		fgets(pole_datum[i], 50 - 1, file);
		if (strlen(pole_datum) > 9) {					// string ma na konci este jeden znak okrem toho co je v.txt preto 9
			printf("Datum: ERROR: nekorektny datum\n");
			korektnost++;
		}
		else {
			for (int j = 0; j < 8; j++) {						//prehcadzam jedntolivymi znakmi v stringu
				if (47 >= (int)(pole_datum[i])[j] || (int)(pole_datum[i])[j] >= 58) {	
					printf("%c\n", (pole_datum[i])[j]);															// Ak to nieje èíslo tak ERROR
					printf("Datum: ERROR: nekorektny datum\n");
					korektnost++;
					break;
				}
			}
			printf("Datum: %s", pole_datum[i]);

		}
		puts("");
		fgets(buff, 50, file);
	}
	if (korektnost != 0) {
		printf("\nNekorektne vstupy !\nPocet : %d", korektnost);
		exit(1);
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
		switch (input) {

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
