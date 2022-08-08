#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leitor.h"
#include "classFile.h"
#include "estruturas.h"

//Programa principal, onde o arquivo .class será carregado, passado para o leitor e fará todas as ações necessárias.
int main(int argc, char const *argv[]){
    ClassFile *classfile = malloc(sizeof(ClassFile));
    int entrada=0;
	int saida=0;

	//Armazenar a string para conter o nome do arquivo .class que será lido pelo leitor
	char *filename = malloc(100*sizeof(char));
	char *outputName = malloc(100*sizeof(char));
	
    // Essas condicionais serão utilizadas para formar o menu
    if(argc > 1){
		if(strlen(argv[1]) > 6 && !strcmp(argv[1] + strlen(argv[1]) - 6, ".class")){
			strcpy(filename, argv[1]);
			entrada = 1;
		} else if(strlen(argv[1]) > 4 && !strcmp(argv[1] + strlen(argv[1]) - 4, ".txt")){
			strcpy(outputName, argv[1]);
			saida = 1;
		}
		if(argc > 2){
			if(strlen(argv[2]) > 4 && !strcmp(argv[2] + strlen(argv[2]) - 4, ".txt")){
				strcpy(outputName, argv[2]);
				saida = 1;
			} else if(strlen(argv[2]) > 6 && !strcmp(argv[2] + strlen(argv[2]) - 6, ".class")){
				strcpy(filename, argv[2]);
				entrada = 1;
			}	
		}
	}
    //Se for saída
	if(!entrada){
		scanf("%s",filename);
	}
    //se for entrada
	if(!saida){
		printf("Qual nome para  o arquivo\n");
		scanf("%s",outputName);
	}	

	classfile = readFile(filename);

	FILE *outputFile = fopen(outputName, "w"); /*w text writing*/
	if (classfile != NULL && outputFile != NULL) {
        printClassFile(classfile, stdout);
		printClassFile(classfile, outputFile);
		fclose(outputFile);
	}else{
		printf("ERROR!! Falha ao criar arquivo.\n");
	}

	free(classfile);
	free(filename);
	free(outputName);

	return (0);
}

