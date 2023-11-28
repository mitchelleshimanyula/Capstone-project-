#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50
#define MAX_BUSES 10
#define MAX_SEATS 60


typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Employee;

bool authenticate(Employee* employees, int numEmployees, const char* username, const char* password) {
    // Search for the employee with the specified username and password
    int i = 0;
    while (i < numEmployees && (strcmp(employees[i].username, username) != 0 || strcmp(employees[i].password, password) != 0)) {
        i++;
    }

    // Check if the employee was found
    return i < numEmployees;
}

int main() {
    Employee employees[] = {
        {"employee1", "password1"},
        {"employee2", "password2"}
    };
    int numEmployees = sizeof(employees) / sizeof(Employee);
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter your username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0';

    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';

    if (authenticate(employees, numEmployees, username, password)) {
        printf("Login successful!\n");
        
    } else {
        printf("Login failed!\n");
	}
}
// Structure to represent a bus
typedef struct {
    int busNumber;
    char source[50];
    char destination[50];
}

// Function declarations
void displayAllBuses(Bus buses[], int *numBuses);
void addBus(Bus buses[], int *numBuses);
void deleteBus(Bus buses[], int *numBuses);
void modifyBus(Bus buses[], int numBuses);

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

    }while (choice != 0);
   }
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
  }
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

//Structure to represent a booking
struct Booking
{
    char customer_name[50];
    int bus_number;
    int seat_number;
    struct Booking *next; // To point to the next booking
};

//Initialize the head of the linked list
struct Booking *head = NULL;

//Function to add a new booking
void addBooking(char customer_name[], int bus_number, int seat_number) {
    struct Booking *new_booking = (struct Booking*) malloc(sizeof(struct Booking));
    strcpy(new_booking->customer_name, customer_name);
    new_booking->bus_number = bus_number;
    new_booking->seat_number = seat_number;
    new_booking->next = head; // New booking points to the previous head
    head = new_booking; // New booking becomes the new head
}

//Function to display the booking history
void viewBookingHistory() {
    struct Booking *temp = head;
    printf("Booking History:\n");
    while(temp != NULL) {
        printf("Booking %d:\n",temp->bus_number);
        printf("Customer name:%s\n",temp->customer_name);
        printf("Bus Number:%d\n",temp->bus_number);
        printf("Seat Number:%d\n",temp->seat_number);
        printf("\n");
        temp = temp->next; // Move to the next booking
    }
}

int main() {
    int choice;
    do{
        printf("1. Add Booking\n" );
        printf("2. View Booking History\n" );
        printf("3.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        
        switch(choice) {
            case 1: {
                char customer_name[50];
                int bus_number, seat_number;
                printf("Enter customer name: ");
                scanf("%s", customer_name);
                printf("Enter bus number: ");
                scanf("%d", &bus_number);
                printf("Enter seat number: ");
                scanf("%d", &seat_number);
                addBooking(customer_name, bus_number, seat_number);
                break;
            }
            case 2:
                viewBookingHistory();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.Please try again.\n");
                break;
        }
    }while(choice!=3);
  }
}

struct Booking {
    char customer_name[50];
    int bus_number;
    int seat_number;
};

void saveBooking(struct Booking booking) {
    FILE *file = fopen("bookings.txt", "a");
    if (file == NULL) {
        printf("Error: Unable to open the file for writing.\n");
        return;
    }

    fprintf(file, "%s %d %d\n", booking.customer_name, booking.bus_number, booking.seat_number);
    fclose(file);
}

void addBooking() {
    struct Booking newBooking;
    printf("Enter Customer Name: ");
    scanf("%s", newBooking.customer_name);
    printf("Enter Bus Number: ");
    scanf("%d", &newBooking.bus_number);
    printf("Enter Seat Number: ");
    scanf("%d", &newBooking.seat_number);

    saveBooking(newBooking);
    printf("Booking added successfully.\n");
}

int main() {
    int choice;
    do {
        printf("1. Add Booking\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBooking();
                break;
            case 2:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 2);

    return 0;
}