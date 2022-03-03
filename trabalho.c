#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*

Podemos criar um sistema que simplesmente 
1 - cadastra usuários, 
2 - mostra
3 - mostra1
4 - cadastro livros 
5 - vende livros, 
6 - compra livros, 
7 - consulta ao estoque,
8 - devoluções de livros

*/

struct usuario{
	//inserir código aqui
	int id;
	int idade; 
	char nome[25];
	char sobrenome[35];
	char email[100];
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
	}



}	

void menu(){
	int opcao;
	struct usuario P[30];


	while(1){
		printf("\nBem vindo ao Sistema de Livraria");
		printf("\n1- Cadastrar");
		printf("\n2- Mostrar Todos");
		printf("\n3- Mostrar um");
        printf("\n4- Vender Livros ");
        printf("\n5- Comprar Livros ");
        printf("\n6- Carrinho de Compras ");
        printf("\n7- Devolver livros ");
		printf("\n9- Sair ");
		printf("\nDigite opcao: ");
		scanf("%d", &opcao);
	
		if(opcao == 1) cadastro(P);
		// if(opcao == 2) mostra(P);
		// if(opcao == 3) mostra(P);
        // if(opcao == 2) mostra1(P);
		// if(opcao == 9) return;
	}
}


int main(){
	menu();
}
