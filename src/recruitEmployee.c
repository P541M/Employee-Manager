#include "../include/functionHeaders.h"

void recruitEmployee(struct employee **headLL) {
    // Allocates memory for the employee
    a3Emp *employeeBlock = malloc(sizeof(a3Emp));

    employeeBlock->empId = 0;
    a3Emp *tempEmployeeBlock = *headLL;
    int i = 0;
    char dependentsTwo = 'y';
    int numOfDependents = 0;
    int empIdTemp = 0;
    int ASCIIVal = 0;

    printf("Enter the first name of the employee: ");
    scanf("%s", employeeBlock->fname);
    printf("Enter the last name of the employee: ");
    scanf("%s", employeeBlock->lname);
    printf("\n");

    // Allocate for dependents
    employeeBlock->dependents = malloc(sizeof(char *));
    employeeBlock->dependents[i] = malloc(sizeof(char) * MAX_LENGTH);

    while ((dependentsTwo != 'n' || dependentsTwo != 'N') && (dependentsTwo == 'y' || dependentsTwo == 'Y')) {
        numOfDependents++;
        printf("Enter name of dependent #%d: ", i + 1);
        scanf(" %s", employeeBlock->dependents[i]);

        // Resize the array for the dependent
        employeeBlock->dependents = realloc(employeeBlock->dependents, ((numOfDependents + 1) * sizeof(char *)));
        employeeBlock->dependents[i] =
            realloc(employeeBlock->dependents[i], (strlen(employeeBlock->dependents[i]) * sizeof(char)));

        printf("Do you want any more dependents? ");
        scanf(" %c", &dependentsTwo);
        printf("\n");

        i++;

        // Allocate memory for next dependent
        employeeBlock->dependents[i] = malloc(sizeof(char) * MAX_LENGTH);
    }

    // Sends it to the struct
    employeeBlock->numDependents = numOfDependents;

    printf("You have %d dependents.\n\n", employeeBlock->numDependents);

    // Makes the employee ID using the name
    for (int i = 0; i < strlen(employeeBlock->fname); i++) {
        ASCIIVal = (int)(employeeBlock->fname[i]);
        empIdTemp += ASCIIVal;
    }

    empIdTemp = empIdTemp + strlen(employeeBlock->lname);
    employeeBlock->empId = empIdTemp;

    // Checks if the ID already exists
    int existingId = duplicateIdCheck(headLL, employeeBlock->empId);

    // Will adjust the ID if it already exists
    while (existingId) {
        employeeBlock->empId = employeeBlock->empId + (rand() % 999 + 1);
        existingId = duplicateIdCheck(headLL, employeeBlock->empId);
    }

    printf("Your computer-generated empId is %d\n\n", employeeBlock->empId);

    // Pushes the employee to the end of the list
    employeeBlock->nextEmployee = NULL;
    if (*headLL == NULL) {
        *headLL = employeeBlock;
    } else {
        tempEmployeeBlock = *headLL;
        while (tempEmployeeBlock->nextEmployee != NULL) {
            tempEmployeeBlock = tempEmployeeBlock->nextEmployee;
        }
        tempEmployeeBlock->nextEmployee = employeeBlock;
    }
}
