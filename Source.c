#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>



function_v() {

}
function_o() {

}

int main() {
	char fun;
	scanf("%c", &fun);
	while (fun) {
		FILE* file = fopen("zaznamy.txt", "r");
		if (fun == 'v') {
			function_v(file);
		}
		if (fun == 'k') {
			break;
		}
		if (fun == 'o') {
			function_o();
		}
		scanf("%c", &fun);
	}
	return 0;
}

