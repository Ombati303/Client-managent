#include <stdio.h>
#include <string.h>

//struct that store user admin information
struct adminInformation {
    char adminName[50];
    char adminPassword[9];
};

//struct that store client information
struct clientInformation {
    char clientName[50];
    char clientOrder[50];
    int clientNumber;
    int clientExpenditure;
    int clientPayment;
    int clientBalance;
};
// function to add new client information to the array of clients
void addClient(struct clientInformation clients[], int *numClients) {
    printf("\nEnter client information:\n");
    printf("Name: ");
    scanf("%s", clients[*numClients].clientName);
    printf("Order: ");
    scanf("%s", clients[*numClients].clientOrder);
    printf("Number: ");
    scanf("%d", &clients[*numClients].clientNumber);
    printf("Expenditure: ");
    scanf("%d", &clients[*numClients].clientExpenditure);
    printf("Payment: ");
    scanf("%d", &clients[*numClients].clientPayment);
    clients[*numClients].clientBalance = clients[*numClients].clientExpenditure - clients[*numClients].clientPayment;
    (*numClients)++;
    printf("\nClient added successfully.\n\n");
}

// function to display all client information
void displayClients(struct clientInformation clients[], int numClients) {
    printf("\nClient information:\n");
    for (int i = 0; i < numClients; i++) {
        printf("Name: %s\n", clients[i].clientName);
        printf("Order: %s\n", clients[i].clientOrder);
        printf("Number: %d\n", clients[i].clientNumber);
        printf("Expenditure: %d\n", clients[i].clientExpenditure);
        printf("Payment: %d\n", clients[i].clientPayment);
        printf("Balance: %d\n", clients[i].clientBalance);
        printf("\n");
    }
}

// function to edit client information by client number
void editClient(struct clientInformation clients[], int numClients) {
    int clientNumber;
    printf("\nEnter client number to edit: ");
    scanf("%d", &clientNumber);
    for (int i = 0; i < numClients; i++) {
        if (clients[i].clientNumber == clientNumber) {
            printf("\nEditing client %d:\n", clientNumber);
            printf("Name: ");
            scanf("%s", clients[i].clientName);
            printf("Order: ");
            scanf("%s", clients[i].clientOrder);
            printf("Number: ");
            scanf("%d", &clients[i].clientNumber);
            printf("Expenditure: ");
            scanf("%d", &clients[i].clientExpenditure);
            printf("Payment: ");
            scanf("%d", &clients[i].clientPayment);
            clients[i].clientBalance = clients[i].clientExpenditure - clients[i].clientPayment;
            printf("\nClient information updated.\n\n");
            return;
        }
    }
    printf("\nClient number %d not found.\n\n", clientNumber);
}
// function to search client information by client name
void searchClient(struct clientInformation clients[], int numClients) {
char clientName[50];
printf("\nEnter client name to search: ");
scanf("%s", clientName);
int found = 0;
for (int i = 0; i < numClients; i++) {
if (strcmp(clients[i].clientName, clientName) == 0) {
printf("\nClient found:\n");
printf("Name: %s\n", clients[i].clientName);
printf("Order: %s\n", clients[i].clientOrder);
printf("Number: %d\n", clients[i].clientNumber);
printf("Expenditure: %d\n", clients[i].clientExpenditure);
printf("Payment: %d\n", clients[i].clientPayment);
printf("Balance: %d\n", clients[i].clientBalance);
printf("\n");
found = 1;
break;
}
}
if (!found) {
printf("\nClient name '%s' not found.\n\n", clientName);
}
}

void clientOptions() {
struct clientInformation clients[100];
int numClients = 0;
int choice;
do {
printf("Choose an option:\n");
printf("1. Add client\n");
printf("2. Display clients\n");
printf("3. Edit client\n");
printf("5. Search client\n");
printf("6. Exit\n");
printf("Enter choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
addClient(clients, &numClients);
break;
case 2:
displayClients(clients, numClients);
break;
case 3:
editClient(clients, numClients);
break;
case 5:
searchClient(clients, numClients);
break;
case 6:
printf("Exiting program...\n");
break;
default:
printf("Invalid choice. Try again.\n");
break;
}
} while (choice != 6);
}

//administrator information
void admin() {
    printf("1: log in\n2: register\n3: exit\n");

    //opt1 to store admin first option
    short int opt1;
    scanf("%hd", &opt1);

    struct adminInformation adminInformation;

    if (opt1 == 1) {
        printf("Enter your username: ");
        scanf("%s", adminInformation.adminName);
        printf("Enter your password: ");
        scanf("%s", adminInformation.adminPassword);

        int result = strcmp(adminInformation.adminName, adminInformation.adminName);
        int result2 = strcmp(adminInformation.adminPassword, adminInformation.adminPassword);

        if (result == 0 || result2 == 0) {
            printf("    welcome \n");
            clientOptions();
        } else {
            printf("Invalid username or password.\n");
        }

    } else if (opt1 == 2) {
        printf("Username: ");
        scanf("%s", adminInformation.adminName);
        printf("Password: ");
        scanf("%s", adminInformation.adminPassword);
        printf("\nLog now:\n");
        printf("Enter your username: ");
        scanf("%s", adminInformation.adminName);
        printf("Enter your password: ");
        scanf("%s", adminInformation.adminPassword);

        int result = strcmp(adminInformation.adminName, adminInformation.adminName);
        int result2 = strcmp(adminInformation.adminPassword, adminInformation.adminPassword);

        if (result == 0 || result2 == 0) {
            printf("    welcome \n");
            clientOptions();
        } else {
            printf("Invalid username or password.\n");
        }

    } else if (opt1 == 3) {
        printf("\nYou exited.\n");
    } else {
        printf("Invalid option!\n");
    }
}

int main() {
    printf("Welcome\n");
    admin();
    return 0;
}
