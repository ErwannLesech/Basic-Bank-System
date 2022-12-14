#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bank.h"

void createAccount(struct login *user, struct bank *db)
{
    struct bank_account *account = malloc(sizeof(struct bank_account));
    printf("Enter account number: ");
    scanf("%d", &account->account_number);
    printf("Enter account balance: ");
    scanf("%d", &account->account_balance);
    for (int i = 0; i < 100; i++)
    {
        if (db->accounts[i].account_number == account->account_number)
        {
            printf("Account already exists!\n");
            break;
        }
        
        if (db->accounts[i].account_number == 0)
        {
            db->accounts[i] = *account;
            break;
        }
    }
    if (db->accounts[99].account_number != 0)
    {
        printf("Database is full!\n");
    }
    else
    {
        for(int i = 0; i < 10; i++)
        {
            if (user->accounts[i].account_number = 0)
            {
                user->accounts[i] = *account;
                break;
            }
        }
    }
}

void deleteAccount(struct login *user, int account_number, struct bank *db)
{
    for (int i = 0; i < 100; i++)
    {
        if (db->accounts[i].account_number == account_number)
        {
            db->accounts[i].account_number = 0;
            db->accounts[i].account_balance = 0;
            break;
        }
    }
    for (size_t i = 0; i < 10; i++)
    {
        if (user->accounts[i].account_number == account_number)
        {
            user->accounts[i].account_number = 0;
            user->accounts[i].account_balance = 0;
            break;
        }
    }
    
}

void printAccount(int account_number, struct bank *db)
{
    for (int i = 0; i < 100; i++)
    {
        if (db->accounts[i].account_number == account_number)
        {
            printf("Account number: %d \n Account balance: %d \n", db->accounts[i].account_number, db->accounts[i].account_balance);
            break;
        }
    }
}

void depositMoney(int account_number, int amount, struct bank *db)
{
    for (int i = 0; i < 100; i++)
    {
        if (db->accounts[i].account_number == account_number)
        {
            db->accounts[i].account_balance += amount;
            break;
        }
    }
}

void withdrawMoney(int account_number, int amount, struct bank *db)
{
    for (int i = 0; i < 100; i++)
    {
        if (db->accounts[i].account_number == account_number)
        {
            db->accounts[i].account_balance -= amount;
            break;
        }
    }
}

void transferMoney(int account1_number, int account2_number, int amount, struct bank *db)
{
    for (int i = 0; i < 100; i++)
    {
        if (db->accounts[i].account_number == account1_number)
        {
            db->accounts[i].account_balance -= amount;
        }
        if (db->accounts[i].account_number == account2_number)
        {
            db->accounts[i].account_balance += amount;
        }
    }
}


