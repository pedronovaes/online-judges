// Pedro Marcelino Mendes Novaes Melo
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int a, b, c;
    int x, y, z;

    scanf(" %d %d %d", &a, &b, &c);
    scanf(" %d %d %d", &x, &y, &z);

    printf("%d\n", (x/a) * (y/b) * (z/c));
    return 0;
}
