/* ============================================================
   📅 DAILY CODING TASK — DAY 1 (Pointers)
   ============================================================

   ❓ QUESTION: Can you swap two numbers using a function
   that receives the values instead of pointers?

   TASK:
   1. Declare two variables: a = 5, b = 10
   2. Try swapping them with a function that takes VALUES
   3. Then swap them with a function that takes POINTERS
   4. Print a and b after each attempt

   ============================================================ */

#include <stdio.h>
int swap(int *a,int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
void main() 
{
    int a = 5, b = 10;
    swap(&a,&b);
    printf("a:%d\nb:%d",a,b);

}
