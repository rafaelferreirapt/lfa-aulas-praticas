#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool M2(char* u);

int main(int argc,char* argv[]){
	if(argc == 1){
		printf("Incorrect number og arguments\n");
	}
	int i;
	for(i = 1; i<argc; i++){
		if(strspn(argv[i], "abc") != strlen(argv[i])){
			printf("Invalid group\n");
		}else{
			if(M2(argv[i]))
				printf("True\n");
			else printf("False\n");
		}
	}

	exit(0);
}

bool M2(char* u){
	char cond = 'b';
	int i;

	for(i = 0; i<strlen(u); i++){
		if(u[i] == cond){
			int j;
			char prev = u[i+1];
			for(j = i+1; j<strlen(u); j++){
				if(u[j] == cond){
					char sub[strlen(u)-j];
					strcpy(sub, u+j);
					if(M2(sub)){
						return true;
					}else
						return false;
				}
				if(prev == u[j]){

				}else
					return false;
			}
		}
	}
	return true;
}