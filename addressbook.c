
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {
    typedef struct {
        char name[50];
        char phoneNumber[20];
        char email[50];
    } Contact;

    Contact contacts[10];

    printf("Welcome to address book. Type help to get started.\n");

    while (true) {
        printf("\n$ ");
        char command[5];
        scanf("%4s", command); // Adjust to read up to 4 characters

        if (strcmp(command, "nc") == 0) {
            printf("Enter the index (0-9) for the contact. Entering an index of an already existing contact will overwrite that contact.\n");
            int index;
            scanf("%d", &index);
            if (index < 0 || index > 9) {
                printf("Index out of range. Please enter a value between 0 and 9.\n");
                continue;
            }

            printf("Enter the contact name: ");
            scanf("%49s", contacts[index].name);
            printf("\n");

            printf("Enter the contact phone number: ");
            scanf("%19s", contacts[index].phoneNumber);
            printf("\n");

            printf("Enter the contact email: ");
            scanf("%49s", contacts[index].email);
            printf("\n");

            printf("The contact you have entered is:\n");
            printf("Name: %s\n", contacts[index].name);
            printf("Phone: %s\n", contacts[index].phoneNumber);
            printf("Email: %s\n", contacts[index].email);
            printf("Is this correct? y/n ");
            char correct[2];
            scanf("%1s", correct);
            if (strcmp(correct, "y") == 0) {
                printf("Contact created successfully at index %d.\n", index);

                // Open the file in append mode
                FILE *file = fopen("contacts.txt", "a");
                if (file == NULL) {
                    perror("Failed to open file");
                    return 1;
                }

                // Write the contact information to the file
                fprintf(file, "Index %d: Name: %s, Phone: %s, Email: %s\n",
                        index, contacts[index].name, contacts[index].phoneNumber, contacts[index].email);

                // Close the file
	        fclose(file);

            }
        } else if (strcmp(command, "exit") == 0) {
            break;


	} else if (strcmp(command, "help") == 0) {
		printf("List of available commands: nc, help, exit.");

	} else {
            printf("Unknown command. Type 'help' to see available commands.\n");
        }
    }


}

