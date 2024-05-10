#include "../include/functionHeaders.h"

int countEmployees(a3Emp* headLL) {
    int count = 0;
    a3Emp* currentEmp = headLL;

    // While loop to go through the LL till it reaches the end
    while (currentEmp != NULL) {
        // Increment the count
        count++;

        // Moves onto the next employee in the list
        currentEmp = currentEmp->nextEmployee;
    }
    return count;
}
