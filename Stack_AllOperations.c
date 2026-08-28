/*
============================================================
  STACK ALL OPERATIONS — AKTU UNIT 2
  Simple Teaching Version
============================================================

WHAT IS A STACK?
  A Stack is a data structure that follows LIFO principle.
  LIFO = Last In, First Out

  Think of it like a stack of plates:
  - You ADD (push) a plate on TOP
  - You REMOVE (pop) the plate from TOP
  - You can only see the TOP plate
  - You cannot access plates in the middle directly

  Visual:
    [  30  ]  <-- TOP (last added, first removed)
    [  20  ]
    [  10  ]

============================================================
  TWO WAYS TO IMPLEMENT A STACK:
  
  1. Using ARRAY  (fixed size, simple)
  2. Using LINKED LIST (dynamic size, no overflow)
============================================================
*/

#include <stdio.h>
#include <stdlib.h>

/* ==========================================================
   PART 1: STACK USING ARRAY
   ========================================================== */
#define MAX_SIZE 5

// PUSH — Add element to top of stack
void push(int stack[], int *top, int value) {
    if (*top == MAX_SIZE - 1) {
        printf("  [OVERFLOW] Cannot push %d — Stack is full!\n", value);
        return;
    }
    (*top)++;
    stack[*top] = value;
    printf("  Pushed %d -> stack[%d]\n", value, *top);
}

// POP — Remove and return the top element
int pop(int stack[], int *top) {
    if (*top == -1) {
        printf("  [UNDERFLOW] Cannot pop — Stack is empty!\n");
        return -1;
    }
    int value = stack[*top];
    (*top)--;
    printf("  Popped %d <- stack[%d]\n", value, *top + 1);
    return value;
}

// DISPLAY — Show all elements by traversing
void display(int stack[], int top) {
    if (top == -1) {
        printf("  Stack: [] (empty)\n");
        return;
    }
    printf("  Stack: [");
    for (int i = 0; i <= top; i++) {
        printf("%d", stack[i]);
        if (i < top) printf(", ");
    }
    printf("]\n");
    printf("  Top -> %d\n", stack[top]);
}

/* ==========================================================
   DEMO: Array Stack
   ========================================================== */
void demoArrayStack() {
    int stack[MAX_SIZE];
    int top = -1;

    printf("\n========================================\n");
    printf("  PART 1: STACK USING ARRAY\n");
    printf("========================================\n\n");

    // --- PUSH ---
    printf("--- PUSH OPERATIONS ---\n\n");
    
    push(stack, &top, 10);
    push(stack, &top, 20);
    push(stack, &top, 30);
    push(stack, &top, 40);
    push(stack, &top, 50);
    
    printf("\n");
    display(stack, top);
    printf("\n");

    // --- OVERFLOW TEST ---
    printf("--- OVERFLOW TEST ---\n\n");
    push(stack, &top, 60);
    printf("\n");

    // --- POP ---
    printf("--- POP OPERATIONS ---\n\n");
    
    pop(stack, &top);
    pop(stack, &top);
    pop(stack, &top);
    
    printf("\n");
    display(stack, top);
    printf("\n");

    // --- POP ALL ---
    printf("--- POP ALL REMAINING ---\n\n");
    pop(stack, &top);
    pop(stack, &top);
    
    printf("\n");
    display(stack, top);
    printf("\n");

    // --- UNDERFLOW TEST ---
    printf("--- UNDERFLOW TEST ---\n\n");
    pop(stack, &top);
    printf("\n");
}

/* ==========================================================
   PART 2: STACK USING LINKED LIST
   ========================================================== */

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// PUSH — Add a new node at the beginning
void pushLL(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if (newNode == NULL) {
        printf("  [OVERFLOW] Memory allocation failed!\n");
        return;
    }
    
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
    
    printf("  Pushed %d\n", value);
}

// POP — Remove the top node
int popLL(struct Node** top) {
    if (*top == NULL) {
        printf("  [UNDERFLOW] Stack is empty!\n");
        return -1;
    }
    
    struct Node* temp = *top;
    int value = temp->data;
    *top = (*top)->next;
    free(temp);
    
    printf("  Popped %d\n", value);
    return value;
}

// DISPLAY — Show all nodes by traversing
void displayLL(struct Node* top) {
    if (top == NULL) {
        printf("  Stack: NULL (empty)\n");
        return;
    }
    
    printf("  Stack: ");
    struct Node* current = top;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL)
            printf(" -> ");
        current = current->next;
    }
    printf(" -> NULL\n");
}

/* ==========================================================
   DEMO: Linked List Stack
   ========================================================== */
void demoLLStack() {
    struct Node* top = NULL;

    printf("\n========================================\n");
    printf("  PART 2: STACK USING LINKED LIST\n");
    printf("========================================\n\n");

    // --- PUSH ---
    printf("--- PUSH OPERATIONS ---\n\n");
    
    pushLL(&top, 10);
    displayLL(top);
    
    pushLL(&top, 20);
    displayLL(top);
    
    pushLL(&top, 30);
    displayLL(top);
    
    printf("\n");

    // --- POP ---
    printf("--- POP OPERATIONS ---\n\n");
    
    popLL(&top);
    displayLL(top);
    
    popLL(&top);
    displayLL(top);
    
    popLL(&top);
    displayLL(top);
    printf("\n");
}

/* ==========================================================
   MAIN
   ========================================================== */
int main() {
    printf("\n");
    printf("============================================\n");
    printf("    STACK ALL OPERATIONS — AKTU UNIT 2\n");
    printf("============================================\n");

    demoArrayStack();
    demoLLStack();

    // --- SUMMARY ---
    printf("============================================\n");
    printf("  SUMMARY OF STACK OPERATIONS\n");
    printf("============================================\n\n");
    printf("  OPERATION     WHAT IT DOES              TIME\n");
    printf("  ---------     ----------                ----\n");
    printf("  PUSH          Add element to top        O(1)\n");
    printf("  POP           Remove top element        O(1)\n");
    printf("  display       Show all elements         O(n)\n\n");

    printf("  KEY CONCEPTS:\n");
    printf("  - Stack follows LIFO (Last In, First Out)\n");
    printf("  - Array stack has FIXED size (overflow possible)\n");
    printf("  - Linked list stack has DYNAMIC size (no overflow)\n");
    printf("  - All basic operations are O(1) — very fast!\n\n");

    return 0;
}

/*
============================================================
COMPILATION:
  gcc Stack_AllOperations.c -o Stack_AllOperations.exe

RUN:
  Stack_AllOperations.exe
============================================================
*/
