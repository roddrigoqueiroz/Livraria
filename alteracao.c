#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 30

struct usuario{
	int id;
	char nome[25];
    int mes;
	int state; // Define se o usuário já foi cadastrado. 0 = nao, 1 = sim
	double saldo;
};

struct livros{
	int id;
	int quantidade;
	double preco;
	char nome[50];
	char autor[50];
	int state; // Define se o livro já foi cadastrado. 0 = nao, 1 = sim
};


int checaMes(int mes){
    if (mes <= 12 && mes >= 1)
        return 1; // 1 = True
    else
        return 0;
}

// 1 - cadastra usuarios
void cadastro(struct usuario T[]){
	int i, qtdCadastro;

	printf("\nQuantos usuarios vc quer cadastrar? ");
	scanf("%d", &qtdCadastro);

	for(i = 0; i < N && qtdCadastro != 0; i++){
		
		if (T[i].state == 0){

			printf("\nUSUARIO %d\n", i + 1);
			
			T[i].id = i;
	
			printf("ID do usuario: %d\n", T[i].id);

			setbuf(stdin,NULL);
			printf("Insira um nome: ");
			scanf("%[^\n]", T[i].nome);

            printf("Digite o mes de aniversario: ");
            scanf("%d", &T[i].mes);

            while (checaMes(T[i].mes) == 0){
                printf("Digite um mes valido. ");
                scanf("%d", &T[i].mes);
            }

			printf("Insira o saldo: ");
			scanf("%lf", &T[i].saldo);

			T[i].state = 1; // Usuário já cadastrado
			// Atualiza a qtd de usuários já cadastrada. Quando chega a 0 cadastrou tds
			qtdCadastro--;
		}
	}
}

// 2- Mostrar todos os usuários cadastrados
void mostra(struct usuario T[]){
	int i;

    for (i = 0; i < N; i++){

		if (T[i].state == 1){
			printf("\nUSUARIO %d\n", i + 1);
			printf("ID: %d\n", T[i].id);
			printf("Nome: %s\n", T[i].nome);
            printf("Mes de aniversario: %d\n", T[i].mes);
			printf("Saldo: R$ %.2lf\n", T[i].saldo);
		}
    }
}

// 3- Cadastro de livros
void cadastroLivros(struct livros L[]){
	int i, qtdLivros;

	printf("Quantos livros vai cadastrar? ");
	scanf("%d", &qtdLivros);

	for (i = 0; i < N && qtdLivros != 0; i++){

		if (L[i].state == 0){
			printf("\nCADASTRO DO LIVRO %d\n", i + 1);

			L[i].id = i;
			printf("ID do livro: %d\n", L[i].id);

			printf("Quantidade deste livro: ");
			scanf("%d", &L[i].quantidade);
			
			setbuf(stdin,NULL);
			printf("Nome do livro: ");
			scanf("%[^\n]", L[i].nome);
			
			setbuf(stdin,NULL);
			printf("Autor: ");
			scanf("%[^\n]", L[i].autor);
			
			printf("Preco: ");
			scanf("%lf", &L[i].preco);

			L[i].state = 1; // Livro já cadastrado

			// Atualiza os livros para os que faltam cadastrar
			qtdLivros--;
		}
	}
}

// 4- Mostra todos os livros
void mostraLivros(struct livros L[]){
	int i;

	for (i = 0; i < N; i++){

		if (L[i].state == 1){
			printf("\nLIVRO %d\n", i + 1);
			printf("ID: %d\n", L[i].id);
			printf("Quantidade deste livro: %d\n", L[i].quantidade);
			printf("Nome: %s\n", L[i].nome);
			printf("Autor: %s\n", L[i].autor);
			printf("Preco: R$ %.2lf\n", L[i].preco);
		}
    }
}

int achaLivro(int id, struct livros L[], int *posicao){
	int i;

	for (i = 0; i < N; i++){
		if (L[i].id == id && L[i].state == 1){
			*posicao = i;
			return 1; // 1 == True
		}
	}
	return 0; // 0 == False
}

int achaUsuario(int id, struct usuario T[], int *posicao){
	int i;

	for (i = 0; i < N; i++){
		if (T[i].id == id && T[i].state == 1){
			*posicao = i;
			return 1; // 1 == True
		}
	}
	return 0; // 0 == False
}

// 5 - Vender livros
void venderLivros(struct usuario T[], struct livros L[]){
	int idLivro, qtdLivros, posicaoLivro = 0;
	int idUsuario, posicaoUsuario = 0;
	int opcao;
	double totalCompra, saldoUsuario;

	printf("ID do livro: ");
	scanf("%d", &idLivro);

	while (achaLivro(idLivro, L, &posicaoLivro) == 0){
		printf("Livro nao encontrado. Digite outro id de livro: ");
		scanf("%d", &idLivro);
	}
	printf("Nome do livro: %s\n", L[posicaoLivro].nome);


	printf("ID do usuario: ");
	scanf("%d", &idUsuario);

	while (achaUsuario(idUsuario, T, &posicaoUsuario) == 0){
		printf("Usuario nao encontrado. Digite outro id de usuario: ");
		scanf("%d", &idUsuario);
	}
	printf("Nome do usuario: %s\n\n", T[posicaoUsuario].nome);

	printf("Preco unitario: R$ %.2lf\n", L[posicaoLivro].preco);
	printf("Quantos livros vai levar? ");
	scanf("%d", &qtdLivros);
	
	// Calcula o total da compra
	totalCompra = L[posicaoLivro].preco * (double)qtdLivros;
	
	printf("\nTotal da compra: R$ %.2lf\n", totalCompra);

	printf("Confirma a compra? (1- sim, 2- nao) ");
	scanf("%d", &opcao);

	if (opcao == 1){
		// Atualização do saldo do usuário e a qtd de livros no estoque
		while (opcao == 1){
			if ((T[posicaoUsuario].saldo -= totalCompra) >= 0){

				L[posicaoLivro].quantidade -= qtdLivros;

				printf("\nNome do livro: %s\n", L[posicaoLivro].nome);
				printf("Quantidade de livros no estoque: %d\n", L[posicaoLivro].quantidade);
				printf("Seu saldo apos a compra: R$ %.2lf\n", T[posicaoUsuario].saldo);
				printf("Parabens! Boa leitura!\n\n");
				return;
			}
			else{
				printf("Saldo insuficiente. Por favor adicione mais dinheiro a conta.\n");
				T[posicaoUsuario].saldo += totalCompra;
				
				printf("Quer adicionar mais dinheiro? (1- sim, 2- nao) ");
				scanf("%d", &opcao);
				
				if (opcao == 1){
					printf("Quanto quer adicionar de saldo? ");
					scanf("%lf", &saldoUsuario);

					T[posicaoUsuario].saldo += saldoUsuario;
					printf("Saldo atual: R$ %.2lf\n\n", T[posicaoUsuario].saldo);
				}
				else
					return;
			}
		}
	}
	else{
		printf("Compra cancelada com sucesso!\n");
		return;
	}
}

int achaNomeLivros(char nome[], struct livros L[], int *posicao){
	int i;

	for (i = 0; i < N; i++){
		if (strcmp(nome, L[i].nome) == 0 && L[i].state == 1){
			*posicao = i;
			return 1; // True
		}
	}
	return 0; // False
}

// 6- Compra livros
void comprarLivros(struct usuario T[], struct livros L[]){
	int qtdLvrComprados, posicaoLivro = 0;
	int idUsuarioCompra, posicaoUsuario = 0;
	int opcao;
	double totalPago;
	char nomeLvrComprado[50];

	printf("ID do usuario que ira vender: ");
	scanf("%d", &idUsuarioCompra);

	while (achaUsuario(idUsuarioCompra, T, &posicaoUsuario) == 0){
		printf("Usuario nao encontrado.\n");
		printf("Deseja cadastrar um novo usuario? (1- sim, 2- nao) ");
		scanf("%d", &opcao);

		if (opcao == 1){
			cadastro(T);
			printf("\nID do usuario que ira vender: ");
			scanf("%d", &idUsuarioCompra);
		}
		else{
			printf("Digite outro ID: ");
			scanf("%d", &idUsuarioCompra);
		}
	}

    setbuf(stdin, NULL);
	printf("Nome do livro que deseja comprar: ");
	scanf("%[^\n]", nomeLvrComprado);

	while (achaNomeLivros(nomeLvrComprado, L, &posicaoLivro) == 0){
		printf("Livro nao encontrado.\n");
		printf("Deseja cadastrar um novo livro? (1- sim, 2- nao) ");
		scanf("%d", &opcao);

		if (opcao == 1){
			cadastroLivros(L);
			setbuf(stdin, NULL);
			printf("\nNome do livro que deseja comprar: ");
			scanf("%[^\n]", nomeLvrComprado);
		}
		else{
			setbuf(stdin, NULL);
			printf("\nNome do livro que deseja comprar: ");
			scanf("%[^\n]", nomeLvrComprado);
		}
	}

    setbuf(stdin, NULL);
	printf("Quantos livros iguais quer comprar? ");
	scanf("%d", &qtdLvrComprados);
	
	L[posicaoLivro].quantidade += qtdLvrComprados;
	totalPago = (double)qtdLvrComprados * L[posicaoLivro].preco;
	T[posicaoUsuario].saldo += totalPago;
	
	printf("\nSaldo atual do usuario: %.2lf\n", T[posicaoUsuario].saldo);
	
}

// 7- Mudar cadastro
void mudarCadastro(struct usuario T[]){
    int idUsuario, qtdUsuarios, i, posicaoUsuario = 0;
    
    printf("Quantos usuarios quer recadastrar? ");
    scanf("%d", &qtdUsuarios);

    for (i = 0; i < qtdUsuarios; i++){
        printf("ID do usuario: ");
        scanf("%d", &idUsuario);
		
		while (achaUsuario(idUsuario, T, &posicaoUsuario) == 0){
			printf("Usuario nao encontrado.\n");
			printf("Digite outro ID: ");
			scanf("%d", &idUsuario);
		}

		setbuf(stdin,NULL);
        printf("Alterar Nome: ");
        scanf("%[^\n]", T[posicaoUsuario].nome);

        printf("Alterar mes de aniversario: ");
        scanf("%d", T[posicaoUsuario].mes);

        while (checaMes(T[i].mes) == 0){
            printf("Digite um mes valido. ");
            scanf("%d", &T[i].mes);
        }

		printf("Alterar saldo: ");
		scanf("%lf", &T[posicaoUsuario].saldo);
    }
}

// 8- Altera o cadastro dos livros
void mudarCadastroLivros(struct livros L[]){
	int idLivro, qtdLivros, i, posicaoLivro = 0;
    
    printf("Quantos livros quer recadastrar? ");
    scanf("%d", &qtdLivros);

    for (i = 0; i < qtdLivros; i++){
        printf("ID do livro: ");
        scanf("%d", &idLivro);
		
		while (achaLivro(idLivro, L, &posicaoLivro) == 0){
			printf("Livro nao encontrado.\n");
			printf("Digite outro ID: ");
			scanf("%d", &idLivro);
		}

		setbuf(stdin,NULL);
        printf("Alterar quantidade do livro no estoque: ");
		scanf("%d", &L[posicaoLivro].quantidade);

		setbuf(stdin,NULL);
		printf("Alterar nome: ");
        scanf("%[^\n]", L[posicaoLivro].nome);

		setbuf(stdin,NULL);
		printf("Alterar autor: ");
		scanf("%[^\n]", L[posicaoLivro].autor);

		printf("Alterar preco: ");
		scanf("%lf", &L[posicaoLivro].preco);
    }
}

// 9- Devolve Livros
void devolveLivros(struct usuario T[], struct livros L[]){
	int idLivro, posicaoLivro = 0, qtdLivros;
	int idUsuario, posicaoUsuario = 0;

	setbuf(stdin,NULL);
	printf("ID do livro que deseja devolver: ");
	scanf("%d", &idLivro);
	printf("Quantos livros quer devolver? ");
	scanf("%d", &qtdLivros);
	printf("ID do usuario que vai devolver: ");
	scanf("%d", &idUsuario);

	if (achaLivro(idLivro, L, &posicaoLivro) == 1){
		L[posicaoLivro].quantidade += qtdLivros;
		
		if (achaUsuario(idUsuario, T, &posicaoUsuario) == 0){
			printf("Digite outro ID: ");
			scanf("%d", &idUsuario);
		}

		T[posicaoUsuario].saldo += (double)qtdLivros * L[posicaoLivro].preco;
		printf("Quantidade atual do livro: %d\n", L[posicaoLivro].quantidade);
		printf("Livro devolvido com sucesso! Obrigado!\n");
		return;
	}
	else{
		printf("Seu livro nao esta cadastrado. Talvez nao tenha comprado aqui.\n");
		return;
	}
}

void menu(){


	int opcao;
	struct usuario P[N];
	struct livros L[N];

	int i;
	for(i = 0; i < N; i++){
		P[i].state = 0;
		L[i].state = 0;
	}

	while(1){
		setbuf(stdin,NULL);
		printf("\nBem vindo ao Sistema de Livraria");
		printf("\n1- Cadastrar Usuarios "); // Rayanne
		printf("\n2- Mostrar Todos os Usuarios "); // Daniel
		printf("\n3- Cadastrar Livros "); // Rayanne
		printf("\n4- Mostrar Todos os Livros "); // Daniel
        printf("\n5- Vender Livros "); // Rodrigo
        printf("\n6- Comprar Livros "); // Emanuel
        printf("\n7- Mudar Cadastro de Usuarios "); // Wothon
		printf("\n8- Mudar Cadastro de Livros "); // Wothon
        printf("\n9- Devolver Livros "); // Wellyson
		printf("\n10- Sair ");
		printf("\nDigite opcao: ");
		scanf("%d", &opcao);
	
		if(opcao == 1) cadastro(P);
		if(opcao == 2) mostra(P);
		if(opcao == 3) cadastroLivros(L);
		if(opcao == 4) mostraLivros(L);
		if(opcao == 5) venderLivros(P, L);
		if(opcao == 6) comprarLivros(P, L);
		if(opcao == 7) mudarCadastro(P);
		if(opcao == 8) mudarCadastroLivros(L);
		if(opcao == 9) devolveLivros(P, L);
		if(opcao == 10) return;
	}
}

int main(){
	menu();
}