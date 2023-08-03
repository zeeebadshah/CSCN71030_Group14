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