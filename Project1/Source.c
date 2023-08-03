//Group 14 - CSCN71030 - Team Based Software Development Project 2 
// - Muhammad Zahan Badshah
// - Mayank Ameti
// - Aditya Parab 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "Account.h"


int main(void) {
    int choice;
    bool done = true;
    while (done) {
        printf("\n------------------------\n");
        printf("Bank Account Management System\n");
        printf("------------------------\n");
        printf("1. Add New Account\n");
        printf("2. Delete Account\n");
        printf("3. Update Account\n");
        printf("4. transfer money\n");
        printf("5. Display Single Account\n");
        printf("6. Display Range Accounts\n");
        printf("7. Display All Accounts\n");
        printf("8. Search Account\n");
        printf("9. Save Data\n");
        printf("10. Load Data\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice, try again");
        }

        switch (choice) {
        case 1:
            addNewAccount();
            break;
        case 2:
            deleteAccount();
            break;
        case 3:
            updateAccount();
            break;
        case 4:
            transferMoney();
            break;
        case 5:
            displaySingleAccount();
            break;
        case 6:
            displayRangeAccounts();
            break;
        case 7:
            displayAllAccounts();
            break;
        case 8:
            searchAccount();
            break;
        case 9:
            saveData();
            break;
        case 10:
            loadData();
            break;
        case 11:
            printf("\nExiting program...\n");
            exit(0);
        default:
            printf("\nInvalid choice! Try again.\n");
            break;
        }
    }
    return 0;
}