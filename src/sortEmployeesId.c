#include "../include/functionHeaders.h"

void sortEmployeesId(struct employee* headLL) {
    int numEmployees = 0;
    struct employee* currentEmp = headLL;

    // Finds the amount of employees in the LL
    while (currentEmp != NULL) {
        numEmployees++;
        currentEmp = currentEmp->nextEmployee;
    }

    // Allocate memory
    struct employee** tempArray = malloc(numEmployees * sizeof(struct employee*));

    // Populates the array
    currentEmp = headLL;
    int i = 0;
    while (currentEmp != NULL) {
        tempArray[i] = currentEmp;
        currentEmp = currentEmp->nextEmployee;
        i++;
    }

    // Bubble sort for the ID's
    for (int i = 0; i < numEmployees - 1; i++) {
        for (int j = 0; j < numEmployees - i - 1; j++) {
            if (tempArray[j]->empId > tempArray[j + 1]->empId) {
                struct employee* temp = tempArray[j];
                tempArray[j] = tempArray[j + 1];
                tempArray[j + 1] = temp;
            }
        }
    }

    // Prints the sorted LL
    printf("Sorted list of employees by ID:\n\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("Employee #%d:\n", i + 1);
        printf("\tEmployee id: %d\n", tempArray[i]->empId);
        printf("\tFirst name: %s\n", tempArray[i]->fname);
        printf("\tLast name: %s\n", tempArray[i]->lname);
        printf("\tDependents [%d]: ", tempArray[i]->numDependents);
        printf("\n");
        for (int j = 0; j < tempArray[i]->numDependents; j++) {
            printf("%s", tempArray[i]->dependents[j]);
            if (j < tempArray[i]->numDependents - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
}
