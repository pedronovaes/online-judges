// Pedro Marcelino Mendes Novaes Melo
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct grafos {
    int u;
    int v;
    int custo;
};

const int MAX_N = 501;
int finde[MAX_N];
int N, M, total = 0;
grafos g;
vector<grafos> grafo;

bool comparar_custos(const grafos &aresta1, const grafos &aresta2);
void kruskal();

int main(int argc, char const *argv[]) {
    int i, j;

    scanf(" %d %d", &N, &M);

    for (i = 0; i < N; i++) {
        finde[i] = 0;
    }

    for (i = 0; i < M; i++) {
        scanf(" %d %d %d", &g.u, &g.v, &g.custo);
        grafo.push_back(g);
        finde[g.u] = g.u;
        finde[g.v] = g.v;
    }

    sort(grafo.begin(), grafo.end(), comparar_custos);
    kruskal();
    printf("%d\n", total);
    return 0;
}

bool comparar_custos(const grafos &aresta1, const grafos &aresta2) {
    return aresta1.custo < aresta2.custo;
}

void kruskal() {
    int i, j;

    for (i = 0; i < grafo.size(); ++i) {
        if (finde[grafo[i].u] != finde[grafo[i].v]) {
            int x = finde[grafo[i].u];
            total += grafo[i].custo;
            for (j = 1; j <= N; j++) {
                if (finde[j] == x)
                    finde[j] = finde[grafo[i].v];
            }
        }
    }
}
