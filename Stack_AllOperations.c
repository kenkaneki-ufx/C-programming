/*
============================================================
Stack All Operations — AKTU Unit 2
============================================================

PROBLEM NAME:
Complete Stack Implementation with All Operations & Applications

------------------------------------------------------------
GOAL:
Write a C program that implements Stack using both Array and 
Linked List methods, and demonstrates stack applications 
as per AKTU Data Structures Unit 2 syllabus.

------------------------------------------------------------
AKTU UNIT 2 TOPICS COVERED:

PART A — Stack using Array:
  1. Push operation
  2. Pop operation
  3. Peek / Top element
  4. isEmpty check
  5. isFull check
  6. Display / Traverse
  7. Size of stack

PART B — Stack using Linked List:
  1. Push operation
  2. Pop operation
  3. Peek / Top element
  4. isEmpty check
  5. Display / Traverse

PART C — Stack Applications:
  1. Infix to Postfix Conversion
  2. Postfix Expression Evaluation
  3. Parenthesis Matching
  4. Tower of Hanoi (Recursive — demonstrates stack in recursion)

------------------------------------------------------------
REQUIREMENTS:

1. Define structures for:
   - Array-based stack (int array + top index)
   - Linked list node (data + next pointer)
   - Linked list stack (top pointer)

2. Array Stack Functions:
   - void pushArray(int stack[], int *top, int maxSize, int value)
   - int popArray(int stack[], int *top)
   - int peekArray(int stack[], int top)
   - int isEmptyArray(int top)
   - int isFullArray(int top, int maxSize)
   - void displayArray(int stack[], int top)
   - int sizeArray(int top)

3. Linked List Stack Functions:
   - void pushLL(struct LLNode** top, int value)
   - int popLL(struct LLNode** top)
   - int peekLL(struct LLNode* top)
   - int isEmptyLL(struct LLNode* top)
   - void displayLL(struct LLNode* top)

4. Application Functions:
   - int precedence(char op)
   - void infixToPostfix(char infix[], char postfix[])
   - int evaluatePostfix(char postfix[])
   - int parenthesesMatch(char expression[])
   - void towerOfHanoi(int n, char from, char to, char aux)

5. Menu-driven main() to demonstrate all operations

------------------------------------------------------------
RULES:

- Use proper error handling (stack overflow/underflow)
- Free all dynamically allocated memory
- Validate user input
- Handle edge cases (empty stack, single element)
- Use clear output formatting with labels

------------------------------------------------------------
CONSTRAINTS:

- Maximum stack size: 100 for array implementation
- Expressions up to 200 characters
- Operands: single-digit numbers (0-9) for postfix evaluation
- Operators: +, -, *, /, ^

------------------------------------------------------------
CONCEPTS PRACTICED:

- Stack data structure (LIFO principle)
- Array implementation of stack
- Linked list implementation of stack
- Push and Pop operations
- Peek / Top operation
- Overflow and Underflow conditions
- Infix to Postfix conversion (Shunting Yard Algorithm)
- Postfix expression evaluation using stack
- Parenthesis matching using stack
- Operator precedence and associativity
- Dynamic memory allocation for linked list stack
- Recursion and system call stack (Tower of Hanoi)
- Menu-driven program design

------------------------------------------------------------
DIFFICULTY: 7/10

------------------------------------------------------------
ALGORITHM NOTES:

1. PUSH (Array): Increment top, store element at stack[top]
2. POP (Array): Return stack[top], decrement top
3. PUSH (LL): Create node, point new node's next to top, update top
4. POP (LL): Store top's data, move top to next, free old top
5. INFIX TO POSTFIX: 
   - If operand, add to postfix
   - If '(', push to operator stack
   - If ')', pop and add to postfix until '('
   - If operator, pop higher/equal precedence operators first
6. POSTFIX EVALUATION:
   - If operand, push to number stack
   - If operator, pop two operands, apply operator, push result
7. PARENTHESIS MATCHING:
   - If opening bracket, push to stack
   - If closing bracket, check if top matches
8. TOWER OF HANOI:
   - Move n-1 disks from source to auxiliary
   - Move nth disk from source to destination
   - Move n-1 disks from auxiliary to destination

------------------------------------------------------------
FILENAME SUGGESTION:
Stack_AllOperations.c

COMMIT MESSAGE:
"Add complete stack implementation with array, linked list, and applications"

============================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* ==========================================================
   HELPER FUNCTION — Clear input buffer after scanf
   ========================================================== */
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* ==========================================================
   STRUCTURE DEFINITIONS
   ========================================================== */

// Node for Linked List based Stack
struct LLNode {
    int data;
    struct LLNode* next;
};

// Structure for Operator Stack (used in infix to postfix)
struct CharStack {
    char items[100];
    int top;
};

/* ==========================================================
   PART A: STACK USING ARRAY — All Operations
   ========================================================== */

// Function: Check if stack is empty
// Time Complexity: O(1)
int isEmptyArray(int top) {
    return (top == -1);
}

// Function: Check if stack is full
// Time Complexity: O(1)
int isFullArray(int top, int maxSize) {
    return (top == maxSize - 1);
}

// Function: Get size of stack
// Time Complexity: O(1)
int sizeArray(int top) {
    return (top + 1);
}

// Function: Push element onto array stack
// Time Complexity: O(1)
void pushArray(int stack[], int *top, int maxSize, int value) {
    if (isFullArray(*top, maxSize)) {
        printf("  [STACK OVERFLOW] Cannot push %d - Stack is full!\n", value);
        return;
    }
    (*top)++;
    stack[*top] = value;
    printf("  Push %d: [", value);
    for (int i = 0; i <= *top; i++) {
        printf("%d", stack[i]);
        if (i < *top) printf(", ");
    }
    printf("]\n");
}

// Function: Pop element from array stack
// Time Complexity: O(1)
int popArray(int stack[], int *top) {
    if (isEmptyArray(*top)) {
        printf("  [STACK UNDERFLOW] Cannot pop - Stack is empty!\n");
        return -1;
    }
    int value = stack[*top];
    (*top)--;
    return value;
}

// Function: Peek at top element of array stack
// Time Complexity: O(1)
int peekArray(int stack[], int top) {
    if (isEmptyArray(top)) {
        printf("  [EMPTY] No top element - Stack is empty!\n");
        return -1;
    }
    return stack[top];
}

// Function: Display all elements of array stack
// Time Complexity: O(n)
void displayArray(int stack[], int top) {
    if (isEmptyArray(top)) {
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

// Function to demonstrate all Array Stack operations
void demoArrayStack() {
    int maxSize = 5;
    int stack[100];
    int top = -1;

    printf("\n========== PART A: STACK USING ARRAY ==========\n");
    printf("Array Stack created (max size: %d)\n\n", maxSize);

    // Push 5 elements
    printf("--- Push Operations ---\n");
    pushArray(stack, &top, maxSize, 10);
    pushArray(stack, &top, maxSize, 20);
    pushArray(stack, &top, maxSize, 30);
    pushArray(stack, &top, maxSize, 40);
    pushArray(stack, &top, maxSize, 50);

    // Try pushing when full (overflow)
    printf("\n--- Stack Overflow Test ---\n");
    pushArray(stack, &top, maxSize, 60);

    // Check isFull
    printf("\n--- Status Checks ---\n");
    printf("  Stack is FULL: %s\n", isFullArray(top, maxSize) ? "Yes" : "No");
    printf("  Stack is EMPTY: %s\n", isEmptyArray(top) ? "Yes" : "No");
    printf("  Stack size: %d\n", sizeArray(top));

    // Peek
    printf("\n--- Peek Operation ---\n");
    printf("  Top element: %d\n", peekArray(stack, top));

    // Display
    printf("\n--- Display ---\n");
    displayArray(stack, top);

    // Pop elements
    printf("\n--- Pop Operations ---\n");
    printf("  Pop: %d\n", popArray(stack, &top));
    printf("  Pop: %d\n", popArray(stack, &top));
    printf("  Pop: %d\n", popArray(stack, &top));

    // Display after pops
    printf("\n--- Display After Pops ---\n");
    displayArray(stack, top);

    // Check status again
    printf("\n--- Updated Status ---\n");
    printf("  Stack is FULL: %s\n", isFullArray(top, maxSize) ? "Yes" : "No");
    printf("  Stack is EMPTY: %s\n", isEmptyArray(top) ? "Yes" : "No");
    printf("  Stack size: %d\n", sizeArray(top));

    // Pop all remaining
    printf("\n--- Pop All Remaining ---\n");
    while (!isEmptyArray(top)) {
        printf("  Pop: %d\n", popArray(stack, &top));
    }

    // Try popping from empty (underflow)
    printf("\n--- Stack Underflow Test ---\n");
    popArray(stack, &top);

    printf("\n======================================================\n");
}

/* ==========================================================
   PART B: STACK USING LINKED LIST — All Operations
   ========================================================== */

// Forward declaration
void displayLL(struct LLNode* top);

// Function: Check if linked list stack is empty
// Time Complexity: O(1)
int isEmptyLL(struct LLNode* top) {
    return (top == NULL);
}

// Function: Push element onto linked list stack
// Time Complexity: O(1)
void pushLL(struct LLNode** top, int value) {
    struct LLNode* newNode = (struct LLNode*)malloc(sizeof(struct LLNode));
    if (newNode == NULL) {
        printf("  [STACK OVERFLOW] Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;

    printf("  Push %d: ", value);
    displayLL(*top);
}

// Function: Pop element from linked list stack
// Time Complexity: O(1)
int popLL(struct LLNode** top) {
    if (isEmptyLL(*top)) {
        printf("  [STACK UNDERFLOW] Cannot pop - Stack is empty!\n");
        return -1;
    }
    struct LLNode* temp = *top;
    int value = temp->data;
    *top = (*top)->next;
    free(temp);
    return value;
}

// Function: Peek at top element of linked list stack
// Time Complexity: O(1)
int peekLL(struct LLNode* top) {
    if (isEmptyLL(top)) {
        printf("  [EMPTY] No top element - Stack is empty!\n");
        return -1;
    }
    return top->data;
}

// Function: Display all elements of linked list stack
// Time Complexity: O(n)
void displayLL(struct LLNode* top) {
    if (isEmptyLL(top)) {
        printf("NULL (empty)\n");
        return;
    }
    struct LLNode* current = top;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) printf(" -> ");
        current = current->next;
    }
    printf(" -> NULL\n");
}

// Function to free entire linked list stack
void freeLLStack(struct LLNode** top) {
    while (!isEmptyLL(*top)) {
        popLL(top);
    }
}

// Function to demonstrate all Linked List Stack operations
void demoLLStack() {
    struct LLNode* top = NULL;

    printf("\n========== PART B: STACK USING LINKED LIST ==========\n");
    printf("Linked List Stack:\n");

    // Push elements
    printf("\n--- Push Operations ---\n");
    pushLL(&top, 10);
    pushLL(&top, 20);
    pushLL(&top, 30);
    pushLL(&top, 40);
    pushLL(&top, 50);

    // Check isEmpty
    printf("\n--- Status Checks ---\n");
    printf("  Stack is EMPTY: %s\n", isEmptyLL(top) ? "Yes" : "No");

    // Peek
    printf("\n--- Peek Operation ---\n");
    printf("  Top element: %d\n", peekLL(top));

    // Display full stack
    printf("\n--- Full Stack Display ---\n");
    printf("  Stack: ");
    displayLL(top);

    // Pop elements
    printf("\n--- Pop Operations ---\n");
    printf("  Pop: %d\n", popLL(&top));
    printf("  Pop: %d\n", popLL(&top));
    printf("  Pop: %d\n", popLL(&top));

    // Display after pops
    printf("\n--- Display After Pops ---\n");
    printf("  Stack: ");
    displayLL(top);

    // Peek after pops
    printf("  Top element: %d\n", peekLL(top));

    // Pop all remaining
    printf("\n--- Pop All Remaining ---\n");
    while (!isEmptyLL(top)) {
        printf("  Pop: %d\n", popLL(&top));
    }

    // Try popping from empty
    printf("\n--- Stack Underflow Test ---\n");
    popLL(&top);

    // Free memory
    freeLLStack(&top);

    printf("\n======================================================\n");
}

/* ==========================================================
   PART C: STACK APPLICATIONS
   ========================================================== */

/* ----------------------------------------------------------
   APPLICATION 1: INFIX TO POSTFIX CONVERSION
   ----------------------------------------------------------
   
   Algorithm (Shunting Yard Algorithm):
   1. Scan infix expression from left to right
   2. If operand -> add to postfix
   3. If '(' -> push to operator stack
   4. If ')' -> pop and add to postfix until '('
   5. If operator -> pop operators with higher/equal precedence
      from stack, then push current operator
   6. After scanning, pop all remaining operators
   
   Operator Precedence:
     ^ (exponent) = 3 (highest)
     *, /          = 2
     +, -          = 1 (lowest)
   
   Associativity:
     ^ is Right-to-Left
     +, -, *, / are Left-to-Right
   ---------------------------------------------------------- */

// Function: Get precedence of operator
int precedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default:  return 0;
    }
}

// Function: Check if character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function: Check if character is left parenthesis
int isLeftParen(char ch) {
    return (ch == '(' || ch == '[' || ch == '{');
}

// Function: Check if character is right parenthesis
int isRightParen(char ch) {
    return (ch == ')' || ch == ']' || ch == '}');
}

// Function: Check matching parentheses
int isMatchingPair(char left, char right) {
    return ((left == '(' && right == ')') ||
            (left == '[' && right == ']') ||
            (left == '{' && right == '}'));
}

// --- Char Stack operations (for operators) ---
void pushChar(struct CharStack* s, char ch) {
    s->top++;
    s->items[s->top] = ch;
}

char popChar(struct CharStack* s) {
    return s->items[s->top--];
}

char peekChar(struct CharStack* s) {
    return s->items[s->top];
}

int isCharEmpty(struct CharStack* s) {
    return (s->top == -1);
}

// Function: Convert infix to postfix expression
// Input:  "A+B*C"
// Output: "ABC*+"
void infixToPostfix(char infix[], char postfix[]) {
    struct CharStack opStack;
    opStack.top = -1;

    int i = 0;  // Index for infix
    int j = 0;  // Index for postfix

    while (infix[i] != '\0') {
        char ch = infix[i];

        // Case 1: Operand (letter or digit) -> add to postfix
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        // Case 2: Left parenthesis -> push to stack
        else if (isLeftParen(ch)) {
            pushChar(&opStack, ch);
        }
        // Case 3: Right parenthesis -> pop until matching left
        else if (isRightParen(ch)) {
            while (!isCharEmpty(&opStack) && !isLeftParen(peekChar(&opStack))) {
                postfix[j++] = popChar(&opStack);
            }
            if (!isCharEmpty(&opStack)) {
                popChar(&opStack);  // Remove the '('
            }
        }
        // Case 4: Operator -> pop higher precedence operators first
        else if (isOperator(ch)) {
            while (!isCharEmpty(&opStack) && isOperator(peekChar(&opStack)) &&
                   ((precedence(peekChar(&opStack)) > precedence(ch)) ||
                    (precedence(peekChar(&opStack)) == precedence(ch) && ch != '^'))) {
                postfix[j++] = popChar(&opStack);
            }
            pushChar(&opStack, ch);
        }
        i++;
    }

    // Pop all remaining operators
    while (!isCharEmpty(&opStack)) {
        postfix[j++] = popChar(&opStack);
    }

    postfix[j] = '\0';  // Null-terminate the postfix string
}

// Function to demonstrate Infix to Postfix Conversion
void demoInfixToPostfix() {
    char infix[200];
    char postfix[200];

    printf("\n--- APPLICATION 1: INFIX TO POSTFIX CONVERSION ---\n\n");

    // Predefined examples
    char* examples[] = {
        "A+B*C",
        "(A+B)*C",
        "A+B*C-D/E",
        "A*(B+C)-D",
        "(A+B)*(C-D)",
        "A^B^C",
        "A+B-C*D/E"
    };
    int numExamples = sizeof(examples) / sizeof(examples[0]);

    printf("  %-25s %-25s\n", "Infix Expression", "Postfix Expression");
    printf("  %-25s %-25s\n", "-------------------------", "-------------------------");

    for (int i = 0; i < numExamples; i++) {
        infixToPostfix(examples[i], postfix);
        printf("  %-25s %-25s\n", examples[i], postfix);
    }

    // Custom input
    printf("\n  Enter custom infix expression: ");
    clearInputBuffer();
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("  Infix:   %s\n", infix);
    printf("  Postfix: %s\n", postfix);
}

/* ----------------------------------------------------------
   APPLICATION 2: POSTFIX EXPRESSION EVALUATION
   ----------------------------------------------------------
   
   Algorithm:
   1. Scan postfix expression from left to right
   2. If operand -> push to number stack
   3. If operator -> pop two operands, apply operator, push result
   4. Final result is at top of stack
   
   Note: Operands are single-digit numbers (0-9)
   ---------------------------------------------------------- */

// Function: Evaluate a postfix expression
// Input:  "53+82-*"
// Output: 48  (because (5+3)*(8-2) = 8*6 = 48)
int evaluatePostfix(char postfix[]) {
    int numStack[100];
    int numTop = -1;

    int i = 0;
    int result = 0;

    printf("  Evaluating: %s\n", postfix);
    printf("  Steps:\n");

    while (postfix[i] != '\0') {
        char ch = postfix[i];

        // If operand, push to stack
        if (isdigit(ch)) {
            numStack[++numTop] = ch - '0';  // Convert char to int
            printf("    Operand %d pushed\n", ch - '0');
        }
        // If operator, pop two operands and apply
        else if (isOperator(ch)) {
            int b = numStack[numTop--];  // Second operand (top)
            int a = numStack[numTop--];  // First operand
            int res;

            switch (ch) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
                case '^': {
                    res = 1;
                    for (int k = 0; k < b; k++) res *= a;
                    break;
                }
                default: res = 0;
            }

            printf("    Operator '%c': %d %c %d = %d\n", ch, a, ch, b, res);
            numStack[++numTop] = res;
        }
        i++;
    }

    result = numStack[numTop];
    printf("  Final Result: %d\n", result);
    return result;
}

// Function to demonstrate Postfix Evaluation
void demoPostfixEvaluation() {
    printf("\n--- APPLICATION 2: POSTFIX EXPRESSION EVALUATION ---\n\n");

    // Predefined examples
    printf("  Example 1:\n");
    evaluatePostfix("53+");

    printf("\n  Example 2:\n");
    evaluatePostfix("53+82-*");

    printf("\n  Example 3:\n");
    evaluatePostfix("95+2*");

    printf("\n  Example 4:\n");
    evaluatePostfix("231*+9-");

    // Custom input
    char postfix[200];
    printf("\n  Enter custom postfix expression (single digits): ");
    clearInputBuffer();
    scanf("%s", postfix);
    printf("\n  Custom Evaluation:\n");
    evaluatePostfix(postfix);
}

/* ----------------------------------------------------------
   APPLICATION 3: PARENTHESIS MATCHING
   ----------------------------------------------------------
   
   Algorithm:
   1. Scan expression from left to right
   2. If opening bracket -> push to stack
   3. If closing bracket:
      a. If stack empty -> NOT MATCHED
      b. If top matches -> pop and continue
      c. If top doesn't match -> NOT MATCHED
   4. After scanning, if stack not empty -> NOT MATCHED
   5. If stack empty -> MATCHED
   
   Supported pairs: (), [], {}
   ---------------------------------------------------------- */

// Function: Check if parentheses are balanced (detailed output)
int parenthesesMatchDetailed(char expression[]) {
    char stack[200];
    int top = -1;

    printf("  Expression: %s\n", expression);
    printf("  Scanning:\n");

    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];

        // If opening bracket, push to stack
        if (isLeftParen(ch)) {
            stack[++top] = ch;
            printf("    '%c' is opening -> push to stack (stack size: %d)\n", ch, top + 1);
        }
        // If closing bracket, check for match
        else if (isRightParen(ch)) {
            if (top == -1) {
                printf("    '%c' is closing but stack is EMPTY -> NOT MATCHED\n", ch);
                printf("  Result: NOT MATCHED (extra closing '%c')\n", ch);
                return 0;
            }
            char open = stack[top--];
            if (isMatchingPair(open, ch)) {
                printf("    '%c' is closing -> matches '%c' -> pop (stack size: %d)\n", ch, open, top + 1);
            } else {
                printf("    '%c' doesn't match '%c' -> NOT MATCHED\n", ch, open);
                printf("  Result: NOT MATCHED\n");
                return 0;
            }
        }
        // Non-bracket characters are ignored
    }

    if (top == -1) {
        printf("  Stack is empty after scanning -> MATCHED\n");
        printf("  Result: MATCHED\n");
        return 1;
    } else {
        printf("  Stack not empty (size: %d) -> NOT MATCHED\n", top + 1);
        printf("  Result: NOT MATCHED (missing %d closing bracket(s))\n", top + 1);
        return 0;
    }
}

// Function: Quick check (no verbose output)
int parenthesesMatchQuick(char expression[]) {
    char stack[200];
    int top = -1;
    int matched = 1;

    for (int j = 0; expression[j] != '\0'; j++) {
        char ch = expression[j];
        if (isLeftParen(ch)) {
            stack[++top] = ch;
        } else if (isRightParen(ch)) {
            if (top == -1 || !isMatchingPair(stack[top], ch)) {
                matched = 0;
                break;
            }
            top--;
        }
    }
    return (matched && top == -1);
}

// Function to demonstrate Parenthesis Matching
void demoParenthesisMatching() {
    printf("\n--- APPLICATION 3: PARENTHESIS MATCHING ---\n\n");

    // Predefined examples
    char* examples[] = {
        "(a+b)*c",
        "{(a+b)*[c-d]}",
        "((a+b))",
        "{(a+b)*[c-d}",
        "((a+b)*(c-d])",
        "a+b*c",
        "[{()}]",
        "([{)]}"
    };
    int numExamples = sizeof(examples) / sizeof(examples[0]);

    printf("  %-30s Result\n", "Expression");
    printf("  %-30s ------\n", "------------------------------");

    for (int i = 0; i < numExamples; i++) {
        printf("  %-30s %s\n", examples[i],
               parenthesesMatchQuick(examples[i]) ? "MATCHED" : "NOT MATCHED");
    }

    // Custom input with detailed output
    char expression[200];
    printf("\n  Enter custom expression for detailed analysis:\n  ");
    clearInputBuffer();
    scanf("%s", expression);
    printf("\n");
    parenthesesMatchDetailed(expression);
}

/* ----------------------------------------------------------
   APPLICATION 4: TOWER OF HANOI (Recursive)
   ----------------------------------------------------------
   
   The Tower of Hanoi is a classic problem that demonstrates
   how recursion uses the system call stack.
   
   Problem: Move n disks from source peg to destination peg
   using an auxiliary peg, following these rules:
   1. Only one disk can be moved at a time
   2. Only the top disk of a peg can be moved
   3. A larger disk cannot be placed on a smaller disk
   
   Algorithm:
   1. Move n-1 disks from source to auxiliary (using destination as temp)
   2. Move the nth (largest) disk from source to destination
   3. Move n-1 disks from auxiliary to destination (using source as temp)
   
   Total moves = 2^n - 1
   Time Complexity: O(2^n)
   ---------------------------------------------------------- */

// Global counter for moves
int hanoiMoves = 0;

// Function: Solve Tower of Hanoi
void towerOfHanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        hanoiMoves++;
        printf("  Move disk 1 from %c to %c\n", from, to);
        return;
    }
    towerOfHanoi(n - 1, from, aux, to);
    hanoiMoves++;
    printf("  Move disk %d from %c to %c\n", n, from, to);
    towerOfHanoi(n - 1, aux, to, from);
}

// Function to demonstrate Tower of Hanoi
void demoTowerOfHanoi() {
    int n;

    printf("\n--- APPLICATION 4: TOWER OF HANOI ---\n\n");
    printf("  The Tower of Hanoi demonstrates recursion and system call stack.\n");
    printf("  Rules:\n");
    printf("    1. Move only one disk at a time\n");
    printf("    2. Only the top disk can be moved\n");
    printf("    3. Never place a larger disk on a smaller one\n\n");

    printf("  Enter number of disks (1-8): ");
    clearInputBuffer();
    scanf("%d", &n);

    if (n < 1 || n > 8) {
        printf("  Invalid input! Please enter a number between 1 and 8.\n");
        return;
    }

    printf("\n  Tower of Hanoi with %d disks:\n", n);
    printf("  Pegs: A (Source), B (Destination), C (Auxiliary)\n\n");

    hanoiMoves = 0;
    towerOfHanoi(n, 'A', 'B', 'C');

    printf("\n  Total moves required: %d\n", hanoiMoves);
    printf("  Formula: 2^%d - 1 = %d\n", n, (1 << n) - 1);
}

/* ==========================================================
   MAIN FUNCTION — Menu Driven
   ========================================================== */

int main() {
    int choice;
    int running = 1;

    printf("\n");
    printf("======================================================\n");
    printf("       STACK ALL OPERATIONS — AKTU UNIT 2\n");
    printf("======================================================\n");

    while (running) {
        printf("\n--- MAIN MENU ---\n");
        printf("1.  Stack using Array (Full Demo)\n");
        printf("2.  Stack using Linked List (Full Demo)\n");
        printf("3.  Infix to Postfix Conversion\n");
        printf("4.  Postfix Expression Evaluation\n");
        printf("5.  Parenthesis Matching\n");
        printf("6.  Tower of Hanoi\n");
        printf("7.  Run ALL Demos\n");
        printf("0.  Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                demoArrayStack();
                break;
            case 2:
                demoLLStack();
                break;
            case 3:
                demoInfixToPostfix();
                break;
            case 4:
                demoPostfixEvaluation();
                break;
            case 5:
                demoParenthesisMatching();
                break;
            case 6:
                demoTowerOfHanoi();
                break;
            case 7:
                demoArrayStack();
                demoLLStack();
                demoInfixToPostfix();
                demoPostfixEvaluation();
                demoParenthesisMatching();
                demoTowerOfHanoi();
                break;
            case 0:
                running = 0;
                printf("\n======================================================\n");
                printf("  All Stack Operations Completed Successfully!\n");
                printf("  Topics Covered:\n");
                printf("    - Stack using Array (Push, Pop, Peek, Display)\n");
                printf("    - Stack using Linked List (Push, Pop, Peek, Display)\n");
                printf("    - Infix to Postfix Conversion\n");
                printf("    - Postfix Expression Evaluation\n");
                printf("    - Parenthesis Matching\n");
                printf("    - Tower of Hanoi (Recursive)\n");
                printf("======================================================\n\n");
                break;
            default:
                printf("  Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

/*
============================================================
COMPILATION:
  gcc Stack_AllOperations.c -o Stack_AllOperations.exe

RUN:
  Stack_AllOperations.exe

OUTPUT FILE:
  Stack_AllOperations.exe
============================================================
*/
