#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = c;
    }
}
char pop() {
    if (top == -1) {
        return '\0';
    } else {
        return stack[top--];
    }
}


char peek() {
    if (top == -1) {
        return '\0';
    } else {
        return stack[top];
    }
}


int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}


int isRightAssociative(char op) {
    return op == '^';
}

int isOperand(char c) {
    if ((c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9'))
        return 1;
    return 0;
}
 
void infixToPostfix(char* infix, char* postfix) {
    int i, j = 0;
    char c;

    for (i = 0; infix[i] != '\0'; i++) {
        c = infix[i];

    
        if (isOperand(c)) {
            postfix[j++] = c;
        }
        
        else if (c == '(') {
            push(c);
        }
       
        else if (c == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); 
        }
       
        else {
            while (top != -1 &&
                   ((precedence(peek()) > precedence(c)) ||
                   (precedence(peek()) == precedence(c) && !isRightAssociative(c))) &&
                   peek() != '(') {
                postfix[j++] = pop();
            }
            push(c);
        }
    }

    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
