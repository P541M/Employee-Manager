#include "../include/functionHeaders.h"

int lookOnId(struct employee* headLL, int whichEmpId) {
    int position = 1;
    struct employee* currentEmp = headLL;

    // While loop to go through the LL till it reaches the end
    while (currentEmp != NULL) {
        // If statement to check if the current employee the code is looking at matches
        if (currentEmp->empId == whichEmpId) {
            return position;
        }

        // Moves onto then next employee in the list if not
        currentEmp = currentEmp->nextEmployee;
        position++;
    }

    // No ID was found
    return -1;
}
