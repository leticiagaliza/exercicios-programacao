#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct cadastro {
	char nome[50];
	int cpf;
	int setorN;
	char setor[100];
	char cadastrado;
};

struct cadastro cadastros[100];
int contador = 0;
int cadastroAtual = -1;

void realizarCadastro() {

	printf("Digite seu nome: ");
	scanf("%s", cadastros[contador].nome);
	printf("Digite seu CPF: ");
	scanf("%d", &cadastros[contador].cpf);

	cadastros[contador].cadastrado = 'S';
	cadastroAtual = contador;
	system("clear");
}

void atendimento () {
	system("clear");

	if (cadastroAtual == -1) {
        printf("Cadastro não realizado. Por favor, realize o cadastro primeiro.\n");
        realizarCadastro();
    }

	int atend;
	printf("Digite uma das opções de atendimento \n");
	printf("1 - Abertura de Conta \n");
	printf("2 - Caixa \n");
	printf("3 - Gerente Pessoa Física \n");
	printf("4 - Gerente Pessoa Jurídica \n");
	scanf("%d", &atend);

	cadastros[contador].setorN = atend; 

	switch (atend) {
		case 1: {
			system("clear");
			strcpy(cadastros[contador].setor, "Tipo Atendimento - 1 - Abertura de Conta");
			break;
		}
		case 2: {
			system("clear");
			strcpy(cadastros[contador].setor, "Tipo Atendimento - 2 - Caixa");
			break;
		}
		case 3: {
			system("clear");
			strcpy(cadastros[contador].setor, "Tipo Atendimento - 3 - Gerente Pessoa F�sica");
			break;
		}
		case 4: {
			system("clear");
			strcpy(cadastros[contador].setor, "Tipo Atendimento - 4 - Gerente Pessoa Jur�dica");
			break;
		}
		default: {
			system("clear");
			printf("Opção inválida \n");
			break;
		}
	}

	cadastros[contador].cadastrado = 'S';
	cadastroAtual = contador;
	contador++;
	strcpy(cadastros[contador].nome, cadastros[contador-1].nome);
	cadastros[contador].cpf = cadastros[contador-1].cpf;
		
	system("clear");	
}

void listaAtend() {

	for (int cont = 0; cont < contador; cont++) {
		if (cadastros[cont].cadastrado == 'S') {
			printf("Nome: %s \n", cadastros[cont].nome);
			printf("CPF: %d \n", cadastros[cont].cpf);
			printf("%s \n", cadastros[cont].setor);
			printf("==========================================\n");
		}
	}
	
}

void atendSetor() {
	system("clear");
	int nsetor;
	
	printf("Digite uma das opções de atendimento \n");
	printf("1 - Abertura de Conta \n");
	printf("2 - Caixa \n");
	printf("3 - Gerente Pessoa Física \n");
	printf("4 - Gerente Pessoa Jurídica \n");
	scanf("%d", &nsetor);
	
	for (int cont2 = 0; cont2 < contador; cont2++) {
        if (cadastros[cont2].cadastrado == 'S' && cadastros[cont2].setorN == nsetor) {
            printf("Nome: %s\n", cadastros[cont2].nome);
            printf("CPF: %d\n", cadastros[cont2].cpf);
            printf("%s\n", cadastros[cont2].setor);
            printf("==========================================\n");
        }
    }	
		
	
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	int opcao;
	
	do {
		printf("Bem-vindo ao sistema de atendimento \n");
		printf("1 - Solicitar Atendimento \n");
		printf("2 - Listar Atendimentos Registrados \n");
		printf("3 - Listar Atendimentos por setor \n");
		printf("4 - Sair \n");
		scanf("%d", &opcao);
		
		switch (opcao) {
			case 1 : {
				atendimento();
				break;
			}
			case 2: {
				listaAtend();
				printf("Pressione Enter para continuar...");
                while (getchar() != '\n');
                getchar();
				system("clear");
				break;
			}
			case 3: {
				atendSetor();
				printf("Pressione Enter para continuar...");
                while (getchar() != '\n');
                getchar();
				system("clear");
				break;
			}
			case 4: {
				system("clear");
				printf("Atendimento encerrado.");
				break;
			}
			default: {
				printf("Opção inválida \n");
				printf("Pressione Enter para continuar...");
                while (getchar() != '\n');
                getchar();
				system("clear");
				break;
			}
		}
	} while (opcao!=4);

	return 0;
}
