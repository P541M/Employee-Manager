#include "../include/functionHeaders.h"

int main() {
    // Variable declaration for user input
    int userChoice = 0;

    // Variable declaration for function 1, 2, 3, 4, 5, 6, 7, 8, 9
    struct employee* head = NULL;

    // Variable declaration for function 3
    int position = 0;

    // Variable declaration for function 4
    int choiceId = 0;
    int idPosition = 0;

    // Variable declaration for function 5
    char fullName[100];
    int idPositionTwo = 0;

    // Variable declaration for function 6
    int numEmployees = 0;

    // Variable declaration for function 8
    int whichOne;

    // While loop to display the functions
    while (userChoice != 10) {
        printf("Choose a menu option (1-10):\n");
        printf("--------------------------------\n");
        printf("1. Add a new employee\n");
        printf("2. Print data of all employees\n");
        printf("3. Print data of the nth employee\n");
        printf("4. Search for employee based on empId\n");
        printf("5. Search for employee based on full name\n");
        printf("6. Count the total number of employees\n");
        printf("7. Sort the employees based on their empId\n");
        printf("8. Remove the nth employee in the current LL\n");
        printf("9. Remove all employees in the current LL\n");
        printf("10. Exit\n");
        printf("--------------------------------\n\n");
        printf("Enter your option: ");
        scanf("%d", &userChoice);
        printf("\n");

        if (userChoice == 1) {
            recruitEmployee(&head);
        } else if (userChoice == 2) {
            printAll(head);
        } else if (userChoice == 3) {
            printf("Enter a position: ");
            scanf("%d", &position);
            printOne(head, position);
        } else if (userChoice == 4) {
            printf("Enter an employee ID: ");
            scanf("%d", &choiceId);
            printf("\n");
            idPosition = lookOnId(head, choiceId);

            if (idPosition == -1) {
                printf("There is no employee ID found.\n\n");
            } else {
                printOne(head, idPosition);
            }
        } else if (userChoice == 5) {
            printf("Enter the full name of the employee: ");
            scanf(" %[^\n]s", fullName);
            printf("\n");
            idPositionTwo = lookOnFullName(head, fullName);

            if (idPositionTwo == -1) {
                printf("There is no employee found with that name.\n\n");
                printf("\n");
            } else {
                printOne(head, idPositionTwo);
            }
        } else if (userChoice == 6) {
            numEmployees = countEmployees(head);
            printf("Total number of employees = %d\n\n", numEmployees);
        } else if (userChoice == 7) {
            sortEmployeesId(head);
            printf("\n");
        } else if (userChoice == 8) {
            int totalEmployees = countEmployees(head);
            printf("\nCurrently there are %d employees.\n", totalEmployees);
            printf("Which employee do you wish to fire - enter a value between 1 and %d: ", totalEmployees);
            scanf("%d", &whichOne);
            fireOne(&head, whichOne);
            totalEmployees = countEmployees(head);
            printf("There are now %d employees\n\n", totalEmployees);
        } else if (userChoice == 9) {
            fireAll(&head);
            printAll(head);
        }
    }

    printf("Thank you for runing my program :)\n\n");

    return 0;
}
