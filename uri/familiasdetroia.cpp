// Pedro Marcelino Mendes Novaes Melo
#include <cstdio>
#include <vector>

using namespace std;

int N, M;
const int MAX = 100000;

vector<int> grafo[MAX];
int visitados[MAX];

int dfs();
void dfs_visit(int u);

int main() {
    int i, j, x, y, familias;

    scanf(" %d %d", &N, &M);

    for (i = 0; i < N; i++) {
        grafo[i].clear();
        visitados[i] = 0;
    }

    for (i = 0; i < M; i++) {
        scanf(" %d %d", &x, &y);
        grafo[x - 1].push_back(y - 1);
        grafo[y - 1].push_back(x - 1);
    }

    familias = dfs();
    printf("%d\n", familias);

    return 0;
}

int dfs() {
    int i, familia = 0;

    for (i = 0; i < N; i++) {
        if (visitados[i] == 0) {
            dfs_visit(i);
            familia++;
        }
    }

    return familia;
}

void dfs_visit(int u) {
    visitados[u] = 1;

    for (vector<int>::iterator i = grafo[u].begin(); i != grafo[u].end(); i++) {
        int v = *i;
        if (visitados[v] == 0)
            dfs_visit(v);
    }
}
