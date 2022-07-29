// Pedro Marcelino Mendes Novaes Melo
#include <stdio.h>

int E, L, visitas = 0;

int dfs(int grafo[][E], int visitados[], int pos_inicial);

int main(){
	int i, j, x, y, qtd_visitados, teste = 0;

	while(1){
		teste++;
		visitas = 0;
		scanf(" %d %d", &E, &L);

		if((E == 0) && (L == 0))
			break;
		if((E < 3) || (E > 100))
			if((L < (E - 1)) || (L > (E * (E - 1)/2)))
				break;

		int matriz_adj[E][E];
		int visitados[E];
		for(i = 0; i < E; i++){
			for(j = 0; j < E; j++)
				matriz_adj[i][j] = 0;
			visitados[i] = 0;
		}

		for(i = 0; i < L; i++){
			scanf(" %d %d", &x, &y);
			matriz_adj[x - 1][y - 1]++;
			matriz_adj[y - 1][x - 1]++;
		}

		qtd_visitados = dfs(matriz_adj, visitados, 0);

		printf("Teste %d\n", teste);
		if(qtd_visitados == E){
			printf("normal\n\n");
		}else{
			printf("falha\n\n");
		}
	}
}

int dfs(int grafo[][E], int visitados[], int pos_inicial){
	int i;

	visitados[pos_inicial] = 1;
	visitas++;

	for(i = 0; i < E; i++){
		if((grafo[pos_inicial][i] == 1) && (visitados[i] == 0)){
			dfs(grafo, visitados, i);
		}
	}

	return visitas; 	
}