#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUSES 10
#define MAX_SEATS 60

// Structure to represent a bus
typedef struct {
    int busNumber;
    char source[50];
    char destination[50];
    int seats[MAX_SEATS];
} Bus;

// Function declarations
void initializeBuses(Bus buses[], int numBuses);
void displayAvailableBuses(Bus buses[], int numBuses);
void viewAvailableSeats(Bus *bus);
void bookSeat(Bus *bus, int seatNumber);
void issueTicket(Bus *bus, int seatNumber);
void cancelBooking(Bus *bus, int seatNumber);

int main() {
    Bus buses[MAX_BUSES];
    initializeBuses(buses, MAX_BUSES);

    int choice;
    do {
        printf("\n--- Bus Reservation System ---\n");
        printf("1. Display Available Buses\n");
        printf("2. View Available Seats for a Bus\n");
        printf("3. Book a Seat\n");
        printf("4. Issue Ticket\n");
        printf("5. Cancel Booking\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayAvailableBuses(buses, MAX_BUSES);
                break;
            case 2:
                {
                    int busNumber;
                    printf("Enter Bus Number: ");
                    scanf("%d", &busNumber);
                    if (busNumber >= 1 && busNumber <= MAX_BUSES) {
                        viewAvailableSeats(&buses[busNumber - 1]);
                    } else {
                        printf("Invalid Bus Number\n");
                    }
                }
                break;
            case 3:
                {
                    int busNumber, seatNumber;
                    printf("Enter Bus Number: ");
                    scanf("%d", &busNumber);
                    if (busNumber >= 1 && busNumber <= MAX_BUSES) {
                        printf("Enter Seat Number: ");
                        scanf("%d", &seatNumber);
                        if (seatNumber >= 1 && seatNumber <= MAX_SEATS) {
                            bookSeat(&buses[busNumber - 1], seatNumber);
                        } else {
                            printf("Invalid Seat Number\n");
                        }
                    } else {
                        printf("Invalid Bus Number\n");
                    }
                }
                break;
            case 4:
                {
                    int busNumber, seatNumber;
                    printf("Enter Bus Number: ");
                    scanf("%d", &busNumber);
                    if (busNumber >= 1 && busNumber <= MAX_BUSES) {
                        printf("Enter Seat Number: ");
                        scanf("%d", &seatNumber);
                        if (seatNumber >= 1 && seatNumber <= MAX_SEATS) {
                            issueTicket(&buses[busNumber - 1], seatNumber);
                        } else {
                            printf("Invalid Seat Number\n");
                        }
                    } else {
                        printf("Invalid Bus Number\n");
                    }
                }
                break;
            case 5:
                {
                    int busNumber, seatNumber;
                    printf("Enter Bus Number: ");
                    scanf("%d", &busNumber);
                    if (busNumber >= 1 && busNumber <= MAX_BUSES) {
                        printf("Enter Seat Number: ");
                        scanf("%d", &seatNumber);
                        if (seatNumber >= 1 && seatNumber <= MAX_SEATS) {
                            cancelBooking(&buses[busNumber - 1], seatNumber);
                        } else {
                            printf("Invalid Seat Number\n");
                        }
                    } else {
                        printf("Invalid Bus Number\n");
                    }
                }
                break;
            case 0:
                printf("Exiting the Bus Reservation System. Goodbye!\n");
                break;
            default:
                printf("Invalid Choice. Please enter a valid option.\n");
        }

    } while (choice != 0);

    return 0;
}

// Initialize bus data
void initializeBuses(Bus buses[], int numBuses) {
    int i = 0;
    while (i < numBuses) {
        buses[i].busNumber = i + 1;
        sprintf(buses[i].source, "Source%d", i + 1);
        sprintf(buses[i].destination, "Destination%d", i + 1);

        int j = 0;
        while (j < MAX_SEATS) {
            buses[i].seats[j] = 0; // 0 indicates an available seat
            j++;
        }

        i++;
    }
}

// Display available buses
void displayAvailableBuses(Bus buses[], int numBuses) {
    int i = 0;
    while (i < numBuses) {
        printf("%d. %s to %s\n", buses[i].busNumber, buses[i].source, buses[i].destination);
        i++;
    }
}

// View available seats for a bus
void viewAvailableSeats(Bus *bus) {
    printf("\nAvailable Seats for Bus %d (%s to %s):\n", bus->busNumber, bus->source, bus->destination);

    int i = 0;
    while (i < MAX_SEATS) {
        if (bus->seats[i] == 0) {
            printf("%d ", i + 1); // Display available seat numbers
        }
        i++;
    }

    printf("\n");
}

// Book a seat on a bus
void bookSeat(Bus *bus, int seatNumber) {
    if (bus->seats[seatNumber - 1] == 0) {
        bus->seats[seatNumber - 1] = 1; // 1 indicates a booked seat
        printf("Seat %d booked successfully on Bus %d.\n", seatNumber, bus->busNumber);
    } else {
        printf("Seat %d is already booked.\n", seatNumber);
    }
}

// Issue a ticket for a booked seat
void issueTicket(Bus *bus, int seatNumber) {
    if (bus->seats[seatNumber - 1] == 1) {
        printf("Ticket Issued for Seat %d on Bus %d (%s to %s).\n", seatNumber, bus->busNumber, bus->source, bus->destination);
    } else {
        printf("Seat %d is not booked. Cannot issue a ticket.\n", seatNumber);
    }
}

// Cancel booking for a seat
void cancelBooking(Bus *bus, int seatNumber) {
    if (bus->seats[seatNumber - 1] == 1) {
        bus->seats[seatNumber - 1] = 0; // Mark the seat as available
        printf("Booking canceled for Seat %d on Bus %d.\n", seatNumber, bus->busNumber);
    } else {
        printf("Seat %d is not booked. No booking to cancel.\n", seatNumber);
    }
}
