#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
    
    return 0;
}