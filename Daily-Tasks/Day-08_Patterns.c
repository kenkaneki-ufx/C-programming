/* ============================================================
   DAILY CODING TASK - DAY 8 (Patterns - a little tricky)
   ============================================================
   QUESTION: Can you build shapes with nested loops?
   TASK (think before you code - use TWO loops, one inside
   the other):
   1. Print this star pattern with 5 rows:
         * 
         * *
         * * *
         * * * *
         * * * * *
      (outer loop = rows, inner loop = stars in that row)
   2. Print the star pattern UPSIDE DOWN with 4 rows:
         * * * *
         * * *
         * *
         *
   3. Print a number triangle with 5 rows:
         1
         1 2
         1 2 3
         1 2 3 4
         1 2 3 4 5
      (inner loop prints 1 up to the row number)
      
   4. Print the number triangle UPSIDE DOWN with 4 rows:
         1 2 3 4
         1 2 3
         1 2
         1
   ============================================================ */
#include <stdio.h>
void pattern1(int n)
{
   int i,j;
   for( i = 0; i < n; i++)
   {
      for( j = 0; j <= i; j++)
         printf("* ");
      printf("\n");
   }
}
void pattern2(int n)
{
   int i,j;
   for( i = n; i > 0; i--)
   {
      for( j = i; j > 0; j--)
         printf("* ");
      printf("\n");
   }
}
void pattern3(int n)
{
   int i,j;
   for( i = 1; i <= n; i++)
   {
      for( j = 1; j <= i; j++)
         printf("%d ",j);
      printf("\n");
   }
}
void pattern4(int n)
{
   int i,j;
   for( i = n; i > 0; i--)
   {
      for( j = 1; j <= i; j++)
         printf("%d ",j);
      printf("\n");
   }
}
void main() 
{
   pattern1(5);
   pattern2(4);
   pattern3(5);
   pattern4(4);
}
