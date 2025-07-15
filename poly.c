#include <stdio.h>

struct term {
    int coef;
    int exp;
};

int main() {
    struct term poly[10], poly1[10], p3[20];
    int n, m, i, j, k = 0;
    printf("Enter the number of terms in polynomial 1: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter the coefficient and exponent of term %d: ", i + 1);
        scanf("%d %d", &poly[i].coef, &poly[i].exp);
    }
    printf("Polynomial 1 is: ");
    for (i = 0; i < n; i++) {
        printf("%d x^%d", poly[i].coef, poly[i].exp);
        if (i < n - 1) printf(" + ");
    }
    printf("\n");
    printf("Enter the number of terms in polynomial 2: ");
    scanf("%d", &m);
    for (j = 0; j < m; j++) {
        printf("Enter the coefficient and exponent of term %d: ", j + 1);
        scanf("%d %d", &poly1[j].coef, &poly1[j].exp);
    }
    printf("Polynomial 2 is: ");
    for (j = 0; j < m; j++) {
        printf("%d x^%d", poly1[j].coef, poly1[j].exp);
        if (j < m - 1) printf(" + ");
    }
    printf("\n");
    i = 0; j = 0; k = 0;
    while (i < n && j < m) {
        if (poly[i].exp == poly1[j].exp) {
            p3[k].coef = poly[i].coef + poly1[j].coef;
            p3[k].exp = poly[i].exp;
            i++; j++; k++;
        } else if (poly[i].exp > poly1[j].exp) {
            p3[k] = poly[i];
            i++; k++;
        } else {
            p3[k] = poly1[j];
            j++; k++;
        }
    }
    while (i < n) {
        p3[k] = poly[i];
        i++; k++;
    }
    while (j < m) {
        p3[k] = poly1[j];
        j++; k++;
    }
    printf("The sum of the polynomials is: ");
    for (i = 0; i < k; i++) {
        printf("%d x^%d", p3[i].coef, p3[i].exp);
        if (i < k - 1) printf(" + ");
    }
    printf("\n");

    return 0;
}

