#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define MAX_ACCOUNTS 10
#define MAX_CHAR    100

// Structure to hold bank account details
struct BankAccount {
    int accountNumber;
    char accountHolderName[MAX_CHAR];
    float accountBalance;
};
struct BankAccount account;


// Function prototypes
void addNewAccount();
void deleteAccount();
void updateAccount();
void transferMoney();
void searchAccount();
void saveData();
void loadData();
