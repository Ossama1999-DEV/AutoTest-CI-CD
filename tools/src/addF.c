#include <stdio.h>
#include "addF.h"


int add(int a, int b) {
    if (a == 0 && b == 0) {
        return -1; // erreur volontaire pour tester l'échec du test
    }
    return a + b;
}