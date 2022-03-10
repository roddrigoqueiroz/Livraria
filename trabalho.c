#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 30

struct usuario{
	//inserir código aqui
	int id;
	int idade; 
	char* nome[25];
	char* sobrenome[35];
	char* email[100];
	int state;
};

int idJaExiste(int id, struct usuario T[], int qtdJaCadastrada){
	
	int i;

	for(i = 0; i < qtdJaCadastrada; i++){
		if(T[i].id == id){
			printf("ID ja existe\n");
			return 0; // ID ja existe
		}
	}

	return 1; // ID nao existe
}

// 1 - cadastra usuarios
void cadastro(struct usuario T[]){
	int i;
	int qtdCadastro;

	for (i = 0; i < N; i++)
		T[i].state = 0; // Usuário não cadastrado

	printf("Quantos usuarios vc quer cadastrar?\n");
	scanf("%d", &qtdCadastro);

	for(i = 0; i < qtdCadastro; i++){
		
		printf("\nUSUARIO %d\n", i + 1); 
		
		printf("Insira um id: ");

		scanf("%d", &T[i].id) ;

		if(idJaExiste(T[i].id, T, i) == 0){
			return; 
		}

		printf("Insira um idade: ");		
		scanf("%d", &T[i].idade);

		printf("Insira um nome: ");
		scanf("%s", &T[i].nome);

		printf("Insira um sobrenome: ");
		scanf("%s", &T[i].sobrenome );

		printf("Insira um email: ");
		scanf("%s", &T[i].email);

		T[i].state = 1; // Usuário já cadastrado
	}
}

void mostra(struct usuario T[]){
	int i, qtdCadastrada;

    printf("Quantos usuarios foram cadastrados?\n");
    scanf("%d", &qtdCadastrada);

    for (i = 0; i < qtdCadastrada; i++){
        printf("USUARIO %d\n\n", i + 1);
        printf("ID: %d\n", T[i].id);
        printf("Idade: %d\n", T[i].idade);
        printf("Nome: %s\n", T[i].nome);
        printf("Sobrenome: %s\n", T[i].sobrenome);
        printf("E-mail: %s\n", T[i].email);
    }
}

void mudarCadastro(struct usuario T[]){
    int usuario, qtdUsuarios, i;
    
    printf("Quantos usuarios quer recadastrar?\n");
    scanf("%d", &qtdUsuarios);

    for (i = 0; i < qtdUsuarios; i++){
        printf("Qual usuario quer mudar?\n");
        scanf("%d", &usuario); // Usuário precisa ser o número mostrado na tela ou seja, i - 1

        printf("Alterar ID: ");
        scanf("%d", &T[usuario - 1].id);
        printf("Alterar Idade: ");
        scanf("%d", &T[usuario - 1].idade);
        printf("Alterar Nome: ");
        scanf("%s", &T[usuario - 1].nome);
        printf("Alterar Sobrenome: ");
        scanf("%s", &T[usuario - 1].sobrenome);
        printf("Alterar e-mail: ");
        scanf("%s", &T[usuario - 1].email);
    }
}

// void mostra1(struct a_definir T[]){
// 	//inserir código aqui
// }


void menu(){
	int opcao;
	struct usuario P[N];


	while(1){
		printf("\nBem vindo ao Sistema de Livraria");
		printf("\n1- Cadastrar");
		printf("\n2- Mostrar Todos");
		printf("\n3- Mostrar um");
        printf("\n4- Vender Livros ");
        printf("\n5- Comprar Livros ");
        printf("\n6- Mudar cadastro ");
        printf("\n7- Devolver livros ");
		printf("\n9- Sair ");
		printf("\nDigite opcao: ");
		scanf("%d", &opcao);
	
		if(opcao == 1) cadastro(P);
		if(opcao == 2) mostra(P);
		if(opcao == 6) mudarCadastro(P);
        // if(opcao == 2) mostra1(P);
		if(opcao == 9) return;
	}
}


int main(){
	menu();
}