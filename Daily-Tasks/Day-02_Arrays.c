/* ============================================================
   DAILY CODING TASK - DAY 2 (Arrays - beginner friendly)
   ============================================================
   QUESTION: Can you store 5 numbers and print them all?
   TASK (easy part - no pointers needed!):
   1. Make an array: nums[5] = {10, 20, 30, 40, 50};
   2. Print all 5 numbers using a normal loop
      (hint: nums[0] is the first, nums[1] is the second...)
   3. Also print the total of all 5 numbers
   BONUS (only if you feel ready - skip if not!):
   Try the pointer way instead: int *p = nums;
   then use p[0], p[1], p[2]... - yes, pointers work with []
   like arrays do. They are cousins!
   ============================================================ */
#include <stdio.h>
void main() {
   int i,total=0,nums[5] = {10, 20, 30, 40, 50};
   printf("The numbers are: ");
   for (i=0;i<5;i++)
   {
      printf("%d ",nums[i]);
      total+=nums[i];
   }
   printf("\nThe total of all 5 numbers is: %d",total);
}
