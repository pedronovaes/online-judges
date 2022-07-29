// Pedro Marcelino Mendes Novaes Melo
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct grafos {
    int u;
    int v;
    int custo;
};

const int MAX_N = 100000;
int N, M, total = 0;
grafos g;
vector<grafos> grafo;

bool comparar_custos_min(const grafos &aresta1, const grafos &aresta2);
bool comparar_custos_max(const grafos &aresta1, const grafos &aresta2);
int kruskal(int *findd);

int main(int argc, char const *argv[]) {
    int i, j;
    int findd_min[MAX_N], findd_max[MAX_N];

    while (1) {
        scanf(" %d %d", &N, &M);

        if (N == 0)
            break;

        grafo.clear();
        for (i = 0; i < N; i++) {
            findd_min[i] = 0;
            findd_max[i] = 0;
        }

        for (i = 0; i < M; i++) {
            scanf(" %d %d %d", &g.u, &g.v, &g.custo);
            grafo.push_back(g);
            findd_min[g.u] = g.u;
            findd_min[g.v] = g.v;
            findd_max[g.u] = g.u;
            findd_max[g.v] = g.v;
        }

        // 1 for min and 2 for max
        sort(grafo.begin(), grafo.end(), comparar_custos_min);
        int min_ = kruskal(findd_min);
        total = 0;
        sort(grafo.begin(), grafo.end(), comparar_custos_max);
        int max_ = kruskal(findd_max);
        total = 0;
        printf("%d\n", max_ - min_);
    }

    return 0;
}

bool comparar_custos_min(const grafos &aresta1, const grafos &aresta2) {
    return aresta1.custo < aresta2.custo;
}

bool comparar_custos_max(const grafos &aresta1, const grafos &aresta2) {
    return aresta1.custo > aresta2.custo;
}

int kruskal(int *findd) {
    int i, j;

    for (i = 0; i < grafo.size(); i++) {
        if (findd[grafo[i].u] != findd[grafo[i].v]) {
            int x = findd[grafo[i].u];
            total += grafo[i].custo;
            for (j = 1; j <= N; j++) {
                if (findd[j] == x) {
                    findd[j] = findd[grafo[i].v];
                }
            }
        }
    }

    return total;
}
