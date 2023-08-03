#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Account.h"

struct BankAccount* accounts;
int numAccounts = 0;

void addNewAccount() {
    printf("\nEnter account number: ");
    if (scanf("%d", &account.accountNumber) != 1) {
        printf("Please Enter Valid Input");
        return;
    }
    printf("Enter account holder name: ");
    if (scanf("%99s", account.accountHolderName) != 1) {
        printf("Please Enter Valid Input");
        return;
    }
    printf("Enter account balance: ");
    if (scanf("%f", &account.accountBalance) != 1) {
        printf("Please Enter Valid Input");
        return;
    }

    // Increase the size of the accounts array
    numAccounts++;
    struct BankAccount* temp = (struct BankAccount*)realloc(accounts, numAccounts * sizeof(struct BankAccount));
    if (temp == NULL) {
        printf("Memory allocation failed");
        return;
    }
    accounts = temp;
    // Add the new account to the array
    accounts[numAccounts - 1] = account;

    printf("\nNew account added successfully!\n");
}
void deleteAccount() {
    int accountNumber;
    int accountIndex = -1;
    printf("\nEnter account number to delete: ");
    if (scanf("%d", &accountNumber) != 1) {
        printf("Error: Invalid input");
        return;
    }

    // Find the index of the account to be deleted
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            accountIndex = i;
            break;
        }
    }

    // Delete the account from the array
    if (accountIndex == -1) {
        printf("\nAccount not found!\n");
    }
    else {
        for (int i = accountIndex; i < numAccounts - 1; i++) {
            accounts[i] = accounts[i + 1];
        }
        numAccounts--;
        struct BankAccount* tmpPtr;
        tmpPtr = (struct BankAccount*)realloc(accounts, numAccounts * sizeof(struct BankAccount));
        if (tmpPtr == NULL) {
            printf("Error: Memory allocation failed");
            // handle the error appropriately (e.g., exit the program)
        }
        else {
            accounts = tmpPtr;
        }
        printf("\nAccount deleted successfully!\n");
    }
}
void updateAccount() {
    int accountNumber;
    int accountIndex = -1;
    printf("\nEnter account number to update: ");
    if (scanf("%d", &accountNumber) != 1) {
        printf("\nInvalid Input\n");
        return;
    }

    // Find the index of the account to be updated
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            accountIndex = i;
            break;
        }
    }

    // Update the account details
    if (accountIndex == -1) {
        printf("\nAccount not found!\n");
    }
    else {
        printf("\n1. Update account holder name\n");
        printf("2. Update account balance\n");
        printf("3. Deposit money\n");
        printf("4. Withdraw money\n");
        printf("\nEnter your choice: ");
        int choice;
        if (scanf("%d", &choice) != 1) {
            printf("Invalid Choice\n");
            return;
        }

        switch (choice) {
        case 1:
            printf("\nEnter new account holder name: ");
            if (scanf("%s", accounts[accountIndex].accountHolderName) != 1) {
                printf("Invalid Input\n");
                return;
            }
            printf("\nAccount holder name updated successfully!\n");
            break;

        case 2:
            printf("Enter new account balance: ");
            if (scanf("%f", &accounts[accountIndex].accountBalance) != 1) {
                printf("Invalid Input\n");
                return;
            }
            printf("\nAccount balance updated successfully!\n");
            break;

        case 3:
            printf("Enter the amount to be deposited: ");
            float depositAmount;
            if (scanf("%f", &depositAmount) != 1) {
                printf("Invalid Input\n");
            }
            accounts[accountIndex].accountBalance += depositAmount;
            printf("\nAmount deposited successfully!\n");
            break;

        case 4:
            printf("Enter the amount to be withdrawn: ");
            float withdrawAmount;
            if (scanf("%f", &withdrawAmount) != 1) {
                printf("Invalid Input\n");
                return;
            }
            if (withdrawAmount > accounts[accountIndex].accountBalance) {
                printf("\nInsufficient balance!\n");
            }
            else {
                accounts[accountIndex].accountBalance -= withdrawAmount;
                printf("\nAmount withdrawn successfully!\n");
            }
            break;

        default:
            printf("\nInvalid choice!\n");
        }
    }
}
void transferMoney() {
    int sourceAccountNumber, destAccountNumber, sourceAccountIndex = -1, destAccountIndex = -1;
    float amount;
    printf("\nEnter source account number: ");
    if (scanf("%d", &sourceAccountNumber) != 1) {
        printf("Invalid source account number\n");
        return;
    }
    printf("Enter destination account number: ");
    if (scanf("%d", &destAccountNumber) != 1) {
        printf("Invalid destination account number\n");
        return;
    }
    printf("Enter amount to transfer: ");
    if (scanf("%f", &amount) != 1) {
        printf("Invalid amount entered");
        return;
    }

    // Find the indexes of the source and destination accounts
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == sourceAccountNumber) {
            sourceAccountIndex = i;
        }
        if (accounts[i].accountNumber == destAccountNumber) {
            destAccountIndex = i;
        }
    }

    // Check if source and destination accounts exist
    if (sourceAccountIndex == -1) {
        printf("\nSource account not found!\n");
    }
    else if (destAccountIndex == -1) {
        printf("\nDestination account not found!\n");
    }
    else {
        // Check if the source account has sufficient balance
        if (accounts[sourceAccountIndex].accountBalance >= amount) {
            accounts[sourceAccountIndex].accountBalance -= amount;
            accounts[destAccountIndex].accountBalance += amount;
            printf("\nAmount transferred successfully!\n");
        }
        else {
            printf("\nInsufficient balance!\n");
        }
    }
}
void searchAccount() {
    char accountHolderName[MAX_CHAR];
    int accountFound = 0;
    printf("\nEnter account holder name to search: ");
    if (scanf("%99s", accountHolderName) != 1) {
        printf("Error reading input!\n");
        return;
    }
    accountHolderName[strlen(accountHolderName)] = '\0';

    // Display the accounts with matching account holder name
    printf("\nAccounts with account holder name '%s':\n", accountHolderName);
    for (int i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].accountHolderName, accountHolderName) == 0) {
            printf("Account Number: %d\n", accounts[i].accountNumber);
            printf("Account Holder Name: %s\n", accounts[i].accountHolderName);
            printf("Account Balance: %f\n\n", accounts[i].accountBalance);
            accountFound = 1;
        }
    }

    if (!accountFound) {
        printf("No accounts found with account holder name '%s'\n", accountHolderName);
    }
}