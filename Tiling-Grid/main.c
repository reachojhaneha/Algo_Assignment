#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double FA(int n) {
    if(n == 2)
        return 2.0;
    return FA(n-1) * 4 + 3;
}

double FB(int n) {
    if(n == 2)
        return 3.0;
    return FB(n-1) * 4 - 4.5;
}

double FC(int n) {
    if(n == 2)
        return 1.5;
    return FC(n-1) * 4;
}

double FD(int n) {
    if(n == 2)
        return 1.0;
    return FD(n-1) * 4 + 3;
}

int main(int argc, char** argv) {
    int k = 3;
    if(argc > 1)
        k = atoi(argv[1]);
    if(k < 2) {
        printf("Please enter k > 2\n");
        exit(0);
    }
    double a = FA(k);
    double b = FB(k);
    double c = FC(k);
    double d = FD(k);
    double area = pow(2, 2*k-1);

    printf("Total Squares covered by each tiles\n");
    printf(" A = %.1lf tiles (%.3lf%%)\n", a, a * 100 / area);
    printf(" B = %.1lf tiles (%.3lf%%)\n", b, b * 100 / area);
    printf(" C = %.1lf tiles (%.3lf%%)\n", c, c * 100 / area);
    printf(" D = %.1lf tiles (%.3lf%%)\n", d, d * 100 / area);
    printf(" Empty = 0.5 tiles (%.3lf%%)\n", 0.5 * 100 / area);
    printf("Total Grid = %.1lf tiles\n", a + b + c + d + 0.5);

    return 0;
}
