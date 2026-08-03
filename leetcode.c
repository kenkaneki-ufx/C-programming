int reverse(long int x) 
{
    long int d,rev = 0;
    while (x != 0) 
    {
        d = x % 10;
        rev = rev * 10 + d;
        x /= 10;
    }
    return rev;
}

#include <stdio.h>
void main()
{
    long int x;
    printf("Enter a number: ");
    scanf("%ld",&x);
    printf("%ld",reverse(x));
}
