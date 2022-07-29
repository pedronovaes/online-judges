// Pedro Marcelino Mendes Novaes Melo
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 99999

int n, m, c, k;
int g[1010][1010];
int w[1010];
queue<int> fila;

void max();
int dijkstra(int orgn, int dest);

int main (){
	int s, d;

	while (1) {
		scanf("%d %d", &n, &m);
		if ((n == 0) & (m == 0))
			return 0;

		max();

		for (int i = 0; i < m; i++) {
			int u, v, p;
			scanf("%d %d %d", &u, &v, &p);
			g[u - 1][v - 1] = p;
		}

		scanf(" %d %d", &s, &d);
		int resultado = dijkstra(s - 1, d - 1);

		if (resultado != INF) {
			printf("%d\n", resultado);
		}
		else
			printf("-1\n");
	}
	return 0;
}

void max(){
	int i, j;

	for (i = 0; i <= n; i++){
		w[i]= INF;
		for (j = 0; j <= n; j++)
			g[i][j] = INF;
	}
}

int dijkstra(int orgn, int dest){
	w[orgn] = 0;
	fila.push(orgn);

	while (!fila.empty()) {
		int i = fila.front();
		fila.pop();
		for (int j = 0; j < n; j++) {
			if (g[i][j] != INF && w[j] > w[i] + g[i][j]){
				w[j] = w[i] + g[i][j];
				fila.push(j);
			}
		}
	}
	return w[dest];
}
