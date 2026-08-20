/*
============================================================
Day 16 — Functions Logical
============================================================
PROBLEM NAME:
Pass by Value vs Pass by Reference + Recursion Basics
------------------------------------------------------------
GOAL:
Write C programs that demonstrate the difference between 
pass by value and pass by reference, and practice basic 
recursion.
------------------------------------------------------------
REQUIREMENTS:
PART 1: Pass by Value vs Pass by Reference
1. Write a function swapByValue(int a, int b) that tries 
   to swap two numbers using pass by value
2. Write a function swapByReference(int *a, int *b) that 
   swaps two numbers using pointers
3. Call both functions from main and show the difference
4. Demonstrate why pass by value doesn't affect original
PART 2: Basic Recursion
5. Write a recursive function to calculate factorial
6. Write a recursive function to print numbers from N to 1
7. Write a recursive function to calculate sum of N natural numbers
------------------------------------------------------------
RULES:
- Use pointers for pass by reference
- Use * and & operators correctly
- Recursion must have a base case
- Do NOT use loops for recursive functions
------------------------------------------------------------
CONSTRAINTS:
- Maximum value for factorial: 12 (to avoid overflow)
- Numbers for countdown: positive integers
- Understand: pass by value = copy, pass by reference = original
------------------------------------------------------------
EXAMPLE RUN (Part 1):
--- Pass by Value ---
Before swap: a = 10, b = 20
Inside swapByValue: a = 20, b = 10
After swapByValue: a = 10, b = 20 (unchanged!)
--- Pass by Reference ---
Before swap: x = 10, y = 20
Inside swapByReference: x = 20, y = 10
After swapByReference: x = 20, y = 10 (changed!)
------------------------------------------------------------
EXAMPLE RUN (Part 2):
--- Factorial ---
Enter number: 5
Factorial of 5 = 120
--- Countdown ---
Enter number: 5
5 4 3 2 1
--- Sum ---
Enter number: 5
Sum of 1 to 5 = 15
------------------------------------------------------------
CONCEPTS PRACTICED:
- Pass by value
- Pass by reference (pointers)
- Pointer dereferencing
- Recursive functions
- Base case in recursion
- Function call stack concept
------------------------------------------------------------
DIFFICULTY: 4/10
------------------------------------------------------------
FILENAME SUGGESTION:
Day-16_FunctionsLogical.c
COMMIT MESSAGE:
"Add pass by value/reference and recursion examples"
============================================================
*/
#include <stdio.h>
// Part 1: Pass by Value
void swapByValue(int a, int b) {
   int c = a;
   a = b;
   b = c; 
   printf("Inside swapByValue: a = %d, b = %d\n", a, b);
}
// Part 1: Pass by Reference
void swapByReference(int *x, int *y) {
   int c = *x;
   *x = *y;
   *y = c;
   printf("Inside swapByReference: x = %d, y = %d\n", *x, *y);
}
// Part 2: Recursive Factorial
int factorial(int n) {
   if(n == 1)
      return 1;
   return n*factorial(n-1);
}
// Part 2: Recursive Countdown
void countdown(int n) {
   if(n == 0)
      return;
   printf("%d ", n);
   countdown(n-1);
}
// Part 2: Recursive Sum
int sum(int n) {
   if(n == 1)
      return 1;
   return n+sum(n-1);
}
void main() 
{
   /* Part 1: Demonstrate swap difference */
   int a = 10, b = 20;
   printf("\n--- Pass by Value ---\n");
   printf("Before swap: a = %d, b = %d\n", a, b);
   swapByValue(a,b);
   printf("After swapByValue: a = %d, b = %d (unchanged!)\n", a, b);
   
   int x = 10, y = 20;
   printf("\n--- Pass by Reference ---\n");
   printf("Before swap: x = %d, y = %d\n", x, y);
   swapByReference(&x,&y);
   printf("After swapByReference: x = %d, y = %d (changed!)\n", x, y);
   
   
   /* Part 2: Test recursive functions */
   int n;
   printf("\n\n--- Factorial ---\n");
   printf("Enter a number: ");
   scanf("%d",&n);
   printf("Factorial of %d = %d\n", n, factorial(n));
   printf("\n--- Countdown ---\n");
   printf("Enter a positive number: ");
   scanf("%d",&n);
   countdown(n);
   printf("\n\n--- Sum ---\n");
   printf("Enter a number: ");
   scanf("%d",&n);
   printf("Sum of 1 to %d = %d\n", n, sum(n));
}
