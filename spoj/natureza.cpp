// Pedro Marcelino Mendes Novaes Melo
#include <map>
#include <string>
#include <algorithm>
#include <cstring>
#include <stdio.h>
#include <iostream>

using namespace std;

// C = numero de criaturas (vertices), R = numero de relacoes (arestas)
int C, R, visitas = 0;

const int MAX_C = 5001;

int grafo_criatura[MAX_C][MAX_C];
int visitados[MAX_C];

int dfs(int pos_inicial){
	int i;

	visitados[pos_inicial] = 1;
	visitas++;

	for(i = 0; i < C; i++){
		if((grafo_criatura[pos_inicial][i] >= 1) && (visitados[i] == 0)){
			dfs(i);
		}
	}

	return visitas; 	
}

int main(){
	int i, j, pos_bicho1, pos_bicho2, qtd_visitados, maior = 0;
	char nome[31], bicho1[31], bicho2[31];

	map<string, int> criaturas;

	while(1){
		visitas = 0;
		maior = 0;
		scanf(" %d %d", &C, &R);

		if((C == 0) && (R == 0))
			break;

		for(i = 0; i < C; i++){
			for(j = 0; j < C; j++)
				grafo_criatura[i][j] = 0;
			visitados[i] = 0;
		}

		// lendo o nome das criaturas e mapeando com um numero
		for(i = 0; i < C; i++){
			scanf(" %s", nome);
			criaturas[string(nome)] = i;
		}

		for(i = 0; i < R; i++){
			scanf(" %s", bicho1);
			pos_bicho1 = criaturas[bicho1];
			scanf(" %s", bicho2);
			pos_bicho2 = criaturas[bicho2];

			grafo_criatura[pos_bicho1][pos_bicho2]++;
			grafo_criatura[pos_bicho2][pos_bicho1]++;
		}

		for(i = 0; i < C; i++){
			if(visitados[i] == 0){

				visitas = 0;
				qtd_visitados = dfs(i);
				if(qtd_visitados > maior)
					maior = qtd_visitados;
			}
		}
		
		printf("%d\n", maior);
	}
	return 0;
}