#include <stdio.h>
#include <stdlib.h>

int IsLucky(int n) {
    static int counter = 2; 

    if (n < counter) return 1;

    if (n % counter == 0) return 0;

    n -= n / counter;

    counter += 1;

    return IsLucky(n);
}

/*Driver function to test above function*/
int main()
{
  int x = 5;

  scanf("%d", &x);
  if( IsLucky(x) )
    printf("%d is a lucky no.\n", x);
  else
    printf("%d is not a lucky no.\n", x);
}
