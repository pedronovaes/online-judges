// Pedro Marcelino Mendes Novaes Melo
#include <map>
#include <string>
#include <algorithm>
#include <cstring>
#include <stdio.h>
#include <iostream>

using namespace std;

const int MAX_N = 32;

int N, M, ini, fim, ordem = 0;

int grafo[MAX_N][MAX_N];
int grau[MAX_N];
int fila[MAX_N];
int saida[MAX_N];

map<string, int> amigos;
map<int, string> amigos_reversos;

void iniciar_fila();
void enfileira(int numero);
int desenfileira();
void executa_ordenacao_topologica();

int main(){
	int i, j, teste = 0, pos_amigo1, pos_amigo2, x;
	char nome[30];

	while(1){
		teste++;
		ordem = 0;
		scanf(" %d", &N);

		if(N == 0)
			break;

		for(i = 0; i < N; i++){
			scanf(" %s", nome);
			amigos[string(nome)] = i;
			amigos_reversos[i] = string(nome);
		}

		for(i = 0; i < N; i++){
			for(j = 0; j < N; j++)
				grafo[i][j] = 0;
			grau[i] = -1;
		}

		for(i = 0; i < N; i++){
			scanf(" %s %d", nome, &M);
			pos_amigo1 = amigos[nome];
			grau[pos_amigo1] = M;

			for(j = 0; j < M; j++){
				scanf(" %s", nome);
				pos_amigo2 = amigos[nome];
				grafo[pos_amigo1][pos_amigo2]++;
			}
		}

		printf("Teste %d\n", teste);

		executa_ordenacao_topologica();
		if(ordem == 0){
			printf("impossivel\n\n");
		}else{
			for(i = 0; i < N; i++){
				x = saida[i];
				cout<<amigos_reversos[x];
				printf(" ");
			}
			printf("\n\n");
		}
	}

	return 0;
}

void iniciar_fila(){
	ini = 0;
	fim = 0;
}

void enfileira(int numero){
	fila[fim++] = numero;
}

int desenfileira(){
	return fila[ini++];
}

void executa_ordenacao_topologica(){
	int i, j, k = 0;

	iniciar_fila();

	for(i = (N - 1); i >= 0; i--){
		if(grau[i] == 0){
			enfileira(i);
			grau[i]--;
			ordem = 1;
		}
	}

	if(ordem == 0){
		return;
	}

	while(ini != fim){
		int u = desenfileira();
		saida[k] = u;
		k++;
		for(i = 0; i < N; i++){
			if(grafo[i][u] == 1){
				grau[i]--;
			}
		}
		for(i = 0; i < N; i++){
			if(grau[i] == 0){
				enfileira(i);
				grau[i]--;
				//ordem = 1;
			}
		}
	}

	if(k == N)
		ordem = 1;
	else
		ordem = 0;

	return;
}