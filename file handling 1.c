#include <stdio.h>

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