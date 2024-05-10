#include "../include/functionHeaders.h"

void printAll(struct employee* headLL) {
    int numEmployees = 0;
    struct employee* currentEmp = headLL;

    // Goes through the LL and counts the employees
    while (currentEmp != NULL) {
        numEmployees++;
        currentEmp = currentEmp->nextEmployee;
    }

    currentEmp = headLL;
    int i = 1;

    // Goes through the LL and prints the contents
    while (currentEmp != NULL) {
        printf("Employee # %d:\n", i);
        printf("\tEmployee id: %d\n", currentEmp->empId);
        printf("\tFirst name: %s\n", currentEmp->fname);
        printf("\tLast name: %s\n", currentEmp->lname);
        printf("\tDependents [%d]: ", currentEmp->numDependents);

        // Prints the dependents
        for (int j = 0; j < currentEmp->numDependents; j++) {
            printf("%s", currentEmp->dependents[j]);
            if (j < currentEmp->numDependents - 1) {
                printf(", ");
            }
        }
        printf("\n\n");

        currentEmp = currentEmp->nextEmployee;
        i++;
    }

    printf("Currently, there are %d employees.\n\n", numEmployees);
}
