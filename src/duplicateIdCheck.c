#include "../include/functionHeaders.h"

int duplicateIdCheck(struct employee **head, int empId) {
    struct employee *currentId = *head;

    // Goes through the LL
    while (currentId != NULL) {
        // If the ID's match
        if (currentId->empId == empId) {
            return 1;
        }

        // Move to the next item in the LL
        currentId = currentId->nextEmployee;
    }
    return 0;
}
