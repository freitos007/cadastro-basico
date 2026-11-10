#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

#define VERDADEIRO 1
#define TAMANHO 50
#define BARRA_ZERO 1

void Cadastro(char* nome, char* usuario, char* senha){
	char confirmarSenha[TAMANHO];

	puts("Digite o seu nome completo");
	fgets(nome, TAMANHO, stdin);

	puts("Digite o seu nome de usuario");
	fgets(usuario, TAMANHO, stdin);

	do{
		puts("Digite a sua senha");
		fgets(senha, TAMANHO, stdin);

		puts("confirme sua senha");
		fgets(confirmarSenha, TAMANHO, stdin);
	}while(strcmp(senha, confirmarSenha) != 0);

	nome[strcspn(nome, "\n")] 	= '\0'; 
	usuario[strcspn(usuario, "\n")] = '\0'; 
	senha[strcspn(senha, "\n")] 	= '\0'; 
}

void ValidarNome(char *nome){
	int caracteres 	= 0;
	int palavras	= 0;
	int i		= 0;
	
	while(nome[i] != '\0'){
		caracteres++;
		i++;
	}

	printf("%d", caracteres);
}

int main(){
	char nome[TAMANHO];
	char usuario[TAMANHO];
	char senha[TAMANHO];
	int opcao;
	int sair = 0;

	while(sair != VERDADEIRO){
		puts("Selecione uma opção\n1: Cadastrar-se \n2: Validar Nome");
		scanf("%d", &opcao);
		while ((getchar()) != '\n');
		switch(opcao){
			case 1:
				Cadastro(nome, usuario, senha);
				break;
			case 2:
				ValidarNome(nome);
				break;
			default:
				sair = VERDADEIRO;
				break;
		}
	}

	return 0;
}
