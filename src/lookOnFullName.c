#include "../include/functionHeaders.h"

int lookOnFullName(struct employee* headLL, char whichName[100]) {
    int position = 0;
    struct employee* currentEmp = headLL;

    // while loop to go through the LL till it reaches the end
    while (currentEmp != NULL) {
        char empFullName[200];

        // Concatenates the names to later be compared.
        strcpy(empFullName, currentEmp->fname);
        strcat(empFullName, " ");
        strcat(empFullName, currentEmp->lname);

        // Compares the names
        if (strcmp(empFullName, whichName) == 0) {
            return position + 1;
        }

        // Will continue to next employee if the names do not match
        position++;
        currentEmp = currentEmp->nextEmployee;
    }

    // No employee was found
    return -1;
}
