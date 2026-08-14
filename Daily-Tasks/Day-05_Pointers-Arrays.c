/* ============================================================
   DAILY CODING TASK - DAY 5 (Pointers & Arrays - beginner friendly)
   ============================================================
   QUESTION: Can you walk through an array using a pointer?
   TASK (easy part - just like Day 2's bonus!):
   1. Make an array: int nums[4] = {2, 4, 6, 8};
   2. Make a pointer: int *p = nums;
   3. Print nums[0], nums[1], nums[2], nums[3] using
      p[0], p[1], p[2], p[3] - pointers work with [] too!
   BONUS (only if you feel ready - skip if not!):
   Try the * operator way instead: *(p+0), *(p+1), *(p+2), *(p+3).
   Same numbers, right? That's the real pointer magic.
   ============================================================ */
#include <stdio.h>
void main() {
    int nums[4] = {2, 4, 6, 8};   // 4 boxes of int, side by side in memory
    int *p = nums;                // p points at the FIRST box (nums[0])
    /* ============================================================
       BUFFY'S ANSWER TO YOUR QUESTION: what is *(p+i)?
       ------------------------------------------------------------
       Think of p as a flashlight pointing at the FIRST box of the
       array. Now:
         p + i   ->  move the flashlight FORWARD by i boxes.
                     (NOT i bytes - C knows p is an int*, so it
                     jumps i * sizeof(int) bytes automatically.)
         *(p+i)  ->  the * (dereference) then READS the value
                     that the flashlight is pointing at.
       So *(p+i) and nums[i] are THE SAME THING. Two spellings,
       one meaning. p+i is just an address, * makes it a value.
       ============================================================ */
    // EASY WAY: pointers work with [] exactly like arrays
    printf("p[0]=%d p[1]=%d p[2]=%d p[3]=%d\n",
           p[0], p[1], p[2], p[3]);   // prints: 2 4 6 8
    // BONUS WAY: the * operator version - same numbers!
    // i goes 0..3, so *(p+0) reads box 0, *(p+1) reads box 1, ...
    for (int i = 0; i < 4; i++) {
        printf("*(p+%d)=%d\n", i, *(p + i));   // 2, then 4, then 6, then 8
    }
    // Little proof they are identical: nums[2] vs *(p+2) vs p[2]
    printf("nums[2]=%d, *(p+2)=%d, p[2]=%d  <- all the same!\n",
           nums[2], *(p + 2), p[2]);
}
