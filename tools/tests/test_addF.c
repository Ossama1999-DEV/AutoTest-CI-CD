// #include <stdio.h>
// #include <stdlib.h>
// #include "addF.h"

// int main() {

//     if (add(2, 3) != 5) {
//         printf("Test 1 failed\n");
//         return 1;
//     }

//     if (add(0, 0) != -1) {
//         printf("Test 2 failed: add(0,0) protection broken\n");
//         return 1;
//     }

//     printf("All tests passed ✅\n");
//     return 0;
// }
#include <assert.h>
#include "addF.h"

int main() {
    assert(add(2, 3) == 5);
    assert(add(0, 0) == -1);
    return 0;
}