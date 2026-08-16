/* ============================================================
   DAILY CODING TASK - DAY 11 (Arrays - beginner friendly)
   ============================================================
   QUESTION: How do you print an array in reverse?
   TASK (easy part - just follow the pattern):
   1. Read 5 numbers into an array
   2. Print them in the order they were entered
   3. Print them BACKWARDS
   BONUS (only if you feel ready - skip if not!):
   Also print the LARGEST and SMALLEST number
   in the array.
   ============================================================ */
#include <stdio.h>
void main() 
{
   int i,ar[5];
   printf("Enter 5 numbers: ");
   for( i = 0; i < 5; i++)
      scanf("%d", &ar[i]);
   printf("\nThe Entered Array is:  [ ");
   for( i = 0; i < 5; i++)
      printf("%d ", ar[i]);
   printf("]\nThe Backward Array is: [ ");
   for( i = 4; i >= 0; i--)
      printf("%d ", ar[i]);
 
   // BONUS Task ->
   int largest = ar[0],smallest = ar[0];
   for(i = 1; i < 5; i++)
   {
      if(largest < ar[i])
         largest = ar[i];
      if(smallest > ar[i])
         smallest = ar[i];
   }
   printf("]\n\nThe largest element in array is:  %d", largest);
   printf("\nThe smallest element in array is: %d", smallest);
}
