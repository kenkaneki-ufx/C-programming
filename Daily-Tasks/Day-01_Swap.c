/* ============================================================
   📅 DAILY CODING TASK — DAY 1 (Swap - beginner friendly)
   ============================================================

   ❓ QUESTION: Can you swap two numbers using a function that receives the values?

   TASK:
   1. Declare two variables: a = 5, b = 10
   2. Try swapping them with a function that takes VALUES
   4. Print a and b before & after swap
   ============================================================ */
#include <stdio.h>
int swap(int a,int b)
{
    int c = a;
    a = b;
    b = c;
    printf("\nAfter Swap\na:%d\nb:%d",a,b);
}
void main() 
{
    int a = 5, b = 10;
    printf("\nBefore Swap\na:%d\nb:%d",a,b);
    swap(a,b);

}
