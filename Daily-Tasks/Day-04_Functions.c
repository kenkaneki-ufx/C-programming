/* ============================================================
   DAILY CODING TASK - DAY 4 (Functions - beginner friendly)
   ============================================================
   QUESTION: Can you write your own function that adds two numbers?
   TASK (easy part - no pointers needed!):
   1. Write a function: add(a, b) that returns the sum of a and b
   2. Call it from main() 
   3. Print the result
   BONUS (only if you feel ready - skip if not!):
   Write a second function int multiply(int a, int b) and print
   both results: "Sum: 10, Product: 21"
   ============================================================ */
#include <stdio.h>
int add(int a, int b)
{
   return a + b;
}
void main() 
{
   int a,b;
   printf("Enter a first number : ");
    scanf("%d",&a);
   printf("Enter a second number: ");
    scanf("%d",&b);
   printf("%d + %d = %d",a,b,add(a,b));
}
