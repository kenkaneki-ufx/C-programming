/*
============================================================
Day 31
============================================================

PROBLEM NAME:
Popular Number

------------------------------------------------------------
Statement: You are given n integers, each between 1 and 100.
Find the value that occurs most often. If several values are
tied for the highest count, print the SMALLEST of them.
Print the value and how many times it occurs.
------------------------------------------------------------

------------------------------------------------------------
INPUT:
The first line contains an integer t (1 <= t <= 100) — the
number of test cases. Each test case consists of two lines:
- the first line contains an integer n (1 <= n <= 1000);
- the second line contains n integers a_1, a_2, ..., a_n
  (1 <= a_i <= 100).

OUTPUT:
For each test case print two integers: the most frequent
value (smallest one on ties) and its count.

------------------------------------------------------------
CONSTRAINTS:
- 1 <= t <= 100
- 1 <= n <= 1000
- 1 <= a_i <= 100

------------------------------------------------------------
SAMPLE INPUT:
3
7
4 2 4 7 2 4 7
5
9 3 9 3 5
1
6

SAMPLE OUTPUT:
4 3
3 2
6 1

------------------------------------------------------------
Note: Test 1: 4 occurs three times, 2 and 7 occur twice, so
the answer is 4 with count 3. Test 2: 9 and 3 both occur
twice; the smallest of them is 3. Test 3: only one number.

------------------------------------------------------------
CONCEPTS PRACTICED:
- Frequency counting with an array
- Tie-breaking by scanning in increasing order
- Reasonable variable choices for the job

------------------------------------------------------------
DIFFICULTY: 3/10  (~ Codeforces 900)

------------------------------------------------------------
OPTIONAL HINT:
Make a frequency array of size 101 and increment
freq[value] while reading. Then scan values from 1 to 100
and keep the one with the largest count; scanning in
increasing order with a strict > comparison automatically
gives the smallest value on ties.

------------------------------------------------------------
FILENAME SUGGESTION:
Day-31_PopularNumber.c

COMMIT MESSAGE:
"Add Day 31 - Popular Number"

============================================================
*/

// #include <stdio.h>

// // Write your solution here

// void main() {
//     // Read t. For each test case: frequency-count the values
//     // into an array of size 101, then scan 1..100 for the
//     // largest count (smallest value wins ties). Print value
//     // and count.

// }

#include <stdio.h>

int main() 
{
    int t;
    if(scanf("%d",&t)!=1) return 0;
    while(t>0)
    {

        int arr[100],i,n;
        int visited[100]={0}, count[100]={1};
        
        scanf("%d", &n);        
        for(i = 0; i < n; i++)
             scanf("%d", &arr[i]);
        
        for(int i = 0; i < n; i++)
        {
            if(visited[i] != 0)
                continue;
            for(int j = i + 1; j < n; j++)
            {
                if(arr[i] == arr[j])
                {
                    count[i]++;    
                    visited[i] = arr[i];
                }
            }
          }
        printf("%d %d\n", visited[0],count[0]);
        t--;
    }
}