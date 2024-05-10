#include "../include/functionHeaders.h"

void printOne(struct employee* headLL, int whichOne) {
    int numEmployees = 0;
    struct employee* currentEmp = headLL;

    // Finds the amount of employees
    while (currentEmp != NULL) {
        numEmployees++;
        currentEmp = currentEmp->nextEmployee;
    }

    // If statement to check if the given position is valid
    if (whichOne < 1 || whichOne > numEmployees) {
        printf("Invalid input. Please enter a valid position between 1 and %d.\n\n", numEmployees);
        return;
    }

    currentEmp = headLL;
    int i = 1;

    // To find the employee
    while (currentEmp != NULL && i < whichOne) {
        currentEmp = currentEmp->nextEmployee;
        i++;
    }

    // Prints the info for the given position
    printf("Employee # %d:\n", whichOne);
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
}
