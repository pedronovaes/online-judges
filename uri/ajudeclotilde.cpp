// Pedro Marcelino Mendes Novaes Melo
#include <cstdio>
#include <queue>

using namespace std;

const int MAX = 1000000;
queue<int> fila;
int visitados[MAX], distancia[MAX];
int o, d, k;

void bfs(int origem);
void adjacentes(int u);

int main(int argc, char const *argv[]) {
    int i, canal_proibido;

    while (1) {
        scanf(" %d %d %d", &o, &d, &k);

        if (o == 0)
            break;

        fila = queue<int>();
        for (i = 0; i < MAX; i++) {
            visitados[i] = 0;
            distancia[i] = -1;
        }

        for (i = 0; i < k; i++) {
            scanf(" %d", &canal_proibido);
            visitados[canal_proibido] = 1;
        }

        bfs(o);
    }
    return 0;
}

void bfs(int origem) {
    visitados[origem] = 1;
    distancia[origem] = 0;
    fila.push(origem);

    while (!fila.empty()) {
        int u = fila.front();
        fila.pop();

        if (distancia[d] != -1)
            break;

        adjacentes(u);
    }

    printf("%d\n", distancia[d]);
}

void adjacentes(int u) {
    int canal;

    // botao -1
    canal = u - 1;
    if(!visitados[canal] && canal > 0){
        visitados[canal] = 1;
        distancia[canal] = distancia[u] + 1;
        fila.push(canal);
    }

    // botao +1
    canal = u + 1;
    if(!visitados[canal] && canal <= 100000){
        visitados[canal] = 1;
        distancia[canal] = distancia[u] + 1;
        fila.push(canal);
    }

    // botao /2
    canal = u / 2;
    if(u % 2 == 0 && !visitados[canal]){
        visitados[canal] = 1;
        distancia[canal] = distancia[u] + 1;
        fila.push(canal);
    }

    // botao *2
    canal = u * 2;
    if(canal <= 100000 && !visitados[canal]){
        visitados[canal] = 1;
        distancia[canal] = distancia[u] + 1;
        fila.push(canal);
    }

    // botao *3
    canal = u * 3;
    if(canal <= 100000 && !visitados[canal]){
        visitados[canal] = 1;
        distancia[canal] = distancia[u] + 1;
        fila.push(canal);
    }
}
