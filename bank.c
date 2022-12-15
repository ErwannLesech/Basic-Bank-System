#include <stdio.h> // For printf()
#include <stdlib.h> // For exit()
#include <string.h> // For strcmp()
#include "bank.h" // For login system

// DATABASE FUNCTIONS

void initDatabase(struct bank *db)
{
    for (int i = 0; i < 10; i++)
    {
        db->users[i].username[0] = '\0';
        db->users[i].password[0] = '\0';
    }
    for (int i = 0; i < 100; i++)
    {
        db->accounts[i].account_number = 0;
        db->accounts[i].account_balance = 0;
    }
}

void addUser(struct bank *db, struct login *user)
{
    for (int i = 0; i < 10; i++)
    {
        if (db->users[i].username[0] == '\0')
        {
            db->users[i] = *user;
            db->accounts[i] = *user->accounts;
            break;
        }
    }
    if (db->users[9].username[0] != '\0')
    {
        printf("Database is full!\n");
    }
}

void removeUser(struct bank *db, struct login *user)
{
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(db->users[i].username, user->username) == 0)
        {
            db->users[i].username[0] = '\0';
            db->users[i].password[0] = '\0';
            break;
        }
    }
}

int findUser(struct bank *db, struct login *user)
{
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(db->users[i].username, user->username) == 0)
        {
            if (strcmp(db->users[i].password, user->password) == 0)
            {
                return i;
            }
        }
    }

    return -1;
}

void printDatabase(struct bank *db)
{
    printf("Database:\n--------\n");
    for (int i = 0; i < 10; i++)
    {
        if (db->users[i].username[0] != '\0')
        {
            printf("Username: %s Password: %s\n", db->users[i].username, db->users[i].password);
            for (size_t i = 0; i < 10; i++)
            {
                if (db->users[i].accounts[i].account_number != 0)
                {
                    printf("Account number: %d - Account balance: %d\n", db->users[i].accounts[i].account_number, db->users[i].accounts[i].account_balance);
                }
            }
            
        }
    }
    printf("--------\n");
}

// FUNCTIONS FOR USER

void registerUser(struct login *user)
{
    printf("Enter username: ");
    scanf("%s", user->username);
    printf("Enter password: ");
    scanf("%s", user->password);
    for (size_t i = 0; i < 10; i++)
    {
        user->accounts[i].account_number = 0;
        user->accounts[i].account_balance = 0;
    }
    
}

void loginUser(struct login *user)
{
    printf("Enter username: ");
    scanf("%s", user->username);
    printf("Enter password: ");
    scanf("%s", user->password);
}

int checkUser(struct bank *db, struct login *user)
{
    int index = findUser(db, user);

    if (index == -1)
    {
        printf("User not found!\n");
        return -1;
    }
    else
    {
        printf("User found!\n");
        return index;
    }
}

void printUser(struct login *user)
{
    printf("Username: %s Password: %s\n", user->username, user->password);
    for (size_t i = 0; i < 10; i++)
    {
        if (user->accounts[i].account_number != 0)
        {
            printf("Account number: %d - Account balance: %d\n", user->accounts[i].account_number, user->accounts[i].account_balance);
        }
    }
    
}

void exitProgram()
{
    printf("Exiting program...\n");
    exit(0);
}

// FUNCTIONS FOR BANK ACCOUNTS

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