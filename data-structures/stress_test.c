#include <stdio.h>

int main()
{
    // Stress test for loop till it fails
    for (float x = 0.000000; x < 0.000001; x = x + 0.0000001)
    {
        printf("Loop Stress Test: %f\n", x);
    }

    return 0;
}
