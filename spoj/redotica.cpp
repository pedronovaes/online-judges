// Pedro Marcelino Mendes Novaes Melo
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct grafos {
    int u;
    int v;
    int custo;
};

grafos g;
vector<grafos> grafo;

const int MAX_N = 101;
int N, M;
int findd[MAX_N];

bool comparar_custos(const grafos &aresta1, const grafos &aresta2);
void kruskal();

int main(int argc, char const *argv[]) {
    int i, teste = 0;

    while (1) {
        teste++;
        scanf(" %d %d", &N, &M);

        if ((N == 0) && (M == 0))
            break;

        for (i = 0; i < N; i++) {
            findd[i] = 0;
        }

        for (i = 0; i < M; i++) {
            scanf(" %d %d %d", &g.u, &g.v, &g.custo);
            grafo.push_back(g);
            findd[g.u] = g.u;
            findd[g.v] = g.v;
        }

        printf("Teste %d\n", teste);
        sort(grafo.begin(), grafo.end(), comparar_custos);
        kruskal();
        printf("\n");
        grafo.clear();

    }
    return 0;
}

bool comparar_custos(const grafos &aresta1, const grafos &aresta2) {
    return aresta1.custo < aresta2.custo;
}

void kruskal() {
    int i, j;

    for (i = 0; i < grafo.size(); ++i) {
        if (findd[grafo[i].u] != findd[grafo[i].v]) {
            int x = findd[grafo[i].u];

            if (grafo[i].u < grafo[i].v)
                printf("%d %d\n", grafo[i].u, grafo[i].v);
            else
                printf("%d %d\n", grafo[i].v, grafo[i].u);

            for (j = 1; j <= N; j++) {
                if (findd[j] == x)
                    findd[j] = findd[grafo[i].v];
            }
        }
    }
}
