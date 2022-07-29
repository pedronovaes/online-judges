// Pedro Marcelino Mendes Novaes Melo
#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

int N, M, tempo, menor;
const int MAX_N = 100005;

vector<int> grafo[MAX_N];
vector<int> grafo_transposto[MAX_N];
stack<int> pilha;
set<int> componentes_conexas;
int visitados[MAX_N];
int d[MAX_N];
int f[MAX_N];
int saida[MAX_N];

void dfs();
void dfs_transposto();
void dfs_visit(int u);
void dfs_visit_transposto(int u);

int main() {
    int i, j, x, y;

    scanf(" %d %d", &N, &M);

    for (i = 0; i < N; i++) {
        grafo[i].clear();
        grafo_transposto[i].clear();
        visitados[i] = 0;
        d[i] = 0;
        f[i] = 0;
    }

    for (i = 0; i < M; i++) {
        scanf(" %d %d", &x, &y);
        grafo[x].push_back(y);
        grafo_transposto[y].push_back(x);
    }

    dfs();
    dfs_transposto();

    for (i = 0; i < N; i++) {
        printf("%d\n", saida[i]);
    }

    return 0;
}

void dfs() {
    int i;

    tempo = 0;

    for (i = 0; i < N; i++) {
        if (visitados[i] == 0)
            dfs_visit(i);
    }
}

void dfs_visit(int u) {
    tempo = tempo + 1;
    d[u] = tempo;
    visitados[u] = 1;

    for (std::vector<int>::iterator i = grafo[u].begin(); i != grafo[u].end(); ++i) {
        int v = *i;
        if (visitados[v] == 0)
            dfs_visit(v);
    }

    tempo = tempo + 1;
    f[u] = tempo;
    pilha.push(u);
}

void dfs_transposto() {
    int i;

    for (i = 0; i < N; i++) {
        visitados[i] = 0;
    }

    for (i = 0; i < N; i++) {
        int verts_pilha = pilha.top();
        if (visitados[verts_pilha] == 0) {
            dfs_visit_transposto(verts_pilha);

            menor = *componentes_conexas.begin();
            while (componentes_conexas.size() != 0) {
                int x = *componentes_conexas.begin();
                saida[x] = menor;
                componentes_conexas.erase(x);
            }
        }
        pilha.pop();
    }
}

void dfs_visit_transposto(int u) {
    componentes_conexas.insert(u);
    visitados[u] = 1;

    for (std::vector<int>::iterator i = grafo_transposto[u].begin(); i != grafo_transposto[u].end(); ++i) {
        int v = *i;
        if (visitados[v] == 0)
            dfs_visit_transposto(v);
    }
}
