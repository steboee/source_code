#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>



function_v() {
	FILE *file = fopen("pacienti.txt", "r");
	char **pole;
	char buff[100];
	pole = (char**)malloc(4*sizeof(char*));

	if (pole == NULL) {
		printf("Pole sa nepodarilo vytvorit.\n");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < 6; i++) {
		pole[i] = (char*)malloc(6*i);
	}
	int i = 1;
	while ((fgets(buff, sizeof(buff), file)) != NULL) {
		if (i % 7 == 0){
			printf("\n");
			i++;
		}
		else {
			pole[i] = buff;
			printf("[%d] %s", i, pole[i]);
			i++;
		}
	}
	free(*pole);
	pole = NULL;
	return 0;
}


int main() {
	char input;
	FILE *file = fopen("pacienti.txt", "r");
	while (scanf("%c", &input)) {
		if (input == 'v') {
			int a = function_v();
		}
		if (input == 'k') {
			printf("halo");
		}
	}
	return 0;
}

