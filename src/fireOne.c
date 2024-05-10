#include "../include/functionHeaders.h"

void fireOne(a3Emp **headLL, int whichOne) {
    // Gets the number of employees using a previous function
    int count = countEmployees(*headLL);

    if (whichOne < 1 || whichOne > count) {
        printf("Invalid input. Please enter a value between 1 and %d.\n", count);
        return;
    }

    a3Emp *currentEmp = *headLL;
    a3Emp *previousEmp = NULL;

    // Goes through the LL to find the employee to be fired
    for (int i = 1; i < whichOne; i++) {
        previousEmp = currentEmp;
        currentEmp = currentEmp->nextEmployee;
    }

    // Updating of the nodes to delete the employee
    if (previousEmp == NULL) {
        *headLL = currentEmp->nextEmployee;
    } else {
        previousEmp->nextEmployee = currentEmp->nextEmployee;
    }

    printf("Employee [Id: %d] fired.\n", currentEmp->empId);
}
