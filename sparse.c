#include <stdio.h>

#define MAX_SIZE 10  

int main() {
    int i, j, k = 1, q = 1, m1, n1, m2, n2;

    
    printf("Enter the rows & columns for Matrix A: ");
    scanf("%d%d", &m1, &n1);

    
    printf("Enter the rows & columns for Matrix B: ");
    scanf("%d%d", &m2, &n2);

   
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE * MAX_SIZE][3];
    int C[MAX_SIZE][MAX_SIZE], D[MAX_SIZE * MAX_SIZE][3];
    int result[MAX_SIZE * MAX_SIZE][3];

    
    printf("Enter the Matrix A:\n");
    for (i = 0; i < m1; i++) {
        for (j = 0; j < n1; j++) {
            scanf("%d", &A[i][j]);
        }
    }

   
    printf("Enter the Matrix B:\n");
    for (i = 0; i < m2; i++) {
        for (j = 0; j < n2; j++) {
            scanf("%d", &C[i][j]);
        }
    }

    
    printf("The Matrix A is:\n");
    for (i = 0; i < m1; i++) {
        for (j = 0; j < n1; j++) {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }

    
    printf("The Matrix B is:\n");
    for (i = 0; i < m2; i++) {
        for (j = 0; j < n2; j++) {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }

    
    B[0][0] = m1;
    B[0][1] = n1;
    B[0][2] = 0;  
    for (i = 0; i < m1; i++) {
        for (j = 0; j < n1; j++) {
            if (A[i][j] != 0) {
                B[k][0] = i;   
                B[k][1] = j;   
                B[k][2] = A[i][j];   
                k++;
                B[0][2]++;   
            }
        }
    }

    
    D[0][0] = m2;
    D[0][1] = n2;
    D[0][2] = 0;  
    for (i = 0; i < m2; i++) {
        for (j = 0; j < n2; j++) {
            if (C[i][j] != 0) {
                D[q][0] = i;   
                D[q][1] = j;   
                D[q][2] = C[i][j];   
                q++;
                D[0][2]++;   
            }
        }
    }

   
    printf("The Sparse Matrix representation of A is:\n");
    for (i = 0; i <= B[0][2]; i++) {  
        printf("%d\t%d\t%d\n", B[i][0], B[i][1], B[i][2]);
    }

    
    printf("The Sparse Matrix representation of B is:\n");
    for (i = 0; i <= D[0][2]; i++) { 
        printf("%d\t%d\t%d\n", D[i][0], D[i][1], D[i][2]);
    }

    
    int resultIndex = 1;  
    for (i = 1; i <= B[0][2]; i++) { 
        int found = 0;
        for (j = 1; j <= D[0][2]; j++) {  
            if (B[i][0] == D[j][0] && B[i][1] == D[j][1]) { 
                result[resultIndex][0] = B[i][0];  
                result[resultIndex][1] = B[i][1];  
                result[resultIndex][2] = B[i][2] + D[j][2];  
                resultIndex++;
                found = 1;
                break;
            }
        }

        
        if (!found) {
            result[resultIndex][0] = B[i][0];
            result[resultIndex][1] = B[i][1];
            result[resultIndex][2] = B[i][2];
            resultIndex++;
        }
    }

    
    for (j = 1; j <= D[0][2]; j++) {
        int found = 0;
        for (i = 1; i <= B[0][2]; i++) {
            if (D[j][0] == B[i][0] && D[j][1] == B[i][1]) {
                found = 1;
                break;
            }
        }
       
        if (!found) {
            result[resultIndex][0] = D[j][0];
            result[resultIndex][1] = D[j][1];
            result[resultIndex][2] = D[j][2];
            resultIndex++;
        }
    }

  
    result[0][0] = m1;  
    result[0][1] = n1;  
    result[0][2] = resultIndex - 1;  

    
    printf("The Sparse Matrix representation of the addition result is:\n");
 
    for (i = 0; i <= result[0][2]; i++) {
        printf("%d\t%d\t%d\n", result[i][0], result[i][1], result[i][2]);
    }

    int transpose[MAX_SIZE * MAX_SIZE][3];
    transpose[0][0] = result[0][1];  
    transpose[0][1] = result[0][0];  
    transpose[0][2] = result[0][2];  

   
    int transposeIndex = 1;
    for (i = 1; i <= result[0][2]; i++) {
        transpose[transposeIndex][0] = result[i][1];  
        transpose[transposeIndex][1] = result[i][0];  
        transpose[transposeIndex][2] = result[i][2];  
        transposeIndex++;
    }

    
    printf("The Transpose of the Sparse Matrix is:\n");
    for (i = 1; i <= transpose[0][2]; i++) {
        printf("%d\t%d\t%d\n", transpose[i][0], transpose[i][1], transpose[i][2]);
    }


    return 0;
}
