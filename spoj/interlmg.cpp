// Pedro Marcelino Mendes Novaes Melo
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

struct grafos {
    int u;
    int v;
    double custo;
};

struct cidades {
    double x;
    double y;
};

grafos g;
vector<grafos> grafo;

cidades c;
vector<cidades> cidade;

const int MAX_N = 1001;
int N;
int findd[MAX_N];
double maior = 0.0;

double find_distance(int i, int j);
bool comparar_custos(const grafos &aresta1, const grafos &aresta2);
void kruskal();

int main(int argc, char const *argv[]) {
    int i, j;

    while (1) {
        grafo.clear();
        cidade.clear();
        maior = 0;

        scanf(" %d", &N);

        if (N == 0)
            break;

        for (i = 0; i < N; i++) {
            findd[i] = 0;
        }

        for (i = 0; i < N; i++) {
            scanf(" %lf %lf", &c.x, &c.y);
            cidade.push_back(c);
        }

        for (i = 0; i < cidade.size(); ++i) {
            g.u = i;
            findd[g.u] = g.u;
            j = i + 1;

            while (j < cidade.size()) {
                g.v = j;
                findd[g.v] = g.v;
                double custo = find_distance(i, j);
                g.custo = custo;
                grafo.push_back(g);
                j++;
            }
        }

        sort(grafo.begin(), grafo.end(), comparar_custos);
        for (i = 0; i < grafo.size(); ++i) {
            printf("[u: %d, v: %d, custo: %.4lf]\n", grafo[i].u, grafo[i].v, grafo[i].custo);
        }
        kruskal();
    }
    return 0;
}

double find_distance(int i, int j) {
    double dist = sqrt( pow(cidade[i].x - cidade[j].x, 2) + pow(cidade[i].y - cidade[j].y, 2));
    return dist;
}

bool comparar_custos(const grafos &aresta1, const grafos &aresta2) {
    return aresta1.custo < aresta2.custo;
}

void kruskal() {
    int i, j;

    for (i = 0; i < grafo.size(); ++i) {
        if (findd[grafo[i].u] != findd[grafo[i].v]) {
            int x = findd[grafo[i].u];
            int y = findd[grafo[i].v];

            for (j = 0; j < N; j++) {
                if (findd[j] == y)
                    findd[j] = x;
            }

            if (grafo[i].custo > maior)
                maior = grafo[i].custo;
        }
    }
    printf("%.4lf\n", maior);
}
