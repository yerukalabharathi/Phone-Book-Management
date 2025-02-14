#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[50];
    char phone[15];
    char email[50];
};

struct Phonebook {
    struct Contact contacts[MAX_CONTACTS];
    int count;
};

void addContact(struct Phonebook* pb, const char* name, const char* phone, const char* email) {
    if (pb->count < MAX_CONTACTS) {
        strncpy_s(pb->contacts[pb->count].name, name, sizeof(pb->contacts[pb->count].name) - 1);
        strncpy_s(pb->contacts[pb->count].phone, phone, sizeof(pb->contacts[pb->count].phone) - 1);
        strncpy_s(pb->contacts[pb->count].email, email, sizeof(pb->contacts[pb->count].email) - 1);
        pb->count++;
        printf("Contact added successfully.\n");
    }
    else {
        printf("Phonebook is full. Cannot add more contacts.\n");
    }
}

void searchContact(const struct Phonebook* pb, const char* name) {
    int found = 0;
    for (int i = 0; i < pb->count; ++i) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            printf("Contact found:\n");
            printf("Name: %s\nPhone: %s\nEmail: %s\n", pb->contacts[i].name, pb->contacts[i].phone, pb->contacts[i].email);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

void displayPhonebook(const struct Phonebook* pb) {
    if (pb->count == 0) {
        printf("Phonebook is empty.\n");
    }
    else {
        printf("Phonebook contacts:\n");
        for (int i = 0; i < pb->count; ++i) {
            printf("Name: %s\nPhone: %s\nEmail: %s\n\n", pb->contacts[i].name, pb->contacts[i].phone, pb->contacts[i].email);
        }
    }
}

int main() {
    struct Phonebook phonebook;
    phonebook.count = 0;
    int choice;
    char name[50], phone[15], email[50];

    do {
        printf("\nPhonebook Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Display Phonebook\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter contact details:\n");
            printf("Name: ");
            scanf_s("%s", name, sizeof(name));
            printf("Phone: ");
            scanf_s("%s", phone, sizeof(phone));
            printf("Email: ");
            scanf_s("%s", email, sizeof(email));
            addContact(&phonebook, name, phone, email);
            break;
        case 2:
            printf("Enter name to search: ");
            scanf_s("%s", name, sizeof(name));
            searchContact(&phonebook, name);
            break;
        case 3:
            displayPhonebook(&phonebook);
            break;
        case 4:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
