// Pedro Marcelino Mendes Novaes Melo
#include <iostream>
#include <cstdio>

using namespace std;

const int MAX_N = 60;
int N;
int grafo[MAX_N][MAX_N];
int grau[MAX_N];

void encontra_circuito(int num);

int main(int argc, char const *argv[]) {
    int i, j, k, x, y, T, teste = 0, possivel;

    scanf(" %d", &T);
    for (k = 0; k < T; k++) {
        teste++;
        possivel = 1;
        scanf(" %d", &N);

        for (i = 0; i <= 50; i++) {
            for (j = 0; j <= 50; j++)
                grafo[i][j] = 0;
            grau[i] = 0;
        }

        for (i = 1; i <= N; i++) {
            scanf(" %d %d", &x, &y);
            grafo[x][y]++;
            grafo[y][x]++;
            grau[x]++;
            grau[y]++;
        }

        for (i = 1; i <= 50; i++) {
            if (!(grau[i] % 2) == 0) {
                possivel = 0;
                break;
            }
        }

        if (possivel == 1) {
            printf("Case #%d\n", teste);
            encontra_circuito(x);
        }
        else {
            printf("Case #%d\n", teste);
            printf("some beads may be lost\n");
        }
        printf("\n");
        possivel = 1;
    }
    return 0;
}

void encontra_circuito(int num) {
    int i;

    for (i = 1; i <= 50; i++) {
        if (grafo[num][i] > 0) {
            grafo[num][i]--;
            grafo[i][num]--;
            encontra_circuito(i);
            printf("%d %d\n", i, num);
        }
    }
}
