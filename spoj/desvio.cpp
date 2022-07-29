// Pedro Marcelino Mendes Novaes Melo
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 9999

int n, m, c, k;
int g[1010][1010];
int w[1010];
queue<int> fila;

void max();
int dijkstra(int orgn, int dest);

int main (){

	while (1) {
		scanf("%d %d %d %d", &n, &m, &c, &k);
		if ((n == 0) & (m == 0) & (c == 0) & (k == 0))
			return 0;

		max();

		for (int i = 1; i <= m; i++) {
			int u, v, p;
			scanf("%d %d %d", &u, &v, &p);
			if (u >= c && v >= c) {
				g[u][v] = p;
				g[v][u] = p;
			}
			if (u >= c && v < c)
				g[u][v] = p;
			if (u < c && v >= c)
				g[v][u] = p;
			if (u < c && v < c && abs(u-v) == 1) {
				g[u][v] = p;
				g[v][u] = p;
			}
		}
		printf("%d\n", dijkstra(k, c - 1));
	}
	return 0;
}

void max(){
	int i, j;

	for (i = 0; i <= n; i++) {
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
			if (g[i][j] != INF && w[j] > w[i] + g[i][j]) {
				w[j] = w[i] + g[i][j];
				fila.push(j);
			}
		}
	}
	return w[dest];
}
