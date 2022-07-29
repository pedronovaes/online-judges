// Pedro Marcelino Mendes Novaes Melo
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int a;
    int ano = 1986;

    scanf("%d", &a);

    while (1) {
        if (a >= ano) {
            ano += 76;
        }
        else
            break;
    }

    printf("%d\n", ano);
    return 0;
}
