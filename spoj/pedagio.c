// Pedro Marcelino Mendes Novaes Melo
#include <stdio.h>

#define TAM 51

// C = numero de cidades (vertices), E = numero de estradas (arestas)
// L = cidade atual, P = numero maximo de pedagios a pagar
int C, E, L, P, ini, fim, fila[TAM];

void iniciar_fila();
void limpar_fila();
void enfileira(int numero);
int desenfileira();
void bfs(int grafo[][C], int visitados[], int custos[], int inicio);

int main(){
	int i, j, X, Y, num_teste = 0;

	while(1){
		num_teste++;
		scanf(" %d %d %d %d", &C, &E, &L, &P);

		if((C == 0) && (E == 0) && (L == 0) && (P == 0))
			break;

		int visitados[C];
		int grafo[C][C];
		int custos[C];

		for(i = 0; i < C; i++){
			for(j = 0; j < C; j++)
				grafo[i][j] = 0;
			custos[i] = -1;
		}

		for(i = 0; i < E; i++){
			scanf(" %d %d", &X, &Y);
			grafo[X - 1][Y - 1] = 1;
			grafo[Y - 1][X - 1] = 1;
		}
		//printf("num pedagio: %d\n", P);
		printf("Teste %d\n", num_teste);
		bfs(grafo, visitados, custos, (L - 1));
		for(i = 0; i < C; i++){
			if(i != (L - 1)){
				if((custos[i] <= P) && (custos[i] > 0))
					printf("%d ", (i + 1));
			}
		}
		printf("\n\n");
	}
	return 0;
}

void iniciar_fila(){
	ini = 0;
	fim = 0;
}

void limpar_fila(){
	int i;
	for(i = 0; i < TAM; i++)
		fila[i] = -1;
}

void enfileira(int numero){
	fila[fim++] = numero;
}

int desenfileira(){
	return fila[ini++];
}

void bfs(int grafo[][C], int visitados[], int custos[], int inicio){
	int i, u, custo = 0;

	iniciar_fila();

	for(i = 0; i < C; i++)
		visitados[i] = 0;

	visitados[inicio] = 1;
	custos[inicio] = custo++;
	enfileira(inicio);
	
	while(ini != fim){
		u = desenfileira();
		for(i = 0; i < C; i++){
			if((grafo[u][i] == 1) && (visitados[i] == 0)){
				visitados[i] = 1;
				custos[i] = custo;
				enfileira(i);
			}
		}
		if(!(custos[fila[ini]] == (custo - 1)))
			custo++;
	}

	limpar_fila();

	/*for(i = 0; i < C; i++)
		printf("[%d:%d] ", (i + 1), visitados[i]);
	printf("\n");*/
}