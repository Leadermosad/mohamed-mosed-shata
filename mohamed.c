#include <stdio.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_NAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

struct User {
    char username[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct User users[MAX_USERS];
int numUsers = 0;

void registerUser() {
    if (numUsers >= MAX_USERS) {
        printf("Maximum number of users reached. Cannot register more users.\n");
        return;
    }
    
    struct User newUser;
    
    printf("Enter username (up to %d characters): ", MAX_NAME_LENGTH);
    scanf("%s", newUser.username);
    
    printf("Enter password (up to %d characters): ", MAX_PASSWORD_LENGTH);
    scanf("%s", newUser.password);
    
    users[numUsers++] = newUser;
    
    printf("Registration successful!\n");
}

void loginUser() {
    char username[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    
    printf("Enter username: ");
    scanf("%s", username);
    
    printf("Enter password: ");
    scanf("%s", password);
    
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful. Welcome, %s!\n", users[i].username);
            return;
        }
    }
    
    printf("Login failed. Invalid username or password.\n");
}

int main() {
    int choice;
    
    do {
        printf("\n-- User Authentication System --\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
    
    return 0;                                                                                                         
}
