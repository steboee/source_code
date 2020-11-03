#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

function_v() {
	FILE* file = fopen("pacienti.txt", "r");
	char** pole_meno;
	char** pole_rodnecislo;
	char** pole_diagnoza;
	char** pole_vysetrenie;
	char** pole_vysledok;
	char** pole_datum;
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

	pole_meno = calloc(pacienti, sizeof(char*));
	pole_rodnecislo = calloc(pacienti, sizeof(char*));
	pole_diagnoza = calloc(pacienti, sizeof(char*));
	pole_vysetrenie = calloc(pacienti, sizeof(char*));
	pole_vysledok = calloc(pacienti, sizeof(char*));
	pole_datum = calloc(pacienti, sizeof(char*));

	int korektnost = 1;
	for (int i = 0; i < pacienti; i++) {
		

		//MENO PRIEZVISKO KONTROLA
		pole_meno[i] = calloc(100, sizeof(char));
		fgets(pole_meno[i], 100, file);
		if (strlen(pole_meno[i]) > 50) {							// Meno priezvisko moze byt najviac 50 znakovy retazec	
			printf("ERROR : meno pacienta %s nesplna poziadavky\n", pole_meno[i]);
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
					printf("Meno priezvisko: ERROR: nepsravne meno\n");
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
			printf("Rodne cislo: ERROR: neplatne rodne cislo velkost !\n");
			korektnost++;
		}
		else if ((cislo % 11) != 0) {									// Rodne cislo musi byt delitelne 11
			printf("Rodne cislo: ERROR: neplatne rodne cislo delenie!\n");
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
			printf("Diagnoza: ERROR: nespravna dlzak!\n");
			korektnost++;
		}
		else if ((pole_diagnoza[i])[0] <= 'A' || (pole_diagnoza[i])[0] >= 'Z') {
			printf("Diagnoza: ERROR: nespravna pismeno!\n");
			korektnost++;
		}
		else if (dia > 99) {
			printf("Diagnoza: ERROR: nespravna cislo!\n");
			korektnost++;
		}
		else {
			printf("Diagnoza: %s", pole_diagnoza[i]);
		}

		//VYSETRENIE KONTROLA
		pole_vysetrenie[i] = calloc(50, sizeof(char*));
		fgets(pole_vysetrenie[i], 50 - 1, file);
		if (strlen(pole_vysetrenie[i]) > 51) {
			printf("Vysetrenie: ERROR: nespravne vysetrenie\n");
			korektnost++;
		}
		else {
			printf("Vysetrenie: %s", pole_vysetrenie[i]);
		}

		//VYSLEDOK KONTROLA
		pole_vysledok[i] = calloc(50, sizeof(char*));
		fgets(pole_vysledok[i], 50 - 1, file);
		int dlzkadigits = strlen(pole_vysledok[i]);
		printf("%d", dlzkadigits);		//dlzka stringu bez desatinnej .
		int intcislo = atoi(pole_vysledok);
		if (0 >= intcislo || intcislo >= 1000) {
			printf("Vyledok: ERROR:nekorektný výsledok\n");
			korektnost++;
		}
		else if(dlzkadigits)
	
		printf("%d", dlzkadigits);// pocet cifier v stringu -- bez "."
									//vytvorenie int zo stringu
		int j = 0;
		int new = intcislo;
		while (new != 0) {		// pocitanie cifier INT-egru
			new = new / 10;
			j++;
		}
		int decimal = dlzkadigits - j;			//pocet cifier za desatinnou ciarkou
		if (decimal > 4) {
			printf("Vysledok: ERROR:nekorektný výsledok\n");
			korektnost++;
		}
		else {
			printf("Vysledok: %s", pole_vysledok[i]);
		}



		//DATUM KONTROLA
		pole_datum[i] = calloc(50, sizeof(char*));
		fgets(pole_datum[i], 50 - 1, file);
		int zle = 0;
		if (strlen(pole_datum[i]) > 9) {					// string ma na konci este jeden znak okrem toho co je v.txt preto 9
			printf("Datum: ERROR: nekorektny datum\n");
			korektnost++;
		}
		else {
			for (int j = 0; j < 9; j++) {						//prehcadzam jedntolivymi znakmi v stringu
				if (47 >= (pole_datum[i])[j] || (pole_datum[i])[j] >= 59) {	
					printf("%d\n", (pole_datum[i])[j]);																// Ak to nieje èíslo tak ERROR
					zle++;
					korektnost--;
					break;
				}
			}
		}
		if (zle == 0) {
			printf("Datum: %s", pole_datum[i]);
		}
		else {
			printf("Datum: ERROR\n");
		}
		puts("");
		fgets(buff, sizeof(buff), file);

	}
	if (korektnost != 0) {
		printf("\nNekorektne vstupy !\nPoèet : %d\n", korektnost);
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



}
