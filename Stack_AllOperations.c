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
  - You can only see (peek) the TOP plate
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
   ==========================================================
   
   HOW IT WORKS:
   - We use a simple array: int stack[5]
   - We use a variable 'top' to track where the top element is
   - top = -1 means stack is empty
   - top = 4 means stack is full (for size 5)
   
   Visual:
   Index:  [0]  [1]  [2]  [3]  [4]
   Value:  10   20   30    -    -
   Top:                     ^--- top = 2
   ========================================================== */

// Step 1: Define the maximum size of our stack
#define MAX_SIZE 5

// Step 2: Function to check if stack is empty
// When top = -1, no elements are in the stack
int isEmpty(int top) {
    return (top == -1);  // returns 1 (true) if empty, 0 (false) if not
}

// Step 3: Function to check if stack is full
// When top = MAX_SIZE - 1, stack cannot accept more elements
int isFull(int top) {
    return (top == MAX_SIZE - 1);  // returns 1 if full, 0 if not
}

// Step 4: PUSH — Add element to top of stack
// 
// HOW PUSH WORKS:
//   Before: top = 1, stack = [10, 20, _, _, _]
//   Push 30:
//     1. Increment top: top = 2
//     2. Place 30 at stack[2]
//   After:  top = 2, stack = [10, 20, 30, _, _]
//
void push(int stack[], int *top, int value) {
    if (isFull(*top)) {
        printf("  [OVERFLOW] Cannot push %d — Stack is full!\n", value);
        return;
    }
    (*top)++;
    stack[*top] = value;
    printf("  Pushed %d -> stack[%d]\n", value, *top);
}

// Step 5: POP — Remove and return the top element
//
// HOW POP WORKS:
//   Before: top = 2, stack = [10, 20, 30, _, _]
//   Pop:
//     1. Save the value at stack[2] = 30
//     2. Move top down by 1: top = 1
//     3. Return the saved value (30)
//   After:  top = 1, stack = [10, 20, _, _, _]
//
int pop(int stack[], int *top) {
    if (isEmpty(*top)) {
        printf("  [UNDERFLOW] Cannot pop — Stack is empty!\n");
        return -1;
    }
    int value = stack[*top];
    (*top)--;
    printf("  Popped %d <- stack[%d]\n", value, *top + 1);
    return value;
}

// Step 6: PEEK — Look at the top element without removing it
int peek(int stack[], int top) {
    if (isEmpty(top)) {
        printf("  [EMPTY] Stack is empty!\n");
        return -1;
    }
    return stack[top];
}

// Step 7: DISPLAY — Show all elements
//
// HOW DISPLAY WORKS:
//   Start from index 0, go up to top
//   Print each element
//
void display(int stack[], int top) {
    if (isEmpty(top)) {
        printf("  Stack is empty: []\n");
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

// Step 8: SIZE — Count how many elements are in the stack
int size(int top) {
    return top + 1;
}

/* ==========================================================
   DEMO: Test all Array Stack operations
   ========================================================== */
void demoArrayStack() {
    int stack[MAX_SIZE];
    int top = -1;

    printf("\n========================================\n");
    printf("  PART 1: STACK USING ARRAY\n");
    printf("========================================\n\n");

    // --- PUSH 5 ELEMENTS ---
    printf("--- PUSH OPERATIONS ---\n");
    printf("  (Adding elements to the top of stack)\n\n");
    
    push(stack, &top, 10);
    push(stack, &top, 20);
    push(stack, &top, 30);
    push(stack, &top, 40);
    push(stack, &top, 50);
    
    printf("\n");
    display(stack, top);
    printf("\n");

    // --- TRY PUSHING WHEN FULL ---
    printf("--- OVERFLOW TEST ---\n\n");
    push(stack, &top, 60);
    printf("\n");

    // --- PEEK ---
    printf("--- PEEK OPERATION ---\n\n");
    printf("  Top element = %d\n", peek(stack, top));
    display(stack, top);
    printf("\n");

    // --- POP 3 ELEMENTS ---
    printf("--- POP OPERATIONS ---\n\n");
    
    pop(stack, &top);
    pop(stack, &top);
    pop(stack, &top);
    
    printf("\n");
    display(stack, top);
    printf("  Size = %d\n", size(top));
    printf("\n");

    // --- POP ALL REMAINING ---
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
   ==========================================================
   
   HOW IT WORKS:
   - Each element is a NODE containing data + pointer to next
   - TOP points to the first node
   - No fixed size — can grow as much as memory allows
   - No overflow (unless memory runs out)
   
   Visual:
   TOP -> [30|*] -> [20|*] -> [10|*] -> NULL
   
   Each node has:
   - data: the value stored
   - next: pointer to the next node
   ========================================================== */

// Step 1: Define the Node structure
struct Node {
    int data;           // The value stored in this node
    struct Node* next;  // Pointer to the next node
};

// Step 2: PUSH — Add a new node at the beginning
//
// HOW PUSH WORKS:
//   Before: TOP -> [20] -> [10] -> NULL
//   Push 30:
//     1. Create new node with data = 30
//     2. New node's next = current top (20)
//     3. Update top to point to new node
//   After:  TOP -> [30] -> [20] -> [10] -> NULL
//
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

// Step 3: POP — Remove the top node
//
// HOW POP WORKS:
//   Before: TOP -> [30] -> [20] -> [10] -> NULL
//   Pop:
//     1. Save the data from top node (30)
//     2. Move top to next node (20)
//     3. Free the old top node's memory
//   After:  TOP -> [20] -> [10] -> NULL
//
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

// Step 4: DISPLAY — Show all nodes by traversing
//
// HOW DISPLAY WORKS:
//   Start at top, follow 'next' pointers until NULL
//   This TRAVERSES the entire stack and prints each element
//
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
   DEMO: Test all Linked List Stack operations
   ========================================================== */
void demoLLStack() {
    struct Node* top = NULL;

    printf("\n========================================\n");
    printf("  PART 2: STACK USING LINKED LIST\n");
    printf("========================================\n\n");

    // --- PUSH ELEMENTS ---
    printf("--- PUSH OPERATIONS ---\n\n");
    
    pushLL(&top, 10);
    displayLL(top);
    
    pushLL(&top, 20);
    displayLL(top);
    
    pushLL(&top, 30);
    displayLL(top);
    
    printf("\n");

    // --- POP ELEMENTS ---
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
   MAIN — Run both demos
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
    printf("  PEEK          See top element           O(1)\n");
    printf("  isEmpty       Check if stack empty      O(1)\n");
    printf("  isFull        Check if stack full       O(1)\n");
    printf("  display       Show all elements         O(n)\n");
    printf("  size          Count elements            O(1)\n\n");

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
