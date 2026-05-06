#include <assert.h>
#include <stdio.h>

#include "addF.h"

int main() {
    assert(add(2, 3) == 5);
    assert(add(-1, 1) == 0);
    printf("All tests passed successfully!\n");

    // test volontairement faux (décommente pour voir Jenkins échouer)
    // assert(add(2,2) == 5);

    return 0;
}