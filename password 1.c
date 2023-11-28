#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

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

    return 0;
}
