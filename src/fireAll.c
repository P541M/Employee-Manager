#include "../include/functionHeaders.h"

void fireAll(a3Emp **headLL) {
    char confirmation;
    printf("Are you sure you want to fire everyone: ");
    scanf(" %c", &confirmation);

    // User input validation
    if (confirmation == 'y' || confirmation == 'Y') {
        a3Emp *currentEmp = *headLL;

        // While loop to go through the LL till it reaches the end
        while (currentEmp != NULL) {
            a3Emp *nextEmp = currentEmp->nextEmployee;

            // Frees everything
            free(currentEmp->dependents[0]);
            free(currentEmp->dependents);
            free(currentEmp);

            // Move onto the next employee
            currentEmp = nextEmp;
        }
        *headLL = NULL;
        printf("All fired. Linked list is now empty.\n");
    }
}
