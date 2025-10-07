#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPRESSION_SIZE 100

typedef struct Node {
    char data;
    struct Node *left;
    struct Node *right;
} Node;


typedef struct StackNode {
    Node *tree_node;
    struct StackNode *next;
} StackNode;


StackNode *stack_top = NULL;
Node *construct_expression_tree(const char *postfix);
void print_prefix(Node *root);
void print_postfix(Node *root);
void free_tree(Node *root);

int is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

Node *create_tree_node(char data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        perror("Memory allocation failed for tree node");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void push(Node *tree_node) {
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    if (!newNode) {
        perror("Memory allocation failed for stack node");
        exit(EXIT_FAILURE);
    }
    newNode->tree_node = tree_node;
    newNode->next = stack_top;
    stack_top = newNode;
}

Node *pop() {
    if (stack_top == NULL) {
        return NULL;
    }
    StackNode *temp = stack_top;
    Node *popped_node = temp->tree_node;
    stack_top = stack_top->next;
    free(temp);
    return popped_node;
}
Node *construct_expression_tree(const char *postfix) {
   
    stack_top = NULL; 
    
    int i = 0;
    char c;
    Node *node1, *node2, *newNode;

    while ((c = postfix[i++]) != '\0') {
        if (c == ' ' || c == '\n' || c == '\r') {
            continue;
        }
        
        if (!is_operator(c)) {
            newNode = create_tree_node(c);
            push(newNode);
        } else {
            newNode = create_tree_node(c);
            node1 = pop(); 
            node2 = pop(); 

            if (!node1 || !node2) {
                fprintf(stderr, "\nError: Invalid postfix expression - insufficient operands for operator '%c'.\n", c);
              
                if(node1) free(node1);
                if(node2) free(node2);
                while (stack_top != NULL) free_tree(pop()); 
                free(newNode);
                return NULL;
            }

            newNode->right = node1;
            newNode->left = node2;
            push(newNode);
        }
    }

    Node *root = pop();
    
    if (stack_top != NULL) {
        fprintf(stderr, "\nError: Invalid postfix expression - multiple elements remaining on stack (too many operands).\n");
        while (stack_top != NULL) free_tree(pop());
        free_tree(root); 
        return NULL;
    }
    
    return root;
}
void print_prefix(Node *root) {
    if (root == NULL) return;
    printf("%c", root->data);
    print_prefix(root->left);
    print_prefix(root->right);
}

void print_postfix(Node *root) {
    if (root == NULL) return;
    print_postfix(root->left);
    print_postfix(root->right);
    printf("%c", root->data);
}

void free_tree(Node *root) {
    if (root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main() {
    char postfix_input[MAX_EXPRESSION_SIZE];
    
    printf("Please enter a simple postfix arithmetic expression:");
    
    
    if (fgets(postfix_input, MAX_EXPRESSION_SIZE, stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }
    
  
    postfix_input[strcspn(postfix_input, "\n")] = 0;

    printf("\nInput: %s", postfix_input);

   
    Node *root = construct_expression_tree(postfix_input);

    if (root != NULL) {
        printf("\nExpression Tree Traversal:\n");
        
       
        printf("Prefix Equivalent (Preorder): ");
        print_prefix(root);
        printf("\n");

       
        printf("Postfix Equivalent (Postorder): ");
        print_postfix(root);
        printf("\n");
        
     
        free_tree(root);
    } else {
        printf("\nExpression Tree construction failed. Please check your postfix expression for validity.\n");
    }

    return 0;
}
