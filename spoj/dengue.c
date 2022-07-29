// Pedro Marcelino Mendes Novaes Melo
#include <stdio.h>

#define TAM 101

// N = numero de vilas no pais (vertices)
int N, ini, fim, fila[TAM];

void iniciar_fila();
void limpar_fila();
void enfileira(int numero);
int desenfileira();
int bfs(int grafo[][N], int visitados[], int inicio);

int main(){
	int i, j, X, Y, num_teste = 0, dist, menor_distancia = 1000, v;

	while(1){
		num_teste++;
		scanf(" %d", &N);

		if(N == 1){
			printf("Teste %d\n", num_teste);
			printf("1\n");
			continue;
		}

		if(N == 0)
			break;

		int grafo[N][N];
		int visitados[N];

			for(i = 0; i < N; i++){
			for(j = 0; j < N; j++)
				grafo[i][j] = 0;	
		}

		for(i = 0; i < (N - 1); i++){
			scanf(" %d %d", &X, &Y);
			grafo[X - 1][Y - 1] = 1;
			grafo[Y - 1][X - 1] = 1;
		}
		
		printf("Teste %d\n", num_teste);
		for(i = 0; i < N; i++){
			dist = bfs(grafo, visitados, i);
			if(dist < menor_distancia){
				menor_distancia = dist;
				v = (i + 1);
			}
		}

		printf("%d\n", v);
		printf("\n");
		menor_distancia = 1000;
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

int bfs(int grafo[][N], int visitados[], int inicio){
	int i, u, distancia[N], maior_distancia = 0;

	iniciar_fila();

	for(i = 0; i < N; i++){
		visitados[i] = 0;
		distancia[i] = 0;
	}

	visitados[inicio] = 1;
	distancia[inicio] = 0;

	enfileira(inicio);

	while(ini != fim){
		u = desenfileira();
		for(i = 0; i < N; i++){
			if((grafo[u][i] == 1) && visitados[i] == 0){
				visitados[i] = 1;
				distancia[i] = distancia[u] + 1;
				enfileira(i);
			}
		}
	}

	for(i = 0; i < N; i++){
		if(distancia[i] > maior_distancia)
			maior_distancia = distancia[i];
	}

	//limpar_fila();

	return (maior_distancia);

}