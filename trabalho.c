#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10

// Sistema de Informação para uma livraria

/*Podemos criar um sistema que simplesmente cadastra usuários, cadastro livros,
mostra, mostra1, vende livros, compra livros, consulta ao estoque,
devoluções de livros*/

typedef struct
{
	int id;
    int amount; // quantidade no estoque
    char name[100];
	int price;
}
book;

typedef struct
{
	char name[50];
}
user;


book books[N];

struct a_definir{
	//inserir código aqui
};

void cadastro(struct a_definir T[]){
	//inserir código aqui
}

void mostra(struct a_definir T[]){
	//inserir código aqui
}

void mostra1(struct a_definir T[]){
	//inserir código aqui
}

// void cadastrar_livros(struct a_definir T[]){
    
// }


void menu(){
	int opcao;
	struct a_definir P[30];

	while(1){
		printf("\nBem vindo ao Sistema de... ");
		printf("\n1- Cadastrar Usuario");
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
		if(opcao == 2) mostra(P);
		if(opcao == 3) mostra1(P);
        if(opcao == 4) castrar_livros(P);
		if(opcao == 9) return;
	}
}


int main(){
	menu();
}
