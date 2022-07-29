// Pedro Marcelino Mendes Novaes Melo
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int l, d;
    int k, p;
    int custo, qtd_pegadios, gasolina;

    scanf(" %d %d", &l, &d);
    scanf(" %d %d", &k, &p);

    qtd_pegadios = l/d;
    custo = (qtd_pegadios * p) + (l * k);

    printf("%d\n", custo);
    return 0;
}
