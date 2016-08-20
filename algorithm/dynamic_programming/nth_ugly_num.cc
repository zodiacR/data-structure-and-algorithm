#include <stdio.h>
#include <stdlib.h>

unsigned min(unsigned a, unsigned b, unsigned c) {
    if (a <= b){
        if (a <= c) return a;
        else return c;
    }
    else if (b <= c) return b;
    else return c;
}

unsigned getNthUgly(unsigned n){
    unsigned ugly[n];
    unsigned i2 = 0, i3 = 0, i5 = 0;
    unsigned f2 = 2, f3 = 3, f5 = 5;
    ugly[0] = 1;

    for (unsigned i = 1; i < n; i++){
        unsigned next_ugly = min(f2, f3, f5);
        ugly[i] = next_ugly;

        if (next_ugly == f2) f2 = 2 * ugly[++i2];
        if (next_ugly == f3) f3 = 3 * ugly[++i3];
        if (next_ugly == f5) f5 = 5 * ugly[++i5];
    }

    return ugly[n-1];
}

/* Driver program to test above functions */
int main()
{
    int n;
    scanf("%d", &n);
    unsigned no = getNthUgly(n);
    printf("%dth ugly no. is %d \n", n, no);
    return 0;
}
