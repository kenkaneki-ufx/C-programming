/* ============================================================
   DAILY CODING TASK - DAY 7 (Loops - beginner friendly)
   ============================================================
   QUESTION: How do you run a block of code many times?
   TASK (easy part - just follow the pattern):
   1. Print numbers 1 to 10 using a for loop
   2. Read a number N from the user and print the sum of 1 to N (1 + 2 + 3 + ... + N)
   3. Print the multiplication table of 7
      (7 x 1 = 7, 7 x 2 = 14, ... up to 7 x 10 = 70)
   BONUS (only if you feel ready - skip if not!):
   Print only the EVEN numbers from 2 to 20 using a
   while loop.
   ============================================================ */
#include <stdio.h>
void main() 
{
   // Task - 1
   int i;
   printf("\nPrinting numbers 1 to 10:\n");
   for( i = 1; i <= 10; i++)          
      printf("%d ", i);
   
   // Task - 2
   int n,sum=0;
   printf("\n\nEnter a number: ");        
   scanf("%d",&n);
   for( i = 1; i <= n; i++)
      sum+=i;
   printf("The sum of 1 to %d is: %d\n", n, sum);
   
   // Task - 3
   printf("\nMultiplication table of 7:\n");
   for( i = 1; i <= 10; i++)          
      printf("7 x %d = %d\n", i, i*7);
   
   // Bonus Task
   i = 2;
   printf("\nEVEN numbers from 2 to 20:\n");
   while (i <= 20)                     //   while ( i <= 20)
   {                                   //   {
      if( i %2 == 0)                   //       printf("%d ", i);
         printf("%d ", i);             //       i+=2;
      i++;                             //    }
   }                                   
}
