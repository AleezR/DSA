#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int pow;
    struct Node* next;
};

struct Node* createNode(int coeff, int pow) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

void insertTerm(struct Node** poly, int coeff, int pow) {
    struct Node* newNode = createNode(coeff, pow);

    if (*poly == NULL) {
        *poly = newNode;
    } else {
        struct Node* temp = *poly;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

struct Node* addPolynomials(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;
    struct Node* ptr1 = p1;
    struct Node* ptr2 = p2;

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->pow > ptr2->pow) {
            insertTerm(&result, ptr1->coeff, ptr1->pow);
            ptr1 = ptr1->next;
        } else if (ptr1->pow < ptr2->pow) {
            insertTerm(&result, ptr2->coeff, ptr2->pow);
            ptr2 = ptr2->next;
        } else {
            int sum = ptr1->coeff + ptr2->coeff;
            if (sum != 0) {
                insertTerm(&result, sum, ptr1->pow);
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }

    while (ptr1 != NULL) {
        insertTerm(&result, ptr1->coeff, ptr1->pow);
        ptr1 = ptr1->next;
    }

    while (ptr2 != NULL) {
        insertTerm(&result, ptr2->coeff, ptr2->pow);
        ptr2 = ptr2->next;
    }

    return result;
}
void displayPolynomial(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->pow);
        poly = poly->next;
        if (poly != NULL)
            printf(" + ");
    }
    printf("\n");
}

int main() {
    struct Node* p1 = NULL;
    struct Node* p2 = NULL;
    struct Node* result = NULL;

    int n, coeff, pow;

    printf("Enter number of terms in Polynomial 1: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and power for term %d: ", i + 1);
        scanf("%d %d", &coeff, &pow);
        insertTerm(&p1, coeff, pow);
    }

    printf("\nEnter number of terms in Polynomial 2: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and power for term %d: ", i + 1);
        scanf("%d %d", &coeff, &pow);
        insertTerm(&p2, coeff, pow);
    }

    printf("\nPolynomial 1: ");
    displayPolynomial(p1);
    printf("Polynomial 2: ");
    displayPolynomial(p2);

    result = addPolynomials(p1, p2);
    printf("\nSum of Polynomials: ");
    displayPolynomial(result);

    return 0;
}

