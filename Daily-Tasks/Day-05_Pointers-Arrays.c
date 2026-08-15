/* ============================================================
   DAILY CODING TASK - DAY 5 (Pointers & Arrays - beginner friendly)
   ============================================================
   QUESTION: Can you walk through an array using a pointer?
      1. Make an array: nums[4] = {2, 4, 6, 8};
      2. Make a pointer: *p = nums;
      3. Print nums[0], nums[1], nums[2], nums[3] using p[0], p[1], p[2], p[3] - pointers work with [] too!
   ============================================================ */
#include <stdio.h>
void main() 
{
   int i,nums[4] = {2, 4, 6, 8};
   int *p = nums;
   for( i = 0; i < 4; i++)
      printf("nums[%d]=%d  -->  p[%d]=%d\t*(p+%d)=%d\n", i, nums[i], i, p[i], i, *(p + i));
   printf("\nnums[2]=%d, *(p+2)=%d, p[2]=%d  <- all the same!",nums[2], *(p + 2), p[2]);
}
