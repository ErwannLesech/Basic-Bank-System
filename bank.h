#ifndef BANK_H
#define BANK_H

#include "login.h"

struct bank_account
{
    int account_number;
    int account_balance;
};

// Function to create a new bank account
void createAccount(struct login *user, struct bank *db);

// Function to delete a bank account
void deleteAccount(struct login *user, int account_number, struct bank *db);

// Function to print a bank account
void printAccount(int account_number, struct bank *db);

// Function to deposit money to a bank account
void depositMoney(int account_number, int amount, struct bank *db);

// Function to withdraw money from a bank account
void withdrawMoney(int account_number, int amount, struct bank *db);

// Function to transfer money from one bank account to another
void transferMoney(int account1_number, int account2_number, int amount, struct bank *db);

#endif