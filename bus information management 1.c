#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUSES 10

// Structure to represent a bus
typedef struct {
    int busNumber;
    char source[50];
    char destination[50];
} Bus;

// Function declarations
void displayAllBuses(Bus buses[], int *numBuses);
void addBus(Bus buses[], int *numBuses);
void deleteBus(Bus buses[], int *numBuses);
void modifyBus(Bus buses[], int numBuses);

int main() {
    Bus buses[MAX_BUSES];
    int numBuses = 0;
    int choice;

    do {
        printf("\n--- Bus Information Management System ---\n");
        printf("1. Display All Buses\n");
        printf("2. Add a New Bus Schedule\n");
        printf("3. Delete a Bus Schedule\n");
        printf("4. Modify a Bus Schedule\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayAllBuses(buses, &numBuses);
                break;
            case 2:
                addBus(buses, &numBuses);
                break;
            case 3:
                deleteBus(buses, &numBuses);
                break;
            case 4:
                modifyBus(buses, numBuses);
                break;
            case 0:
                printf("Exiting the Bus Information Management System. Goodbye!\n");
                break;
            default:
                printf("Invalid Choice. Please enter a valid option.\n");
        }

    } while (choice != 0);

    return 0;
}

// Display all bus schedules
void displayAllBuses(Bus buses[], int *numBuses) {
    printf("\nAll Bus Schedules:\n");
    int i = 0;
    while (i < *numBuses) {
        printf("Bus %d: %s to %s\n", buses[i].busNumber, buses[i].source, buses[i].destination);
        i++;
    }
}

// Add a new bus schedule
void addBus(Bus buses[], int *numBuses) {
    if (*numBuses < MAX_BUSES) {
        Bus newBus;
        newBus.busNumber = *numBuses + 1;

        printf("Enter Source: ");
        scanf("%s", newBus.source);
        printf("Enter Destination: ");
        scanf("%s", newBus.destination);

        buses[*numBuses] = newBus;
        (*numBuses)++;

        printf("Bus Schedule added successfully!\n");
    } else {
        printf("Cannot add more buses. Maximum limit reached.\n");
    }
}

// Delete a bus schedule
void deleteBus(Bus buses[], int *numBuses) {
    if (*numBuses > 0) {
        int busNumber;
        printf("Enter Bus Number to delete: ");
        scanf("%d", &busNumber);

        int i = 0;
        while (i < *numBuses && buses[i].busNumber != busNumber) {
            i++;
        }

        if (i < *numBuses) {
            // Shift remaining buses to fill the gap
            memmove(&buses[i], &buses[i + 1], (*numBuses - i - 1) * sizeof(Bus));
            (*numBuses)--;
            printf("Bus Schedule %d deleted successfully!\n", busNumber);
        } else {
            printf("Bus Schedule not found.\n");
        }
    } else {
        printf("No buses to delete.\n");
    }
}

// Modify a bus schedule
void modifyBus(Bus buses[], int numBuses) {
    if (numBuses > 0) {
        int busNumber;
        printf("Enter Bus Number to modify: ");
        scanf("%d", &busNumber);

        int i = 0;
        while (i < numBuses && buses[i].busNumber != busNumber) {
            i++;
        }

        if (i < numBuses) {
            printf("Enter new Source: ");
            scanf("%s", buses[i].source);
            printf("Enter new Destination: ");
            scanf("%s", buses[i].destination);

            printf("Bus Schedule %d modified successfully!\n", busNumber);
        } else {
            printf("Bus Schedule not found.\n");
        }
    } else {
        printf("No buses to modify.\n");
    }
}
